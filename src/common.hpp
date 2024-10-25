#ifndef COMMON_HPP
#define COMMON_HPP

#include "stdemace.h"
#include <string>

static std::string getStatus(S16BIT statusCode) {
  char buf[80];
  aceErrorStr(statusCode, buf, 80);
  return buf;
}

#endif // COMMON_HPP