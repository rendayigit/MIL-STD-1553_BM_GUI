#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
#include "slint_internal.h"
#include "slint_interpreter_generated_public.h"

            namespace slint::cbindgen_private {
                struct Value;
                using slint::interpreter::ValueType;
                using slint::interpreter::PropertyDescriptor;
                using slint::interpreter::Diagnostic;
                template <typename T> using Box = T*;
            }

namespace slint {
namespace cbindgen_private {

/// ComponentCompiler is deprecated, use [`Compiler`] instead
struct ComponentCompiler;

struct ErasedItemTreeBox;

#if defined(SLINT_TARGET_64)
struct StructOpaque {
    uintptr_t _0[6];
};
#endif

#if defined(SLINT_TARGET_32)
struct StructOpaque {
    uint64_t _0[4];
};
#endif

#if defined(SLINT_TARGET_64)
struct ModelNotifyOpaque {
    uintptr_t _0[8];
};
#endif

#if defined(SLINT_TARGET_32)
struct ModelNotifyOpaque {
    uintptr_t _0[12];
};
#endif

struct ModelAdaptorVTable {
    uintptr_t (*row_count)(VRef<ModelAdaptorVTable>);
    Value *(*row_data)(VRef<ModelAdaptorVTable>, uintptr_t row);
    void (*set_row_data)(VRef<ModelAdaptorVTable>, uintptr_t row, Box<Value> value);
    const ModelNotifyOpaque *(*get_notify)(VRef<ModelAdaptorVTable>);
    void (*drop)(VRefMut<ModelAdaptorVTable>);
};

struct StructIteratorOpaque {
    uintptr_t _0[5];
};

struct ComponentDefinitionOpaque {
    uintptr_t _0[1];
};

using DynamicComponentVRc = VRc<ItemTreeVTable, ErasedItemTreeBox>;

/// This represent an instance of a dynamic component
///
/// You can create an instance with the [`ComponentDefinition::create`] function.
///
/// Properties and callback can be accessed using the associated functions.
///
/// An instance can be put on screen with the [`ComponentInstance::run`] function.
struct ComponentInstance {
    DynamicComponentVRc inner;
};

using ComponentCompilerOpaque = ComponentCompiler*;

extern "C" {

/// Construct a new Value in the given memory location
Box<Value> slint_interpreter_value_new();

/// Construct a new Value in the given memory location
Box<Value> slint_interpreter_value_clone(const Value *other);

/// Destruct the value in that memory location
void slint_interpreter_value_destructor(Box<Value> val);

bool slint_interpreter_value_eq(const Value *a, const Value *b);

/// Construct a new Value in the given memory location as string
Box<Value> slint_interpreter_value_new_string(const SharedString *str);

/// Construct a new Value in the given memory location as double
Box<Value> slint_interpreter_value_new_double(double double_);

/// Construct a new Value in the given memory location as bool
Box<Value> slint_interpreter_value_new_bool(bool b);

/// Construct a new Value in the given memory location as array model
Box<Value> slint_interpreter_value_new_array_model(const SharedVector<Box<Value>> *a);

/// Construct a new Value in the given memory location as Brush
Box<Value> slint_interpreter_value_new_brush(const Brush *brush);

/// Construct a new Value in the given memory location as Struct
Box<Value> slint_interpreter_value_new_struct(const StructOpaque *struc);

/// Construct a new Value in the given memory location as image
Box<Value> slint_interpreter_value_new_image(const Image *img);

/// Construct a new Value containing a model in the given memory location
Box<Value> slint_interpreter_value_new_model(uint8_t *model, const ModelAdaptorVTable *vtable);

ValueType slint_interpreter_value_type(const Value *val);

const SharedString *slint_interpreter_value_to_string(const Value *val);

const double *slint_interpreter_value_to_number(const Value *val);

const bool *slint_interpreter_value_to_bool(const Value *val);

/// Extracts a `SharedVector<ValueOpaque>` out of the given value `val`, writes that into the
/// `out` parameter and returns true; returns false if the value does not hold an extractable
/// array.
bool slint_interpreter_value_to_array(const Box<Value> *val, SharedVector<Box<Value>> *out);

const Brush *slint_interpreter_value_to_brush(const Value *val);

const StructOpaque *slint_interpreter_value_to_struct(const Value *val);

const Image *slint_interpreter_value_to_image(const Value *val);

/// Construct a new Struct in the given memory location
void slint_interpreter_struct_new(StructOpaque *val);

/// Construct a new Struct in the given memory location
void slint_interpreter_struct_clone(const StructOpaque *other, StructOpaque *val);

/// Destruct the struct in that memory location
void slint_interpreter_struct_destructor(StructOpaque *val);

Value *slint_interpreter_struct_get_field(const StructOpaque *stru, Slice<uint8_t> name);

void slint_interpreter_struct_set_field(StructOpaque *stru,
                                        Slice<uint8_t> name,
                                        const Value *value);

void slint_interpreter_struct_iterator_destructor(StructIteratorOpaque *val);

/// Advance the iterator and return the next value, or a null pointer
Value *slint_interpreter_struct_iterator_next(StructIteratorOpaque *iter, Slice<uint8_t> *k);

StructIteratorOpaque slint_interpreter_struct_make_iter(const StructOpaque *stru);

/// Get a property. Returns a null pointer if the property does not exist.
Value *slint_interpreter_component_instance_get_property(const ErasedItemTreeBox *inst,
                                                         Slice<uint8_t> name);

bool slint_interpreter_component_instance_set_property(const ErasedItemTreeBox *inst,
                                                       Slice<uint8_t> name,
                                                       const Value *val);

/// Invoke a callback or function. Returns raw boxed value on success and null ptr on failure.
Value *slint_interpreter_component_instance_invoke(const ErasedItemTreeBox *inst,
                                                   Slice<uint8_t> name,
                                                   Slice<Box<Value>> args);

/// Set a handler for the callback.
/// The `callback` function must initialize the `ret` (the `ret` passed to the callback is initialized and is assumed initialized after the function)
bool slint_interpreter_component_instance_set_callback(const ErasedItemTreeBox *inst,
                                                       Slice<uint8_t> name,
                                                       Box<Value> (*callback)(void *user_data,
                                                                              Slice<Box<Value>> arg),
                                                       void *user_data,
                                                       void (*drop_user_data)(void*));

/// Get a global property. Returns a raw boxed value on success; nullptr otherwise.
Value *slint_interpreter_component_instance_get_global_property(const ErasedItemTreeBox *inst,
                                                                Slice<uint8_t> global,
                                                                Slice<uint8_t> property_name);

bool slint_interpreter_component_instance_set_global_property(const ErasedItemTreeBox *inst,
                                                              Slice<uint8_t> global,
                                                              Slice<uint8_t> property_name,
                                                              const Value *val);

/// The `callback` function must initialize the `ret` (the `ret` passed to the callback is initialized and is assumed initialized after the function)
bool slint_interpreter_component_instance_set_global_callback(const ErasedItemTreeBox *inst,
                                                              Slice<uint8_t> global,
                                                              Slice<uint8_t> name,
                                                              Box<Value> (*callback)(void *user_data,
                                                                                     Slice<Box<Value>> arg),
                                                              void *user_data,
                                                              void (*drop_user_data)(void*));

/// Invoke a global callback or function. Returns raw boxed value on success; nullptr otherwise.
Value *slint_interpreter_component_instance_invoke_global(const ErasedItemTreeBox *inst,
                                                          Slice<uint8_t> global,
                                                          Slice<uint8_t> callable_name,
                                                          Slice<Box<Value>> args);

/// Show or hide
void slint_interpreter_component_instance_show(const ErasedItemTreeBox *inst, bool is_visible);

/// Return a window for the component
///
/// The out pointer must be uninitialized and must be destroyed with
/// slint_windowrc_drop after usage
void slint_interpreter_component_instance_window(const ErasedItemTreeBox *inst,
                                                 const WindowAdapterRcOpaque **out);

/// Instantiate an instance from a definition.
///
/// The `out` must be uninitialized and is going to be initialized after the call
/// and need to be destroyed with slint_interpreter_component_instance_destructor
void slint_interpreter_component_instance_create(const ComponentDefinitionOpaque *def,
                                                 ComponentInstance *out);

void slint_interpreter_component_instance_component_definition(const ErasedItemTreeBox *inst,
                                                               ComponentDefinitionOpaque *component_definition_ptr);

/// Construct a new ModelNotifyNotify in the given memory region
void slint_interpreter_model_notify_new(ModelNotifyOpaque *val);

/// Destruct the value in that memory location
void slint_interpreter_model_notify_destructor(ModelNotifyOpaque *val);

void slint_interpreter_model_notify_row_changed(const ModelNotifyOpaque *notify, uintptr_t row);

void slint_interpreter_model_notify_row_added(const ModelNotifyOpaque *notify,
                                              uintptr_t row,
                                              uintptr_t count);

void slint_interpreter_model_notify_reset(const ModelNotifyOpaque *notify);

void slint_interpreter_model_notify_row_removed(const ModelNotifyOpaque *notify,
                                                uintptr_t row,
                                                uintptr_t count);

void slint_interpreter_component_compiler_new(ComponentCompilerOpaque *compiler);

void slint_interpreter_component_compiler_destructor(ComponentCompilerOpaque *compiler);

void slint_interpreter_component_compiler_set_include_paths(ComponentCompilerOpaque *compiler,
                                                            const SharedVector<SharedString> *paths);

void slint_interpreter_component_compiler_set_style(ComponentCompilerOpaque *compiler,
                                                    Slice<uint8_t> style);

void slint_interpreter_component_compiler_set_translation_domain(ComponentCompilerOpaque *compiler,
                                                                 Slice<uint8_t> translation_domain);

void slint_interpreter_component_compiler_get_style(const ComponentCompilerOpaque *compiler,
                                                    SharedString *style_out);

void slint_interpreter_component_compiler_get_include_paths(const ComponentCompilerOpaque *compiler,
                                                            SharedVector<SharedString> *paths);

void slint_interpreter_component_compiler_get_diagnostics(const ComponentCompilerOpaque *compiler,
                                                          SharedVector<Diagnostic> *out_diags);

bool slint_interpreter_component_compiler_build_from_source(ComponentCompilerOpaque *compiler,
                                                            Slice<uint8_t> source_code,
                                                            Slice<uint8_t> path,
                                                            ComponentDefinitionOpaque *component_definition_ptr);

bool slint_interpreter_component_compiler_build_from_path(ComponentCompilerOpaque *compiler,
                                                          Slice<uint8_t> path,
                                                          ComponentDefinitionOpaque *component_definition_ptr);

/// Construct a new Value in the given memory location
void slint_interpreter_component_definition_clone(const ComponentDefinitionOpaque *other,
                                                  ComponentDefinitionOpaque *def);

/// Destruct the component definition in that memory location
void slint_interpreter_component_definition_destructor(ComponentDefinitionOpaque *val);

/// Returns the list of properties of the component the component definition describes
void slint_interpreter_component_definition_properties(const ComponentDefinitionOpaque *def,
                                                       SharedVector<PropertyDescriptor> *props);

/// Returns the list of callback names of the component the component definition describes
void slint_interpreter_component_definition_callbacks(const ComponentDefinitionOpaque *def,
                                                      SharedVector<SharedString> *callbacks);

/// Returns the list of function names of the component the component definition describes
void slint_interpreter_component_definition_functions(const ComponentDefinitionOpaque *def,
                                                      SharedVector<SharedString> *functions);

/// Return the name of the component definition
void slint_interpreter_component_definition_name(const ComponentDefinitionOpaque *def,
                                                 SharedString *name);

/// Returns a vector of strings with the names of all exported global singletons.
void slint_interpreter_component_definition_globals(const ComponentDefinitionOpaque *def,
                                                    SharedVector<SharedString> *names);

/// Returns a vector of the property descriptors of the properties of the specified publicly exported global
/// singleton. Returns true if a global exists under the specified name; false otherwise.
bool slint_interpreter_component_definition_global_properties(const ComponentDefinitionOpaque *def,
                                                              Slice<uint8_t> global_name,
                                                              SharedVector<PropertyDescriptor> *properties);

/// Returns a vector of the names of the callbacks of the specified publicly exported global
/// singleton. Returns true if a global exists under the specified name; false otherwise.
bool slint_interpreter_component_definition_global_callbacks(const ComponentDefinitionOpaque *def,
                                                             Slice<uint8_t> global_name,
                                                             SharedVector<SharedString> *names);

/// Returns a vector of the names of the functions of the specified publicly exported global
/// singleton. Returns true if a global exists under the specified name; false otherwise.
bool slint_interpreter_component_definition_global_functions(const ComponentDefinitionOpaque *def,
                                                             Slice<uint8_t> global_name,
                                                             SharedVector<SharedString> *names);

} // extern "C"

} // namespace cbindgen_private
} // namespace slint
