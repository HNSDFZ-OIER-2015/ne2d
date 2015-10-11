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
struct BasicRectangle : public IObject {
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

    bool Contain(const ValueType x, const ValueType y) const {
        return Left() <= x && x <= Right() && Top() <= y && y <= Bottom();
    }

    bool Contain(const VectorType &vector) const {
        return Contain(vector.X, vector.Y);
    }

    bool Contain(const BasicRectangle &rect) const {
        return Contain(rect.LeftTop()) && Contain(rect.RightBottom());
    }

    // TODO(riteme): Add IntersectWith, Offest functions.

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
        // (X, Y, W, H)
        VectorType vectorDifference = Size - Position;
        return Format("({}, {}, {}, {})", Position.X, Position.Y,
                      vectorDifference.X, vectorDifference.Y);
    }

    virtual SizeType HashCode() const {
        return Position.HashCode() + Size.HashCode() % 31;
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
    template <typename TRectangle = BasicRectangle<Float>>
    inline static TRectangle FromTwoVector(
        const typename TRectangle::VectorType &vec1,
        const typename TRectangle::VectorType &vec2) noexcept {
        return TRectangle(TRectangle::VectorType::Min(vec1, vec2),
                          TRectangle::VectorType::Max(vec1, vec2) -
                              TRectangle::VectorType::Min(vec1, vec2));
    }

    /**
     * 增长或减少某个矩形的大小
     * @param  rect 目标矩形
     * @param  x    横向的变化量
     * @param  y    纵向的变化量
     * @return      返回处理后的矩形
     * @remark
     *     该函数不会检查处理后的矩形的合法性，可能产生意外的结果
     */
    template <typename TRectangle = BasicRectangle<Float>>
    inline static TRectangle Inflate(
        const TRectangle &rect,
        const typename TRectangle::ValueType x,
        const typename TRectangle::ValueType y) noexcept {
        return TRectangle(rect.Left(), rect.Top(), rect.Right() + x,
                          rect.Bottom() + y);
    }

    /**
     * 增长或减少摸个矩形的大小
     * @param  rect 目标矩形
     * @param  size 横向和纵向的变化量
     * @return      返回处理后的矩形
     * @remark
     *     size.X: 横向变化量
     *     size.Y: 纵向变化量
     */
    template <typename TRectangle = BasicRectangle<Float>>
    inline static TRectangle Inflate(
        const TRectangle &rect,
        const typename TRectangle::VectorType &size) noexcept {
        return Inflate(rect, size.X, size.Y);
    }

    // TODO(riteme): Complete other helper functions.
};  // struct BasicRectangle

typedef BasicRectangle<Float> Rectangle;

}  // namespace ne

#endif  // NE2D_RECTANGLE_HPP_
