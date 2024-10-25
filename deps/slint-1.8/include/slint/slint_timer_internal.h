#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

namespace slint {
namespace cbindgen_private {

/// The TimerMode specifies what should happen after the timer fired.
///
/// Used by the [`Timer::start()`] function.
enum class TimerMode : uint8_t {
    /// A SingleShot timer is fired only once.
    SingleShot,
    /// A Repeated timer is fired repeatedly until it is stopped or dropped.
    Repeated,
};

extern "C" {

/// Start a timer with the given mode, duration in millisecond and callback. A timer id may be provided (first argument).
/// A value of -1 for the timer id means a new timer is to be allocated.
/// The (new) timer id is returned.
/// The timer MUST be destroyed with slint_timer_destroy.
uintptr_t slint_timer_start(uintptr_t id,
                            TimerMode mode,
                            uint64_t duration,
                            void (*callback)(void*),
                            void *user_data,
                            void (*drop_user_data)(void*));

/// Execute a callback with a delay in millisecond
void slint_timer_singleshot(uint64_t delay,
                            void (*callback)(void*),
                            void *user_data,
                            void (*drop_user_data)(void*));

/// Stop a timer and free its raw data
void slint_timer_destroy(uintptr_t id);

/// Stop a timer
void slint_timer_stop(uintptr_t id);

/// Restart a repeated timer
void slint_timer_restart(uintptr_t id);

/// Returns true if the timer is running; false otherwise.
bool slint_timer_running(uintptr_t id);

/// Returns the interval in milliseconds. 0 when the timer was never started.
uint64_t slint_timer_interval(uintptr_t id);

} // extern "C"

} // namespace cbindgen_private
} // namespace slint
