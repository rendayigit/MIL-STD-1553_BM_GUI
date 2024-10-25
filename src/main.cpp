#include "app-window.h"
#include "bm.hpp"
#include "common.hpp"
#include <string>

int main(int argc, char **argv) {
  int errorCode = 0;

  auto ui = AppWindow::create();

  ui->invoke_setFilterText("RT01:SA01");  // TODO: remove after testing
  ui->invoke_setMessages("Test message"); // TODO: remove after testing

  BM bm;

  // bm.setUpdateFilter([&](std::string text) {
  //   slint::invoke_from_event_loop(
  //       [&] { ui->invoke_setFilterText(text.data()); });
  // });

  // bm.setUpdateMessages([&](std::string text) {
  //   slint::invoke_from_event_loop([&] { ui->invoke_setMessages(text.data()); });
  // });

  bm.setUpdateFilter(
      [&](std::string text) { ui->invoke_setFilterText(text.data()); });
  bm.setUpdateMessages(
      [&](std::string text) { ui->invoke_setMessages(text.data()); });

  ui->on_connectPressed([&] {
    U8BIT deviceNum = static_cast<unsigned short>(
        strtoul(ui->global<guiGlobals>().get_device().data(), nullptr, 16));

    aceFree(deviceNum);
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

  bm.start();
  ui->run();


  return 0;
}
