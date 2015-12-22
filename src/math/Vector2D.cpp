//
// Copyright 2015 riteme
//

#include "Vector2D.hpp"

#include "utility/FloatComparison.hpp"

namespace ne::math {

    auto Vector2D::X() const->ValueType { return m_x; }
    auto Vector2D::Y() const->ValueType { return m_y; }
    auto Vector2D::Z() const->ValueType { return 1; }

    auto Vector2D::X()->ValueType & { return m_x; }
    auto Vector2D::Y()->ValueType & { return m_y; }

    auto operator==(const Vector2D &a, const Vector2D &b)->bool {
        return ne::utility::IsSame(a.X(), b.X()) &&
               ne::utility::IsSame(a.Y(), b.Y());
    }

    auto operator!=(const Vector2D &a, const Vector2D &b)->bool {
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

}  // namespace ne
