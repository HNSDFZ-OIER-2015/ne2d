//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_HPP_
#define NE2D_MATH_HPP_

#include <cmath>

#include "Vector2D.hpp"
#include "Rectangle.hpp"
#include "Matrix3.hpp"

namespace ne::math {

    //////////////
    // 通用操作 //
    /////////////

    /**
     * 将角度值换算为弧度值
     * @param  angle 角度
     * @return       返回对应的弧度
     * @remark:
     *     r = (a * PI) / 180
     */
    template <typename T>
    inline auto ToRadians(const T &angle) noexcept->T {
        return (M_PI * angle) / 180.0;
    }

    /**
     * 将弧度值换算为角度值
     * @param  radians 弧度
     * @return         返回对应的角度
     * @remark:
     *     a = (180 * r) / PI
     */
    template <typename T>
    inline auto ToAngle(const T &radians) noexcept->T {
        return (180.0 * radians) / M_PI;
    }

    // 二维向量和矩阵共用以下方法
    // Add, Subtract, Multiply, Scale

    /**
     * 加法
     * @param  a 左参数
     * @param  b 右参数
     * @return   返回相加结果
     */
    template <typename TMathObject>
    inline auto Add(const TMathObject &a,
                    const TMathObject &b) noexcept->TMathObject {
        return a + b;
    }

    /**
     * 减法
     * @param  a 左参数
     * @param  b 右参数
     * @return   返回相减结果
     */
    template <typename TMathObject>
    inline auto Subtract(const TMathObject &a,
                         const TMathObject &b) noexcept->TMathObject {
        return a - b;
    }

    /**
     * 矩阵乘法
     * @param  a 左参数
     * @param  b 右参数
     * @return   返回相乘结果
     */
    template <typename TMatrix3, typename TReturn = TMatrix3>
    inline auto Multiply(const TMatrix3 &a,
                         const TMatrix3 &b) noexcept->TReturn {
        return a * b;
    }

    /**
     * 标量乘法
     * @param  target 向量或矩阵
     * @param  scale  标量
     * @return        返回相乘结果
     */
    template <typename TMathObject>
    inline auto Scale(
        const TMathObject &target,
        const typename TMathObject::ValueType &scale) noexcept->TMathObject {
        return target * scale;
    }

    //////////////////
    // 二维向量操作 //
    /////////////////

    /**
     * 二维向量的绝对值操作
     * @param  vec 一个二维向量
     * @return     经过绝对值操作的二维向量
     */
    template <typename TVector>
    inline auto Abs(const TVector &vec) noexcept->TVector {
        return { std::abs(vec.X), std::abs(vec.Y) };
    }

    /**
     * 获取二维向量的长度
     * @param  vec 一个二维向量
     * @return     长度值
     */
    template <typename TVector>
    inline auto Length(const TVector &vec) noexcept->
        typename TVector::ValueType {
        return std::hypot(vec.X, vec.Y);
    }

    /**
     * 二维向量的点乘
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      点乘结果
     */
    template <typename TVector>
    inline auto DotMultiply(const TVector &vec1, const TVector &vec2) noexcept->
        typename TVector::ValueType {
        return vec1 * vec2;
    }

    /**
     * 二维向量的叉乘
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      叉乘结果
     */
    template <typename TVector>
    inline auto CrossMultiply(const TVector &vec1,
                              const TVector &vec2) noexcept->
        typename TVector::ValueType {
        return vec1 % vec2;
    }

    /**
     * 计算最大向量
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      取X和Y的最大值组成新的二维向量
     */
    template <typename TVector>
    inline auto Max(const TVector &vec1,
                    const TVector &vec2) noexcept->TVector {
        return { std::max(vec1.X, vec2.X), std::max(vec1.Y, vec2.Y) };
    }

