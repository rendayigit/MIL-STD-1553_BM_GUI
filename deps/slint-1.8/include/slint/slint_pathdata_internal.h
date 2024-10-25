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

/// PathMoveTo describes the event of setting the cursor on the path to use as starting
/// point for sub-sequent events, such as `LineTo`. Moving the cursor also implicitly closes
/// sub-paths and therefore beings a new sub-path.
struct PathMoveTo {
    /// The x coordinate where the current position should be.
    float x;
    /// The y coordinate where the current position should be.
    float y;

    bool operator==(const PathMoveTo& other) const {
        return x == other.x &&
               y == other.y;
    }
    bool operator!=(const PathMoveTo& other) const {
        return x != other.x ||
               y != other.y;
    }
};

/// PathLineTo describes the event of moving the cursor on the path to the specified location
/// along a straight line.
struct PathLineTo {
    /// The x coordinate where the line should go to.
    float x;
    /// The y coordinate where the line should go to.
    float y;

    bool operator==(const PathLineTo& other) const {
        return x == other.x &&
               y == other.y;
    }
    bool operator!=(const PathLineTo& other) const {
        return x != other.x ||
               y != other.y;
    }
};

/// PathArcTo describes the event of moving the cursor on the path across an arc to the specified
/// x/y coordinates, with the specified x/y radius and additional properties.
struct PathArcTo {
    /// The x coordinate where the arc should end up.
    float x;
    /// The y coordinate where the arc should end up.
    float y;
    /// The radius on the x-axis of the arc.
    float radius_x;
    /// The radius on the y-axis of the arc.
    float radius_y;
    /// The rotation along the x-axis of the arc in degrees.
    float x_rotation;
    /// large_arc indicates whether to take the long or the shorter path to complete the arc.
    bool large_arc;
    /// sweep indicates the direction of the arc. If true, a clockwise direction is chosen,
    /// otherwise counter-clockwise.
    bool sweep;

    bool operator==(const PathArcTo& other) const {
        return x == other.x &&
               y == other.y &&
               radius_x == other.radius_x &&
               radius_y == other.radius_y &&
               x_rotation == other.x_rotation &&
               large_arc == other.large_arc &&
               sweep == other.sweep;
    }
    bool operator!=(const PathArcTo& other) const {
        return x != other.x ||
               y != other.y ||
               radius_x != other.radius_x ||
               radius_y != other.radius_y ||
               x_rotation != other.x_rotation ||
               large_arc != other.large_arc ||
               sweep != other.sweep;
    }
};

/// PathCubicTo describes a smooth Bézier curve from the path's current position
/// to the specified x/y location, using two control points.
struct PathCubicTo {
    /// The x coordinate of the curve's end point.
    float x;
    /// The y coordinate of the curve's end point.
    float y;
    /// The x coordinate of the curve's first control point.
    float control_1_x;
    /// The y coordinate of the curve's first control point.
    float control_1_y;
    /// The x coordinate of the curve's second control point.
    float control_2_x;
    /// The y coordinate of the curve's second control point.
    float control_2_y;

    bool operator==(const PathCubicTo& other) const {
        return x == other.x &&
               y == other.y &&
               control_1_x == other.control_1_x &&
               control_1_y == other.control_1_y &&
               control_2_x == other.control_2_x &&
               control_2_y == other.control_2_y;
    }
    bool operator!=(const PathCubicTo& other) const {
        return x != other.x ||
               y != other.y ||
               control_1_x != other.control_1_x ||
               control_1_y != other.control_1_y ||
               control_2_x != other.control_2_x ||
               control_2_y != other.control_2_y;
    }
};

/// PathCubicTo describes a smooth Bézier curve from the path's current position
/// to the specified x/y location, using one control points.
struct PathQuadraticTo {
    /// The x coordinate of the curve's end point.
    float x;
    /// The y coordinate of the curve's end point.
    float y;
    /// The x coordinate of the curve's control point.
    float control_x;
    /// The y coordinate of the curve's control point.
    float control_y;

    bool operator==(const PathQuadraticTo& other) const {
        return x == other.x &&
               y == other.y &&
               control_x == other.control_x &&
               control_y == other.control_y;
    }
    bool operator!=(const PathQuadraticTo& other) const {
        return x != other.x ||
               y != other.y ||
               control_x != other.control_x ||
               control_y != other.control_y;
    }
};

/// PathElement describes a single element on a path, such as move-to, line-to, etc.
struct PathElement {
    enum class Tag {
        /// The MoveTo variant sets the current position on the path.
        MoveTo,
        /// The LineTo variant describes a line.
        LineTo,
        /// The PathArcTo variant describes an arc.
        ArcTo,
        /// The CubicTo variant describes a Bézier curve with two control points.
        CubicTo,
        /// The QuadraticTo variant describes a Bézier curve with one control point.
        QuadraticTo,
        /// Indicates that the path should be closed now by connecting to the starting point.
        Close,
    };

