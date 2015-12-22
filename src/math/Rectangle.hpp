//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_RECTANGLE_HPP_
#define NE2D_MATH_RECTANGLE_HPP_

#include <string>

#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include "Vector2D.hpp"

#include "utility/StringFormat.hpp"

namespace ne::math {
    /**
     * 表示一个矩形
     */
    struct Rectangle : public ne::IObject {
        NONCOMPARABLE(Rectangle)

        typedef Float ValueType;
        typedef Vector2D VectorType;

        Rectangle() : Position(), Size() {}
        Rectangle(const VectorType &position, const VectorType &size)
                : Position(position), Size(size) {}
        Rectangle(const ValueType &x, const ValueType &y, const ValueType &w,
                  const ValueType &h)
                : Position(x, y), Size(w, h) {}

        /**
         * 表示矩形的位置
         * @remark:
         *     Position.X(): 矩形横坐标
         *     Position.Y(): 矩形纵坐标
         */
        Vector2D Position;

        /**
         * 表示矩形的大小
         * @remark:
         *     Size.X(): 矩形的宽度
         *     Size.Y(): 矩形的高度
         */
        Vector2D Size;

        /**
         * 访问矩形的横坐标，纵坐标，宽度，高度
         * @return 返回对应的值
         */
        auto X() const noexcept -> ValueType;
        auto Y() const noexcept -> ValueType;
        auto Width() const noexcept -> ValueType;
        auto Height() const noexcept -> ValueType;

        /**
         * 访问矩形的横坐标，纵坐标，宽度，高度
         * @return 返回对应的值
         * @remark:
         *     可用于修改矩形的属性
         */
        auto X() noexcept -> ValueType &;
        auto Y() noexcept -> ValueType &;
        auto Width() noexcept -> ValueType &;
        auto Height() noexcept -> ValueType &;

        /**
         * 访问矩形的上边界，下边界，左边界和右边界
         * @return 返回对应的值
         */
        auto Top() const noexcept -> ValueType;
        auto Bottom() const noexcept -> ValueType;
        auto Left() const noexcept -> ValueType;
        auto Right() const noexcept -> ValueType;

        /**
         * 访问矩形的坐上角，右上角，左下角和右下角
         * @return 返回对应的点
         */
        auto LeftTop() const noexcept -> VectorType;
        auto RightTop() const noexcept -> VectorType;
        auto LeftBottom() const noexcept -> VectorType;
        auto RightBottom() const noexcept -> VectorType;

        /**
         * 检测点是否在矩形内
         * @param  x 点的横坐标
         * @param  y 点的纵坐标
         * @return   返回一个布尔值
         */
        auto Contain(const ValueType &x, const ValueType &y) const noexcept
            -> bool;

        /**
         * 检测点是否在矩形内
         * @param  vec 二维向量表示点
         * @return     返回一个布尔值
         */
        auto Contain(const VectorType &vec) const noexcept -> bool;

        /**
         * 检测矩形是否在本矩形内
         * @param  rect 目标矩形
         * @return      返回一个布尔值
         */
        auto Contain(const Rectangle &rect) const noexcept -> bool;

        /**
         * 检测该矩形是否与另外一个矩形相交
         * @param  rect 另外一个矩形
         * @return      返回一个布尔值，表示是否相交
         * @remark:
         *     如果需求出相交矩形，请使用ne::math::Intersect。
         */
        auto IntersectWith(const Rectangle &rect) const noexcept -> bool;

        /**
         * 将矩形平移
         * @param x 横向平移量
         * @param y 纵向平移量
         */
        void Offest(const ValueType &x, const ValueType &y) noexcept;

        /**
         * 将矩形平移
         * @param vec 表示平移的二维向量
         * @remark:
         *     vec.X: 横向平移量
         *     vec.Y: 纵向平移量
         */
        void Offest(const VectorType &vec) noexcept;

        /**
         * 增长或减少矩形的大小
         * @param  x    横向的变化量
         * @param  y    纵向的变化量
         * @remark
         *     该函数不会检查处理后的矩形的合法性，可能产生意外的结果
         */
        void Inflate(const ValueType &x, const ValueType &y) noexcept;

        /**
         * 增长或减少矩形的大小
         * @param  size 横向和纵向的变化量
         * @remark
         *     size.X: 横向变化量
         *     size.Y: 纵向变化量
         */
        void Inflate(const VectorType &size) noexcept;

        Rectangle(const Rectangle &lhs)
                : Position(lhs.Position), Size(lhs.Size) {}
        auto operator=(const Rectangle &lhs) -> Rectangle & {
            Position = lhs.Position;
            Size = lhs.Size;

            return *this;
        }

        Rectangle(Rectangle &&rhs) : Position(rhs.Position), Size(rhs.Size) {}
        auto operator=(Rectangle &&rhs) -> Rectangle & {
            Position = rhs.Position;
            Size = rhs.Size;

            return *this;
        }

        /**
         * 矩形的比较函数
         */
        friend auto operator==(const Rectangle &a, const Rectangle &b) -> bool;
        friend auto operator!=(const Rectangle &a, const Rectangle &b) -> bool;

        /**
         * 返回矩形的字符串形式
         * @return 一个字符串
         * @remark:
         *     格式为：
         *     (X = $X, Y = $Y, Width = $Width, Height = $Height)
         */
        virtual auto ToString() const -> std::string {
            return ne::utility::Format("(X = {}, Y = {}, Width = {}, Height = {})", Position.X(),
                          Position.Y(), Size.X(), Size.Y());
        }

        /**
         * 计算矩形的哈希值
         * @return 哈希值
         */
        virtual auto HashCode() const -> ne::SizeType {
            return Position.HashCode() * Size.HashCode();
        }
    };  // struct Rectangle
}  // namespace ne::math

#endif  // NE2D_MATH_RECTANGLE_HPP_
