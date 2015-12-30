//
// Copyright 2015 riteme
//

#include "Rectangle.hpp"

namespace ne {
namespace math {

Rectangle::Rectangle() : Position(), Size() {}

Rectangle::Rectangle(const VectorType &position, const VectorType &size)
        : Position(position), Size(size) {}

Rectangle::Rectangle(const ValueType &x, const ValueType &y, const ValueType &w,
                     const ValueType &h)
        : Position(x, y), Size(w, h) {}

Rectangle::Rectangle(const Rectangle &lhs)
        : Position(lhs.Position), Size(lhs.Size) {}

auto Rectangle::operator=(const Rectangle &lhs) -> Rectangle & {
    Position = lhs.Position;
    Size = lhs.Size;

    return *this;
}

Rectangle::Rectangle(Rectangle &&rhs)
        : Position(rhs.Position), Size(rhs.Size) {}

auto Rectangle::operator=(Rectangle &&rhs) -> Rectangle & {
    Position = rhs.Position;
    Size = rhs.Size;

    return *this;
}

auto Rectangle::X() const noexcept -> ValueType { return Position.X(); }
auto Rectangle::Y() const noexcept -> ValueType { return Position.Y(); }
auto Rectangle::Width() const noexcept -> ValueType { return Size.X(); }
auto Rectangle::Height() const noexcept -> ValueType { return Size.Y(); }

auto Rectangle::X() noexcept -> ValueType & { return Position.X(); }
auto Rectangle::Y() noexcept -> ValueType & { return Position.Y(); }
auto Rectangle::Width() noexcept -> ValueType & { return Size.X(); }
auto Rectangle::Height() noexcept -> ValueType & { return Size.Y(); }

auto Rectangle::Top() const noexcept -> ValueType { return Position.Y(); }

auto Rectangle::Bottom() const noexcept -> ValueType {
    return Position.Y() + Size.Y();
}

auto Rectangle::Left() const noexcept -> ValueType { return Position.X(); }

auto Rectangle::Right() const noexcept -> ValueType {
    return Position.X() + Size.X();
}

auto Rectangle::LeftTop() const noexcept -> VectorType { return Position; }

auto Rectangle::RightTop() const noexcept -> VectorType {
    return VectorType(Position.X() + Size.X(), Position.Y());
}

auto Rectangle::LeftBottom() const noexcept -> VectorType {
    return VectorType(Position.X(), Position.Y() + Size.Y());
}

auto Rectangle::RightBottom() const noexcept -> VectorType {
    return Position + Size;
}

auto Rectangle::Rectangle::Contain(const ValueType &x, const ValueType &y) const
    noexcept -> Bool {
    return Left() <= x && x <= Right() && Top() <= y && y <= Bottom();
}

auto Rectangle::Contain(const VectorType &vec) const noexcept -> Bool {
    return Contain(vec.X(), vec.Y());
}

auto Rectangle::Contain(const Rectangle &rect) const noexcept -> Bool {
    return Contain(rect.LeftTop()) && Contain(rect.RightBottom());
}

auto Rectangle::IntersectWith(const Rectangle &rect) const noexcept -> Bool {
    ValueType nx1 = std::max(Left(), rect.Left());
    ValueType ny1 = std::max(Top(), rect.Top());
    ValueType nx2 = std::min(Right(), rect.Right());
    ValueType ny2 = std::min(Bottom(), rect.Bottom());

    return !(nx1 > nx2 && ny1 > ny2);
}

void Rectangle::Offest(const ValueType &x, const ValueType &y) noexcept {
    Position.X() += x;
    Position.Y() += y;
}

void Rectangle::Offest(const VectorType &vec) noexcept {
    Offest(vec.X(), vec.Y());
}

void Rectangle::Inflate(const ValueType &x, const ValueType &y) noexcept {
    Size.X() += x;
    Size.Y() += y;
}

void Rectangle::Inflate(const VectorType &size) noexcept {
    Inflate(size.X(), size.Y());
}

auto operator==(const Rectangle &a, const Rectangle &b) -> Bool {
    return a.Position == b.Position && a.Size == b.Size;
}

auto operator!=(const Rectangle &a, const Rectangle &b) -> Bool {
    return !(a == b);
}

auto Rectangle::ToString() const -> std::string {
    return ne::utility::Format("(X = {}, Y = {}, Width = {}, Height = {})",
                               Position.X(), Position.Y(), Size.X(), Size.Y());
}
auto Rectangle::HashCode() const -> ne::SizeType {
    return Position.HashCode() * Size.HashCode();
}

}  // namespace math
}  // namespace ne