    /**
     * 计算最小向量
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      取X和Y的最小值组成新的二维向量
     */
    template <typename TVector>
    inline auto Min(const TVector &vec1,
                    const TVector &vec2) noexcept->TVector {
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
    inline auto Rotate(
        const TVector &vec, const TVector &offest,
        const typename TVector::ValueType &angle) noexcept->TVector {
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
    inline auto Normalize(const TVector &vec)->TVector {
        auto length = Length(vec);

        if (length == 0.0f)
            throw std::invalid_argument("vec");
        else
            return vec / length;
    }

    /**
     * 两个二维向量之间进行线性插值
     * @param  start      第一个二维向量
     * @param  end        第二个二维向量
     * @param  percentage 插值的位置
     * @return            返回对应的二维向量
     */
    template <typename TVector>
    inline auto Lerp(
        const TVector &start, const TVector &end,
        const typename TVector::ValueType &percentage) noexcept->TVector {
        return (end - start) * percentage + start;
    }

    //////////////
    // 矩阵操作 //
    /////////////

    // 矩阵乘法，矩阵加法，矩阵减法，矩阵标量乘法(Scale)均在通用操作部分

    /**
     * 生成单位矩阵
     * @return 返回一个单位矩阵
     * @remark:
     *     单位矩阵如下：
     *     [1, 0, 0]
     *     [0, 1, 0]
     *     [0, 0, 1]
     */
    template <typename TValueType = Float,
              typename TMatrix3 = BasicMatrix3<TValueType>>
    inline auto Identity() noexcept->TMatrix3 {
        return TMatrix3();
    }

    /**
     * 矩阵与向量乘法
     * @param  mat 矩阵
     * @param  vec 向量
     * @return     返回相乘结果
     */
    template <typename TMatrix3, typename TVector>
    inline auto Multiply(const TMatrix3 &mat,
                         const TVector &vec) noexcept->TVector {
        return mat * vec;
    }

    /**
     * 生成平移矩阵
     * @param  dx 横向平移量
     * @param  dy 纵向平移量
     * @return    返回对应的平移矩阵
     * @remark:
     *     平移矩阵如下：
     *     [1 0 X]
     *     [0 1 Y]
     *     [0 0 1]
     */
    template <typename TValueType>
    inline auto MatrixTranslate(
        const TValueType &dx,
        const TValueType &dy) noexcept->BasicMatrix3<TValueType> {
        return { 1.0, 0.0, dx, 0.0, 1.0, dy, 0.0, 0.0, 1.0 };
    }

    /**
     * 生成一个平移矩阵并与现有矩阵相乘
     * @param  mat 现有矩阵
     * @param  dx  横向平移量
     * @param  dy  纵向平移量
     * @return     返回合成后的矩阵
     */
    template <typename TMatrix3>
    inline auto MatrixTranslate(
        const TMatrix3 &mat,
        const typename TMatrix3::ValueType &dx,
        const typename TMatrix3::ValueType &dy) noexcept->TMatrix3 {
        return MatrixTranslate(dx, dy) * mat;
    }

    /**
     * 生成缩放矩阵
     * @param  sx 横向缩放比例
     * @param  sy 纵向缩放比例
     * @return    返回对于的缩放矩阵
     * @remark:
     *     缩放矩阵如下：
     *     [X 0 0]
     *     [0 Y 0]
     *     [0 0 1]
     */
    template <typename TValueType>
    inline auto MatrixScale(
        const TValueType &sx,
        const TValueType &sy) noexcept->BasicMatrix3<TValueType> {
        return { sx, 0.0, 0.0, 0.0, sy, 0.0, 0.0, 0.0, 1.0 };
    }

    /**
     * 生成一个缩放矩阵并与现有矩阵相乘
     * @param  mat 现有矩阵
     * @param  sx  横向缩放比例
     * @param  sy  纵向缩放比例
     * @return     返回合成后的矩阵
     */
    template <typename TMatrix3>
    inline auto MatrixScale(
        const TMatrix3 &mat,
        const typename TMatrix3::ValueType &sx,
        const typename TMatrix3::ValueType &sy) noexcept->TMatrix3 {
        return MatrixScale(sx, sy) * mat;
    }

    /**
     * 生成旋转矩阵
     * @param  angle 旋转角度
     * @return       返回对于的旋转矩阵
     * @remark:
     *     旋转矩阵
     *     [cos(a) -sin(a) 0]
     *     [sin(a) cos(a)  0]
     *     [  0      0     1]
     */
    template <typename TValueType>
    inline auto MatrixRotate(
        const TValueType &angle) noexcept->BasicMatrix3<TValueType> {
        auto r = ToRadians(-angle);
        return { std::cos(r), -std::sin(r), 0.0, std::sin(r), std::cos(r),
                 0.0,         0.0,          0.0, 1.0 };
    }

    /**
     * 生成旋转矩阵并与现有矩阵相乘
     * @param  mat   现有矩阵
     * @param  angle 旋转角度
     * @return       返回合成的矩阵
     */
    template <typename TMatrix3>
    inline auto MatrixRotate(
        const TMatrix3 &mat,
        const typename TMatrix3::ValueType &angle) noexcept->TMatrix3 {
        return MatrixRotate(angle) * mat;
    }

    /**
     * 计算矩阵的倒置
     * @param  mat 原矩阵
     * @return     倒置后的矩阵
     * @remark:
     *     该操作时间复杂度为O(1)
     */
    template <typename TMatrix3>
    inline auto Transpose(const TMatrix3 &mat) noexcept->TMatrix3 {
        auto tmp = mat;
        tmp.Transpose();

        return tmp;
    }

    //////////////
    // 矩形操作 //
    /////////////

    /**
     * 生成包含两个二维向量的最小矩形
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      返回最小矩形
     */
    template <typename TVectorType>
    inline auto FromTwoVector(const TVectorType &vec1,
                              const TVectorType &vec2) noexcept
        ->BasicRectangle<typename TVectorType::ValueType> {
        typedef BasicRectangle<typename TVectorType::ValueType> TRectangle;

        return TRectangle(Min(vec1, vec2), Max(vec1, vec2) - Min(vec1, vec2));
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
    template <typename TValueType>
    inline auto FromLTRB(
        const TValueType &left,
        const TValueType &top,
        const TValueType &right,
        const TValueType &bottom) noexcept->BasicRectangle<TValueType> {
    typedef BasicRectangle<TValueType> TRectangle;

    return TRectangle(left, top, right - left, bottom - top);
}

/**
 * 求得相交矩形
 * @param  rect1 第一个矩形
 * @param  rect2 第二个矩形
 * @return       返回两个矩形的交集
 */
template <typename TRectangle>
inline auto Intersect(const TRectangle &rect1, const TRectangle &rect2) noexcept
    -> TRectangle {
    typename TRectangle::ValueType nx1 = std::max(rect1.Left(), rect2.Left());
    typename TRectangle::ValueType ny1 = std::max(rect1.Top(), rect2.Top());
    typename TRectangle::ValueType nx2 = std::min(rect1.Right(), rect2.Right());
    typename TRectangle::ValueType ny2 =
        std::min(rect1.Bottom(), rect2.Bottom());

    // 需先确定相交矩形是否存在
    if (nx1 > nx2 and ny1 > ny2)
        return TRectangle();  // 返回空矩形
    else
        return FromLTRB(nx1, ny1, nx2, ny2);
}

/**
 * 返回合并矩形
 * @param  rect1 第一个矩形
 * @param  rect2 第二个矩形
 * @return       返回两个矩形的并集
 * @remark:
 *     实质上是包含两个矩形的最小矩形
 */
template <typename TRectangle>
inline auto Union(const TRectangle &rect1,
                         const TRectangle &rect2) noexcept -> TRectangle {
    typename TRectangle::ValueType nx1 = std::min(rect1.Left(), rect2.Left());
    typename TRectangle::ValueType ny1 = std::min(rect1.Top(), rect2.Top());
    typename TRectangle::ValueType nx2 = std::max(rect1.Right(), rect2.Right());
    typename TRectangle::ValueType ny2 =
        std::max(rect1.Bottom(), rect2.Bottom());

    return FromLTRB(nx1, ny1, nx2, ny2);
}

}  // namespace ne

#endif  // NE2D_MATH_HPP_
