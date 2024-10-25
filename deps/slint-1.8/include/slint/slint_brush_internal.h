#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
#include "slint_enums_internal.h"

namespace slint {
namespace cbindgen_private {
namespace types {

/// GradientStop describes a single color stop in a gradient. The colors between multiple
/// stops are interpolated.
struct GradientStop {
    /// The color to draw at this stop.
    Color color;
    /// The position of this stop on the entire shape, as a normalized value between 0 and 1.
    float position;

    bool operator==(const GradientStop& other) const {
        return color == other.color &&
               position == other.position;
    }
    bool operator!=(const GradientStop& other) const {
        return color != other.color ||
               position != other.position;
    }
};

/// The LinearGradientBrush describes a way of filling a shape with different colors, which
/// are interpolated between different stops. The colors are aligned with a line that's rotated
/// by the LinearGradient's angle.
using LinearGradientBrush = SharedVector<GradientStop>;

/// The RadialGradientBrush describes a way of filling a shape with a circular gradient
using RadialGradientBrush = SharedVector<GradientStop>;

/// A brush is a data structure that is used to describe how
/// a shape, such as a rectangle, path or even text, shall be filled.
/// A brush can also be applied to the outline of a shape, that means
/// the fill of the outline itself.
struct Brush {
    enum class Tag {
        /// The color variant of brush is a plain color that is to be used for the fill.
        SolidColor,
        /// The linear gradient variant of a brush describes the gradient stops for a fill
        /// where all color stops are along a line that's rotated by the specified angle.
        LinearGradient,
        /// The radial gradient variant of a brush describes a circle variant centered
        /// in the middle
        RadialGradient,
    };

    struct SolidColor_Body {
        Color _0;

        bool operator==(const SolidColor_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const SolidColor_Body& other) const {
            return _0 != other._0;
        }
    };

    struct LinearGradient_Body {
        LinearGradientBrush _0;

        bool operator==(const LinearGradient_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const LinearGradient_Body& other) const {
            return _0 != other._0;
        }
    };

    struct RadialGradient_Body {
        RadialGradientBrush _0;

        bool operator==(const RadialGradient_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const RadialGradient_Body& other) const {
            return _0 != other._0;
        }
    };

    Tag tag;
    union {
        SolidColor_Body solid_color;
        LinearGradient_Body linear_gradient;
        RadialGradient_Body radial_gradient;
    };

    static Brush SolidColor(const Color &_0) {
        Brush result;
        ::new (&result.solid_color._0) (Color)(_0);
        result.tag = Tag::SolidColor;
        return result;
    }

    bool IsSolidColor() const {
        return tag == Tag::SolidColor;
    }

    static Brush LinearGradient(const LinearGradientBrush &_0) {
        Brush result;
        ::new (&result.linear_gradient._0) (LinearGradientBrush)(_0);
        result.tag = Tag::LinearGradient;
        return result;
    }

    bool IsLinearGradient() const {
        return tag == Tag::LinearGradient;
    }

    static Brush RadialGradient(const RadialGradientBrush &_0) {
        Brush result;
        ::new (&result.radial_gradient._0) (RadialGradientBrush)(_0);
        result.tag = Tag::RadialGradient;
        return result;
    }

    bool IsRadialGradient() const {
        return tag == Tag::RadialGradient;
    }

    bool operator==(const Brush& other) const {
        if (tag != other.tag) {
            return false;
        }
        switch (tag) {
            case Tag::SolidColor: return solid_color == other.solid_color;
            case Tag::LinearGradient: return linear_gradient == other.linear_gradient;
            case Tag::RadialGradient: return radial_gradient == other.radial_gradient;

        }
        return true;
    }

    bool operator!=(const Brush& other) const {
        return !(*this == other);
    }

    private:
    Brush() {

    }
    public:


    ~Brush() {
        switch (tag) {
            case Tag::SolidColor: solid_color.~SolidColor_Body(); break;
            case Tag::LinearGradient: linear_gradient.~LinearGradient_Body(); break;
            case Tag::RadialGradient: radial_gradient.~RadialGradient_Body(); break;

        }
    }

    Brush(const Brush& other)
     : tag(other.tag) {
        switch (tag) {
            case Tag::SolidColor: ::new (&solid_color) (SolidColor_Body)(other.solid_color); break;
            case Tag::LinearGradient: ::new (&linear_gradient) (LinearGradient_Body)(other.linear_gradient); break;
            case Tag::RadialGradient: ::new (&radial_gradient) (RadialGradient_Body)(other.radial_gradient); break;

        }
    }
    Brush& operator=(const Brush& other) {
        if (this != &other) {
            this->~Brush();
            new (this) Brush(other);
        }
        return *this;
    }
};

} // namespace types
} // namespace cbindgen_private
} // namespace slint
