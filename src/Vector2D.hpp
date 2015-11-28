//
// Copyright 2015 riteme
//

#ifndef NE2D_VECTOR_HPP_
#define NE2D_VECTOR_HPP_

#include <cmath>

#include <stdexcept>
#include <algorithm>
#include <limits>

#include "StringFormat.hpp"
#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"
#include "FloatComparison.hpp"

namespace ne {

/**
 * 二维向量的基本结构
 * 可以指定数据的类型
 * @remark:
 *     其中Z仅用于辅助与矩阵运算，
 *     不会参与二维向量的运算和比较运算
 */
template <typename T>
struct BasicVector2D : public ne::IObject {
    NONCOMPARABLE(BasicVector2D)

    typedef T ValueType;

    BasicVector2D() : X(0.0f), Y(0.0f), Z(1.0f) {}
    BasicVector2D(const ValueType x, const ValueType y) : X(x), Y(y), Z(1.0f) {}
    BasicVector2D(const ValueType x, const ValueType y, const ValueType z)
            : X(x), Y(y), Z(z) {}

    ValueType X;
    ValueType Y;
    ValueType Z;

    BasicVector2D(const BasicVector2D &lhs) : X(lhs.X), Y(lhs.Y), Z(lhs.Z) {}
    auto operator=(const BasicVector2D &lhs) -> BasicVector2D & {
        X = lhs.X;
        Y = lhs.Y;
        Z = lhs.Z;

        return *this;
    }

    BasicVector2D(BasicVector2D &&rhs) : X(rhs.X), Y(rhs.Y), Z(rhs.Z) {}
    auto operator=(BasicVector2D &&rhs) -> BasicVector2D & {
        X = rhs.X;
        Y = rhs.Y;
        Z = rhs.Z;

        return *this;
    }

    auto operator==(const BasicVector2D &lhs) const -> bool {
        return IsSame(X, lhs.X) && IsSame(Y, lhs.Y);
    }

    auto operator!=(const BasicVector2D &lhs) const -> bool {
        return !((*this) == lhs);
    }

    auto operator+(const BasicVector2D &lhs) const -> BasicVector2D {
        return { X + lhs.X, Y + lhs.Y };
    }

    auto operator-(const BasicVector2D &lhs) const -> BasicVector2D {
        return { X - lhs.X, Y - lhs.Y };
    }

    auto operator+() const -> BasicVector2D { return *this; }
    auto operator-() const -> BasicVector2D { return { -X, -Y }; }

    auto operator*(const T &lhs) const -> BasicVector2D {
        return { X * lhs, Y * lhs };
    }

    auto operator/(const T &lhs) const -> BasicVector2D {
        return { X / lhs, Y / lhs };
    }

    auto operator*(const BasicVector2D &lhs) const -> T {
        return X * lhs.X + Y * lhs.Y;
    }

    auto operator%(const BasicVector2D &lhs) const -> T {
        return X * lhs.Y - lhs.X * Y;
    }

    auto operator+=(const BasicVector2D &lhs) -> BasicVector2D & {
        X += lhs.X;
        Y += lhs.Y;

        return *this;
    }

    auto operator-=(const BasicVector2D &lhs) -> BasicVector2D & {
        X -= lhs.X;
        Y -= lhs.Y;

        return *this;
    }

    auto operator*=(const T &lhs) -> BasicVector2D & {
        X *= lhs;
        Y *= lhs;

        return *this;
    }

    auto operator/=(const T &lhs) -> BasicVector2D & {
        X /= lhs;
        Y /= lhs;

        return *this;
    }

    virtual auto ToString() const -> std::string {
        // (X = $X, Y = $Y)

        return ne::Format("(X = {}, Y = {})", X, Y);
    }

    virtual auto HashCode() const -> ne::SizeType {
        return static_cast<SizeType>(X * Y) / (static_cast<SizeType>(X) % 31);
    }
};  // struct BasicVector2D

/**
 * 单精度浮点数的模板特化
 */
typedef BasicVector2D<Float> Vector2D;

}  // namespace ne

#endif  // NE2D_VECTOR_HPP_
