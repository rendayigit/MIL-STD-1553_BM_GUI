#ifndef BM_HPP
#define BM_HPP

#include "stdemace.h"
#include <array>
#include <string>

class BM {
public:
  BM();
  ~BM();

  int startBm(S16BIT devNum);
  int stopBm();

private:
  S16BIT m_devNum;
};

#endif // BM_HPP