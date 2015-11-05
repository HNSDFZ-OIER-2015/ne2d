//
// Copyright 2015 riteme
//

#ifndef NE2D_RECTANGLE_HPP_
#define NE2D_RECTANGLE_HPP_

#include <string>

#include "Vector.hpp"
#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"
#include "StringFormat.hpp"

namespace ne {

/**
 * 表示一个矩形
 */
template <typename T>
struct BasicRectangle : public ne::IObject {
    NONCOMPARABLE(BasicRectangle)

    typedef T ValueType;
    typedef BasicVector2D<T> VectorType;

    BasicRectangle() : Position(), Size() {}
    BasicRectangle(const VectorType &position, const VectorType &size)
            : Position(position), Size(size) {}
    BasicRectangle(const ValueType x, const ValueType y, const ValueType w,
                   const ValueType h)
            : Position(x, y), Size(w, h) {}

    BasicVector2D<T> Position;
    BasicVector2D<T> Size;

    ValueType X() const { return Position.X; }
    ValueType Y() const { return Position.Y; }
    ValueType Width() const { return Size.X; }
    ValueType Height() const { return Size.Y; }

    // 可做左值
    ValueType &X() { return Position.X; }
    ValueType &Y() { return Position.Y; }
    ValueType &Width() { return Size.X; }
    ValueType &Height() { return Size.Y; }

    ValueType Top() const { return Position.Y; }
    ValueType Bottom() const { return Position.Y + Size.Y; }
    ValueType Left() const { return Position.X; }
    ValueType Right() const { return Position.X + Size.X; }

    VectorType LeftTop() const { return Position; }

    VectorType RightTop() const {
        return VectorType(Position.X + Size.X, Position.Y);
    }

    VectorType LeftBottom() const {
        return VectorType(Position.X, Position.Y + Size.Y);
    }

    VectorType RightBottom() const { return Position + Size; }

    /**
     * 检测点是否在矩形内
     * @param  x 点的横坐标
     * @param  y 点的纵坐标
     * @return   返回一个布尔值
     */
    bool Contain(const ValueType x, const ValueType y) const {
        return Left() <= x && x <= Right() && Top() <= y && y <= Bottom();
    }

    /**
     * 检测点是否在矩形内
     * @param  vec 二维向量表示点
     * @return     返回一个布尔值
     */
    bool Contain(const VectorType &vec) const { return Contain(vec.X, vec.Y); }

    /**
     * 检测矩形是否在本矩形内
     * @param  rect 目标矩形
     * @return      返回一个布尔值
     */
    bool Contain(const BasicRectangle &rect) const {
        return Contain(rect.LeftTop()) && Contain(rect.RightBottom());
    }