    struct MoveTo_Body {
        PathMoveTo _0;

        bool operator==(const MoveTo_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const MoveTo_Body& other) const {
            return _0 != other._0;
        }
    };

    struct LineTo_Body {
        PathLineTo _0;

        bool operator==(const LineTo_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const LineTo_Body& other) const {
            return _0 != other._0;
        }
    };

    struct ArcTo_Body {
        PathArcTo _0;

        bool operator==(const ArcTo_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ArcTo_Body& other) const {
            return _0 != other._0;
        }
    };

    struct CubicTo_Body {
        PathCubicTo _0;

        bool operator==(const CubicTo_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const CubicTo_Body& other) const {
            return _0 != other._0;
        }
    };

    struct QuadraticTo_Body {
        PathQuadraticTo _0;

        bool operator==(const QuadraticTo_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const QuadraticTo_Body& other) const {
            return _0 != other._0;
        }
    };

    Tag tag;
    union {
        MoveTo_Body move_to;
        LineTo_Body line_to;
        ArcTo_Body arc_to;
        CubicTo_Body cubic_to;
        QuadraticTo_Body quadratic_to;
    };

    static PathElement MoveTo(const PathMoveTo &_0) {
        PathElement result;
        ::new (&result.move_to._0) (PathMoveTo)(_0);
        result.tag = Tag::MoveTo;
        return result;
    }

    bool IsMoveTo() const {
        return tag == Tag::MoveTo;
    }

    static PathElement LineTo(const PathLineTo &_0) {
        PathElement result;
        ::new (&result.line_to._0) (PathLineTo)(_0);
        result.tag = Tag::LineTo;
        return result;
    }

    bool IsLineTo() const {
        return tag == Tag::LineTo;
    }

    static PathElement ArcTo(const PathArcTo &_0) {
        PathElement result;
        ::new (&result.arc_to._0) (PathArcTo)(_0);
        result.tag = Tag::ArcTo;
        return result;
    }

    bool IsArcTo() const {
        return tag == Tag::ArcTo;
    }

    static PathElement CubicTo(const PathCubicTo &_0) {
        PathElement result;
        ::new (&result.cubic_to._0) (PathCubicTo)(_0);
        result.tag = Tag::CubicTo;
        return result;
    }

    bool IsCubicTo() const {
        return tag == Tag::CubicTo;
    }

    static PathElement QuadraticTo(const PathQuadraticTo &_0) {
        PathElement result;
        ::new (&result.quadratic_to._0) (PathQuadraticTo)(_0);
        result.tag = Tag::QuadraticTo;
        return result;
    }

    bool IsQuadraticTo() const {
        return tag == Tag::QuadraticTo;
    }

    static PathElement Close() {
        PathElement result;
        result.tag = Tag::Close;
        return result;
    }

    bool IsClose() const {
        return tag == Tag::Close;
    }

    bool operator==(const PathElement& other) const {
        if (tag != other.tag) {
            return false;
        }
        switch (tag) {
            case Tag::MoveTo: return move_to == other.move_to;
            case Tag::LineTo: return line_to == other.line_to;
            case Tag::ArcTo: return arc_to == other.arc_to;
            case Tag::CubicTo: return cubic_to == other.cubic_to;
            case Tag::QuadraticTo: return quadratic_to == other.quadratic_to;
            default: break;
        }
        return true;
    }

    bool operator!=(const PathElement& other) const {
        return !(*this == other);
    }

    private:
    PathElement() {

    }
    public:


    ~PathElement() {
        switch (tag) {
            case Tag::MoveTo: move_to.~MoveTo_Body(); break;
            case Tag::LineTo: line_to.~LineTo_Body(); break;
            case Tag::ArcTo: arc_to.~ArcTo_Body(); break;
            case Tag::CubicTo: cubic_to.~CubicTo_Body(); break;
            case Tag::QuadraticTo: quadratic_to.~QuadraticTo_Body(); break;
            default: break;
        }
    }

    PathElement(const PathElement& other)
     : tag(other.tag) {
        switch (tag) {
            case Tag::MoveTo: ::new (&move_to) (MoveTo_Body)(other.move_to); break;
            case Tag::LineTo: ::new (&line_to) (LineTo_Body)(other.line_to); break;
            case Tag::ArcTo: ::new (&arc_to) (ArcTo_Body)(other.arc_to); break;
            case Tag::CubicTo: ::new (&cubic_to) (CubicTo_Body)(other.cubic_to); break;
            case Tag::QuadraticTo: ::new (&quadratic_to) (QuadraticTo_Body)(other.quadratic_to); break;
            default: break;
        }
    }
    PathElement& operator=(const PathElement& other) {
        if (this != &other) {
            this->~PathElement();
            new (this) PathElement(other);
        }
        return *this;
    }
};

