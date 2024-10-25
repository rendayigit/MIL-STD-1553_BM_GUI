#ifndef BM_HPP
#define BM_HPP

#include "stdemace.h"
#include <array>
#include <functional>
#include <string>

class BM {
public:
  BM();
  ~BM();

  int startBm(S16BIT devNum);
  int stopBm();

  void setUpdateFilter(const std::function<void(std::string)> &updateFilter_) { updateFilter = updateFilter_; }
  void setUpdateMessages(const std::function<void(std::string)> &updateMessages_) { updateMessages = updateMessages_; }

private:
  void monitorThread();

  std::function<void(std::string)> updateFilter;
  std::function<void(std::string)> updateMessages;

  S16BIT m_devNum;
};

#endif // BM_HPP