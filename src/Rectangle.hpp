//
// Copyright 2015 riteme
//

#ifndef NE2D_RECTANGLE_HPP_
#define NE2D_RECTANGLE_HPP_

#include <string>

#include "Vector2D.hpp"
#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"
#include "StringFormat.hpp"

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

        Vector2D Position;
        Vector2D Size;

        auto X() const noexcept -> ValueType { return Position.X(); }
        auto Y() const noexcept -> ValueType { return Position.Y(); }
        auto Width() const noexcept -> ValueType { return Size.X(); }
        auto Height() const noexcept -> ValueType { return Size.Y(); }

        // 可做左值
        auto X() noexcept -> ValueType & { return Position.X(); }
        auto Y() noexcept -> ValueType & { return Position.Y(); }
        auto Width() noexcept -> ValueType & { return Size.X(); }
        auto Height() noexcept -> ValueType & { return Size.Y(); }

        auto Top() const noexcept -> ValueType { return Position.Y(); }
        auto Bottom() const noexcept -> ValueType {
            return Position.Y() + Size.Y();
        }
        auto Left() const noexcept -> ValueType { return Position.X(); }
        auto Right() const noexcept -> ValueType {
            return Position.X() + Size.X();
        }

        auto LeftTop() const noexcept -> VectorType { return Position; }

        auto RightTop() const noexcept -> VectorType {
            return VectorType(Position.X() + Size.X(), Position.Y());
        }

        auto LeftBottom() const noexcept -> VectorType {
            return VectorType(Position.X(), Position.Y() + Size.Y());
        }

        auto RightBottom() const noexcept -> VectorType {
            return Position + Size;
        }

        /**
         * 检测点是否在矩形内
         * @param  x 点的横坐标
         * @param  y 点的纵坐标
         * @return   返回一个布尔值
         */
        auto Contain(const ValueType &x, const ValueType &y) const noexcept
            -> bool {
            return Left() <= x && x <= Right() && Top() <= y && y <= Bottom();
        }

        /**
         * 检测点是否在矩形内
         * @param  vec 二维向量表示点
         * @return     返回一个布尔值
         */
        auto Contain(const VectorType &vec) const noexcept -> bool {
            return Contain(vec.X(), vec.Y());
        }

        /**
         * 检测矩形是否在本矩形内
         * @param  rect 目标矩形
         * @return      返回一个布尔值
         */
        auto Contain(const Rectangle &rect) const noexcept -> bool {
            return Contain(rect.LeftTop()) && Contain(rect.RightBottom());
        }

        /**
         * 检测该矩形是否与另外一个矩形相交
         * @param  rect 另外一个矩形
         * @return      返回一个布尔值，表示是否相交
         * @remark:
         *     如果需求出相交矩形，请使用Intersect。
         */
        auto IntersectWith(const Rectangle &rect) const noexcept -> bool {
            ValueType nx1 = std::max(Left(), rect.Left());
            ValueType ny1 = std::max(Top(), rect.Top());
            ValueType nx2 = std::min(Right(), rect.Right());
            ValueType ny2 = std::min(Bottom(), rect.Bottom());

            return !(nx1 > nx2 && ny1 > ny2);
        }

        /**
         * 将矩形平移
         * @param x 横向平移量
         * @param y 纵向平移量
         */
        void Offest(const ValueType &x, const ValueType &y) noexcept {
            Position.X() += x;
            Position.Y() += y;
        }

        /**
         * 将矩形平移
         * @param vec 表示平移的二维向量
         * @remark:
         *     vec.X: 横向平移量
         *     vec.Y: 纵向平移量
         */
        void Offest(const VectorType &vec) noexcept {
            Offest(vec.X(), vec.Y());
        }

        /**
         * 增长或减少矩形的大小
         * @param  x    横向的变化量
         * @param  y    纵向的变化量
         * @remark
         *     该函数不会检查处理后的矩形的合法性，可能产生意外的结果
         */
        void Inflate(const ValueType &x, const ValueType &y) noexcept {
            Size.X() += x;
            Size.Y() += y;
        }

        /**
         * 增长或减少矩形的大小
         * @param  size 横向和纵向的变化量
         * @remark
         *     size.X: 横向变化量
         *     size.Y: 纵向变化量
         */
        void Inflate(const VectorType &size) noexcept {
            Inflate(size.X(), size.Y());
        }

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

        auto operator==(const Rectangle &lhs) const -> bool {
            return Position == lhs.Position && Size == lhs.Size;
        }

        auto operator!=(const Rectangle &lhs) const -> bool {
            return !((*this) == lhs);
    }

    virtual auto ToString() const -> std::string {
        // (X = $X, Y = $Y, Width = $W, Height = $H)

        return ne::utility::Format("(X = {}, Y = {}, Width = {}, Height = {})", Position.X(),
                      Position.Y(), Size.X(), Size.Y());
    }

    virtual auto HashCode() const -> ne::SizeType {
        return Position.HashCode() + Size.HashCode();
    }
};  // struct Rectangle

}  // namespace ne

#endif  // NE2D_RECTANGLE_HPP_
