//
// Copyright 2015 riteme
//

#ifndef NE2D_RECTANGLE_HPP_
#define NE2D_RECTANGLE_HPP_

#include <string>

#include "Vector.hpp"
#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"
#include "StringFormat.hpp"

namespace ne {

// TODO(riteme): Complete Rectangle structure and its unittest.

/**
 * 表示一个矩形
 */
template <typename T>
struct BasicRectangle : public IObject {
    NONCOMPARABLE(BasicRectangle)

    typedef T ValueType;
    typedef BasicVector2D<T> VectorType;

    BasicRectangle() : Position(), Size() {}
    BasicRectangle(const VectorType &position, const VectorType &size)
            : Position(position), Size(size) {}
    BasicRectangle(const ValueType x, const ValueType y, const ValueType w,
                   const ValueType h)
            : Position(x, y), Size(w, h) {}

    BasicVector2D<T> Position;
    BasicVector2D<T> Size;

    ValueType X() const { return Position.X; }
    ValueType Y() const { return Position.Y; }
    ValueType Width() const { return Size.X; }
    ValueType Height() const { return Size.Y; }

    // 可做左值
    ValueType &X() { return Position.X; }
    ValueType &Y() { return Position.Y; }
    ValueType &Width() { return Size.X; }
    ValueType &Height() { return Size.Y; }

    ValueType Top() const { return Position.Y; }
    ValueType Bottom() const { return Position.Y + Size.Y; }
    ValueType Left() const { return Position.X; }
    ValueType Right() const { return Position.X + Size.X; }

    VectorType LeftTop() const { return Position; }
    VectorType RightTop() const {
        return VectorType(Position.X + Size.X, Position.Y);
    }
    VectorType LeftBottom() const {
        return VectorType(Position.X, Position.Y + Size.Y);
    }
    VectorType RightBottom() const { return Position + Size; }

    // TODO(riteme): Complete this.
    bool Contain(const ValueType x, const ValueType y) const;
    bool Contain(const VectorType &vec) const;
    bool Contain(const BasicRectangle &rect) const;

    BasicRectangle(const BasicRectangle &lhs)
            : Position(lhs.Position), Size(lhs.Size) {}
    BasicRectangle &operator=(const BasicRectangle &lhs) {
        Position = lhs.Position;
        Size = lhs.Size;

        return *this;
    }

    BasicRectangle(BasicRectangle &&rhs)
            : Position(rhs.Position), Size(rhs.Size) {}
    BasicRectangle &operator=(BasicRectangle &&rhs) {
        Position = rhs.Position;
        Size = rhs.Size;

        return *this;
    }

    bool operator==(const BasicRectangle &lhs) const {
        return Position == lhs.Position && Size == lhs.Size;
    }

    bool operator!=(const BasicRectangle &lhs) const {
        return !((*this) == lhs);
    }

    virtual std::string ToString() const {
        // (X, Y, W, H)
        VectorType vectorDifference = Size - Position;
        return Format("({}, {}, {}, {})", Position.X, Position.Y,
                      vectorDifference.X, vectorDifference.Y);
    }

    virtual SizeType HashCode() const {
        return Position.HashCode() + Size.HashCode() % 31;
    }
};  // struct BasicRectangle

typedef BasicRectangle<Float> Rectangle;

// TODO(riteme): Add helper functions.

}  // namespace ne

#endif  // NE2D_RECTANGLE_HPP_
