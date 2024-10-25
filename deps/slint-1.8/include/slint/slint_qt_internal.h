#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
#include "slint_internal.h"

            namespace slint::cbindgen_private {
                // HACK ALERT: This struct declaration is duplicated in internal/backend/qt/qt_widgets.rs - keep in sync.
                struct SlintTypeErasedWidget
                {
                    virtual ~SlintTypeErasedWidget() = 0;
                    SlintTypeErasedWidget(const SlintTypeErasedWidget&) = delete;
                    SlintTypeErasedWidget& operator=(const SlintTypeErasedWidget&) = delete;

                    virtual void *qwidget() const = 0;
                };
                using SlintTypeErasedWidgetPtr = std::unique_ptr<SlintTypeErasedWidget>;
            }
            

namespace slint {
namespace cbindgen_private {

struct NativeStyleMetrics {
    Property<LogicalLength> layout_spacing;
    Property<LogicalLength> layout_padding;
    Property<LogicalLength> text_cursor_width;
    Property<Color> window_background;
    Property<Color> default_text_color;
    Property<LogicalLength> default_font_size;
    Property<Color> textedit_background;
    Property<Color> textedit_text_color;
    Property<Color> textedit_background_disabled;
    Property<Color> textedit_text_color_disabled;
    Property<Color> placeholder_color;
    Property<Color> placeholder_color_disabled;
    Property<bool> dark_color_scheme;
    Property<LayoutAlignment> tab_bar_alignment;
    const uint8_t *style_change_listener;
    inline explicit NativeStyleMetrics(void* = nullptr); inline ~NativeStyleMetrics();
};

struct NativePalette {
    Property<Brush> background;
    Property<Brush> foreground;
    Property<Brush> alternate_background;
    Property<Brush> alternate_foreground;
    Property<Brush> accent_background;
    Property<Brush> accent_foreground;
    Property<Brush> control_background;
    Property<Brush> control_foreground;
    Property<Brush> selection_background;
    Property<Brush> selection_foreground;
    Property<Brush> border;
    Property<ColorScheme> color_scheme;
    const uint8_t *style_change_listener;
    inline explicit NativePalette(void* = nullptr); inline ~NativePalette();
};

using QStyle_StandardPixmap = unsigned int;

using QAccessible_Event = unsigned int;

using QAccessible_Role = unsigned int;

using QAccessible_Text = unsigned int;

using Qt_KeyboardModifier = unsigned int;

using Qt_AlignmentFlag = unsigned int;

using Qt_TextFlag = unsigned int;

using Qt_Key = unsigned int;

using Qt_CursorShape = unsigned int;

using Qt_FillRule = unsigned int;

struct NativeButton {
    Property<SharedString> text;
    Property<Image> icon;
    Property<bool> pressed;
    Property<bool> has_hover;
    Property<bool> checkable;
    Property<bool> checked;
    Property<bool> primary;
    Property<bool> has_focus;
    private_api::CallbackHelper<void> clicked;
    Property<bool> enabled;
    Property<bool> colorize_icon;
    Property<StandardButtonKind> standard_button_kind;
    Property<bool> is_standard_button;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
    CachedRenderingData cached_rendering_data;
};

struct NativeSpinBoxData {
    uint32_t active_controls;
    bool pressed;
};

struct NativeSpinBox {
    Property<bool> enabled;
    Property<bool> has_focus;
    Property<int32_t> value;
    Property<int32_t> minimum;
    Property<int32_t> maximum;
    Property<int32_t> step_size;
    CachedRenderingData cached_rendering_data;
    private_api::CallbackHelper<int> edited;
    Property<NativeSpinBoxData> data;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeCheckBox {
    Property<bool> enabled;
    Property<bool> has_focus;
    private_api::CallbackHelper<void> toggled;
    Property<SharedString> text;
    Property<bool> has_hover;
    Property<bool> checked;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
    CachedRenderingData cached_rendering_data;
};

struct NativeSliderData {
    uint32_t active_controls;
    /// For sliders, this is a bool, For scroll area: 1 == horizontal, 2 == vertical
    uint8_t pressed;
    float pressed_x;
    float pressed_val;
};

struct NativeSlider {
    Property<Orientation> orientation;
    Property<bool> enabled;
    Property<bool> has_focus;
    Property<float> value;
    Property<float> minimum;
    Property<float> maximum;
    CachedRenderingData cached_rendering_data;
    Property<NativeSliderData> data;
    private_api::CallbackHelper<float> changed;
    private_api::CallbackHelper<float> released;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeProgressIndicator {
    Property<bool> indeterminate;
    Property<float> progress;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
    CachedRenderingData cached_rendering_data;
};

struct NativeGroupBox {
    Property<bool> enabled;
    Property<SharedString> title;
    CachedRenderingData cached_rendering_data;
    Property<LogicalLength> native_padding_left;
    Property<LogicalLength> native_padding_right;
    Property<LogicalLength> native_padding_top;
    Property<LogicalLength> native_padding_bottom;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeLineEdit {
    CachedRenderingData cached_rendering_data;
    Property<LogicalLength> native_padding_left;
    Property<LogicalLength> native_padding_right;
    Property<LogicalLength> native_padding_top;
    Property<LogicalLength> native_padding_bottom;
    Property<bool> has_focus;
    Property<bool> enabled;
    Property<InputType> input_type;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeScrollView {
    Property<LogicalLength> horizontal_max;
    Property<LogicalLength> horizontal_page_size;
    Property<LogicalLength> horizontal_value;
    Property<LogicalLength> vertical_max;
    Property<LogicalLength> vertical_page_size;
    Property<LogicalLength> vertical_value;
    CachedRenderingData cached_rendering_data;
    Property<LogicalLength> native_padding_left;
    Property<LogicalLength> native_padding_right;
    Property<LogicalLength> native_padding_top;
    Property<LogicalLength> native_padding_bottom;
    Property<bool> enabled;
    Property<bool> has_focus;
    Property<NativeSliderData> data;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeStandardListViewItem {
    Property<StandardListViewItem> item;
    Property<int32_t> index;
    Property<bool> is_selected;
    CachedRenderingData cached_rendering_data;
    Property<bool> has_hover;
    Property<bool> has_focus;
    Property<bool> pressed;
    Property<LogicalLength> pressed_x;
    Property<LogicalLength> pressed_y;
    /// Specify that this item is in fact used in a ComboBox
    Property<bool> combobox;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeTableHeaderSection {
    Property<TableColumn> item;
    Property<int32_t> index;
    CachedRenderingData cached_rendering_data;
    Property<bool> has_hover;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeComboBox {
    Property<bool> enabled;
    Property<bool> has_focus;
    Property<bool> pressed;
    Property<bool> has_hover;
    Property<bool> is_open;
    Property<SharedString> current_value;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
    CachedRenderingData cached_rendering_data;
};

struct NativeComboBoxPopup {
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
    CachedRenderingData cached_rendering_data;
};

struct NativeTabWidget {
    Property<LogicalLength> width;
    Property<LogicalLength> height;
    CachedRenderingData cached_rendering_data;
    Property<LogicalLength> content_min_height;
    Property<LogicalLength> content_min_width;
    Property<LogicalLength> tabbar_preferred_height;
    Property<LogicalLength> tabbar_preferred_width;
    Property<int32_t> current_index;
    Property<int32_t> current_focused;
    Property<LogicalLength> content_x;
    Property<LogicalLength> content_y;
    Property<LogicalLength> content_height;
    Property<LogicalLength> content_width;
    Property<LogicalLength> tabbar_x;
    Property<LogicalLength> tabbar_y;
    Property<LogicalLength> tabbar_height;
    Property<LogicalLength> tabbar_width;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
};

struct NativeTab {
    Property<SharedString> title;
    Property<Image> icon;
    Property<bool> enabled;
    Property<bool> pressed;
    Property<int32_t> current;
    Property<int32_t> current_focused;
    Property<int32_t> tab_index;
    Property<int32_t> num_tabs;
    SlintTypeErasedWidgetPtr widget_ptr;
    Property<int32_t> animation_tracker;
    CachedRenderingData cached_rendering_data;
};

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarMenuButton = 0;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarMinButton = 1;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarMaxButton = 2;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarCloseButton = 3;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarNormalButton = 4;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarShadeButton = 5;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarUnshadeButton = 6;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TitleBarContextHelpButton = 7;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DockWidgetCloseButton = 8;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MessageBoxInformation = 9;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MessageBoxWarning = 10;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MessageBoxCritical = 11;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MessageBoxQuestion = 12;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DesktopIcon = 13;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_TrashIcon = 14;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ComputerIcon = 15;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DriveFDIcon = 16;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DriveHDIcon = 17;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DriveCDIcon = 18;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DriveDVDIcon = 19;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DriveNetIcon = 20;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DirOpenIcon = 21;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DirClosedIcon = 22;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DirLinkIcon = 23;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DirLinkOpenIcon = 24;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileIcon = 25;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileLinkIcon = 26;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ToolBarHorizontalExtensionButton = 27;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ToolBarVerticalExtensionButton = 28;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogStart = 29;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogEnd = 30;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogToParent = 31;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogNewFolder = 32;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogDetailedView = 33;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogInfoView = 34;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogContentsView = 35;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogListView = 36;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_FileDialogBack = 37;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DirIcon = 38;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogOkButton = 39;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogCancelButton = 40;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogHelpButton = 41;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogOpenButton = 42;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogSaveButton = 43;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogCloseButton = 44;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogApplyButton = 45;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogResetButton = 46;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogDiscardButton = 47;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogYesButton = 48;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogNoButton = 49;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ArrowUp = 50;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ArrowDown = 51;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ArrowLeft = 52;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ArrowRight = 53;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ArrowBack = 54;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_ArrowForward = 55;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DirHomeIcon = 56;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_CommandLink = 57;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_VistaShield = 58;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_BrowserReload = 59;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_BrowserStop = 60;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaPlay = 61;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaStop = 62;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaPause = 63;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaSkipForward = 64;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaSkipBackward = 65;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaSeekForward = 66;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaSeekBackward = 67;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaVolume = 68;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_MediaVolumeMuted = 69;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_LineEditClearButton = 70;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogYesToAllButton = 71;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogNoToAllButton = 72;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogSaveAllButton = 73;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogAbortButton = 74;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogRetryButton = 75;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_DialogIgnoreButton = 76;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_RestoreDefaultsButton = 77;

constexpr static const QStyle_StandardPixmap QStyle_StandardPixmap_SP_CustomBase = 4026531840;

constexpr static const QAccessible_Event QAccessible_Event_SoundPlayed = 1;

constexpr static const QAccessible_Event QAccessible_Event_Alert = 2;

constexpr static const QAccessible_Event QAccessible_Event_ForegroundChanged = 3;

constexpr static const QAccessible_Event QAccessible_Event_MenuStart = 4;

constexpr static const QAccessible_Event QAccessible_Event_MenuEnd = 5;

constexpr static const QAccessible_Event QAccessible_Event_PopupMenuStart = 6;

constexpr static const QAccessible_Event QAccessible_Event_PopupMenuEnd = 7;

constexpr static const QAccessible_Event QAccessible_Event_ContextHelpStart = 12;

constexpr static const QAccessible_Event QAccessible_Event_ContextHelpEnd = 13;

constexpr static const QAccessible_Event QAccessible_Event_DragDropStart = 14;

constexpr static const QAccessible_Event QAccessible_Event_DragDropEnd = 15;

constexpr static const QAccessible_Event QAccessible_Event_DialogStart = 16;

constexpr static const QAccessible_Event QAccessible_Event_DialogEnd = 17;

constexpr static const QAccessible_Event QAccessible_Event_ScrollingStart = 18;

constexpr static const QAccessible_Event QAccessible_Event_ScrollingEnd = 19;

constexpr static const QAccessible_Event QAccessible_Event_MenuCommand = 24;

constexpr static const QAccessible_Event QAccessible_Event_ActionChanged = 257;

constexpr static const QAccessible_Event QAccessible_Event_ActiveDescendantChanged = 258;

constexpr static const QAccessible_Event QAccessible_Event_AttributeChanged = 259;

constexpr static const QAccessible_Event QAccessible_Event_DocumentContentChanged = 260;

constexpr static const QAccessible_Event QAccessible_Event_DocumentLoadComplete = 261;

constexpr static const QAccessible_Event QAccessible_Event_DocumentLoadStopped = 262;

constexpr static const QAccessible_Event QAccessible_Event_DocumentReload = 263;

constexpr static const QAccessible_Event QAccessible_Event_HyperlinkEndIndexChanged = 264;

constexpr static const QAccessible_Event QAccessible_Event_HyperlinkNumberOfAnchorsChanged = 265;

constexpr static const QAccessible_Event QAccessible_Event_HyperlinkSelectedLinkChanged = 266;

constexpr static const QAccessible_Event QAccessible_Event_HypertextLinkActivated = 267;

constexpr static const QAccessible_Event QAccessible_Event_HypertextLinkSelected = 268;

constexpr static const QAccessible_Event QAccessible_Event_HyperlinkStartIndexChanged = 269;

constexpr static const QAccessible_Event QAccessible_Event_HypertextChanged = 270;

constexpr static const QAccessible_Event QAccessible_Event_HypertextNLinksChanged = 271;

constexpr static const QAccessible_Event QAccessible_Event_ObjectAttributeChanged = 272;

constexpr static const QAccessible_Event QAccessible_Event_PageChanged = 273;

constexpr static const QAccessible_Event QAccessible_Event_SectionChanged = 274;

constexpr static const QAccessible_Event QAccessible_Event_TableCaptionChanged = 275;

constexpr static const QAccessible_Event QAccessible_Event_TableColumnDescriptionChanged = 276;

constexpr static const QAccessible_Event QAccessible_Event_TableColumnHeaderChanged = 277;

constexpr static const QAccessible_Event QAccessible_Event_TableModelChanged = 278;

constexpr static const QAccessible_Event QAccessible_Event_TableRowDescriptionChanged = 279;

constexpr static const QAccessible_Event QAccessible_Event_TableRowHeaderChanged = 280;

constexpr static const QAccessible_Event QAccessible_Event_TableSummaryChanged = 281;

constexpr static const QAccessible_Event QAccessible_Event_TextAttributeChanged = 282;

constexpr static const QAccessible_Event QAccessible_Event_TextCaretMoved = 283;

constexpr static const QAccessible_Event QAccessible_Event_TextColumnChanged = 285;

constexpr static const QAccessible_Event QAccessible_Event_TextInserted = 286;

constexpr static const QAccessible_Event QAccessible_Event_TextRemoved = 287;

constexpr static const QAccessible_Event QAccessible_Event_TextUpdated = 288;

constexpr static const QAccessible_Event QAccessible_Event_TextSelectionChanged = 289;

constexpr static const QAccessible_Event QAccessible_Event_VisibleDataChanged = 290;

constexpr static const QAccessible_Event QAccessible_Event_ObjectCreated = 32768;

constexpr static const QAccessible_Event QAccessible_Event_ObjectDestroyed = 32769;

constexpr static const QAccessible_Event QAccessible_Event_ObjectShow = 32770;

constexpr static const QAccessible_Event QAccessible_Event_ObjectHide = 32771;

constexpr static const QAccessible_Event QAccessible_Event_ObjectReorder = 32772;

constexpr static const QAccessible_Event QAccessible_Event_Focus = 32773;

constexpr static const QAccessible_Event QAccessible_Event_Selection = 32774;

constexpr static const QAccessible_Event QAccessible_Event_SelectionAdd = 32775;

constexpr static const QAccessible_Event QAccessible_Event_SelectionRemove = 32776;

constexpr static const QAccessible_Event QAccessible_Event_SelectionWithin = 32777;

constexpr static const QAccessible_Event QAccessible_Event_StateChanged = 32778;

constexpr static const QAccessible_Event QAccessible_Event_LocationChanged = 32779;

constexpr static const QAccessible_Event QAccessible_Event_NameChanged = 32780;

constexpr static const QAccessible_Event QAccessible_Event_DescriptionChanged = 32781;

constexpr static const QAccessible_Event QAccessible_Event_ValueChanged = 32782;

constexpr static const QAccessible_Event QAccessible_Event_ParentChanged = 32783;

constexpr static const QAccessible_Event QAccessible_Event_HelpChanged = 32928;

constexpr static const QAccessible_Event QAccessible_Event_DefaultActionChanged = 32944;

constexpr static const QAccessible_Event QAccessible_Event_AcceleratorChanged = 32960;

constexpr static const QAccessible_Event QAccessible_Event_InvalidEvent = 32961;

constexpr static const QAccessible_Role QAccessible_Role_NoRole = 0;

constexpr static const QAccessible_Role QAccessible_Role_TitleBar = 1;

constexpr static const QAccessible_Role QAccessible_Role_MenuBar = 2;

constexpr static const QAccessible_Role QAccessible_Role_ScrollBar = 3;

constexpr static const QAccessible_Role QAccessible_Role_Grip = 4;

constexpr static const QAccessible_Role QAccessible_Role_Sound = 5;

constexpr static const QAccessible_Role QAccessible_Role_Cursor = 6;

constexpr static const QAccessible_Role QAccessible_Role_Caret = 7;

constexpr static const QAccessible_Role QAccessible_Role_AlertMessage = 8;

constexpr static const QAccessible_Role QAccessible_Role_Window = 9;

constexpr static const QAccessible_Role QAccessible_Role_Client = 10;

constexpr static const QAccessible_Role QAccessible_Role_PopupMenu = 11;

constexpr static const QAccessible_Role QAccessible_Role_MenuItem = 12;

constexpr static const QAccessible_Role QAccessible_Role_ToolTip = 13;

constexpr static const QAccessible_Role QAccessible_Role_Application = 14;

constexpr static const QAccessible_Role QAccessible_Role_Document = 15;

constexpr static const QAccessible_Role QAccessible_Role_Pane = 16;

constexpr static const QAccessible_Role QAccessible_Role_Chart = 17;

constexpr static const QAccessible_Role QAccessible_Role_Dialog = 18;

constexpr static const QAccessible_Role QAccessible_Role_Border = 19;

constexpr static const QAccessible_Role QAccessible_Role_Grouping = 20;

constexpr static const QAccessible_Role QAccessible_Role_Separator = 21;

constexpr static const QAccessible_Role QAccessible_Role_ToolBar = 22;

constexpr static const QAccessible_Role QAccessible_Role_StatusBar = 23;

constexpr static const QAccessible_Role QAccessible_Role_Table = 24;

constexpr static const QAccessible_Role QAccessible_Role_ColumnHeader = 25;

constexpr static const QAccessible_Role QAccessible_Role_RowHeader = 26;

constexpr static const QAccessible_Role QAccessible_Role_Column = 27;

constexpr static const QAccessible_Role QAccessible_Role_Row = 28;

constexpr static const QAccessible_Role QAccessible_Role_Cell = 29;

constexpr static const QAccessible_Role QAccessible_Role_Link = 30;

constexpr static const QAccessible_Role QAccessible_Role_HelpBalloon = 31;

constexpr static const QAccessible_Role QAccessible_Role_Assistant = 32;

constexpr static const QAccessible_Role QAccessible_Role_List = 33;

constexpr static const QAccessible_Role QAccessible_Role_ListItem = 34;

constexpr static const QAccessible_Role QAccessible_Role_Tree = 35;

constexpr static const QAccessible_Role QAccessible_Role_TreeItem = 36;

constexpr static const QAccessible_Role QAccessible_Role_PageTab = 37;

constexpr static const QAccessible_Role QAccessible_Role_PropertyPage = 38;

constexpr static const QAccessible_Role QAccessible_Role_Indicator = 39;

constexpr static const QAccessible_Role QAccessible_Role_Graphic = 40;

constexpr static const QAccessible_Role QAccessible_Role_StaticText = 41;

constexpr static const QAccessible_Role QAccessible_Role_EditableText = 42;

constexpr static const QAccessible_Role QAccessible_Role_Button = 43;

constexpr static const QAccessible_Role QAccessible_Role_PushButton = 43;

constexpr static const QAccessible_Role QAccessible_Role_CheckBox = 44;

constexpr static const QAccessible_Role QAccessible_Role_RadioButton = 45;

constexpr static const QAccessible_Role QAccessible_Role_ComboBox = 46;

constexpr static const QAccessible_Role QAccessible_Role_ProgressBar = 48;

constexpr static const QAccessible_Role QAccessible_Role_Dial = 49;

constexpr static const QAccessible_Role QAccessible_Role_HotkeyField = 50;

constexpr static const QAccessible_Role QAccessible_Role_Slider = 51;

constexpr static const QAccessible_Role QAccessible_Role_SpinBox = 52;

constexpr static const QAccessible_Role QAccessible_Role_Canvas = 53;

constexpr static const QAccessible_Role QAccessible_Role_Animation = 54;

constexpr static const QAccessible_Role QAccessible_Role_Equation = 55;

constexpr static const QAccessible_Role QAccessible_Role_ButtonDropDown = 56;

constexpr static const QAccessible_Role QAccessible_Role_ButtonMenu = 57;

constexpr static const QAccessible_Role QAccessible_Role_ButtonDropGrid = 58;

constexpr static const QAccessible_Role QAccessible_Role_Whitespace = 59;

constexpr static const QAccessible_Role QAccessible_Role_PageTabList = 60;

constexpr static const QAccessible_Role QAccessible_Role_Clock = 61;

constexpr static const QAccessible_Role QAccessible_Role_Splitter = 62;

constexpr static const QAccessible_Role QAccessible_Role_LayeredPane = 128;

constexpr static const QAccessible_Role QAccessible_Role_Terminal = 129;

constexpr static const QAccessible_Role QAccessible_Role_Desktop = 130;

constexpr static const QAccessible_Role QAccessible_Role_Paragraph = 131;

constexpr static const QAccessible_Role QAccessible_Role_WebDocument = 132;

constexpr static const QAccessible_Role QAccessible_Role_Section = 133;

constexpr static const QAccessible_Role QAccessible_Role_Notification = 134;

constexpr static const QAccessible_Role QAccessible_Role_ColorChooser = 1028;

constexpr static const QAccessible_Role QAccessible_Role_Footer = 1038;

constexpr static const QAccessible_Role QAccessible_Role_Form = 1040;

constexpr static const QAccessible_Role QAccessible_Role_Heading = 1044;

constexpr static const QAccessible_Role QAccessible_Role_Note = 1051;

constexpr static const QAccessible_Role QAccessible_Role_ComplementaryContent = 1068;

constexpr static const QAccessible_Role QAccessible_Role_UserRole = 65535;

constexpr static const QAccessible_Text QAccessible_Text_Name = 0;

constexpr static const QAccessible_Text QAccessible_Text_Description = 1;

constexpr static const QAccessible_Text QAccessible_Text_Value = 2;

constexpr static const QAccessible_Text QAccessible_Text_Help = 3;

constexpr static const QAccessible_Text QAccessible_Text_Accelerator = 4;

constexpr static const QAccessible_Text QAccessible_Text_DebugDescription = 5;

constexpr static const QAccessible_Text QAccessible_Text_UserText = 65535;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_NoModifier = 0;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_ShiftModifier = 33554432;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_ControlModifier = 67108864;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_AltModifier = 134217728;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_MetaModifier = 268435456;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_KeypadModifier = 536870912;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_GroupSwitchModifier = 1073741824;

constexpr static const Qt_KeyboardModifier Qt_KeyboardModifier_KeyboardModifierMask = 4261412864;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignLeft = 1;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignLeading = 1;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignRight = 2;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignTrailing = 2;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignHCenter = 4;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignJustify = 8;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignAbsolute = 16;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignHorizontal_Mask = 31;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignTop = 32;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignBottom = 64;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignVCenter = 128;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignBaseline = 256;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignVertical_Mask = 480;

constexpr static const Qt_AlignmentFlag Qt_AlignmentFlag_AlignCenter = 132;

constexpr static const Qt_TextFlag Qt_TextFlag_TextSingleLine = 256;

constexpr static const Qt_TextFlag Qt_TextFlag_TextDontClip = 512;

constexpr static const Qt_TextFlag Qt_TextFlag_TextExpandTabs = 1024;

constexpr static const Qt_TextFlag Qt_TextFlag_TextShowMnemonic = 2048;

constexpr static const Qt_TextFlag Qt_TextFlag_TextWordWrap = 4096;

constexpr static const Qt_TextFlag Qt_TextFlag_TextWrapAnywhere = 8192;

constexpr static const Qt_TextFlag Qt_TextFlag_TextDontPrint = 16384;

constexpr static const Qt_TextFlag Qt_TextFlag_TextIncludeTrailingSpaces = 134217728;

constexpr static const Qt_TextFlag Qt_TextFlag_TextHideMnemonic = 32768;

constexpr static const Qt_TextFlag Qt_TextFlag_TextJustificationForced = 65536;

constexpr static const Qt_TextFlag Qt_TextFlag_TextForceLeftToRight = 131072;

constexpr static const Qt_TextFlag Qt_TextFlag_TextForceRightToLeft = 262144;

constexpr static const Qt_TextFlag Qt_TextFlag_TextLongestVariant = 524288;

constexpr static const Qt_TextFlag Qt_TextFlag_TextBypassShaping = 1048576;

constexpr static const Qt_Key Qt_Key_Key_Escape = 16777216;

constexpr static const Qt_Key Qt_Key_Key_Tab = 16777217;

constexpr static const Qt_Key Qt_Key_Key_Backtab = 16777218;

constexpr static const Qt_Key Qt_Key_Key_Backspace = 16777219;

constexpr static const Qt_Key Qt_Key_Key_Return = 16777220;

constexpr static const Qt_Key Qt_Key_Key_Enter = 16777221;

constexpr static const Qt_Key Qt_Key_Key_Insert = 16777222;

constexpr static const Qt_Key Qt_Key_Key_Delete = 16777223;

constexpr static const Qt_Key Qt_Key_Key_Pause = 16777224;

constexpr static const Qt_Key Qt_Key_Key_Print = 16777225;

constexpr static const Qt_Key Qt_Key_Key_SysReq = 16777226;

constexpr static const Qt_Key Qt_Key_Key_Clear = 16777227;

constexpr static const Qt_Key Qt_Key_Key_Home = 16777232;

constexpr static const Qt_Key Qt_Key_Key_End = 16777233;

constexpr static const Qt_Key Qt_Key_Key_Left = 16777234;

constexpr static const Qt_Key Qt_Key_Key_Up = 16777235;

constexpr static const Qt_Key Qt_Key_Key_Right = 16777236;

constexpr static const Qt_Key Qt_Key_Key_Down = 16777237;

constexpr static const Qt_Key Qt_Key_Key_PageUp = 16777238;

constexpr static const Qt_Key Qt_Key_Key_PageDown = 16777239;

constexpr static const Qt_Key Qt_Key_Key_Shift = 16777248;

constexpr static const Qt_Key Qt_Key_Key_Control = 16777249;

constexpr static const Qt_Key Qt_Key_Key_Meta = 16777250;

constexpr static const Qt_Key Qt_Key_Key_Alt = 16777251;

constexpr static const Qt_Key Qt_Key_Key_CapsLock = 16777252;

constexpr static const Qt_Key Qt_Key_Key_NumLock = 16777253;

constexpr static const Qt_Key Qt_Key_Key_ScrollLock = 16777254;

constexpr static const Qt_Key Qt_Key_Key_F1 = 16777264;

constexpr static const Qt_Key Qt_Key_Key_F2 = 16777265;

constexpr static const Qt_Key Qt_Key_Key_F3 = 16777266;

constexpr static const Qt_Key Qt_Key_Key_F4 = 16777267;

constexpr static const Qt_Key Qt_Key_Key_F5 = 16777268;

constexpr static const Qt_Key Qt_Key_Key_F6 = 16777269;

constexpr static const Qt_Key Qt_Key_Key_F7 = 16777270;

constexpr static const Qt_Key Qt_Key_Key_F8 = 16777271;

constexpr static const Qt_Key Qt_Key_Key_F9 = 16777272;

constexpr static const Qt_Key Qt_Key_Key_F10 = 16777273;

constexpr static const Qt_Key Qt_Key_Key_F11 = 16777274;

constexpr static const Qt_Key Qt_Key_Key_F12 = 16777275;

constexpr static const Qt_Key Qt_Key_Key_F13 = 16777276;

constexpr static const Qt_Key Qt_Key_Key_F14 = 16777277;

constexpr static const Qt_Key Qt_Key_Key_F15 = 16777278;

constexpr static const Qt_Key Qt_Key_Key_F16 = 16777279;

constexpr static const Qt_Key Qt_Key_Key_F17 = 16777280;

constexpr static const Qt_Key Qt_Key_Key_F18 = 16777281;

constexpr static const Qt_Key Qt_Key_Key_F19 = 16777282;

constexpr static const Qt_Key Qt_Key_Key_F20 = 16777283;

constexpr static const Qt_Key Qt_Key_Key_F21 = 16777284;

constexpr static const Qt_Key Qt_Key_Key_F22 = 16777285;

constexpr static const Qt_Key Qt_Key_Key_F23 = 16777286;

constexpr static const Qt_Key Qt_Key_Key_F24 = 16777287;

constexpr static const Qt_Key Qt_Key_Key_F25 = 16777288;

constexpr static const Qt_Key Qt_Key_Key_F26 = 16777289;

constexpr static const Qt_Key Qt_Key_Key_F27 = 16777290;

constexpr static const Qt_Key Qt_Key_Key_F28 = 16777291;

constexpr static const Qt_Key Qt_Key_Key_F29 = 16777292;

constexpr static const Qt_Key Qt_Key_Key_F30 = 16777293;

constexpr static const Qt_Key Qt_Key_Key_F31 = 16777294;

constexpr static const Qt_Key Qt_Key_Key_F32 = 16777295;

constexpr static const Qt_Key Qt_Key_Key_F33 = 16777296;

constexpr static const Qt_Key Qt_Key_Key_F34 = 16777297;

constexpr static const Qt_Key Qt_Key_Key_F35 = 16777298;

constexpr static const Qt_Key Qt_Key_Key_Super_L = 16777299;

constexpr static const Qt_Key Qt_Key_Key_Super_R = 16777300;

constexpr static const Qt_Key Qt_Key_Key_Menu = 16777301;

constexpr static const Qt_Key Qt_Key_Key_Hyper_L = 16777302;

constexpr static const Qt_Key Qt_Key_Key_Hyper_R = 16777303;

constexpr static const Qt_Key Qt_Key_Key_Help = 16777304;

constexpr static const Qt_Key Qt_Key_Key_Direction_L = 16777305;

constexpr static const Qt_Key Qt_Key_Key_Direction_R = 16777312;

constexpr static const Qt_Key Qt_Key_Key_Space = 32;

constexpr static const Qt_Key Qt_Key_Key_Any = 32;

constexpr static const Qt_Key Qt_Key_Key_Exclam = 33;

constexpr static const Qt_Key Qt_Key_Key_QuoteDbl = 34;

constexpr static const Qt_Key Qt_Key_Key_NumberSign = 35;

constexpr static const Qt_Key Qt_Key_Key_Dollar = 36;

constexpr static const Qt_Key Qt_Key_Key_Percent = 37;

constexpr static const Qt_Key Qt_Key_Key_Ampersand = 38;

constexpr static const Qt_Key Qt_Key_Key_Apostrophe = 39;

constexpr static const Qt_Key Qt_Key_Key_ParenLeft = 40;

constexpr static const Qt_Key Qt_Key_Key_ParenRight = 41;

constexpr static const Qt_Key Qt_Key_Key_Asterisk = 42;

constexpr static const Qt_Key Qt_Key_Key_Plus = 43;

constexpr static const Qt_Key Qt_Key_Key_Comma = 44;

constexpr static const Qt_Key Qt_Key_Key_Minus = 45;

constexpr static const Qt_Key Qt_Key_Key_Period = 46;

constexpr static const Qt_Key Qt_Key_Key_Slash = 47;

constexpr static const Qt_Key Qt_Key_Key_0 = 48;

constexpr static const Qt_Key Qt_Key_Key_1 = 49;

constexpr static const Qt_Key Qt_Key_Key_2 = 50;

constexpr static const Qt_Key Qt_Key_Key_3 = 51;

constexpr static const Qt_Key Qt_Key_Key_4 = 52;

constexpr static const Qt_Key Qt_Key_Key_5 = 53;

constexpr static const Qt_Key Qt_Key_Key_6 = 54;

constexpr static const Qt_Key Qt_Key_Key_7 = 55;

constexpr static const Qt_Key Qt_Key_Key_8 = 56;

constexpr static const Qt_Key Qt_Key_Key_9 = 57;

constexpr static const Qt_Key Qt_Key_Key_Colon = 58;

constexpr static const Qt_Key Qt_Key_Key_Semicolon = 59;

constexpr static const Qt_Key Qt_Key_Key_Less = 60;

constexpr static const Qt_Key Qt_Key_Key_Equal = 61;

constexpr static const Qt_Key Qt_Key_Key_Greater = 62;

constexpr static const Qt_Key Qt_Key_Key_Question = 63;

constexpr static const Qt_Key Qt_Key_Key_At = 64;

constexpr static const Qt_Key Qt_Key_Key_A = 65;

constexpr static const Qt_Key Qt_Key_Key_B = 66;

constexpr static const Qt_Key Qt_Key_Key_C = 67;

constexpr static const Qt_Key Qt_Key_Key_D = 68;

constexpr static const Qt_Key Qt_Key_Key_E = 69;

constexpr static const Qt_Key Qt_Key_Key_F = 70;

constexpr static const Qt_Key Qt_Key_Key_G = 71;

constexpr static const Qt_Key Qt_Key_Key_H = 72;

constexpr static const Qt_Key Qt_Key_Key_I = 73;

constexpr static const Qt_Key Qt_Key_Key_J = 74;

constexpr static const Qt_Key Qt_Key_Key_K = 75;

constexpr static const Qt_Key Qt_Key_Key_L = 76;

constexpr static const Qt_Key Qt_Key_Key_M = 77;

constexpr static const Qt_Key Qt_Key_Key_N = 78;

constexpr static const Qt_Key Qt_Key_Key_O = 79;

constexpr static const Qt_Key Qt_Key_Key_P = 80;

constexpr static const Qt_Key Qt_Key_Key_Q = 81;

constexpr static const Qt_Key Qt_Key_Key_R = 82;

constexpr static const Qt_Key Qt_Key_Key_S = 83;

constexpr static const Qt_Key Qt_Key_Key_T = 84;

constexpr static const Qt_Key Qt_Key_Key_U = 85;

constexpr static const Qt_Key Qt_Key_Key_V = 86;

constexpr static const Qt_Key Qt_Key_Key_W = 87;

constexpr static const Qt_Key Qt_Key_Key_X = 88;

constexpr static const Qt_Key Qt_Key_Key_Y = 89;

constexpr static const Qt_Key Qt_Key_Key_Z = 90;

constexpr static const Qt_Key Qt_Key_Key_BracketLeft = 91;

constexpr static const Qt_Key Qt_Key_Key_Backslash = 92;

constexpr static const Qt_Key Qt_Key_Key_BracketRight = 93;

constexpr static const Qt_Key Qt_Key_Key_AsciiCircum = 94;

constexpr static const Qt_Key Qt_Key_Key_Underscore = 95;

constexpr static const Qt_Key Qt_Key_Key_QuoteLeft = 96;

constexpr static const Qt_Key Qt_Key_Key_BraceLeft = 123;

constexpr static const Qt_Key Qt_Key_Key_Bar = 124;

constexpr static const Qt_Key Qt_Key_Key_BraceRight = 125;

constexpr static const Qt_Key Qt_Key_Key_AsciiTilde = 126;

constexpr static const Qt_Key Qt_Key_Key_nobreakspace = 160;

constexpr static const Qt_Key Qt_Key_Key_exclamdown = 161;

constexpr static const Qt_Key Qt_Key_Key_cent = 162;

constexpr static const Qt_Key Qt_Key_Key_sterling = 163;

constexpr static const Qt_Key Qt_Key_Key_currency = 164;

constexpr static const Qt_Key Qt_Key_Key_yen = 165;

constexpr static const Qt_Key Qt_Key_Key_brokenbar = 166;

constexpr static const Qt_Key Qt_Key_Key_section = 167;

constexpr static const Qt_Key Qt_Key_Key_diaeresis = 168;

constexpr static const Qt_Key Qt_Key_Key_copyright = 169;

constexpr static const Qt_Key Qt_Key_Key_ordfeminine = 170;

constexpr static const Qt_Key Qt_Key_Key_guillemotleft = 171;

constexpr static const Qt_Key Qt_Key_Key_notsign = 172;

constexpr static const Qt_Key Qt_Key_Key_hyphen = 173;

constexpr static const Qt_Key Qt_Key_Key_registered = 174;

constexpr static const Qt_Key Qt_Key_Key_macron = 175;

constexpr static const Qt_Key Qt_Key_Key_degree = 176;

constexpr static const Qt_Key Qt_Key_Key_plusminus = 177;

constexpr static const Qt_Key Qt_Key_Key_twosuperior = 178;

constexpr static const Qt_Key Qt_Key_Key_threesuperior = 179;

constexpr static const Qt_Key Qt_Key_Key_acute = 180;

constexpr static const Qt_Key Qt_Key_Key_mu = 181;

constexpr static const Qt_Key Qt_Key_Key_paragraph = 182;

constexpr static const Qt_Key Qt_Key_Key_periodcentered = 183;

constexpr static const Qt_Key Qt_Key_Key_cedilla = 184;

constexpr static const Qt_Key Qt_Key_Key_onesuperior = 185;

constexpr static const Qt_Key Qt_Key_Key_masculine = 186;

constexpr static const Qt_Key Qt_Key_Key_guillemotright = 187;

constexpr static const Qt_Key Qt_Key_Key_onequarter = 188;

constexpr static const Qt_Key Qt_Key_Key_onehalf = 189;

constexpr static const Qt_Key Qt_Key_Key_threequarters = 190;

constexpr static const Qt_Key Qt_Key_Key_questiondown = 191;

constexpr static const Qt_Key Qt_Key_Key_Agrave = 192;

constexpr static const Qt_Key Qt_Key_Key_Aacute = 193;

constexpr static const Qt_Key Qt_Key_Key_Acircumflex = 194;

constexpr static const Qt_Key Qt_Key_Key_Atilde = 195;

constexpr static const Qt_Key Qt_Key_Key_Adiaeresis = 196;

constexpr static const Qt_Key Qt_Key_Key_Aring = 197;

constexpr static const Qt_Key Qt_Key_Key_AE = 198;

constexpr static const Qt_Key Qt_Key_Key_Ccedilla = 199;

constexpr static const Qt_Key Qt_Key_Key_Egrave = 200;

constexpr static const Qt_Key Qt_Key_Key_Eacute = 201;

constexpr static const Qt_Key Qt_Key_Key_Ecircumflex = 202;

constexpr static const Qt_Key Qt_Key_Key_Ediaeresis = 203;

constexpr static const Qt_Key Qt_Key_Key_Igrave = 204;

constexpr static const Qt_Key Qt_Key_Key_Iacute = 205;

constexpr static const Qt_Key Qt_Key_Key_Icircumflex = 206;

constexpr static const Qt_Key Qt_Key_Key_Idiaeresis = 207;

constexpr static const Qt_Key Qt_Key_Key_ETH = 208;

constexpr static const Qt_Key Qt_Key_Key_Ntilde = 209;

constexpr static const Qt_Key Qt_Key_Key_Ograve = 210;

constexpr static const Qt_Key Qt_Key_Key_Oacute = 211;

constexpr static const Qt_Key Qt_Key_Key_Ocircumflex = 212;

constexpr static const Qt_Key Qt_Key_Key_Otilde = 213;

constexpr static const Qt_Key Qt_Key_Key_Odiaeresis = 214;

constexpr static const Qt_Key Qt_Key_Key_multiply = 215;

constexpr static const Qt_Key Qt_Key_Key_Ooblique = 216;

constexpr static const Qt_Key Qt_Key_Key_Ugrave = 217;

constexpr static const Qt_Key Qt_Key_Key_Uacute = 218;

constexpr static const Qt_Key Qt_Key_Key_Ucircumflex = 219;

constexpr static const Qt_Key Qt_Key_Key_Udiaeresis = 220;

constexpr static const Qt_Key Qt_Key_Key_Yacute = 221;

constexpr static const Qt_Key Qt_Key_Key_THORN = 222;

constexpr static const Qt_Key Qt_Key_Key_ssharp = 223;

constexpr static const Qt_Key Qt_Key_Key_division = 247;

constexpr static const Qt_Key Qt_Key_Key_ydiaeresis = 255;

constexpr static const Qt_Key Qt_Key_Key_AltGr = 16781571;

constexpr static const Qt_Key Qt_Key_Key_Multi_key = 16781600;

constexpr static const Qt_Key Qt_Key_Key_Codeinput = 16781623;

constexpr static const Qt_Key Qt_Key_Key_SingleCandidate = 16781628;

constexpr static const Qt_Key Qt_Key_Key_MultipleCandidate = 16781629;

constexpr static const Qt_Key Qt_Key_Key_PreviousCandidate = 16781630;

constexpr static const Qt_Key Qt_Key_Key_Mode_switch = 16781694;

constexpr static const Qt_Key Qt_Key_Key_Kanji = 16781601;

constexpr static const Qt_Key Qt_Key_Key_Muhenkan = 16781602;

constexpr static const Qt_Key Qt_Key_Key_Henkan = 16781603;

constexpr static const Qt_Key Qt_Key_Key_Romaji = 16781604;

constexpr static const Qt_Key Qt_Key_Key_Hiragana = 16781605;

constexpr static const Qt_Key Qt_Key_Key_Katakana = 16781606;

constexpr static const Qt_Key Qt_Key_Key_Hiragana_Katakana = 16781607;

constexpr static const Qt_Key Qt_Key_Key_Zenkaku = 16781608;

constexpr static const Qt_Key Qt_Key_Key_Hankaku = 16781609;

constexpr static const Qt_Key Qt_Key_Key_Zenkaku_Hankaku = 16781610;

constexpr static const Qt_Key Qt_Key_Key_Touroku = 16781611;

constexpr static const Qt_Key Qt_Key_Key_Massyo = 16781612;

constexpr static const Qt_Key Qt_Key_Key_Kana_Lock = 16781613;

constexpr static const Qt_Key Qt_Key_Key_Kana_Shift = 16781614;

constexpr static const Qt_Key Qt_Key_Key_Eisu_Shift = 16781615;

constexpr static const Qt_Key Qt_Key_Key_Eisu_toggle = 16781616;

constexpr static const Qt_Key Qt_Key_Key_Hangul = 16781617;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Start = 16781618;

constexpr static const Qt_Key Qt_Key_Key_Hangul_End = 16781619;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Hanja = 16781620;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Jamo = 16781621;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Romaja = 16781622;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Jeonja = 16781624;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Banja = 16781625;

constexpr static const Qt_Key Qt_Key_Key_Hangul_PreHanja = 16781626;

constexpr static const Qt_Key Qt_Key_Key_Hangul_PostHanja = 16781627;

constexpr static const Qt_Key Qt_Key_Key_Hangul_Special = 16781631;

constexpr static const Qt_Key Qt_Key_Key_Dead_Grave = 16781904;

constexpr static const Qt_Key Qt_Key_Key_Dead_Acute = 16781905;

constexpr static const Qt_Key Qt_Key_Key_Dead_Circumflex = 16781906;

constexpr static const Qt_Key Qt_Key_Key_Dead_Tilde = 16781907;

constexpr static const Qt_Key Qt_Key_Key_Dead_Macron = 16781908;

constexpr static const Qt_Key Qt_Key_Key_Dead_Breve = 16781909;

constexpr static const Qt_Key Qt_Key_Key_Dead_Abovedot = 16781910;

constexpr static const Qt_Key Qt_Key_Key_Dead_Diaeresis = 16781911;

constexpr static const Qt_Key Qt_Key_Key_Dead_Abovering = 16781912;

constexpr static const Qt_Key Qt_Key_Key_Dead_Doubleacute = 16781913;

constexpr static const Qt_Key Qt_Key_Key_Dead_Caron = 16781914;

constexpr static const Qt_Key Qt_Key_Key_Dead_Cedilla = 16781915;

constexpr static const Qt_Key Qt_Key_Key_Dead_Ogonek = 16781916;

constexpr static const Qt_Key Qt_Key_Key_Dead_Iota = 16781917;

constexpr static const Qt_Key Qt_Key_Key_Dead_Voiced_Sound = 16781918;

constexpr static const Qt_Key Qt_Key_Key_Dead_Semivoiced_Sound = 16781919;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowdot = 16781920;

constexpr static const Qt_Key Qt_Key_Key_Dead_Hook = 16781921;

constexpr static const Qt_Key Qt_Key_Key_Dead_Horn = 16781922;

constexpr static const Qt_Key Qt_Key_Key_Dead_Stroke = 16781923;

constexpr static const Qt_Key Qt_Key_Key_Dead_Abovecomma = 16781924;

constexpr static const Qt_Key Qt_Key_Key_Dead_Abovereversedcomma = 16781925;

constexpr static const Qt_Key Qt_Key_Key_Dead_Doublegrave = 16781926;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowring = 16781927;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowmacron = 16781928;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowcircumflex = 16781929;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowtilde = 16781930;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowbreve = 16781931;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowdiaeresis = 16781932;

constexpr static const Qt_Key Qt_Key_Key_Dead_Invertedbreve = 16781933;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowcomma = 16781934;

constexpr static const Qt_Key Qt_Key_Key_Dead_Currency = 16781935;

constexpr static const Qt_Key Qt_Key_Key_Dead_a = 16781952;

constexpr static const Qt_Key Qt_Key_Key_Dead_A = 16781953;

constexpr static const Qt_Key Qt_Key_Key_Dead_e = 16781954;

constexpr static const Qt_Key Qt_Key_Key_Dead_E = 16781955;

constexpr static const Qt_Key Qt_Key_Key_Dead_i = 16781956;

constexpr static const Qt_Key Qt_Key_Key_Dead_I = 16781957;

constexpr static const Qt_Key Qt_Key_Key_Dead_o = 16781958;

constexpr static const Qt_Key Qt_Key_Key_Dead_O = 16781959;

constexpr static const Qt_Key Qt_Key_Key_Dead_u = 16781960;

constexpr static const Qt_Key Qt_Key_Key_Dead_U = 16781961;

constexpr static const Qt_Key Qt_Key_Key_Dead_Small_Schwa = 16781962;

constexpr static const Qt_Key Qt_Key_Key_Dead_Capital_Schwa = 16781963;

constexpr static const Qt_Key Qt_Key_Key_Dead_Greek = 16781964;

constexpr static const Qt_Key Qt_Key_Key_Dead_Lowline = 16781968;

constexpr static const Qt_Key Qt_Key_Key_Dead_Aboveverticalline = 16781969;

constexpr static const Qt_Key Qt_Key_Key_Dead_Belowverticalline = 16781970;

constexpr static const Qt_Key Qt_Key_Key_Dead_Longsolidusoverlay = 16781971;

constexpr static const Qt_Key Qt_Key_Key_Back = 16777313;

constexpr static const Qt_Key Qt_Key_Key_Forward = 16777314;

constexpr static const Qt_Key Qt_Key_Key_Stop = 16777315;

constexpr static const Qt_Key Qt_Key_Key_Refresh = 16777316;

constexpr static const Qt_Key Qt_Key_Key_VolumeDown = 16777328;

constexpr static const Qt_Key Qt_Key_Key_VolumeMute = 16777329;

constexpr static const Qt_Key Qt_Key_Key_VolumeUp = 16777330;

constexpr static const Qt_Key Qt_Key_Key_BassBoost = 16777331;

constexpr static const Qt_Key Qt_Key_Key_BassUp = 16777332;

constexpr static const Qt_Key Qt_Key_Key_BassDown = 16777333;

constexpr static const Qt_Key Qt_Key_Key_TrebleUp = 16777334;

constexpr static const Qt_Key Qt_Key_Key_TrebleDown = 16777335;

constexpr static const Qt_Key Qt_Key_Key_MediaPlay = 16777344;

constexpr static const Qt_Key Qt_Key_Key_MediaStop = 16777345;

constexpr static const Qt_Key Qt_Key_Key_MediaPrevious = 16777346;

constexpr static const Qt_Key Qt_Key_Key_MediaNext = 16777347;

constexpr static const Qt_Key Qt_Key_Key_MediaRecord = 16777348;

constexpr static const Qt_Key Qt_Key_Key_MediaPause = 16777349;

constexpr static const Qt_Key Qt_Key_Key_MediaTogglePlayPause = 16777350;

constexpr static const Qt_Key Qt_Key_Key_HomePage = 16777360;

constexpr static const Qt_Key Qt_Key_Key_Favorites = 16777361;

constexpr static const Qt_Key Qt_Key_Key_Search = 16777362;

constexpr static const Qt_Key Qt_Key_Key_Standby = 16777363;

constexpr static const Qt_Key Qt_Key_Key_OpenUrl = 16777364;

constexpr static const Qt_Key Qt_Key_Key_LaunchMail = 16777376;

constexpr static const Qt_Key Qt_Key_Key_LaunchMedia = 16777377;

constexpr static const Qt_Key Qt_Key_Key_Launch0 = 16777378;

constexpr static const Qt_Key Qt_Key_Key_Launch1 = 16777379;

constexpr static const Qt_Key Qt_Key_Key_Launch2 = 16777380;

constexpr static const Qt_Key Qt_Key_Key_Launch3 = 16777381;

constexpr static const Qt_Key Qt_Key_Key_Launch4 = 16777382;

constexpr static const Qt_Key Qt_Key_Key_Launch5 = 16777383;

constexpr static const Qt_Key Qt_Key_Key_Launch6 = 16777384;

constexpr static const Qt_Key Qt_Key_Key_Launch7 = 16777385;

constexpr static const Qt_Key Qt_Key_Key_Launch8 = 16777386;

constexpr static const Qt_Key Qt_Key_Key_Launch9 = 16777387;

constexpr static const Qt_Key Qt_Key_Key_LaunchA = 16777388;

constexpr static const Qt_Key Qt_Key_Key_LaunchB = 16777389;

constexpr static const Qt_Key Qt_Key_Key_LaunchC = 16777390;

constexpr static const Qt_Key Qt_Key_Key_LaunchD = 16777391;

constexpr static const Qt_Key Qt_Key_Key_LaunchE = 16777392;

constexpr static const Qt_Key Qt_Key_Key_LaunchF = 16777393;

constexpr static const Qt_Key Qt_Key_Key_MonBrightnessUp = 16777394;

constexpr static const Qt_Key Qt_Key_Key_MonBrightnessDown = 16777395;

constexpr static const Qt_Key Qt_Key_Key_KeyboardLightOnOff = 16777396;

constexpr static const Qt_Key Qt_Key_Key_KeyboardBrightnessUp = 16777397;

constexpr static const Qt_Key Qt_Key_Key_KeyboardBrightnessDown = 16777398;

constexpr static const Qt_Key Qt_Key_Key_PowerOff = 16777399;

constexpr static const Qt_Key Qt_Key_Key_WakeUp = 16777400;

constexpr static const Qt_Key Qt_Key_Key_Eject = 16777401;

constexpr static const Qt_Key Qt_Key_Key_ScreenSaver = 16777402;

constexpr static const Qt_Key Qt_Key_Key_WWW = 16777403;

constexpr static const Qt_Key Qt_Key_Key_Memo = 16777404;

constexpr static const Qt_Key Qt_Key_Key_LightBulb = 16777405;

constexpr static const Qt_Key Qt_Key_Key_Shop = 16777406;

constexpr static const Qt_Key Qt_Key_Key_History = 16777407;

constexpr static const Qt_Key Qt_Key_Key_AddFavorite = 16777408;

constexpr static const Qt_Key Qt_Key_Key_HotLinks = 16777409;

constexpr static const Qt_Key Qt_Key_Key_BrightnessAdjust = 16777410;

constexpr static const Qt_Key Qt_Key_Key_Finance = 16777411;

constexpr static const Qt_Key Qt_Key_Key_Community = 16777412;

constexpr static const Qt_Key Qt_Key_Key_AudioRewind = 16777413;

constexpr static const Qt_Key Qt_Key_Key_BackForward = 16777414;

constexpr static const Qt_Key Qt_Key_Key_ApplicationLeft = 16777415;

constexpr static const Qt_Key Qt_Key_Key_ApplicationRight = 16777416;

constexpr static const Qt_Key Qt_Key_Key_Book = 16777417;

constexpr static const Qt_Key Qt_Key_Key_CD = 16777418;

constexpr static const Qt_Key Qt_Key_Key_Calculator = 16777419;

constexpr static const Qt_Key Qt_Key_Key_ToDoList = 16777420;

constexpr static const Qt_Key Qt_Key_Key_ClearGrab = 16777421;

constexpr static const Qt_Key Qt_Key_Key_Close = 16777422;

constexpr static const Qt_Key Qt_Key_Key_Copy = 16777423;

constexpr static const Qt_Key Qt_Key_Key_Cut = 16777424;

constexpr static const Qt_Key Qt_Key_Key_Display = 16777425;

constexpr static const Qt_Key Qt_Key_Key_DOS = 16777426;

constexpr static const Qt_Key Qt_Key_Key_Documents = 16777427;

constexpr static const Qt_Key Qt_Key_Key_Excel = 16777428;

constexpr static const Qt_Key Qt_Key_Key_Explorer = 16777429;

constexpr static const Qt_Key Qt_Key_Key_Game = 16777430;

constexpr static const Qt_Key Qt_Key_Key_Go = 16777431;

constexpr static const Qt_Key Qt_Key_Key_iTouch = 16777432;

constexpr static const Qt_Key Qt_Key_Key_LogOff = 16777433;

constexpr static const Qt_Key Qt_Key_Key_Market = 16777434;

constexpr static const Qt_Key Qt_Key_Key_Meeting = 16777435;

constexpr static const Qt_Key Qt_Key_Key_MenuKB = 16777436;

constexpr static const Qt_Key Qt_Key_Key_MenuPB = 16777437;

constexpr static const Qt_Key Qt_Key_Key_MySites = 16777438;

constexpr static const Qt_Key Qt_Key_Key_News = 16777439;

constexpr static const Qt_Key Qt_Key_Key_OfficeHome = 16777440;

constexpr static const Qt_Key Qt_Key_Key_Option = 16777441;

constexpr static const Qt_Key Qt_Key_Key_Paste = 16777442;

constexpr static const Qt_Key Qt_Key_Key_Phone = 16777443;

constexpr static const Qt_Key Qt_Key_Key_Calendar = 16777444;

constexpr static const Qt_Key Qt_Key_Key_Reply = 16777445;

constexpr static const Qt_Key Qt_Key_Key_Reload = 16777446;

constexpr static const Qt_Key Qt_Key_Key_RotateWindows = 16777447;

constexpr static const Qt_Key Qt_Key_Key_RotationPB = 16777448;

constexpr static const Qt_Key Qt_Key_Key_RotationKB = 16777449;

constexpr static const Qt_Key Qt_Key_Key_Save = 16777450;

constexpr static const Qt_Key Qt_Key_Key_Send = 16777451;

constexpr static const Qt_Key Qt_Key_Key_Spell = 16777452;

constexpr static const Qt_Key Qt_Key_Key_SplitScreen = 16777453;

constexpr static const Qt_Key Qt_Key_Key_Support = 16777454;

constexpr static const Qt_Key Qt_Key_Key_TaskPane = 16777455;

constexpr static const Qt_Key Qt_Key_Key_Terminal = 16777456;

constexpr static const Qt_Key Qt_Key_Key_Tools = 16777457;

constexpr static const Qt_Key Qt_Key_Key_Travel = 16777458;

constexpr static const Qt_Key Qt_Key_Key_Video = 16777459;

constexpr static const Qt_Key Qt_Key_Key_Word = 16777460;

constexpr static const Qt_Key Qt_Key_Key_Xfer = 16777461;

constexpr static const Qt_Key Qt_Key_Key_ZoomIn = 16777462;

constexpr static const Qt_Key Qt_Key_Key_ZoomOut = 16777463;

constexpr static const Qt_Key Qt_Key_Key_Away = 16777464;

constexpr static const Qt_Key Qt_Key_Key_Messenger = 16777465;

constexpr static const Qt_Key Qt_Key_Key_WebCam = 16777466;

constexpr static const Qt_Key Qt_Key_Key_MailForward = 16777467;

constexpr static const Qt_Key Qt_Key_Key_Pictures = 16777468;

constexpr static const Qt_Key Qt_Key_Key_Music = 16777469;

constexpr static const Qt_Key Qt_Key_Key_Battery = 16777470;

constexpr static const Qt_Key Qt_Key_Key_Bluetooth = 16777471;

constexpr static const Qt_Key Qt_Key_Key_WLAN = 16777472;

constexpr static const Qt_Key Qt_Key_Key_UWB = 16777473;

constexpr static const Qt_Key Qt_Key_Key_AudioForward = 16777474;

constexpr static const Qt_Key Qt_Key_Key_AudioRepeat = 16777475;

constexpr static const Qt_Key Qt_Key_Key_AudioRandomPlay = 16777476;

constexpr static const Qt_Key Qt_Key_Key_Subtitle = 16777477;

constexpr static const Qt_Key Qt_Key_Key_AudioCycleTrack = 16777478;

constexpr static const Qt_Key Qt_Key_Key_Time = 16777479;

constexpr static const Qt_Key Qt_Key_Key_Hibernate = 16777480;

constexpr static const Qt_Key Qt_Key_Key_View = 16777481;

constexpr static const Qt_Key Qt_Key_Key_TopMenu = 16777482;

constexpr static const Qt_Key Qt_Key_Key_PowerDown = 16777483;

constexpr static const Qt_Key Qt_Key_Key_Suspend = 16777484;

constexpr static const Qt_Key Qt_Key_Key_ContrastAdjust = 16777485;

constexpr static const Qt_Key Qt_Key_Key_LaunchG = 16777486;

constexpr static const Qt_Key Qt_Key_Key_LaunchH = 16777487;

constexpr static const Qt_Key Qt_Key_Key_TouchpadToggle = 16777488;

constexpr static const Qt_Key Qt_Key_Key_TouchpadOn = 16777489;

constexpr static const Qt_Key Qt_Key_Key_TouchpadOff = 16777490;

constexpr static const Qt_Key Qt_Key_Key_MicMute = 16777491;

constexpr static const Qt_Key Qt_Key_Key_Red = 16777492;

constexpr static const Qt_Key Qt_Key_Key_Green = 16777493;

constexpr static const Qt_Key Qt_Key_Key_Yellow = 16777494;

constexpr static const Qt_Key Qt_Key_Key_Blue = 16777495;

constexpr static const Qt_Key Qt_Key_Key_ChannelUp = 16777496;

constexpr static const Qt_Key Qt_Key_Key_ChannelDown = 16777497;

constexpr static const Qt_Key Qt_Key_Key_Guide = 16777498;

constexpr static const Qt_Key Qt_Key_Key_Info = 16777499;

constexpr static const Qt_Key Qt_Key_Key_Settings = 16777500;

constexpr static const Qt_Key Qt_Key_Key_MicVolumeUp = 16777501;

constexpr static const Qt_Key Qt_Key_Key_MicVolumeDown = 16777502;

constexpr static const Qt_Key Qt_Key_Key_New = 16777504;

constexpr static const Qt_Key Qt_Key_Key_Open = 16777505;

constexpr static const Qt_Key Qt_Key_Key_Find = 16777506;

constexpr static const Qt_Key Qt_Key_Key_Undo = 16777507;

constexpr static const Qt_Key Qt_Key_Key_Redo = 16777508;

constexpr static const Qt_Key Qt_Key_Key_MediaLast = 16842751;

constexpr static const Qt_Key Qt_Key_Key_Select = 16842752;

constexpr static const Qt_Key Qt_Key_Key_Yes = 16842753;

constexpr static const Qt_Key Qt_Key_Key_No = 16842754;

constexpr static const Qt_Key Qt_Key_Key_Cancel = 16908289;

constexpr static const Qt_Key Qt_Key_Key_Printer = 16908290;

constexpr static const Qt_Key Qt_Key_Key_Execute = 16908291;

constexpr static const Qt_Key Qt_Key_Key_Sleep = 16908292;

constexpr static const Qt_Key Qt_Key_Key_Play = 16908293;

constexpr static const Qt_Key Qt_Key_Key_Zoom = 16908294;

constexpr static const Qt_Key Qt_Key_Key_Exit = 16908298;

constexpr static const Qt_Key Qt_Key_Key_Context1 = 17825792;

constexpr static const Qt_Key Qt_Key_Key_Context2 = 17825793;

constexpr static const Qt_Key Qt_Key_Key_Context3 = 17825794;

constexpr static const Qt_Key Qt_Key_Key_Context4 = 17825795;

constexpr static const Qt_Key Qt_Key_Key_Call = 17825796;

constexpr static const Qt_Key Qt_Key_Key_Hangup = 17825797;

constexpr static const Qt_Key Qt_Key_Key_Flip = 17825798;

constexpr static const Qt_Key Qt_Key_Key_ToggleCallHangup = 17825799;

constexpr static const Qt_Key Qt_Key_Key_VoiceDial = 17825800;

constexpr static const Qt_Key Qt_Key_Key_LastNumberRedial = 17825801;

constexpr static const Qt_Key Qt_Key_Key_Camera = 17825824;

constexpr static const Qt_Key Qt_Key_Key_CameraFocus = 17825825;

constexpr static const Qt_Key Qt_Key_Key_unknown = 33554431;

constexpr static const Qt_CursorShape Qt_CursorShape_ArrowCursor = 0;

constexpr static const Qt_CursorShape Qt_CursorShape_UpArrowCursor = 1;

constexpr static const Qt_CursorShape Qt_CursorShape_CrossCursor = 2;

constexpr static const Qt_CursorShape Qt_CursorShape_WaitCursor = 3;

constexpr static const Qt_CursorShape Qt_CursorShape_IBeamCursor = 4;

constexpr static const Qt_CursorShape Qt_CursorShape_SizeVerCursor = 5;

constexpr static const Qt_CursorShape Qt_CursorShape_SizeHorCursor = 6;

constexpr static const Qt_CursorShape Qt_CursorShape_SizeBDiagCursor = 7;

constexpr static const Qt_CursorShape Qt_CursorShape_SizeFDiagCursor = 8;

constexpr static const Qt_CursorShape Qt_CursorShape_SizeAllCursor = 9;

constexpr static const Qt_CursorShape Qt_CursorShape_BlankCursor = 10;

constexpr static const Qt_CursorShape Qt_CursorShape_SplitVCursor = 11;

constexpr static const Qt_CursorShape Qt_CursorShape_SplitHCursor = 12;

constexpr static const Qt_CursorShape Qt_CursorShape_PointingHandCursor = 13;

constexpr static const Qt_CursorShape Qt_CursorShape_ForbiddenCursor = 14;

constexpr static const Qt_CursorShape Qt_CursorShape_WhatsThisCursor = 15;

constexpr static const Qt_CursorShape Qt_CursorShape_BusyCursor = 16;

constexpr static const Qt_CursorShape Qt_CursorShape_OpenHandCursor = 17;

constexpr static const Qt_CursorShape Qt_CursorShape_ClosedHandCursor = 18;

constexpr static const Qt_CursorShape Qt_CursorShape_DragCopyCursor = 19;

constexpr static const Qt_CursorShape Qt_CursorShape_DragMoveCursor = 20;

constexpr static const Qt_CursorShape Qt_CursorShape_DragLinkCursor = 21;

constexpr static const Qt_CursorShape Qt_CursorShape_LastCursor = 21;

constexpr static const Qt_CursorShape Qt_CursorShape_BitmapCursor = 24;

constexpr static const Qt_CursorShape Qt_CursorShape_CustomCursor = 25;

constexpr static const Qt_FillRule Qt_FillRule_OddEvenFill = 0;

constexpr static const Qt_FillRule Qt_FillRule_WindingFill = 1;

extern "C" {

void slint_native_style_metrics_init(Pin<const NativeStyleMetrics*> self_);

void slint_native_style_metrics_deinit(Pin<NativeStyleMetrics*> self_);

void slint_native_palette_init(Pin<const NativePalette*> self_);

void slint_native_palette_deinit(Pin<NativePalette*> self_);

void *slint_qt_get_widget(const WindowAdapterRc *window_adapter);

void *slint_qt_get_widget(const WindowAdapterRc*);

} // extern "C"

} // namespace cbindgen_private
} // namespace slint


namespace slint::private_api {
#define SLINT_DECL_ITEM(ItemName) \
    extern const cbindgen_private::ItemVTable ItemName##VTable; \
    extern SLINT_DLL_IMPORT const cbindgen_private::ItemVTable* slint_get_##ItemName##VTable();

extern "C" {
SLINT_DECL_ITEM(NativeButton);
SLINT_DECL_ITEM(NativeSpinBox);
SLINT_DECL_ITEM(NativeCheckBox);
SLINT_DECL_ITEM(NativeSlider);
SLINT_DECL_ITEM(NativeProgressIndicator);
SLINT_DECL_ITEM(NativeGroupBox);
SLINT_DECL_ITEM(NativeLineEdit);
SLINT_DECL_ITEM(NativeScrollView);
SLINT_DECL_ITEM(NativeStandardListViewItem);
SLINT_DECL_ITEM(NativeTableHeaderSection);
SLINT_DECL_ITEM(NativeComboBox);
SLINT_DECL_ITEM(NativeComboBoxPopup);
SLINT_DECL_ITEM(NativeTabWidget);
SLINT_DECL_ITEM(NativeTab);
SLINT_DECL_ITEM(NativeStyleMetrics);
SLINT_DECL_ITEM(NativePalette);
}

#undef SLINT_DECL_ITEM
}
