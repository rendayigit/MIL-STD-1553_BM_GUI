#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
#include "slint_image_internal.h"
#include "slint_internal.h"

namespace slint::cbindgen_private { struct WindowProperties; }


namespace slint {
namespace cbindgen_private {

/// a Repr(C) variant of slint::platform::LayoutConstraints
struct LayoutConstraintsReprC {
    Size min;
    Size max;
    Size preferred;
    bool has_min;
    bool has_max;
};

using WindowAdapterUserData = void*;

struct RendererPtr {
    const void *_a;
    const void *_b;
};

using PlatformUserData = void*;

struct PlatformTaskOpaque {
    const void *_0;
    const void *_1;
};

using SoftwareRendererOpaque = const void*;

using CppRawHandleOpaque = const void*;

using SkiaRendererOpaque = const void*;

extern "C" {

void slint_windowrc_init(WindowAdapterRcOpaque *out);

void slint_ensure_backend();

/// Enters the main event loop.
void slint_run_event_loop(bool quit_on_last_window_closed);

/// Will execute the given functor in the main thread
void slint_post_event(void (*event)(void *user_data),
                      void *user_data,
                      void (*drop_user_data)(void*));

void slint_quit_event_loop();

void slint_register_font_from_path(const WindowAdapterRcOpaque *win,
                                   const SharedString *path,
                                   SharedString *error_str);

void slint_register_font_from_data(const WindowAdapterRcOpaque *win,
                                   Slice<uint8_t> data,
                                   SharedString *error_str);

void slint_register_bitmap_font(const WindowAdapterRcOpaque *win, const BitmapFont *font_data);

bool slint_string_to_float(const SharedString *string, float *value);

void slint_debug(const SharedString *string);

void slint_window_properties_get_title(const WindowProperties *wp, SharedString *out);

void slint_window_properties_get_background(const WindowProperties *wp, Brush *out);

bool slint_window_properties_get_fullscreen(const WindowProperties *wp);

bool slint_window_properties_get_minimized(const WindowProperties *wp);

bool slint_window_properties_get_maximized(const WindowProperties *wp);

LayoutConstraintsReprC slint_window_properties_get_layout_constraints(const WindowProperties *wp);

void slint_window_adapter_new(WindowAdapterUserData user_data,
                              void (*drop)(WindowAdapterUserData),
                              RendererPtr (*get_renderer_ref)(WindowAdapterUserData),
                              void (*set_visible)(WindowAdapterUserData, bool),
                              void (*request_redraw)(WindowAdapterUserData),
                              IntSize (*size)(WindowAdapterUserData),
                              void (*set_size)(WindowAdapterUserData, IntSize),
                              void (*update_window_properties)(WindowAdapterUserData,
                                                               const WindowProperties*),
                              bool (*position)(WindowAdapterUserData, Point2D<int32_t>*),
                              void (*set_position)(WindowAdapterUserData, Point2D<int32_t>),
                              WindowAdapterRcOpaque *target);

void slint_platform_register(PlatformUserData user_data,
                             void (*drop)(PlatformUserData),
                             void (*window_factory)(PlatformUserData, WindowAdapterRcOpaque*),
                             uint64_t (*duration_since_start)(PlatformUserData),
                             void (*set_clipboard_text)(PlatformUserData,
                                                        const SharedString*,
                                                        Clipboard),
                             bool (*clipboard_text)(PlatformUserData, SharedString*, Clipboard),
                             void (*run_event_loop)(PlatformUserData),
                             void (*quit_event_loop)(PlatformUserData),
                             void (*invoke_from_event_loop)(PlatformUserData, PlatformTaskOpaque));

bool slint_windowrc_has_active_animations(const WindowAdapterRcOpaque *handle);

void slint_platform_update_timers_and_animations();

/// Returns the duration in millisecond until the next timer or `u64::MAX` if there is no pending timers
uint64_t slint_platform_duration_until_next_timer_update();

void slint_platform_task_drop(PlatformTaskOpaque event);

void slint_platform_task_run(PlatformTaskOpaque event);

SoftwareRendererOpaque slint_software_renderer_new(uint32_t buffer_age);

void slint_software_renderer_drop(SoftwareRendererOpaque r);

PhysicalRegion slint_software_renderer_render_rgb8(SoftwareRendererOpaque r,
                                                   Rgb8Pixel *buffer,
                                                   uintptr_t buffer_len,
                                                   uintptr_t pixel_stride);

PhysicalRegion slint_software_renderer_render_rgb565(SoftwareRendererOpaque r,
                                                     uint16_t *buffer,
                                                     uintptr_t buffer_len,
                                                     uintptr_t pixel_stride);

PhysicalRegion slint_software_renderer_render_by_line_rgb565(SoftwareRendererOpaque r,
                                                             void (*process_line_fn)(void*,
                                                                                     uintptr_t,
                                                                                     uintptr_t,
                                                                                     uintptr_t,
                                                                                     void(*)(const void*,
                                                                                             uint16_t*,
                                                                                             uintptr_t),
                                                                                     const void*),
                                                             void *user_data);

void slint_software_renderer_set_rendering_rotation(SoftwareRendererOpaque r, int32_t rotation);

RendererPtr slint_software_renderer_handle(SoftwareRendererOpaque r);

void slint_software_renderer_region_to_rects(const PhysicalRegion *region,
                                             SharedVector<IntRect> *out);

CppRawHandleOpaque slint_new_raw_window_handle_win32(void *hwnd, void *_hinstance);

CppRawHandleOpaque slint_new_raw_window_handle_x11_xcb(uint32_t window,
                                                       uint32_t visual_id,
                                                       void *connection,
                                                       int screen);

CppRawHandleOpaque slint_new_raw_window_handle_x11_xlib(unsigned long window,
                                                        unsigned long visual_id,
                                                        void *display,
                                                        int screen);

CppRawHandleOpaque slint_new_raw_window_handle_wayland(void *surface, void *display);

CppRawHandleOpaque slint_new_raw_window_handle_appkit(void *ns_view, void *_ns_window);

void slint_raw_window_handle_drop(CppRawHandleOpaque handle);

SkiaRendererOpaque slint_skia_renderer_new(CppRawHandleOpaque handle_opaque, IntSize size);

void slint_skia_renderer_drop(SkiaRendererOpaque r);

void slint_skia_renderer_render(SkiaRendererOpaque r);

RendererPtr slint_skia_renderer_handle(SkiaRendererOpaque r);

extern void free(void *p);

extern void *malloc(uintptr_t size);

} // extern "C"

} // namespace cbindgen_private
} // namespace slint
