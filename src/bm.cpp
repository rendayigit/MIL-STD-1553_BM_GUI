#include "bm.hpp"
#include "mt.h"
#include <iostream>

BM::BM() : m_devNum(0x0000) {}

BM::~BM() { aceFree(m_devNum); }

int BM::startBm(S16BIT devNum) {
  S16BIT Err;

  m_devNum = devNum;

  Err = aceInitialize(m_devNum, ACE_ACCESS_CARD, ACE_MODE_MT, 0, 0, 0);

  if (Err) {
    return Err;
  }

  return 0;
}

int BM::stopBm() {
  S16BIT Err;

  Err = aceMTStop(m_devNum);

  if (Err) {
    return Err;
  }

  return 0;
}