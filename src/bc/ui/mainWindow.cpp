#include "mainWindow.hpp"

#include <nlohmann/json.hpp>
#include <string>

#include <wx/debug.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/gtk/button.h>
#include <wx/gtk/colour.h>
#include <wx/gtk/stattext.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/tglbtn.h>
#include <wx/wx.h>

#include "bcGuiCommon.hpp"
#include "createFrameWindow.hpp"
#include "wx/colour.h"

class CustomComponent : public wxPanel {
public:
  CustomComponent(wxWindow *parent, const std::string &label, char bus, int rt, int sa, int wc, BcMode mode,
                  std::array<std::string, RT_SA_MAX_COUNT> data)
      : wxPanel(parent, wxID_ANY) {
    std::string text = label + "\n\nBus: " + bus + "\tRT: " + std::to_string(rt) + "\tSA: " + std::to_string(sa) +
                       "\tWC: " + std::to_string(wc) + "\tMode: ";

    if (mode == BcMode::BC_TO_RT) {
      text += "BC->RT";
    } else if (mode == BcMode::RT_TO_BC) {
      text += "RT->BC";
    } else if (mode == BcMode::RT_TO_RT) {
      text += "RT->RT";
    }

    text += "\nData: ";

    for (int i = 0; i < data.size(); ++i) {
      if (i % 8 == 0) {
        text += "\n\t " + data.at(i);
      } else {
        text += "   " + data.at(i);
      }
    }

    auto *mainSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *orderSizer = new wxBoxSizer(wxVERTICAL);
    auto *repeatSendSizer = new wxBoxSizer(wxVERTICAL);

    wxBitmap upImg(getExecutableDirectory() + "../src/bc/icons/up_arrow.png", wxBITMAP_TYPE_PNG);
    wxBitmap downImg(getExecutableDirectory() + "../src/bc/icons/down_arrow.png", wxBITMAP_TYPE_PNG);
    wxBitmap removeImg(getExecutableDirectory() + "../src/bc/icons/remove.png", wxBITMAP_TYPE_PNG);

    auto *upButton = new wxBitmapButton(this, wxID_ANY, upImg, wxDefaultPosition, wxSize(30, 30), wxNO_BORDER);
    auto *downButton = new wxBitmapButton(this, wxID_ANY, downImg, wxDefaultPosition, wxSize(30, 30), wxNO_BORDER);
    auto *removeButton = new wxBitmapButton(this, wxID_ANY, removeImg, wxDefaultPosition, wxSize(30, 30), wxNO_BORDER);

    upButton->SetBackgroundColour(wxTransparentColour);
    removeButton->SetBackgroundColour(wxTransparentColour);
    downButton->SetBackgroundColour(wxTransparentColour);

    auto *nameLabel = new wxStaticText(this, wxID_ANY, text);

    auto *activeToggle =
        new wxToggleButton(this, wxID_ANY, "Frame Active", wxDefaultPosition, wxSize(120, TOP_BAR_COMP_HEIGHT));
    auto *editFrameButton =
        new wxButton(this, wxID_ANY, "Edit Frame", wxDefaultPosition, wxSize(120, TOP_BAR_COMP_HEIGHT));
    auto *sendButton = new wxButton(this, wxID_ANY, "Send Single", wxDefaultPosition, wxSize(120, TOP_BAR_COMP_HEIGHT));

    orderSizer->Add(upButton, 0, wxALIGN_LEFT | wxALL, 0);
    orderSizer->Add(removeButton, 0, wxALIGN_LEFT | wxALL, 0);
    orderSizer->Add(downButton, 0, wxALIGN_LEFT | wxALL, 0);

    repeatSendSizer->Add(activeToggle, 0, wxALIGN_LEFT | wxALL, 5);
    repeatSendSizer->Add(editFrameButton, 0, wxALIGN_LEFT | wxALL, 5);
    repeatSendSizer->Add(sendButton, 0, wxALIGN_LEFT | wxALL, 5);

    mainSizer->AddSpacer(15);
    mainSizer->Add(orderSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL, 0);
    mainSizer->AddSpacer(30);
    mainSizer->Add(nameLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    mainSizer->Add(repeatSendSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    SetBackgroundColour(this->GetBackgroundColour());
    SetSizer(mainSizer);
  }
};

BusControllerFrame::BusControllerFrame() : wxFrame(nullptr, wxID_ANY, "MIL-STD-1553 Bus Controller") {
  auto *menuFile = new wxMenu;
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  auto *menuBar = new wxMenuBar;
  SetMenuBar(menuBar);
  menuBar->Append(menuFile, "&Commands");

  auto *deviceIdText = new wxStaticText(this, wxID_ANY, "DDC Device ID");

  m_deviceIdTextInput = new wxTextCtrl(
      this, ID_DEVICE_ID_TXT, "00", wxDefaultPosition,
      wxSize(30, TOP_BAR_COMP_HEIGHT)); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

  auto *repeatToggle = new wxToggleButton(this, wxID_ANY, "Repeated Send");

  auto *sendActiveFramesButton = new wxButton(
      this, ID_SEND_ACTIVE_BTN, "Send Active Frames", wxDefaultPosition,
      wxSize(150, TOP_BAR_COMP_HEIGHT)); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

  m_addButton = new wxButton(
      this, ID_ADD_BTN, "Add Frame", wxDefaultPosition,
      wxSize(100, TOP_BAR_COMP_HEIGHT)); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

  m_addButton->SetBackgroundColour(wxColour("#ffcc00"));
  m_addButton->SetForegroundColour(
      wxColour(wxSystemSettingsNative::GetAppearance().IsDark() ? "black" : "wxSYS_COLOUR_WINDOWTEXT"));

  auto *verticalSizer = new wxBoxSizer(wxVERTICAL);
  auto *topHorizontalSizer = new wxBoxSizer(wxHORIZONTAL);

  // Replace bottomHorizontalSizer with scrolled window
  m_scrolledWindow = new wxScrolledWindow(this, wxID_ANY);
  m_scrolledWindow->SetBackgroundColour(this->GetBackgroundColour());
  m_scrolledSizer = new wxBoxSizer(wxVERTICAL);
  m_scrolledWindow->SetSizer(m_scrolledSizer);
  m_scrolledWindow->SetScrollRate(10, 10); // Set scroll speed

  topHorizontalSizer->Add(deviceIdText, 0, wxALIGN_CENTER_VERTICAL, // NOLINT(bugprone-suspicious-enum-usage)
                          5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  topHorizontalSizer->Add(m_deviceIdTextInput, 0, wxEXPAND | wxALL, // NOLINT(bugprone-suspicious-enum-usage)
                          5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  topHorizontalSizer->AddStretchSpacer();
  topHorizontalSizer->Add(repeatToggle, 0, wxALIGN_CENTER_VERTICAL, // NOLINT(bugprone-suspicious-enum-usage)
                          5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  topHorizontalSizer->AddSpacer(5);
  topHorizontalSizer->Add(sendActiveFramesButton, 0, wxALIGN_CENTER_VERTICAL, // NOLINT(bugprone-suspicious-enum-usage)
                          5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  topHorizontalSizer->AddSpacer(5);
  topHorizontalSizer->Add(m_addButton, 0, wxALIGN_CENTER_VERTICAL, // NOLINT(bugprone-suspicious-enum-usage)
                          5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

  verticalSizer->Add(topHorizontalSizer, 0, wxEXPAND | wxALL, // NOLINT(bugprone-suspicious-enum-usage)
                     5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  verticalSizer->Add(m_scrolledWindow, 1, wxEXPAND | wxALL, // NOLINT(bugprone-suspicious-enum-usage)
                     5); // NOLINT(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

  SetSizer(verticalSizer);

  verticalSizer->Fit(this);
  verticalSizer->SetSizeHints(this);

  CreateStatusBar();
  SetStatusText("Ready, add frames to send");

  Bind(wxEVT_BUTTON, &BusControllerFrame::onAddClicked, this, ID_ADD_BTN);
  Bind(wxEVT_MENU, &BusControllerFrame::onAddClicked, this, ID_ADD_MENU);
  Bind(wxEVT_MENU, &BusControllerFrame::onExit, this, wxID_EXIT);

  m_deviceIdTextInput->SetValue(std::to_string(m_bc.getDevNum()));
  SetSize(650, 400);
}

void BusControllerFrame::onAddClicked(wxCommandEvent & /*event*/) {
  auto *frame = new FrameCreationFrame(this);
  frame->Show(true);
}

void BusControllerFrame::onExit(wxCommandEvent & /*event*/) { Close(true); }

void BusControllerFrame::addFrameToList(const std::string &label, char bus, int rt, int sa, int wc, BcMode mode,
                                        std::array<std::string, RT_SA_MAX_COUNT> data) {
  auto *component = new CustomComponent(m_scrolledWindow, label, bus, rt, sa, wc, mode, data);
  m_scrolledSizer->Add(component, 0, wxEXPAND | wxALL, 5);
  m_scrolledWindow->FitInside(); // Update scrollable area
}
