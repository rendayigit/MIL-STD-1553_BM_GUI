#include "bm.hpp"
#include "mt.h"
#include <chrono>
#include <exception>
#include <iostream>
#include <string>

BM::BM() : m_devNum(0x0000) {}

BM::~BM() { stopBm(); }

int BM::startBm(S16BIT devNum) {
  S16BIT Err;

  m_devNum = devNum;

  m_loop = false;

  if (m_monitorThread.joinable()) {
    m_monitorThread.join();
  }

  Err = aceFree(m_devNum);

  if (Err) {
    return Err;
  }

  Err = aceInitialize(m_devNum, ACE_ACCESS_CARD, ACE_MODE_MT, 0, 0, 0);

  if (Err) {
    return Err;
  }

  Err = aceMTStart(m_devNum);

  if (Err) {
    return Err;
  }

  try {
    m_loop = true;
    m_monitorThread = std::thread([&] { monitor(); });
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

int BM::stopBm() {
  S16BIT Err;

  m_loop = false;

  if (m_monitorThread.joinable()) {
    m_monitorThread.join();
  }

  Err = aceMTStop(m_devNum);

  if (Err) {
    return Err;
  }

  Err = aceFree(m_devNum);

  if (Err) {
    return Err;
  }

  return 0;
}

// TODO: Refactor below function, code aqcuired from mtpoll sample
std::string BM::getDecodedMsg(U32BIT nMsgNum, MSGSTRUCT *pMsg) {
  U16BIT i;
  char szBuffer[100];
  U16BIT wRT, wTR1, wTR2, wSA, wWC;

  std::string decodedMessage = "";

  /* Display message header info */
  if (pMsg->wTimeTag2 ||
      pMsg->wTimeTag3) /* If there is a 48-bit time tag, display it */
  {
    sprintf(szBuffer,
            "MSG #%04d.  TIME = %08d:%08d:%08dus    BUS %c   TYPE%d: %s ",
            nMsgNum, pMsg->wTimeTag3 * 2, pMsg->wTimeTag2 * 2,
            pMsg->wTimeTag * 2, pMsg->wBlkSts & ACE_MT_BSW_CHNL ? 'B' : 'A',
            pMsg->wType, aceGetMsgTypeString(pMsg->wType));
    decodedMessage += szBuffer;
  } else /* No 48-bit time tag */
  {
    sprintf(szBuffer, "MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ",
            nMsgNum, pMsg->wTimeTag * 2,
            pMsg->wBlkSts & ACE_MT_BSW_CHNL ? 'B' : 'A', pMsg->wType,
            aceGetMsgTypeString(pMsg->wType));
    decodedMessage += szBuffer;
  }

  /* Display command word info */
  aceCmdWordParse(pMsg->wCmdWrd1, &wRT, &wTR1, &wSA, &wWC);
  sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR1 ? 'T' : 'R', wSA, wWC);
  decodedMessage += "\n            CMD1 " + std::to_string(pMsg->wCmdWrd1) +
                    " --> " + szBuffer;

  if (pMsg->wCmdWrd2Flg) {
    aceCmdWordParse(pMsg->wCmdWrd2, &wRT, &wTR2, &wSA, &wWC);
    sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR2 ? 'T' : 'R', wSA, wWC);
    decodedMessage += "\n            CMD2 " + std::to_string(pMsg->wCmdWrd2) +
                      " --> " + szBuffer;
  }

  /* Display transmit status words */
  if ((wTR1 == 1) || (pMsg->wBlkSts & ACE_MT_BSW_RTRT)) {
    if (pMsg->wStsWrd1Flg) {
      decodedMessage += "\n            STA1 " + std::to_string(pMsg->wStsWrd1);
    }
  }

  /* Display Data words */
  for (i = 0; i < pMsg->wWordCount; i++) {
    if (i == 0) {
      decodedMessage += "\n            DATA ";
    }

    decodedMessage += std::to_string(pMsg->aDataWrds[i]) + "  ";

    if ((i % 8) == 7) {
      decodedMessage += "\n                 ";
    }
  }

  /* Display receive status words */
  if ((wTR1 == 0) && !(pMsg->wBlkSts & ACE_MT_BSW_RTRT)) {
    if (pMsg->wStsWrd1Flg) {
      decodedMessage += "\n            STA1 " + std::to_string(pMsg->wStsWrd1);
    }
  }

  if (pMsg->wStsWrd2Flg) {
    decodedMessage += "\n            STA2 " + std::to_string(pMsg->wStsWrd2);
  }

  decodedMessage += "\n\n";

  return decodedMessage;
}

void BM::monitor() {
  S16BIT Err;
  MSGSTRUCT sMsg;
  U32BIT nMsgNum = 0;

  /* Poll Msgs */
  while (m_loop) {
    Err = aceMTGetStkMsgDecoded(m_devNum, &sMsg, ACE_MT_MSGLOC_NEXT_PURGE,
                                ACE_MT_STKLOC_ACTIVE);
    if (Err == 1) {
      static std::string m_messageBuffer;
      m_messageBuffer += getDecodedMsg(++nMsgNum, &sMsg);

      if (m_messageBuffer.length() >= 1000) {
        updateMessages(m_messageBuffer);
        m_messageBuffer = "";
      }
    }

    // TODO: implement rt sa filter functionality

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
