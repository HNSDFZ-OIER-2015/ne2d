//
// Copyright 2015 riteme
//

#ifndef NE2D_VECTOR_HPP_
#define NE2D_VECTOR_HPP_

#include <stdexcept>
#include <algorithm>
#include <limits>

#include "StringFormat.hpp"
#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include <cmath>

namespace ne {

/**
 * 二维向量的基本结构
 * 可以指定数据的类型
 */
template <typename T>
struct BasicVector2D : public IObject {
    NONCOMPARABLE(BasicVector2D)

    BasicVector2D() : X(0.0f), Y(0.0f) {}
    BasicVector2D(T x, T y) : X(x), Y(y) {}

    T X;
    T Y;

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

    bool operator==(const BasicVector2D &lhs) const {
        return fabs(X - lhs.X) < std::numeric_limits<T>::epsilon() &&
               fabs(Y - lhs.Y) < std::numeric_limits<T>::epsilon();
    }

    bool operator!=(const BasicVector2D &lhs) const {
        return !((*this) == lhs);
    }

    BasicVector2D operator+(const BasicVector2D &lhs) const {
        return { X + lhs.X, Y + lhs.Y };
    }

    BasicVector2D operator-(const BasicVector2D &lhs) const {
        return { X - lhs.X, Y - lhs.Y };
    }

    BasicVector2D operator+() const { return *this; }
    BasicVector2D operator-() const { return { -X, -Y }; }
    BasicVector2D operator*(const T &lhs) const { return { X * lhs, Y * lhs }; }
    BasicVector2D operator/(const T &lhs) const { return { X / lhs, Y / lhs }; }

    T operator*(const BasicVector2D &lhs) const {
        return X * lhs.X + Y * lhs.Y;
    }

    T operator%(const BasicVector2D &lhs) const {
        return X * lhs.Y - lhs.X * Y;
    }

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

    virtual std::string ToString() const {
        // (X, Y)
        return Format("({}, {})", X, Y);
    }

    virtual SizeType HashCode() const {
        return static_cast<SizeType>(X * Y) / (static_cast<SizeType>(X) % 31);
    }
};  // struct BasicVector2D

/**
 * 单精度浮点数的模板特化
 */
typedef BasicVector2D<Float> Vector2D;

/**
 * 二维向量的绝对值操作
 * @param  vec 一个二维向量
 * @return     经过绝对值操作的二维向量
 */
template <typename TVector>
inline TVector Abs(const TVector &vec) noexcept {
    return { std::abs(vec.X), std::abs(vec.Y) };
}

/**
 * 获取二维向量的长度
 * @param  vec 一个二维向量
 * @return     长度值
 */
template <typename TVector>
inline typename TVector::ValueType Length(const TVector &vec) noexcept {
    return std::sqrt(vec.X * vec.X + vec.Y * vec.Y);
}

/**
 * 二维向量的点乘
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      点乘结果
 */
template <typename TVector>
inline typename TVector::ValueType Dot(const TVector &vec1,
                                       const TVector &vec2) noexcept {
    return vec1 * vec2;
}

/**
 * 二维向量的叉乘
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      叉乘结果
 */
template <typename TVector>
inline typename TVector::ValueType Cross(const TVector &vec1,
                                         const TVector &vec2) noexcept {
    return vec1 & vec2;
}

/**
 * 将两个二维向量相加
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      相加结果
 */
template <typename TVector>
inline TVector Add(const TVector &vec1, const TVector &vec2) noexcept {
    return vec1 + vec2;
}

/**
 * 将两个二维向量相减
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      相减结果
 */
template <typename TVector>
inline TVector Subtract(const TVector &vec1, const TVector &vec2) noexcept {
    return vec1 - vec2;
}

/**
 * 缩放二维向量
 * @param  vec   原二维向量
 * @param  scale 缩放比例
 * @return       缩放后的结果
 */
template <typename TVector>
inline TVector Sacle(const TVector &vec,
                     const typename TVector::ValueType scale) noexcept {
    return vec * scale;
}

/**
 * 计算最大向量
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      取X和Y的最大值组成新的二维向量
 */
template <typename TVector>
inline TVector Max(const TVector &vec1, const TVector &vec2) noexcept {
    return { std::max(vec1.X, vec2.X), std::max(vec1.Y, vec2.Y) };
}

/**
 * 计算最小向量
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      取X和Y的最小值组成新的二维向量
 */
template <typename TVector>
inline TVector Min(const TVector &vec1, const TVector &vec2) noexcept {
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
template <typename TVector>
inline TVector Rotate(const TVector &vec, const TVector &offest,
                      const typename TVector::ValueType angle) noexcept {
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
template <typename TVector>
inline TVector Normalize(const TVector &vec) {
    auto length = Length(vec);

    if (length == 0.0f) {
        throw std::invalid_argument("vec");
    } else {
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
template <typename TVector>
inline TVector Lerp(const TVector &start, const TVector &end,
                    const typename TVector::ValueType percentage) noexcept {
    return (end - start) * percentage + start;
}

}  // namespace ne

#endif  // NE2D_VECTOR_HPP_
