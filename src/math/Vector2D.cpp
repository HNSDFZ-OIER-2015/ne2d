//
// Copyright 2015 riteme
//

#include "Vector2D.hpp"

#include "utility/FloatComparison.hpp"

namespace ne::math {
    Vector2D::Vector2D() : m_x(0.0f), m_y(0.0f) {}
    Vector2D::Vector2D(const ValueType &x, const ValueType &y)
            : m_x(x), m_y(y) {}

    Vector2D::Vector2D(const Vector2D &lhs) : m_x(lhs.X()), m_y(lhs.Y()) {}

    auto Vector2D::operator=(const Vector2D &lhs)->Vector2D & {
        m_x = lhs.X();
        m_y = lhs.Y();

        return *this;
    }

    Vector2D::Vector2D(Vector2D && rhs) : m_x(rhs.X()), m_y(rhs.Y()) {}

    auto Vector2D::operator=(Vector2D && rhs)->Vector2D & {
        m_x = rhs.X();
        m_y = rhs.Y();

        return *this;
    }

    auto Vector2D::X() const->ValueType { return m_x; }
    auto Vector2D::Y() const->ValueType { return m_y; }
    auto Vector2D::Z() const->ValueType { return 1; }

    auto Vector2D::X()->ValueType & { return m_x; }
    auto Vector2D::Y()->ValueType & { return m_y; }

    auto operator==(const Vector2D &a, const Vector2D &b)->Bool {
        return ne::utility::IsSame(a.X(), b.X()) &&
               ne::utility::IsSame(a.Y(), b.Y());
    }

    auto operator!=(const Vector2D &a, const Vector2D &b)->Bool {
        return !(a == b);
    }

    auto operator+(Vector2D a)->Vector2D { return a; }

    auto operator-(Vector2D a)->Vector2D {
        a *= -1;
        return a;
    }

    auto operator+(const Vector2D &a, const Vector2D &b)->Vector2D {
        return { a.X() + b.X(), a.Y() + b.Y() };
    }

    auto operator-(const Vector2D &a, const Vector2D &b)->Vector2D {
        return { a.X() - b.X(), a.Y() - b.Y() };
    }

    auto operator*(const Vector2D &a, const Vector2D::ValueType &b)->Vector2D {
        return { a.X() * b, a.Y() * b };
    }

    auto operator*(const Vector2D::ValueType &b, const Vector2D &a)->Vector2D {
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

    auto Vector2D::ToString() const->std::string {
        return ne::utility::Format("(X = {}, Y = {})", X(), Y());
    }

    auto Vector2D::HashCode() const->ne::SizeType {
        return static_cast<SizeType>(X() * Y()) /
               (static_cast<SizeType>(X()) % 31);
    }
}  // namespace ne
