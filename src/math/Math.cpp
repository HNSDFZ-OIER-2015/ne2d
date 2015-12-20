//
// Copyright 2015 riteme
//

#include <cmath>

#include "Math.hpp"

namespace ne::math {
    auto Abs(const Vector2D &vec) noexcept->Vector2D {
        return { std::abs(vec.X()), std::abs(vec.Y()) };
    }

    auto Length(const Vector2D &vec) noexcept->typename Vector2D::ValueType {
        return std::hypot(vec.X(), vec.Y());
    }

    auto DotMultiply(const Vector2D &vec1, const Vector2D &vec2) noexcept->
        typename Vector2D::ValueType {
        return vec1 * vec2;
    }

    auto CrossMultiply(const Vector2D &vec1, const Vector2D &vec2) noexcept->
        typename Vector2D::ValueType {
        return vec1 % vec2;
    }

    auto Max(const Vector2D &vec1, const Vector2D &vec2) noexcept->Vector2D {
        return { std::max(vec1.X(), vec2.X()), std::max(vec1.Y(), vec2.Y()) };
    }

    auto Min(const Vector2D &vec1, const Vector2D &vec2) noexcept->Vector2D {
        return { std::min(vec1.X(), vec2.X()), std::min(vec1.Y(), vec2.Y()) };
    }

    auto Rotate(const Vector2D &vec, const Vector2D &offest,
                const typename Vector2D::ValueType &angle) noexcept->Vector2D {
        Vector2D result;

        auto cosAngle = std::cos(angle * M_PI / 180.0);
        auto sinAngle = std::sin(angle * M_PI / 180.0);

        auto distanceX = vec.X() - offest.X();
        auto distanceY = vec.Y() - offest.Y();

        result.X() = cosAngle * distanceX - sinAngle * distanceY + offest.X();
        result.Y() = sinAngle * distanceX + cosAngle * distanceY + offest.Y();

        return result;
    }

    auto Normalize(const Vector2D &vec)->Vector2D {
        auto length = Length(vec);

        if (length == 0.0)
            throw std::invalid_argument("vec");
        else
            return vec / length;
    }

    auto Lerp(
        const Vector2D &start, const Vector2D &end,
        const typename Vector2D::ValueType &percentage) noexcept->Vector2D {
        return (end - start) * percentage + start;
    }

    auto ZeroMatrix() noexcept->Matrix3 { return Matrix3(); }

    auto IdentityMatrix() noexcept->Matrix3 {
        return Matrix3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    }

    auto TranslateMatrix(const Matrix3::ValueType &dx,
                         const Matrix3::ValueType &dy) noexcept->Matrix3 {
        return { 1.0, 0.0, dx, 0.0, 1.0, dy, 0.0, 0.0, 1.0 };
    }

    auto TranslateMatrix(
        const Matrix3 &mat,
        const typename Matrix3::ValueType &dx,
        const typename Matrix3::ValueType &dy) noexcept->Matrix3 {
        return TranslateMatrix(dx, dy) * mat;
    }

    auto ScaleMatrix(const Matrix3::ValueType &sx,
                     const Matrix3::ValueType &sy) noexcept->Matrix3 {
        return { sx, 0.0, 0.0, 0.0, sy, 0.0, 0.0, 0.0, 1.0 };
    }

    auto ScaleMatrix(const Matrix3 &mat,
                     const typename Matrix3::ValueType &sx,
                     const typename Matrix3::ValueType &sy) noexcept->Matrix3 {
        return ScaleMatrix(sx, sy) * mat;
    }

    auto RotateMatrix(const Matrix3::ValueType &angle) noexcept->Matrix3 {
        auto r = ToRadians(-angle);
        return { std::cos(r), -std::sin(r), 0.0, std::sin(r), std::cos(r),
                 0.0,         0.0,          0.0, 1.0 };
    }

    auto RotateMatrix(
        const Matrix3 &mat,
        const typename Matrix3::ValueType &angle) noexcept->Matrix3 {
        return RotateMatrix(angle) * mat;
    }

    auto Transpose(const Matrix3 &mat) noexcept->Matrix3 {
        auto tmp = mat;
        tmp.Transpose();

        return tmp;
    }

    auto FromTwoVector(const Vector2D &vec1,
                       const Vector2D &vec2) noexcept->Rectangle {
        return Rectangle(Min(vec1, vec2), Max(vec1, vec2) - Min(vec1, vec2));
    }

    auto FromLTRB(const Rectangle::ValueType &left,
                  const Rectangle::ValueType &top,
                  const Rectangle::ValueType &right,
                  const Rectangle::ValueType &bottom) noexcept->Rectangle {
        return Rectangle(left, top, right - left, bottom - top);
    }

    auto Intersect(const Rectangle &rect1,
                   const Rectangle &rect2) noexcept->Rectangle {
        Rectangle::ValueType nx1 = std::max(rect1.Left(), rect2.Left());
        Rectangle::ValueType ny1 = std::max(rect1.Top(), rect2.Top());
        Rectangle::ValueType nx2 = std::min(rect1.Right(), rect2.Right());
        Rectangle::ValueType ny2 = std::min(rect1.Bottom(), rect2.Bottom());

        // 需先确定相交矩形是否存在
        if (nx1 > nx2 and ny1 > ny2)
            return Rectangle();  // 返回空矩形
        else
            return FromLTRB(nx1, ny1, nx2, ny2);
    }

    auto Union(const Rectangle &rect1,
               const Rectangle &rect2) noexcept->Rectangle {
        Rectangle::ValueType nx1 = std::min(rect1.Left(), rect2.Left());
        Rectangle::ValueType ny1 = std::min(rect1.Top(), rect2.Top());
        Rectangle::ValueType nx2 = std::max(rect1.Right(), rect2.Right());
        Rectangle::ValueType ny2 = std::max(rect1.Bottom(), rect2.Bottom());

        return FromLTRB(nx1, ny1, nx2, ny2);
    }
}  // namespace ne::ne2d
