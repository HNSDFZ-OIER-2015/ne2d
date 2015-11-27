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
 */
template <typename T>
struct BasicVector2D : public ne::IObject {
    NONCOMPARABLE(BasicVector2D)

    typedef T ValueType;

    BasicVector2D() : X(0.0f), Y(0.0f) {}
    BasicVector2D(T x, T y) : X(x), Y(y) {}

    T X;
    T Y;

    BasicVector2D(const BasicVector2D &lhs) : X(lhs.X), Y(lhs.Y) {}
    auto operator=(const BasicVector2D &lhs) -> BasicVector2D & {
        X = lhs.X;
        Y = lhs.Y;

        return *this;
    }

    BasicVector2D(BasicVector2D &&rhs) : X(rhs.X), Y(rhs.Y) {}
    auto operator=(BasicVector2D &&rhs) -> BasicVector2D & {
        X = rhs.X;
        Y = rhs.Y;

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

    /**
     * 二维向量的绝对值操作
     * @param  vec 一个二维向量
     * @return     经过绝对值操作的二维向量
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Abs(const TVector &vec) noexcept -> TVector {
        return { std::abs(vec.X), std::abs(vec.Y) };
    }

    /**
     * 获取二维向量的长度
     * @param  vec 一个二维向量
     * @return     长度值
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Length(const TVector &vec) noexcept ->
        typename TVector::ValueType {
        return std::hypot(vec.X, vec.Y);
    }

    /**
     * 二维向量的点乘
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      点乘结果
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Dot(const TVector &vec1, const TVector &vec2) noexcept ->
        typename TVector::ValueType {
        return vec1 * vec2;
    }

    /**
     * 二维向量的叉乘
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      叉乘结果
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Cross(const TVector &vec1, const TVector &vec2) noexcept
        -> typename TVector::ValueType {
        return vec1 & vec2;
    }

    /**
     * 将两个二维向量相加
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      相加结果
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Add(const TVector &vec1, const TVector &vec2) noexcept
        -> TVector {
        return vec1 + vec2;
    }

    /**
     * 将两个二维向量相减
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      相减结果
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Subtract(const TVector &vec1,
                                const TVector &vec2) noexcept -> TVector {
        return vec1 - vec2;
    }

    /**
     * 缩放二维向量
     * @param  vec   原二维向量
     * @param  scale 缩放比例
     * @return       缩放后的结果
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Sacle(const TVector &vec,
                             const typename TVector::ValueType scale) noexcept
        -> TVector {
        return vec * scale;
    }

    /**
     * 计算最大向量
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      取X和Y的最大值组成新的二维向量
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Max(const TVector &vec1, const TVector &vec2) noexcept
        -> TVector {
        return { std::max(vec1.X, vec2.X), std::max(vec1.Y, vec2.Y) };
    }

    /**
     * 计算最小向量
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      取X和Y的最小值组成新的二维向量
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Min(const TVector &vec1, const TVector &vec2) noexcept
        -> TVector {
        return { std::min(vec1.X, vec2.X), std::min(vec1.Y, vec2.Y) };
    }

    /**
     * 旋转二维向量
     * @param  vec    原始的二维向量
     * @param  offest 旋转中心
     * @param  angle  逆时针的旋转角度
     * @return        旋转后的二维向量
     * @remark
     *     将二维向量根据offest平移后，以原点为旋转中心再旋转，然后再平移回去。
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Rotate(const TVector &vec, const TVector &offest,
                              const typename TVector::ValueType angle) noexcept
        -> TVector {
        TVector result;

        auto cosAngle = std::cos(angle * M_PI / 180.0f);
        auto sinAngle = std::sin(angle * M_PI / 180.0f);

        auto distanceX = vec.X - offest.X;
        auto distanceY = vec.Y - offest.Y;

        result.X = cosAngle * distanceX - sinAngle * distanceY + offest.X;
        result.Y = sinAngle * distanceX + cosAngle * distanceY + offest.Y;

        return result;
    }

    /**
     * 将二维向量标准化
     * @param  vec 原二维向量
     * @return     标准化后的向量
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Normalize(const TVector &vec) -> TVector {
        auto length = Length(vec);

        if (length == 0.0f) { throw std::invalid_argument("vec"); } else {
            return vec / length;
        }
    }

    /**
     * 两个二维向量之间进行线性插值
     * @param  start      第一个二维向量
     * @param  end        第二个二维向量
     * @param  percentage 插值的位置
     * @return            返回对应的二维向量
     */
    template <typename TVector = BasicVector2D<T>>
    inline static auto Lerp(const TVector &start, const TVector &end,
                        const typename TVector::ValueType percentage) noexcept ->TVector{
        return (end - start) * percentage + start;
    }
};  // struct BasicVector2D

/**
 * 单精度浮点数的模板特化
 */
typedef BasicVector2D<Float> Vector2D;

}  // namespace ne

#endif  // NE2D_VECTOR_HPP_
