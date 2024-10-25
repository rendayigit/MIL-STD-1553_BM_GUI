#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
namespace slint { class Color; class Brush; }

namespace slint {
namespace cbindgen_private {

using PropertyHandle = uintptr_t;

/// Has the same layout as PropertyHandle
struct PropertyHandleOpaque {
    PropertyHandle _0;

    bool operator==(const PropertyHandleOpaque& other) const {
        return _0 == other._0;
    }
    bool operator!=(const PropertyHandleOpaque& other) const {
        return _0 != other._0;
    }
};

/// Opaque type representing the PropertyTracker
struct PropertyTrackerOpaque {
    uintptr_t dependencies;
    uintptr_t dep_nodes;
    uintptr_t vtable;
    bool dirty;

    bool operator==(const PropertyTrackerOpaque& other) const {
        return dependencies == other.dependencies &&
               dep_nodes == other.dep_nodes &&
               vtable == other.vtable &&
               dirty == other.dirty;
    }
    bool operator!=(const PropertyTrackerOpaque& other) const {
        return dependencies != other.dependencies ||
               dep_nodes != other.dep_nodes ||
               vtable != other.vtable ||
               dirty != other.dirty;
    }
};

/// Has the same layout as Callback<_>
struct CallbackOpaque {
    const void *_0;
    const void *_1;

