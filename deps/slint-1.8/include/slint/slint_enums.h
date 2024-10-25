#pragma once
// This file is auto-generated from api/cpp/cbindgen.rs
namespace slint {
/// This enum describes the different types of buttons for a pointer event,
/// typically on a mouse or a pencil.
enum class PointerEventButton {
    /// A button that is none of left, right, middle, back or forward. For example,
    /// this is used for the task button on a mouse with many buttons.
    Other,
    /// The left button.
    Left,
    /// The right button.
    Right,
    /// The center button.
    Middle,
    /// The back button.
    Back,
    /// The forward button.
    Forward,
};
namespace testing {
/// This enum represents the different values for the `accessible-role` property, used to describe the
/// role of an element in the context of assistive technology such as screen readers.
enum class AccessibleRole {
    /// The element isn't accessible.
    None,
    /// The element is a [`Button`](slint-reference:src/language/widgets/button) or behaves like one.
    Button,
    /// The element is a [`CheckBox`](slint-reference:src/language/widgets/checkbox) or behaves like one.
    Checkbox,
    /// The element is a [`ComboBox`](slint-reference:src/language/widgets/combobox) or behaves like one.
    Combobox,
    /// The element is a [`ListView`](slint-reference:src/language/widgets/listview) or behaves like one.
    List,
    /// The element is a [`Slider`](slint-reference:src/language/widgets/slider) or behaves like one.
    Slider,
    /// The element is a [`SpinBox`](slint-reference:src/language/widgets/spinbox) or behaves like one.
    Spinbox,
    /// The element is a [`Tab`](slint-reference:src/language/widgets/tabwidget) or behaves like one.
    Tab,
    /// The element is similar to the tab bar in a [`TabWidget`](slint-reference:src/language/widgets/tabwidget).
    TabList,
    /// The role for a [`Text`](slint-reference:src/language/builtins/elements#text) element. It's automatically applied.
    Text,
    /// The role for a [`TableView`](slint-reference:src/language/widgets/standardtableview ) or behaves like one.
    Table,
    /// The role for a TreeView or behaves like one. (Not provided yet)
    Tree,
    /// The element is a [`ProgressIndicator`](slint-reference:src/language/widgets/progressindicator) or behaves like one.
    ProgressIndicator,
    /// The role for widget with editable text such as a
    /// [`LineEdit`](slint-reference:src/language/widgets/lineedit) or a [`TextEdit`](slint-reference:src/language/widgets/textedit)
    TextInput,
    /// The element is a [`Switch`](slint-reference:src/language/widgets/switch) or behaves like one.
    Switch,
    /// The element is an item in a [`ListView`](slint-reference:src/language/widgets/listview).
    ListItem,
};
}
}

/// This namespace contains constants for each special non-printable key.
///
/// Each constant can be converted to SharedString.
/// The constants are meant to be used with the slint::Window::dispatch_key_press_event() and
/// slint::Window::dispatch_key_release_event() functions.
///
/// Example:
/// ```
/// window.dispatch_key_press_event(slint::platform::key_codes::Tab);
/// ```
namespace slint::platform::key_codes {

/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Backspace = u8"\u0008";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Tab = u8"\u0009";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Return = u8"\u000a";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Escape = u8"\u001b";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Backtab = u8"\u0019";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Delete = u8"\u007f";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Shift = u8"\u0010";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Control = u8"\u0011";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Alt = u8"\u0012";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view AltGr = u8"\u0013";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view CapsLock = u8"\u0014";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view ShiftR = u8"\u0015";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view ControlR = u8"\u0016";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Meta = u8"\u0017";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view MetaR = u8"\u0018";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Space = u8"\u0020";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view UpArrow = u8"\uf700";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view DownArrow = u8"\uf701";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view LeftArrow = u8"\uf702";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view RightArrow = u8"\uf703";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F1 = u8"\uf704";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F2 = u8"\uf705";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F3 = u8"\uf706";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F4 = u8"\uf707";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F5 = u8"\uf708";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F6 = u8"\uf709";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F7 = u8"\uf70a";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F8 = u8"\uf70b";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F9 = u8"\uf70c";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F10 = u8"\uf70d";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F11 = u8"\uf70e";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F12 = u8"\uf70f";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F13 = u8"\uf710";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F14 = u8"\uf711";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F15 = u8"\uf712";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F16 = u8"\uf713";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F17 = u8"\uf714";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F18 = u8"\uf715";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F19 = u8"\uf716";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F20 = u8"\uf717";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F21 = u8"\uf718";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F22 = u8"\uf719";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F23 = u8"\uf71a";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view F24 = u8"\uf71b";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Insert = u8"\uf727";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Home = u8"\uf729";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view End = u8"\uf72b";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view PageUp = u8"\uf72c";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view PageDown = u8"\uf72d";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view ScrollLock = u8"\uf72f";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Pause = u8"\uf730";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view SysReq = u8"\uf731";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Stop = u8"\uf734";
/// A constant that represents the key code to be used in slint::Window::dispatch_key_press_event()
constexpr std::u8string_view Menu = u8"\uf735";
}
