#pragma once
// This file is auto-generated from api/cpp/cbindgen.rs
#include "slint_builtin_structs.h"
#include "slint_enums_internal.h"
namespace slint::cbindgen_private {
enum class KeyEventType : uint8_t;
/// The `KeyboardModifiers` struct provides booleans to indicate possible modifier keys on a keyboard, such as Shift, Control, etc.
/// It is provided as part of `KeyEvent`'s `modifiers` field.
///
/// Keyboard shortcuts on Apple platforms typically use the Command key (⌘), such as Command+C for "Copy". On other platforms
/// the same shortcut is typically represented using Control+C. To make it easier to develop cross-platform applications, on macOS,
/// Slint maps the Command key to the control modifier, and the Control key to the meta modifier.
///
/// On Windows, the Windows key is mapped to the meta modifier.
struct KeyboardModifiers {
    /// Indicates the Alt key on a keyboard.
    bool alt;
    /// Indicates the Control key on a keyboard, except on macOS, where it is the Command key (⌘).
    bool control;
    /// Indicates the Shift key on a keyboard.
    bool shift;
    /// Indicates the Control key on macos, and the Windows key on Windows.
    bool meta;
    /// \private
    friend bool operator==(const KeyboardModifiers&, const KeyboardModifiers&) = default;
    /// \private
    friend bool operator!=(const KeyboardModifiers&, const KeyboardModifiers&) = default;
};
/// Represents a Pointer event sent by the windowing system.
/// This structure is passed to the `pointer-event` callback of the `TouchArea` element.
struct PointerEvent {
    /// The button that was pressed or released
    PointerEventButton button;
    /// The kind of the event
    PointerEventKind kind;
    /// The keyboard modifiers pressed during the event
    KeyboardModifiers modifiers;
    /// \private
    friend bool operator==(const PointerEvent&, const PointerEvent&) = default;
    /// \private
    friend bool operator!=(const PointerEvent&, const PointerEvent&) = default;
};
/// Represents a Pointer scroll (or wheel) event sent by the windowing system.
/// This structure is passed to the `scroll-event` callback of the `TouchArea` element.
struct PointerScrollEvent {
    /// The amount of pixel in the horizontal direction
    float delta_x;
    /// The amount of pixel in the vertical direction
    float delta_y;
    /// The keyboard modifiers pressed during the event
    KeyboardModifiers modifiers;
    /// \private
    friend bool operator==(const PointerScrollEvent&, const PointerScrollEvent&) = default;
    /// \private
    friend bool operator!=(const PointerScrollEvent&, const PointerScrollEvent&) = default;
};
/// This structure is generated and passed to the key press and release callbacks of the `FocusScope` element.
struct KeyEvent {
    /// The unicode representation of the key pressed.
    SharedString text;
    /// The keyboard modifiers active at the time of the key press event.
    KeyboardModifiers modifiers;
    /// This field is set to true for key press events that are repeated,
    /// i.e. the key is held down. It's always false for key release events.
    bool repeat;
    /// Indicates whether the key was pressed or released
    KeyEventType event_type;
    /// If the event type is KeyEventType::UpdateComposition or KeyEventType::CommitComposition,
    /// then this field specifies what part of the current text to replace.
    /// Relative to the offset of the pre-edit text within the text input element's text.
    std::tuple<int32_t, int32_t, int32_t> replacement_range;
    /// If the event type is KeyEventType::UpdateComposition, this is the new pre-edit text
    SharedString preedit_text;
    /// The selection within the preedit_text
    std::tuple<int32_t, int32_t, int32_t> preedit_selection;
    /// The new cursor position, when None, the cursor is put after the text that was just inserted
    std::pair<int32_t, int32_t> cursor_position;
    std::pair<int32_t, int32_t> anchor_position;
    /// \private
    friend bool operator==(const KeyEvent&, const KeyEvent&) = default;
    /// \private
    friend bool operator!=(const KeyEvent&, const KeyEvent&) = default;
};
using slint::StandardListViewItem;
/// This is used to define the column and the column header of a TableView
struct TableColumn {
    /// The title of the column header
    SharedString title;
    /// The minimum column width (logical length)
    float min_width;
    /// The horizontal column stretch
    float horizontal_stretch;
    /// Sorts the column
    SortOrder sort_order;
    /// the actual width of the column (logical length)
    float width;
    /// \private
    friend bool operator==(const TableColumn&, const TableColumn&) = default;
    /// \private
    friend bool operator!=(const TableColumn&, const TableColumn&) = default;
};
/// Value of the state property
/// A state is just the current state, but also has information about the previous state and the moment it changed
struct StateInfo {
    /// The current state value
    int32_t current_state;
    /// The previous state
    int32_t previous_state;
    /// The instant in which the state changed last
    uint64_t change_time;
    /// \private
    friend bool operator==(const StateInfo&, const StateInfo&) = default;
    /// \private
    friend bool operator!=(const StateInfo&, const StateInfo&) = default;
};
}
