//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_HPP_
#define NE2D_MATH_HPP_

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
    auto ToRadians(const T &angle) noexcept->T {
        return angle * M_PI / 180.0;
    }

    /**
     * 将弧度值换算为角度值
     * @param  radians 弧度
     * @return         返回对应的角度
     * @remark:
     *     a = (180 * r) / PI
     */
    template <typename T>
    auto ToAngle(const T &radians) noexcept->T {
        return radians * 180.0 / M_PI;
    }

    /**
     * 余弦函数
     * @param  x 角度
     * @return   余弦值
     */
    template <typename T>
    auto Cos(const T &x) noexcept->T {
        return std::cos(ToRadians(x));
    }

    /**
     * 正弦函数
     * @param  x 角度
     * @return   正弦值
     */
    template <typename T>
    auto Sin(const T &x) noexcept->T {
        return std::sin(ToRadians(x));
    }

    /**
     * 正切函数
     * @param  x 角度
     * @return   正切值
     */
    template <typename T>
    auto Tan(const T &x) noexcept->T {
        return std::tan(ToRadians(x));
    }

    /**
     * 余切函数
     * @param  x 角度
     * @return   余切值
     */
    template <typename T>
    auto Cot(const T &x) noexcept->T {
        return 1.0 / Tan(x);
    }

    // 二维向量和矩阵共用以下方法
    // Add, Subtract, Multiply, Scale

    /**
     * 加法
     * @param  a 左参数
     * @param  b 右参数
     * @return   返回相加结果
     */
    template <typename TMathObject1, typename TMathObject2>
    auto Add(const TMathObject1 &a, const TMathObject2 &b) noexcept {
        return a + b;
    }

    /**
     * 减法
     * @param  a 左参数
     * @param  b 右参数
     * @return   返回相减结果
     */
    template <typename TMathObject1, typename TMathObject2>
    auto Subtract(const TMathObject1 &a, const TMathObject2 &b) noexcept {
        return a - b;
    }

    /**
     * 乘法
     * @param  a 左参数
     * @param  b 右参数
     * @return   返回相乘结果
     */
    template <typename TMathObject1, typename TMathObject2>
    auto Multiply(const TMathObject1 &a, const TMathObject2 &b) noexcept {
        return a * b;
    }

    /**
     * 标量乘法
     * @param  target 向量或矩阵
     * @param  scale  标量
     * @return        返回相乘结果
     */
    template <typename TMathObject>
    auto Scale(
        const TMathObject &target,
        const typename TMathObject::ValueType &scale) noexcept->TMathObject {
        return target * scale;
    }

    /**
     * 标量乘法
     * @param  scale  标量
     * @param  target 向量或矩阵
     * @return        返回相乘结果
     */
    template <typename TMathObject>
    auto Scale(const typename TMathObject::ValueType &scale,
               const TMathObject &target) noexcept->TMathObject {
        return scale * target;
    }

    //////////////////
    // 二维向量操作 //
    /////////////////

    /**
     * 二维向量的绝对值操作
     * @param  vec 一个二维向量
     * @return     经过绝对值操作的二维向量
     */
    auto Abs(const Vector2D &vec) noexcept->Vector2D;

    /**
     * 获取二维向量的长度
     * @param  vec 一个二维向量
     * @return     长度值
     */
    auto Length(const Vector2D &vec) noexcept->typename Vector2D::ValueType;

    /**
     * 二维向量的点乘
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      点乘结果
     */
    auto DotMultiply(const Vector2D &vec1, const Vector2D &vec2) noexcept->
        typename Vector2D::ValueType;

    /**
     * 二维向量的叉乘
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      叉乘结果
     */
    auto CrossMultiply(const Vector2D &vec1, const Vector2D &vec2) noexcept->
        typename Vector2D::ValueType;

    /**
     * 计算最大向量
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      取X和Y的最大值组成新的二维向量
     */
    auto Max(const Vector2D &vec1, const Vector2D &vec2) noexcept->Vector2D;

    /**
     * 计算最小向量
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      取X和Y的最小值组成新的二维向量
     */
    auto Min(const Vector2D &vec1, const Vector2D &vec2) noexcept->Vector2D;

    /**
     * 旋转二维向量
     * @param  vec    原始的二维向量
     * @param  offest 旋转中心
     * @param  angle  逆时针的旋转角度
     * @return        旋转后的二维向量
     * @remark
     *     将二维向量根据offest平移后，以原点为旋转中心再旋转，然后再平移回去。
     */
    auto Rotate(const Vector2D &vec, const Vector2D &offest,
                const typename Vector2D::ValueType &angle) noexcept->Vector2D;

    /**
     * 将二维向量标准化
     * @param  vec 原二维向量
     * @return     标准化后的向量
     */
    auto Normalize(const Vector2D &vec)->Vector2D;

    /**
     * 两个二维向量之间进行线性插值
     * @param  start      第一个二维向量
     * @param  end        第二个二维向量
     * @param  percentage 插值的位置
     * @return            返回对应的二维向量
     */
    auto Lerp(
        const Vector2D &start, const Vector2D &end,
        const typename Vector2D::ValueType &percentage) noexcept->Vector2D;

    //////////////
    // 矩阵操作 //
    /////////////

    // 矩阵乘法，矩阵加法，矩阵减法，矩阵标量乘法(Scale)均在通用操作部分

    /**
     * 生成零矩阵
     * @return 返回一个零矩阵
     * @remark:
     *     零矩阵如下：
     *     [0, 0, 0]
     *     [0, 0, 0]
     *     [0, 0, 0]
     */
    auto ZeroMatrix() noexcept->Matrix3;

    /**
     * 生成单位矩阵
     * @return 返回一个单位矩阵
     * @remark:
     *     单位矩阵如下：
     *     [1, 0, 0]
     *     [0, 1, 0]
     *     [0, 0, 1]
     */
    auto IdentityMatrix() noexcept->Matrix3;

    /**
     * 生成平移矩阵
     * @param  dx 横向平移量
     * @param  dy 纵向平移量
     * @return    返回对应的平移矩阵
     * @remark:
     *     平移矩阵如下：
     *     [1 0 dx]
     *     [0 1 dy]
     *     [0 0 1 ]
     */
    auto TranslateMatrix(const Matrix3::ValueType &dx,
                         const Matrix3::ValueType &dy) noexcept->Matrix3;

    /**
     * 生成一个平移矩阵并与现有矩阵相乘
     * @param  mat 现有矩阵
     * @param  dx  横向平移量
     * @param  dy  纵向平移量
     * @return     返回合成后的矩阵
     */
    auto TranslateMatrix(
        const Matrix3 &mat,
        const typename Matrix3::ValueType &dx,
        const typename Matrix3::ValueType &dy) noexcept->Matrix3;

    /**
     * 生成缩放矩阵
     * @param  sx 横向缩放比例
     * @param  sy 纵向缩放比例
     * @return    返回对于的缩放矩阵
     * @remark:
     *     缩放矩阵如下：
     *     [sx 0  0]
     *     [0  sy 0]
     *     [0  0  1]
     */
    auto ScaleMatrix(const Matrix3::ValueType &sx,
                     const Matrix3::ValueType &sy) noexcept->Matrix3;

    /**
     * 生成一个缩放矩阵并与现有矩阵相乘
     * @param  mat 现有矩阵
     * @param  sx  横向缩放比例
     * @param  sy  纵向缩放比例
     * @return     返回合成后的矩阵
     */
    auto ScaleMatrix(const Matrix3 &mat,
                     const typename Matrix3::ValueType &sx,
                     const typename Matrix3::ValueType &sy) noexcept->Matrix3;

    /**
     * 生成旋转矩阵
     * @param  angle 旋转角度
     * @return       返回对于的旋转矩阵
     * @remark:
     *     旋转矩阵
     *     [cos(aangle) -sin(aangle) 0]
     *     [sin(aangle) cos(aangle)  0]
     *     [0           0            1]
     */
    auto RotateMatrix(const Matrix3::ValueType &angle) noexcept->Matrix3;

    /**
     * 生成旋转矩阵并与现有矩阵相乘
     * @param  mat   现有矩阵
     * @param  angle 旋转角度
     * @return       返回合成的矩阵
     */
    auto RotateMatrix(
        const Matrix3 &mat,
        const typename Matrix3::ValueType &angle) noexcept->Matrix3;

    /**
     * 计算矩阵的倒置
     * @param  mat 原矩阵
     * @return     倒置后的矩阵
     * @remark:
     *     该操作时间复杂度为O(1)
     */
    auto Transpose(const Matrix3 &mat) noexcept->Matrix3;

    //////////////
    // 矩形操作 //
    /////////////

    /**
     * 生成包含两个二维向量的最小矩形
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      返回最小矩形
     */
    auto FromTwoVector(const Vector2D &vec1,
                       const Vector2D &vec2) noexcept->Rectangle;

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
     auto FromLTRB(
        const Rectangle::ValueType &left,
        const Rectangle::ValueType &top,
        const Rectangle::ValueType &right,
        const Rectangle::ValueType &bottom) noexcept->Rectangle;

    /**
     * 求得相交矩形
     * @param  rect1 第一个矩形
     * @param  rect2 第二个矩形
     * @return       返回两个矩形的交集
     */
     auto Intersect(const Rectangle &rect1, const Rectangle &rect2) noexcept
            ->Rectangle;

    /**
     * 返回合并矩形
     * @param  rect1 第一个矩形
     * @param  rect2 第二个矩形
     * @return       返回两个矩形的并集
     * @remark:
     *     实质上是包含两个矩形的最小矩形
     */
     auto Union(const Rectangle &rect1,
                const Rectangle &rect2) noexcept->Rectangle;
}  // namespace ne::math

#endif  // NE2D_MATH_HPP_
