//
// Copyright 2015 riteme
//

#include "Rectangle.hpp"

namespace ne::math {
    auto Rectangle::X() const noexcept->ValueType { return Position.X(); }
    auto Rectangle::Y() const noexcept->ValueType { return Position.Y(); }
    auto Rectangle::Width() const noexcept->ValueType { return Size.X(); }
    auto Rectangle::Height() const noexcept->ValueType { return Size.Y(); }

    auto Rectangle::X() noexcept->ValueType & { return Position.X(); }
    auto Rectangle::Y() noexcept->ValueType & { return Position.Y(); }
    auto Rectangle::Width() noexcept->ValueType & { return Size.X(); }
    auto Rectangle::Height() noexcept->ValueType & { return Size.Y(); }

    auto Rectangle::Top() const noexcept->ValueType { return Position.Y(); }

    auto Rectangle::Bottom() const noexcept->ValueType {
        return Position.Y() + Size.Y();
    }

    auto Rectangle::Left() const noexcept->ValueType { return Position.X(); }

    auto Rectangle::Right() const noexcept->ValueType {
        return Position.X() + Size.X();
    }

    auto Rectangle::LeftTop() const noexcept->VectorType { return Position; }

    auto Rectangle::RightTop() const noexcept->VectorType {
        return VectorType(Position.X() + Size.X(), Position.Y());
    }

    auto Rectangle::LeftBottom() const noexcept->VectorType {
        return VectorType(Position.X(), Position.Y() + Size.Y());
    }

    auto Rectangle::RightBottom() const noexcept->VectorType {
        return Position + Size;
    }

    auto Rectangle::Rectangle::Contain(const ValueType &x, const ValueType &y)
        const noexcept->bool {
        return Left() <= x && x <= Right() && Top() <= y && y <= Bottom();
    }

    auto Rectangle::Contain(const VectorType &vec) const noexcept->bool {
        return Contain(vec.X(), vec.Y());
    }

    auto Rectangle::Contain(const Rectangle &rect) const noexcept->bool {
        return Contain(rect.LeftTop()) && Contain(rect.RightBottom());
    }

    auto Rectangle::IntersectWith(const Rectangle &rect) const noexcept->bool {
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

    auto operator==(const Rectangle &a, const Rectangle &b)->bool {
        return a.Position == b.Position && a.Size == b.Size;
    }

    auto operator!=(const Rectangle &a, const Rectangle &b)->bool {
        return !(a == b);
    }
}  // namespace ne::math
