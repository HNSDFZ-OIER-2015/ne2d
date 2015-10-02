//
// Copyright 2015 riteme
//

#ifndef NE2D_VECTOR_HPP
#define NE2D_VECTOR_HPP

#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include <utility>
#include <cmath>
#include <algorithm>

namespace ne {

template <typename T>
struct BasicVector2D {
    NONCOMPARABLE(BasicVector2D)

    BasicVector2D(T x, T y) : X(x), Y(y) {}

    T X = 0.0f;
    T Y = 0.0f;

    typedef T ValueType;

    BasicVector2D(const BasicVector2D &lhs) {
        X = lhs.X;
        Y = lhs.Y;
    }
    BasicVector2D &operator=(const BasicVector2D &lhs) {
        X = lhs.X;
        Y = lhs.Y;

        return *this;
    }

    BasicVector2D(BasicVector2D &&rhs) {
        X = rhs.X;
        Y = rhs.Y;
    }
    BasicVector2D &operator=(BasicVector2D &&rhs) {
        X = rhs.X;
        Y = rhs.Y;

        return *this;
    }

    bool operator==(const BasicVector2D &lhs) { return X == lhs.X && Y == lhs.Y; }

    bool operator!=(const BasicVector2D &lhs) { return !((*this) == lhs); }

    BasicVector2D operator+(const BasicVector2D &lhs) { return { X + lhs.X, Y + lhs.Y }; }
    BasicVector2D operator-(const BasicVector2D &lhs) { return { X - lhs.X, Y - lhs.Y }; }
    BasicVector2D operator+() { return *this; }
    BasicVector2D operator-() { return { -X, -Y }; }
    BasicVector2D operator*(const T &lhs) { return { X * lhs, Y * lhs }; }
    BasicVector2D operator/(const T &lhs) { return { X / lhs, Y / lhs }; }
    T operator*(const BasicVector2D &lhs) { return Dot(*this, lhs); }
    T operator&(const BasicVector2D &lhs) { return Cross(*this, lhs); }

    BasicVector2D &operator+=(const BasicVector2D &lhs) {
        X += lhs.X;
        Y += lhs.Y;

        return *this;
    }

    BasicVector2D &operator-=(const BasicVector2D &lhs) {
        X -= lhs.X;
        Y -= lhs.Y;

        return *this;
    }

    BasicVector2D &operator*=(const T &lhs) {
        X *= lhs;
        Y *= lhs;

        return *this;
    }

    BasicVector2D &operator/=(const T &lhs) {
        X /= lhs;
        Y /= lhs;

        return *this;
    }
};  // struct BasicVector2D

typedef BasicVector2D<FloatType> Vector2D;

template <typename TVector>
TVector Abs(const TVector &vec) {
    return { std::abs(vec.X), std::abs(vec.Y) };
}

template <typename TVector>
typename TVector::ValueType Length(const TVector &vec) {
    return std::sqrt(vec.X * vec.X + vec.Y * vec.Y);
}

template <typename TVector>
typename TVector::ValueType Dot(const TVector &vec1, const TVector &vec2) {
    return vec1.X * vec2.X + vec1.Y * vec2.Y;
}

template <typename TVector>
typename TVector::ValueType Cross(const TVector &vec1, const TVector &vec2) {
    return vec1.X * vec2.Y - vec2.X * vec1.Y;
}

template <typename TVector>
TVector Add(const TVector &vec1, const TVector &vec2) {
    return vec1 + vec2;
}

template <typename TVector>
TVector Subtract(const TVector &vec1, const TVector &vec2) {
    return vec1 - vec2;
}

template <typename TVector>
TVector Sacle(const TVector &vec, const typename TVector::ValueType scale) {
    return vec * scale;
}

template <typename TVector>
TVector Max(const TVector &vec1, const TVector &vec2) {
    return { std::max(vec1.X, vec2.X), std::max(vec1.Y, vec2.Y) };
}

template <typename TVector>
TVector Min(const TVector &vec1, const TVector &vec2) {
    return { std::min(vec1.X, vec2.X), std::min(vec1.Y, vec2.Y) };
}

template <typename TVector>
TVector Rotate(const TVector &vec, const TVector &rotate, const typename TVector::ValueType angle) {
    TVector result;

    auto cosAngle = std::cos(angle);
    auto sinAngle = std::sin(angle);

    auto distanceX = vec.X - rotate.X;
    auto distanceY = vec.Y - rotate.Y;

    result.X = cosAngle * distanceX - sinAngle * distanceY + rotate.X;
    result.Y = sinAngle * distanceX + cosAngle * distanceY + rotate.Y;

    return result;
}

template <typename TVector>
TVector Normalize(const TVector &vec) {
    return vec / Length(vec);
}

template <typename TVector>
TVector Lerp(const TVector &start, const TVector &end,
             const typename TVector::ValueType percentage) {
    return (end - start) * percentage + start;
}

}  // namespace ne

#endif  // NE2D_VECTOR_HPP
