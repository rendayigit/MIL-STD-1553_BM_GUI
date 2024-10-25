#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
namespace slint { struct SharedString; }

namespace slint {
namespace cbindgen_private {

/// That's basically the same as `&'a [T]`  but `repr(C)`
///
/// Can be constructed from a slice using the from trait.
///
/// ```
/// use i_slint_core::slice::Slice;
/// let x = Slice::from_slice(&[1, 2, 3]);
/// assert_eq!(x.len(), 3);
/// assert_eq!(x[1], 2);
/// let slice : &'static [u32] = x.as_slice();
/// ```
///
/// Comparing two Slice compare their pointer, not the content.
/// ```
/// use i_slint_core::slice::Slice;
/// let a = Slice::from_slice(&[1, 2, 3]);
/// let slice = [1, 2, 3, 4];
/// let b = Slice::from(&slice[..3]);
/// // two slice coming from the same pointer are equal.
/// assert_eq!(b, Slice::from(&slice[..3]));
/// // these are different because the pointers are different
/// assert_ne!(a, b);
/// // use as_slice to compare the contents
/// assert_eq!(a.as_slice(), b.as_slice());
/// ```
template<typename T>
struct Slice {
    /// Invariant, this is a valid slice of len `len`
    T *ptr;
    uintptr_t len;
    const T &operator[](int i) const { return ptr[i]; }
        /// Note: this doesn't initialize Slice properly, but we need to keep the struct as compatible with C
        constexpr Slice() = default;
        /// Rust uses a NonNull, so even empty slices shouldn't use nullptr
        constexpr Slice(const T *ptr, uintptr_t len) : ptr(ptr ? const_cast<T*>(ptr) : reinterpret_cast<T*>(sizeof(T))), len(len) {}
        
};

extern "C" {

/// Returns a nul-terminated pointer for this string.
/// The returned value is owned by the string, and should not be used after any
/// mutable function have been called on the string, and must not be freed.
const char *slint_shared_string_bytes(const SharedString *ss);

/// Destroy the shared string
void slint_shared_string_drop(const SharedString *ss);

/// Increment the reference count of the string.
/// The resulting structure must be passed to slint_shared_string_drop
void slint_shared_string_clone(SharedString *out, const SharedString *ss);

/// Safety: bytes must be a valid utf-8 string of size len without null inside.
/// The resulting structure must be passed to slint_shared_string_drop
void slint_shared_string_from_bytes(SharedString *out, const char *bytes, uintptr_t len);

/// Create a string from a number.
/// The resulting structure must be passed to slint_shared_string_drop
void slint_shared_string_from_number(SharedString *out, double n);

/// Append some bytes to an existing shared string
///
/// bytes must be a valid utf8 array of size `len`, without null bytes inside
void slint_shared_string_append(SharedString *self_, const char *bytes, uintptr_t len);

} // extern "C"

} // namespace cbindgen_private
} // namespace slint
