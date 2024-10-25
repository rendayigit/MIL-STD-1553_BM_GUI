#include "app-window.h"
#include "bm.hpp"
#include "common.hpp"
#include <string>

int main(int argc, char **argv) {
  int errorCode = 0;

  auto ui = AppWindow::create();

  BM bm;

  bm.setUpdateFilter([&](const std::string &text) {
    slint::invoke_from_event_loop(
        [&] { ui->invoke_setFilterText(text.c_str()); });
  });

  bm.setUpdateMessages([&](const std::string &text) {
    std::cout << text;
    slint::invoke_from_event_loop(
        [&] { ui->invoke_setMessages(std::move(text).c_str()); });
  });

  ui->on_connectPressed([&] {
    U8BIT deviceNum = static_cast<unsigned short>(
        strtoul(ui->global<guiGlobals>().get_device().data(), nullptr, 16));

    errorCode = bm.startBm(deviceNum);
    if (errorCode == 0) {
      ui->invoke_setConnectStatus(true);
    } else {
      ui->invoke_setConnectStatus(false);
      ui->invoke_setError(getStatus(errorCode).c_str());
    }
  });

  ui->on_saSelected([&](slint::SharedString rt, slint::SharedString sa) {
    std::cout << "Selected: " << rt.data() << ": " << sa.data() << std::endl;
  });

  ui->run();

  return 0;
}
