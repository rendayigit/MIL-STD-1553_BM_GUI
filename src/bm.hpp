#ifndef BM_HPP
#define BM_HPP

#include "stdemace.h"
#include <array>
#include <functional>
#include <string>
#include <thread>

class BM {
public:
  BM();
  ~BM();

  int startBm(S16BIT devNum);
  int stopBm();

  void setUpdateFilter(const std::function<void(const std::string &)> &updateFilter_) {
    updateFilter = updateFilter_;
  }
  void
  setUpdateMessages(const std::function<void(const std::string &)> &updateMessages_) {
    updateMessages = updateMessages_;
  }

  void setLoop(bool loop) { m_loop = loop; }

private:
  static std::string getDecodedMsg(U32BIT nMsgNum, MSGSTRUCT *pMsg);
  void monitor();

  std::function<void(const std::string &)> updateFilter;
  std::function<void(const std::string &)> updateMessages;

  std::thread m_monitorThread;

  S16BIT m_devNum;
  bool m_loop = true;
};

#endif // BM_HPP