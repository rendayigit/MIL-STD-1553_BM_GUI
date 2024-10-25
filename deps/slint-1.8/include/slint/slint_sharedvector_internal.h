#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
namespace slint { template<typename T> struct SharedVector; }

namespace slint {
namespace cbindgen_private {

extern "C" {

/// This function is used for the low-level C++ interface to allocate the backing vector of a SharedVector.
uint8_t *slint_shared_vector_allocate(uintptr_t size,
                                      uintptr_t align);

/// This function is used for the low-level C++ interface to deallocate the backing vector of a SharedVector
void slint_shared_vector_free(uint8_t *ptr,
                              uintptr_t size,
                              uintptr_t align);

/// This function is used for the low-level C++ interface to initialize the empty SharedVector.
const uint8_t *slint_shared_vector_empty();

} // extern "C"

} // namespace cbindgen_private
} // namespace slint
