#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
#include "slint_string.h"

/// This macro expands to the to the numeric value of the major version of Slint you're
/// developing against. For example if you're using version 1.5.2, this macro will expand to 1.
#define SLINT_VERSION_MAJOR 1
/// This macro expands to the to the numeric value of the minor version of Slint you're
/// developing against. For example if you're using version 1.5.2, this macro will expand to 5.
#define SLINT_VERSION_MINOR 8
/// This macro expands to the to the numeric value of the patch version of Slint you're
/// developing against. For example if you're using version 1.5.2, this macro will expand to 2.
#define SLINT_VERSION_PATCH 0
/// This macro expands to the string representation of the version of Slint you're developing against.
/// For example if you're using version 1.5.2, this macro will expand to "1.5.2".
#define SLINT_VERSION_STRING "1.8.0"

///This macro is defined when Slint was configured with the SLINT_FEATURE_INTERPRETER flag enabled
#define SLINT_FEATURE_INTERPRETER
///This macro is defined when Slint was configured with the SLINT_FEATURE_TESTING flag enabled
#define SLINT_FEATURE_TESTING
///This macro is defined when Slint was configured with the SLINT_FEATURE_BACKEND_QT flag enabled
#define SLINT_FEATURE_BACKEND_QT
///This macro is defined when Slint was configured with the SLINT_FEATURE_BACKEND_WINIT flag enabled
#define SLINT_FEATURE_BACKEND_WINIT
///This macro is defined when Slint was configured with the SLINT_FEATURE_BACKEND_LINUXKMS_NOSEAT flag enabled
#define SLINT_FEATURE_BACKEND_LINUXKMS_NOSEAT
///This macro is defined when Slint was configured with the SLINT_FEATURE_RENDERER_FEMTOVG flag enabled
#define SLINT_FEATURE_RENDERER_FEMTOVG
///This macro is defined when Slint was configured with the SLINT_FEATURE_RENDERER_SKIA flag enabled
#define SLINT_FEATURE_RENDERER_SKIA
///This macro is defined when Slint was configured with the SLINT_FEATURE_RENDERER_SOFTWARE flag enabled
#define SLINT_FEATURE_RENDERER_SOFTWARE
///This macro is defined when Slint was configured with the SLINT_FEATURE_ACCESSIBILITY flag enabled
#define SLINT_FEATURE_ACCESSIBILITY



namespace slint {

/// This enum describes whether a Window is allowed to be hidden when the user tries to close the window.
/// It is the return type of the callback provided to [Window::on_close_requested].
enum class CloseRequestResponse : uint8_t {
    /// The Window will be hidden (default action)
    HideWindow = 0,
    /// The close request is rejected and the window will be kept shown.
    KeepWindowShown = 1,
};

/// This enum describes a low-level access to specific graphics APIs used
/// by the renderer.
enum class GraphicsAPI : uint8_t {
    /// The rendering is done using OpenGL.
    NativeOpenGL,
};

/// This enum describes the different rendering states, that will be provided
/// to the parameter of the callback for `set_rendering_notifier` on the `slint::Window`.
enum class RenderingState : uint8_t {
    /// The window has been created and the graphics adapter/context initialized. When OpenGL
    /// is used for rendering, the context will be current.
    RenderingSetup,
    /// The scene of items is about to be rendered.  When OpenGL
    /// is used for rendering, the context will be current.
    BeforeRendering,
    /// The scene of items was rendered, but the back buffer was not sent for display presentation
    /// yet (for example GL swap buffers). When OpenGL is used for rendering, the context will be current.
    AfterRendering,
    /// The window will be destroyed and/or graphics resources need to be released due to other
    /// constraints.
    RenderingTeardown,
};

/// This enum describes the different error scenarios that may occur when the application
/// registers a rendering notifier on a `slint::Window`.
enum class SetRenderingNotifierError : uint8_t {
    /// The rendering backend does not support rendering notifiers.
    Unsupported,
    /// There is already a rendering notifier set, multiple notifiers are not supported.
    AlreadySet,
};

/// Represents an RGB pixel.
struct Rgb8Pixel {
    /// red value (between 0 and 255)
    uint8_t r;
    /// green value (between 0 and 255)
    uint8_t g;
    /// blue value (between 0 and 255)
    uint8_t b;
/// \private
friend bool operator==(const Rgb8Pixel&, const Rgb8Pixel&) = default;
};

/// Represents an RGBA pixel.
struct Rgba8Pixel {
    /// red value (between 0 and 255)
    uint8_t r;
    /// green value (between 0 and 255)
    uint8_t g;
    /// blue value (between 0 and 255)
    uint8_t b;
    /// alpha value (between 0 and 255)
    uint8_t a;
/// \private
friend bool operator==(const Rgba8Pixel&, const Rgba8Pixel&) = default;
};

} // namespace slint
