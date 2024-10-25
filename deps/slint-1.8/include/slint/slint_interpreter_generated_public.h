#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

namespace slint {
namespace interpreter {

/// DiagnosticLevel describes the severity of a diagnostic.
enum class DiagnosticLevel : uint8_t {
    /// The diagnostic belongs to an error.
    Error,
    /// The diagnostic belongs to a warning.
    Warning,
};

/// This enum represents the different public variants of the [`Value`] enum, without
/// the contained values.
enum class ValueType : int8_t {
    /// The variant that expresses the non-type. This is the default.
    Void,
    /// An `int` or a `float` (this is also used for unit based type such as `length` or `angle`)
    Number,
    /// Correspond to the `string` type in .slint
    String,
    /// Correspond to the `bool` type in .slint
    Bool,
    /// A model (that includes array in .slint)
    Model,
    /// An object
    Struct,
    /// Correspond to `brush` or `color` type in .slint.  For color, this is then a [`Brush::SolidColor`]
    Brush,
    /// Correspond to `image` type in .slint.
    Image,
    /// The type is not a public type but something internal.
    Other = -1,
};

/// Diagnostic describes the aspects of either a warning or an error, along
/// with its location and a description. Diagnostics are typically returned by
/// slint::interpreter::ComponentCompiler::diagnostics() in a vector.
struct Diagnostic {
    /// The message describing the warning or error.
    SharedString message;
    /// The path to the source file where the warning or error is located.
    SharedString source_file;
    /// The line within the source file. Line numbers start at 1.
    uintptr_t line;
    /// The column within the source file. Column numbers start at 1.
    uintptr_t column;
    /// The level of the diagnostic, such as a warning or an error.
    DiagnosticLevel level;
};

/// PropertyDescriptor is a simple structure that's used to describe a property declared in .slint
/// code. It is returned from in a vector from
/// slint::interpreter::ComponentDefinition::properties().
struct PropertyDescriptor {
    /// The name of the declared property.
    SharedString property_name;
    /// The type of the property.
    ValueType property_type;
};

} // namespace interpreter
} // namespace slint
