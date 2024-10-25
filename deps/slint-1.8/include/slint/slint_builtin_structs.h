#pragma once
// This file is auto-generated from api/cpp/cbindgen.rs
namespace slint {
/// Represents an item in a StandardListView and a StandardTableView.
struct StandardListViewItem {
    /// The text content of the item
    SharedString text;
    /// \private
    friend bool operator==(const StandardListViewItem&, const StandardListViewItem&) = default;
    /// \private
    friend bool operator!=(const StandardListViewItem&, const StandardListViewItem&) = default;
};
}