    bool operator==(const CallbackOpaque& other) const {
        return _0 == other._0 &&
               _1 == other._1;
    }
    bool operator!=(const CallbackOpaque& other) const {
        return _0 != other._0 ||
               _1 != other._1;
    }
};

extern "C" {

/// Initialize the first pointer of the Property. Does not initialize the content.
/// `out` is assumed to be uninitialized
void slint_property_init(PropertyHandleOpaque *out);

/// To be called before accessing the value
void slint_property_update(const PropertyHandleOpaque *handle, void *val);

/// Mark the fact that the property was changed and that its binding need to be removed, and
/// the dependencies marked dirty.
/// To be called after the `value` has been changed
void slint_property_set_changed(const PropertyHandleOpaque *handle, const void *value);

/// Set a binding
///
/// The current implementation will do usually two memory allocation:
///  1. the allocation from the calling code to allocate user_data
///  2. the box allocation within this binding
/// It might be possible to reduce that by passing something with a
/// vtable, so there is the need for less memory allocation.
void slint_property_set_binding(const PropertyHandleOpaque *handle,
                                void (*binding)(void *user_data, void *pointer_to_value),
                                void *user_data,
                                void (*drop_user_data)(void*),
                                bool (*intercept_set)(void *user_data, const void *pointer_to_Value),
                                bool (*intercept_set_binding)(void *user_data, void *new_binding));

/// Set a binding using an already allocated building holder
///
void slint_property_set_binding_internal(const PropertyHandleOpaque *handle, void *binding);

/// Returns whether the property behind this handle is marked as dirty
bool slint_property_is_dirty(const PropertyHandleOpaque *handle);

/// Marks the property as dirty and notifies dependencies.
void slint_property_mark_dirty(const PropertyHandleOpaque *handle);

/// Destroy handle
void slint_property_drop(PropertyHandleOpaque *handle);

/// Internal function to set up a property animation to the specified target value for an integer property.
void slint_property_set_animated_value_int(const PropertyHandleOpaque *handle,
                                           int32_t from,
                                           int32_t to,
                                           const PropertyAnimation *animation_data);

/// Internal function to set up a property animation to the specified target value for a float property.
void slint_property_set_animated_value_float(const PropertyHandleOpaque *handle,
                                             float from,
                                             float to,
                                             const PropertyAnimation *animation_data);

/// Internal function to set up a property animation to the specified target value for a color property.
void slint_property_set_animated_value_color(const PropertyHandleOpaque *handle,
                                             Color from,
                                             Color to,
                                             const PropertyAnimation *animation_data);

/// Internal function to set up a property animation to the specified target value for a brush property.
void slint_property_set_animated_value_brush(const PropertyHandleOpaque *handle,
                                             const Brush *from,
                                             const Brush *to,
                                             const PropertyAnimation *animation_data);

/// Internal function to set up a property animation between values produced by the specified binding for an integer property.
void slint_property_set_animated_binding_int(const PropertyHandleOpaque *handle,
                                             void (*binding)(void*, int*),
                                             void *user_data,
                                             void (*drop_user_data)(void*),
                                             const PropertyAnimation *animation_data,
                                             PropertyAnimation (*transition_data)(void *user_data,
                                                                                  uint64_t *start_instant));

/// Internal function to set up a property animation between values produced by the specified binding for a float property.
void slint_property_set_animated_binding_float(const PropertyHandleOpaque *handle,
                                               void (*binding)(void*, float*),
                                               void *user_data,
                                               void (*drop_user_data)(void*),
                                               const PropertyAnimation *animation_data,
                                               PropertyAnimation (*transition_data)(void *user_data,
                                                                                    uint64_t *start_instant));

/// Internal function to set up a property animation between values produced by the specified binding for a color property.
void slint_property_set_animated_binding_color(const PropertyHandleOpaque *handle,
                                               void (*binding)(void*, Color*),
                                               void *user_data,
                                               void (*drop_user_data)(void*),
                                               const PropertyAnimation *animation_data,
                                               PropertyAnimation (*transition_data)(void *user_data,
                                                                                    uint64_t *start_instant));

/// Internal function to set up a property animation between values produced by the specified binding for a brush property.
void slint_property_set_animated_binding_brush(const PropertyHandleOpaque *handle,
                                               void (*binding)(void*, Brush*),
                                               void *user_data,
                                               void (*drop_user_data)(void*),
                                               const PropertyAnimation *animation_data,
                                               PropertyAnimation (*transition_data)(void *user_data,
                                                                                    uint64_t *start_instant));

/// Internal function to set up a state binding on a Property<StateInfo>.
void slint_property_set_state_binding(const PropertyHandleOpaque *handle,
                                      int32_t (*binding)(void*),
                                      void *user_data,
                                      void (*drop_user_data)(void*));

/// Initialize the first pointer of the PropertyTracker.
/// `out` is assumed to be uninitialized
/// slint_property_tracker_drop need to be called after that
void slint_property_tracker_init(PropertyTrackerOpaque *out);

/// Call the callback with the user data. Any properties access within the callback will be registered.
/// Any currently evaluated bindings or property trackers will be notified if accessed properties are changed.
void slint_property_tracker_evaluate(const PropertyTrackerOpaque *handle,
                                     void (*callback)(void *user_data),
                                     void *user_data);

/// Call the callback with the user data. Any properties access within the callback will be registered.
/// Any currently evaluated bindings or property trackers will be not notified if accessed properties are changed.
void slint_property_tracker_evaluate_as_dependency_root(const PropertyTrackerOpaque *handle,
                                                        void (*callback)(void *user_data),
                                                        void *user_data);

/// Query if the property tracker is dirty
bool slint_property_tracker_is_dirty(const PropertyTrackerOpaque *handle);

/// Destroy handle
void slint_property_tracker_drop(PropertyTrackerOpaque *handle);

/// Construct a ChangeTracker
void slint_change_tracker_construct(ChangeTracker *ct);

/// Drop a ChangeTracker
void slint_change_tracker_drop(ChangeTracker *ct);

/// initialize the change tracker
void slint_change_tracker_init(const ChangeTracker *ct,
                               void *user_data,
                               void (*drop_user_data)(void *user_data),
                               bool (*eval_fn)(void *user_data),
                               void (*notify_fn)(void *user_data));

/// return the current animation tick for the `animation-tick` function
uint64_t slint_animation_tick();

/// Initialize the callback.
/// slint_callback_drop must be called.
void slint_callback_init(CallbackOpaque *out);

/// Emit the callback
void slint_callback_call(const CallbackOpaque *sig, const void *arg, void *ret);

/// Set callback handler.
///
/// The binding has signature fn(user_data)
void slint_callback_set_handler(const CallbackOpaque *sig,
                                void (*binding)(void *user_data, const void *arg, void *ret),
                                void *user_data,
                                void (*drop_user_data)(void*));

/// Destroy callback
void slint_callback_drop(CallbackOpaque *handle);

} // extern "C"

} // namespace cbindgen_private
} // namespace slint