/// Expand Point so that cbindgen can see it. ( is in fact euclid::default::Point2D<f32>)
struct Point {
    float x;
    float y;

    bool operator==(const Point& other) const {
        return x == other.x &&
               y == other.y;
    }
    bool operator!=(const Point& other) const {
        return x != other.x ||
               y != other.y;
    }
};

/// PathData represents a path described by either high-level elements or low-level
/// events and coordinates.
struct PathData {
    enum class Tag {
        /// None is the variant when the path is empty.
        None,
        /// The Elements variant is used to make a Path from shared arrays of elements.
        Elements,
        /// The Events variant describes the path as a series of low-level events and
        /// associated coordinates.
        Events,
        /// The Commands variant describes the path as a series of SVG encoded path commands.
        Commands,
    };

    struct Elements_Body {
        SharedVector<PathElement> _0;

        bool operator==(const Elements_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const Elements_Body& other) const {
            return _0 != other._0;
        }
    };

    struct Events_Body {
        SharedVector<PathEvent> _0;
        SharedVector<Point> _1;

        bool operator==(const Events_Body& other) const {
            return _0 == other._0 &&
                   _1 == other._1;
        }
        bool operator!=(const Events_Body& other) const {
            return _0 != other._0 ||
                   _1 != other._1;
        }
    };

    struct Commands_Body {
        SharedString _0;

        bool operator==(const Commands_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const Commands_Body& other) const {
            return _0 != other._0;
        }
    };

    Tag tag;
    union {
        Elements_Body elements;
        Events_Body events;
        Commands_Body commands;
    };

    static PathData None() {
        PathData result;
        result.tag = Tag::None;
        return result;
    }

    bool IsNone() const {
        return tag == Tag::None;
    }

    static PathData Elements(const SharedVector<PathElement> &_0) {
        PathData result;
        ::new (&result.elements._0) (SharedVector<PathElement>)(_0);
        result.tag = Tag::Elements;
        return result;
    }

    bool IsElements() const {
        return tag == Tag::Elements;
    }

    static PathData Events(const SharedVector<PathEvent> &_0,
                           const SharedVector<Point> &_1) {
        PathData result;
        ::new (&result.events._0) (SharedVector<PathEvent>)(_0);
        ::new (&result.events._1) (SharedVector<Point>)(_1);
        result.tag = Tag::Events;
        return result;
    }

    bool IsEvents() const {
        return tag == Tag::Events;
    }

    static PathData Commands(const SharedString &_0) {
        PathData result;
        ::new (&result.commands._0) (SharedString)(_0);
        result.tag = Tag::Commands;
        return result;
    }

    bool IsCommands() const {
        return tag == Tag::Commands;
    }

    bool operator==(const PathData& other) const {
        if (tag != other.tag) {
            return false;
        }
        switch (tag) {
            case Tag::Elements: return elements == other.elements;
            case Tag::Events: return events == other.events;
            case Tag::Commands: return commands == other.commands;
            default: break;
        }
        return true;
    }

    bool operator!=(const PathData& other) const {
        return !(*this == other);
    }

    private:
    PathData() {

    }
    public:


    ~PathData() {
        switch (tag) {
            case Tag::Elements: elements.~Elements_Body(); break;
            case Tag::Events: events.~Events_Body(); break;
            case Tag::Commands: commands.~Commands_Body(); break;
            default: break;
        }
    }

    PathData(const PathData& other)
     : tag(other.tag) {
        switch (tag) {
            case Tag::Elements: ::new (&elements) (Elements_Body)(other.elements); break;
            case Tag::Events: ::new (&events) (Events_Body)(other.events); break;
            case Tag::Commands: ::new (&commands) (Commands_Body)(other.commands); break;
            default: break;
        }
    }
    PathData& operator=(const PathData& other) {
        if (this != &other) {
            this->~PathData();
            new (this) PathData(other);
        }
        return *this;
    }
};

extern "C" {

#if !defined(SLINT_TARGET_WASM)
/// This function is used for the low-level C++ interface to allocate the backing vector for a shared path element array.
void slint_new_path_elements(void *out,
                             const PathElement *first_element,
                             uintptr_t count);
#endif

#if !defined(SLINT_TARGET_WASM)
/// This function is used for the low-level C++ interface to allocate the backing vector for a shared path event array.
void slint_new_path_events(void *out_events,
                           void *out_coordinates,
                           const PathEvent *first_event,
                           uintptr_t event_count,
                           const Point *first_coordinate,
                           uintptr_t coordinate_count);
#endif

} // extern "C"

} // namespace types
} // namespace cbindgen_private
} // namespace slint
