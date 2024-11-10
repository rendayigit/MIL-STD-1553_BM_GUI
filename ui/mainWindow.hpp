#pragma once

#include "bm.hpp"
#include <mutex>
#include <wx/treectrl.h>
#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
  MyFrame();

private:
  void onConnectClicked(wxCommandEvent &event);
  void onSaClicked(wxTreeEvent &event);
  void onExit(wxCommandEvent &event);

  BM bm;
  int m_uiRecentMessageCount;
  std::mutex m_mutex;
  wxTextCtrl *deviceIdTextInput;
  wxTreeCtrl *milStd1553Tree;
  wxTextCtrl *messageList;
};
