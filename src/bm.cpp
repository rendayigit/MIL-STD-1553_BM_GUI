#include "bm.hpp"

#include <chrono>
#include <exception>
#include <iostream>
#include <string>

constexpr int US_TIME_LENGTH = 8;

BM::BM()
    : m_devNum(Json(CONFIG_PATH).getNode("DEFAULT_DEVICE_NUMBER").getValue<int>()),
      m_monitorPollThreadSleepMs(Json(CONFIG_PATH).getNode("MONITOR_POLL_THREAD_SLEEP_MS").getValue<int>()),
      m_isMonitoring(false), m_filter(false), m_filteredBus('A'), m_filteredRt(0), m_filteredSa(0) {}

BM::~BM() { stopBm(); }

S16BIT BM::startBm(int devNum) {
  S16BIT err = 0;

  m_devNum = devNum;

  m_logger.log(LOG_INFO, "start bm with dev: " + std::to_string(m_devNum));

  m_isMonitoring = false;

  if (m_monitorThread.joinable()) {
    m_monitorThread.join();
  }

  err = aceFree(static_cast<S16BIT>(m_devNum));

  if (err != 0) {
    return err;
  }

  err = aceInitialize(static_cast<S16BIT>(m_devNum), ACE_ACCESS_CARD, ACE_MODE_MT, 0, 0, 0);

  if (err != 0) {
    return err;
  }

  err = aceMTStart(static_cast<S16BIT>(m_devNum));

  if (err != 0) {
    return err;
  }

  try {
    m_isMonitoring = true;
    m_monitorThread = std::thread([&] { monitor(); });
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

S16BIT BM::stopBm() {
  S16BIT err = 0;

  m_logger.log(LOG_INFO, "stop bm with dev: " + std::to_string(m_devNum));

  m_isMonitoring = false;

  if (m_monitorThread.joinable()) {
    m_monitorThread.join();
  }

  err = aceMTStop(static_cast<S16BIT>(m_devNum));

  if (err != 0) {
    return err;
  }

  err = aceFree(static_cast<S16BIT>(m_devNum));

  if (err != 0) {
    return err;
  }

  return 0;
}

Message BM::getMessage(MSGSTRUCT *msg) {
  U16BIT rt = 0;
  U16BIT sa = 0;
  U16BIT rtRx = -1;
  U16BIT saRx = -1;
  U16BIT wc = 0;
  U16BIT wTR1 = 0;
  U16BIT wTR2 = 0;
  bool noRes = false;

  aceCmdWordParse(msg->wCmdWrd1, &rt, &wTR1, &sa, &wc);

  if (msg->wCmdWrd2Flg != 0U) {
    aceCmdWordParse(msg->wCmdWrd2, &rtRx, &wTR2, &saRx, &wc);
  }

  std::ostringstream time;

  time << std::setw(US_TIME_LENGTH) << std::setfill('0') << (msg->wTimeTag3 * 2) << ":" << std::setw(US_TIME_LENGTH)
       << std::setfill('0') << (msg->wTimeTag2 * 2) << ":" << std::setw(US_TIME_LENGTH) << std::setfill('0')
       << (msg->wTimeTag * 2) << "us";

  if ((msg->wBlkSts & ACE_MT_BSW_ERRFLG) != 0) { // NOLINT(hicpp-signed-bitwise)
    if (std::strcmp(aceGetBSWErrString(ACE_MODE_MT, msg->wBlkSts), "NORES") != 0) {
      noRes = true;
    }
  }

  return Message(rt, sa, rtRx, saRx, wc,
                 (msg->wBlkSts & ACE_MT_BSW_CHNL) != 0 ? 'B' : 'A', // NOLINT(hicpp-signed-bitwise)
                 aceGetMsgTypeString(msg->wType), time.str(), msg->aDataWrds, msg->wCmdWrd2Flg != 0U, noRes);
}

void BM::monitor() {
  S16BIT err = 0;
  MSGSTRUCT sMsg;
  std::string messageBuffer;

  // Poll Messages
  while (m_isMonitoring) {
    std::this_thread::sleep_for(std::chrono::milliseconds(m_monitorPollThreadSleepMs));

    err = aceMTGetStkMsgDecoded(static_cast<S16BIT>(m_devNum), &sMsg, ACE_MT_MSGLOC_NEXT_PURGE, ACE_MT_STKLOC_ACTIVE);

    if (err == 1) {
      Message message = getMessage(&sMsg);

      std::string messageString =
          "Time: " + message.getTime() + "\t Bus: " + message.getBus() + "\t Type: " + message.getType() +
          "\t RT: " + std::to_string(message.getRt()) + "\t SA: " + std::to_string(message.getSa()) +
          (message.isCmdWord2()
               ? "\t RT2: " + std::to_string(message.getRtRx()) + "\t SA2: " + std::to_string(message.getSaRx())
               : "") +
          "\t WC: " + std::to_string(message.wc()) + (message.isResponded() ? "" : "\t (No Response)");

      messageString += "\nData: ";

      std::vector<std::string> data = message.getData();

      for (auto &d : data) {
        messageString += d + " ";
      }

      m_logger.log(LOG_INFO, "Bus Activity: \n " + messageString);

      m_updateSaState(message.getBus(), message.getRt(), message.getSa(), message.isResponded());

      if (m_filter and
          not(m_filteredBus == message.getBus() and (m_filteredRt == message.getRt() or m_filteredRt == -1) and
              (m_filteredSa == message.getSa() or m_filteredSa == -1))) {
        continue;
      }

      m_updateMessages(messageString + "\n\n");
    }
  }
}
