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

namespace ne::math {

    /**
     * 二维向量的基本结构
     * 可以指定数据的类型
     * @remark:
     *     其中Z仅用于辅助与矩阵运算，
     *     不会参与二维向量的运算和比较运算
     */
    struct Vector2D : public ne::IObject {
        NONCOMPARABLE(Vector2D)

        typedef Float ValueType;

        Vector2D() : m_x(0.0f), m_y(0.0f) {}
        Vector2D(const ValueType &x, const ValueType &y) : m_x(x), m_y(y) {}

        Vector2D(const Vector2D &lhs) : m_x(lhs.X()), m_y(lhs.Y()) {}
        auto operator=(const Vector2D &lhs) -> Vector2D & {
            m_x = lhs.X();
            m_y = lhs.Y();

            return *this;
        }

        Vector2D(Vector2D &&rhs) : m_x(rhs.X()), m_y(rhs.Y()) {}
        auto operator=(Vector2D &&rhs) -> Vector2D & {
            m_x = rhs.X();
            m_y = rhs.Y();

            return *this;
        }

        auto X() const -> ValueType { return m_x; }
        auto Y() const -> ValueType { return m_y; }
        auto Z() const -> ValueType { return 1; }

        auto X() -> ValueType & { return m_x; }
        auto Y() -> ValueType & { return m_y; }

        friend auto operator==(const Vector2D &a, const Vector2D &b) -> bool;
        friend auto operator!=(const Vector2D &a, const Vector2D &b) -> bool;

        friend auto operator+(const Vector2D a) -> Vector2D;
        friend auto operator-(const Vector2D a) -> Vector2D;

        friend auto operator+(const Vector2D &a, const Vector2D &lhs)
            -> Vector2D;
        friend auto operator-(const Vector2D &a, const Vector2D &lhs)
            -> Vector2D;

        friend auto operator*(const Vector2D &a, const ValueType &lhs)
            -> Vector2D;
        friend auto operator/(const Vector2D &a, const ValueType &lhs)
            -> Vector2D;

        friend auto operator*(const Vector2D &a, const Vector2D &lhs)
            -> ValueType;
        friend auto operator%(const Vector2D &a, const Vector2D &lhs)
            -> ValueType;

        friend auto operator+=(Vector2D &a, const Vector2D &lhs) -> Vector2D &;
        friend auto operator-=(Vector2D &a, const Vector2D &lhs) -> Vector2D &;

        friend auto operator*=(Vector2D &a, const ValueType &lhs) -> Vector2D &;
        friend auto operator/=(Vector2D &a, const ValueType &lhs) -> Vector2D &;

        virtual auto ToString() const -> std::string {
            // (X = $X, Y = $Y)

            return ne::utility::Format("(X = {}, Y = {})", X(), Y());
        }

        virtual auto HashCode() const -> ne::SizeType {
            return static_cast<SizeType>(X() * Y()) /
                   (static_cast<SizeType>(X()) % 31);
        }

     private:
        ValueType m_x;
        ValueType m_y;
    };  // struct Vector2D

    auto operator==(const Vector2D &a, const Vector2D &b)->bool {
        return ne::utility::IsSame(a.X(), b.X()) &&
               ne::utility::IsSame(a.Y(), b.Y());
    }

    auto operator!=(const Vector2D &a, const Vector2D &b)->bool {
        return !(a == b);
    }

    auto operator+(const Vector2D a)->Vector2D { return a; }

    auto operator-(const Vector2D a)->Vector2D { return { -a.X(), -a.Y() }; }

    auto operator+(const Vector2D &a, const Vector2D &b)->Vector2D {
        return { a.X() + b.X(), a.Y() + b.Y() };
    }

    auto operator-(const Vector2D &a, const Vector2D &b)->Vector2D {
        return { a.X() - b.X(), a.Y() - b.Y() };
    }

    auto operator*(const Vector2D &a, const Vector2D::ValueType &b)->Vector2D {
        return { a.X() * b, a.Y() * b };
    }

    auto operator/(const Vector2D &a, const Vector2D::ValueType &b)->Vector2D {
        return { a.X() / b, a.Y() / b };
    }

    auto operator*(const Vector2D &a, const Vector2D &b)->Vector2D::ValueType {
        return a.X() * b.X() + a.Y() * b.Y();
    }

    auto operator%(const Vector2D &a, const Vector2D &b)->Vector2D::ValueType {
        return a.X() * b.Y() - b.X() * a.Y();
    }

    auto operator+=(Vector2D & a, const Vector2D &b)->Vector2D & {
        a.X() += b.X();
        a.Y() += b.Y();

        return a;
    }

    auto operator-=(Vector2D & a, const Vector2D &b)->Vector2D & {
        a.X() -= b.X();
        a.Y() -= b.Y();

        return a;
    }

    auto operator*=(Vector2D & a, const Vector2D::ValueType &b)->Vector2D & {
        a.X() *= b;
        a.Y() *= b;

        return a;
    }

    auto operator/=(Vector2D & a, const Vector2D::ValueType &b)->Vector2D & {
        a.X() /= b;
        a.Y() /= b;

        return a;
    }

}  // namespace ne

#endif  // NE2D_VECTOR_HPP_
