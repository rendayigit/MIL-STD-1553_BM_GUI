#pragma once

#include <mutex>
#include <wx/treectrl.h>
#include <wx/wx.h>

class BusMonitorFrame : public wxFrame {
public:
  BusMonitorFrame();

private:
  void onStartStopClicked(wxCommandEvent &event);
  void onClearFilterClicked(wxCommandEvent &event);
  void onClearClicked(wxCommandEvent &event);
  void onTreeItemClicked(wxTreeEvent &event);
  void onExit(wxCommandEvent &event);

  int m_uiRecentMessageCount;
  std::mutex m_mutex;
  wxTextCtrl *m_deviceIdTextInput;
  wxTreeCtrl *m_milStd1553Tree;
  wxTextCtrl *m_messageList;
  wxButton *m_startStopButton;
  wxButton *m_filterButton;
};