    /**
     * 检测该矩形是否与另外一个矩形相交
     * @param  rect 另外一个矩形
     * @return      返回一个布尔值，表示是否相交
     * @remark:
     *     如果需求出相交矩形，请使用Intersect。
     */
    bool IntersectWith(const BasicRectangle &rect) const {
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
    void Offest(const ValueType x, const ValueType y) {
        Position.X += x;
        Position.Y += y;
    }

    /**
     * 将矩形平移
     * @param vec 表示平移的二维向量
     * @remark:
     *     vec.X: 横向平移量
     *     vec.Y: 纵向平移量
     */
    void Offest(const VectorType &vec) { Offest(vec.X, vec.Y); }

    /**
     * 增长或减少矩形的大小
     * @param  x    横向的变化量
     * @param  y    纵向的变化量
     * @remark
     *     该函数不会检查处理后的矩形的合法性，可能产生意外的结果
     */
    void Inflate(const ValueType x, const ValueType y) {
        Size.X += x;
        Size.Y += y;
    }

    /**
     * 增长或减少矩形的大小
     * @param  size 横向和纵向的变化量
     * @remark
     *     size.X: 横向变化量
     *     size.Y: 纵向变化量
     */
    void Inflate(const VectorType &size) { Inflate(size.X, size.Y); }

    BasicRectangle(const BasicRectangle &lhs)
            : Position(lhs.Position), Size(lhs.Size) {}
    BasicRectangle &operator=(const BasicRectangle &lhs) {
        Position = lhs.Position;
        Size = lhs.Size;

        return *this;
    }

    BasicRectangle(BasicRectangle &&rhs)
            : Position(rhs.Position), Size(rhs.Size) {}
    BasicRectangle &operator=(BasicRectangle &&rhs) {
        Position = rhs.Position;
        Size = rhs.Size;

        return *this;
    }

    bool operator==(const BasicRectangle &lhs) const {
        return Position == lhs.Position && Size == lhs.Size;
    }

    bool operator!=(const BasicRectangle &lhs) const {
        return !((*this) == lhs);
    }

    virtual std::string ToString() const {
        // (X = $X, Y = $Y, Width = $W, Height = $H)

        return Format("(X = {}, Y = {}, Width = {}, Height = {})", Position.X,
                      Position.Y, Size.X, Size.Y);
    }

    virtual SizeType HashCode() const {
        return Position.HashCode() + Size.HashCode();
    }

    /**
     * 求得相交矩形
     * @param  rect1 第一个矩形
     * @param  rect2 第二个矩形
     * @return       返回两个矩形的交集
     */
    template <typename TRectangle = BasicRectangle<T>>
    inline static TRectangle Intersect(const TRectangle &rect1,
                                       const TRectangle &rect2) noexcept {
        ValueType nx1 = std::max(rect1.Left(), rect2.Left());
        ValueType ny1 = std::max(rect1.Top(), rect2.Top());
        ValueType nx2 = std::min(rect1.Right(), rect2.Right());
        ValueType ny2 = std::min(rect1.Bottom(), rect2.Bottom());

        // 需先确定相交矩形是否存在
        if (nx1 > nx2 and ny1 > ny2)
            return TRectangle();  // 返回空矩形
        else
            return TRectangle::FromLTRB(nx1, ny1, nx2, ny2);
    }

    /**
     * 返回合并矩形
     * @param  rect1 第一个矩形
     * @param  rect2 第二个矩形
     * @return       返回两个矩形的并集
     * @remark:
     *     实质上是包含两个矩形的最小矩形
     */
    template <typename TRectangle = BasicRectangle<T>>
    inline static TRectangle Union(const TRectangle &rect1,
                                   const TRectangle &rect2) noexcept {
        ValueType nx1 = std::min(rect1.Left(), rect2.Left());
        ValueType ny1 = std::min(rect1.Top(), rect2.Top());
        ValueType nx2 = std::max(rect1.Right(), rect2.Right());
        ValueType ny2 = std::max(rect1.Bottom(), rect2.Bottom());

        return TRectangle::FromLTRB(nx1, ny1, nx2, ny2);
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
    template <typename TRectangle = BasicRectangle<T>>
    inline static TRectangle FromLTRB(
        const typename TRectangle::ValueType left,
        const typename TRectangle::ValueType top,
        const typename TRectangle::ValueType right,
        const typename TRectangle::ValueType bottom) noexcept {
        return TRectangle(left, top, right - left, bottom - top);
    }

    /**
     * 生成包含两个二维向量的最小矩形
     * @param  vec1 第一个二维向量
     * @param  vec2 第二个二维向量
     * @return      返回最小矩形
     */
    template <typename TRectangle = BasicRectangle<T>>
    inline static TRectangle FromTwoVector(
        const typename TRectangle::VectorType &vec1,
        const typename TRectangle::VectorType &vec2) noexcept {
        return TRectangle(TRectangle::VectorType::Min(vec1, vec2),
                          TRectangle::VectorType::Max(vec1, vec2) -
                              TRectangle::VectorType::Min(vec1, vec2));
    }
};  // struct BasicRectangle

typedef BasicRectangle<Float> Rectangle;

}  // namespace ne

#endif  // NE2D_RECTANGLE_HPP_
