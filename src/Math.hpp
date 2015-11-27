//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_HPP

#include "Vector2D.hpp"
#include "Rectangle.hpp"

namespace ne {

/**
 * 二维向量的绝对值操作
 * @param  vec 一个二维向量
 * @return     经过绝对值操作的二维向量
 */
template <typename TVector = BasicVector2D<Float>>
inline static auto Abs(const TVector &vec) noexcept -> TVector {
    return { std::abs(vec.X), std::abs(vec.Y) };
}

/**
 * 获取二维向量的长度
 * @param  vec 一个二维向量
 * @return     长度值
 */
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
inline static auto Cross(const TVector &vec1, const TVector &vec2) noexcept ->
    typename TVector::ValueType {
    return vec1 & vec2;
}

/**
 * 将两个二维向量相加
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      相加结果
 */
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
inline static auto Subtract(const TVector &vec1, const TVector &vec2) noexcept
    -> TVector {
    return vec1 - vec2;
}

/**
 * 缩放二维向量
 * @param  vec   原二维向量
 * @param  scale 缩放比例
 * @return       缩放后的结果
 */
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
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
template <typename TVector = BasicVector2D<Float>>
inline static auto Lerp(const TVector &start, const TVector &end,
                        const typename TVector::ValueType percentage) noexcept
    -> TVector {
    return (end - start) * percentage + start;
}

/**
 * 生成包含两个二维向量的最小矩形
 * @param  vec1 第一个二维向量
 * @param  vec2 第二个二维向量
 * @return      返回最小矩形
 */
template <typename TRectangle = BasicRectangle<Float>>
inline static auto FromTwoVector(
    const typename TRectangle::VectorType &vec1,
    const typename TRectangle::VectorType &vec2) noexcept -> TRectangle {
    return TRectangle(ne::Min(vec1, vec2),
                      ne::Max(vec1, vec2) - ne::Min(vec1, vec2));
}

/**
 * 根据上下左右的数据来生成一个矩形
 * @param  left   左边界
 * @param  top    上边界
 * @param  right  右边界
 * @param  bottom 下边界
 * @return        返回生成的矩形
 * @remark
 *     该函数不会检查其正确性，可能产生意外的结果
 */
template <typename TRectangle = BasicRectangle<Float>>
inline static auto FromLTRB(
    const typename TRectangle::ValueType left,
    const typename TRectangle::ValueType top,
    const typename TRectangle::ValueType right,
    const typename TRectangle::ValueType bottom) noexcept -> TRectangle {
    return TRectangle(left, top, right - left, bottom - top);
}

/**
 * 求得相交矩形
 * @param  rect1 第一个矩形
 * @param  rect2 第二个矩形
 * @return       返回两个矩形的交集
 */
template <typename TRectangle = BasicRectangle<Float>>
inline static auto Intersect(const TRectangle &rect1,
                             const TRectangle &rect2) noexcept -> TRectangle {
    typename TRectangle::ValueType nx1 = std::max(rect1.Left(), rect2.Left());
    typename TRectangle::ValueType ny1 = std::max(rect1.Top(), rect2.Top());
    typename TRectangle::ValueType nx2 = std::min(rect1.Right(), rect2.Right());
    typename TRectangle::ValueType ny2 =
        std::min(rect1.Bottom(), rect2.Bottom());

    // 需先确定相交矩形是否存在
    if (nx1 > nx2 and ny1 > ny2)
        return TRectangle();  // 返回空矩形
    else
        return ne::FromLTRB(nx1, ny1, nx2, ny2);
}

/**
 * 返回合并矩形
 * @param  rect1 第一个矩形
 * @param  rect2 第二个矩形
 * @return       返回两个矩形的并集
 * @remark:
 *     实质上是包含两个矩形的最小矩形
 */
template <typename TRectangle = BasicRectangle<Float>>
inline static auto Union(const TRectangle &rect1,
                         const TRectangle &rect2) noexcept -> TRectangle {
    typename TRectangle::ValueType nx1 = std::min(rect1.Left(), rect2.Left());
    typename TRectangle::ValueType ny1 = std::min(rect1.Top(), rect2.Top());
    typename TRectangle::ValueType nx2 = std::max(rect1.Right(), rect2.Right());
    typename TRectangle::ValueType ny2 =
        std::max(rect1.Bottom(), rect2.Bottom());

    return ne::FromLTRB(nx1, ny1, nx2, ny2);
}

}  // namespace ne

#endif  // IFNDEF NE2D_MATH_HPP
