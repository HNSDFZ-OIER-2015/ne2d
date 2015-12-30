//
// Copyright 2015 riteme
//

#include "test.hpp"

#include <ne2d/math/Rectangle.hpp>
#include <ne2d/utility/FloatComparison.hpp>

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

TESTCASE_GROUP_BEGIN

TESTCASE("Constructor and attributes test") {
    Rectangle rect;

    CHECK(rect.Position == Vector2D(0, 0));
    CHECK(rect.Size == Vector2D(0, 0))
    CHECK(rect.X() == 0.0f);
    CHECK(rect.Y() == 0.0f);
    CHECK(rect.Width() == 0.0f);
    CHECK(rect.Height() == 0.0f);

    Vector2D pos = { 1, 2 }, size = { 23, 45 };
    rect = Rectangle(pos, size);

    CHECK(rect.Position == pos);
    CHECK(rect.Size == size);

    rect = Rectangle({ 1, 2 }, { 3, 4 });
    CHECK(IsSame(rect.X(), 1));
    CHECK(IsSame(rect.Y(), 2));
    CHECK(IsSame(rect.Width(), 3));
    CHECK(IsSame(rect.Height(), 4));

    rect = Rectangle(0, 1, 5.5, 2.3);
    CHECK(IsSame(rect.Left(), 0));
    CHECK(IsSame(rect.Right(), 5.5));
    CHECK(IsSame(rect.Top(), 1));
    CHECK(IsSame(rect.Bottom(), 3.3));
    CHECK(rect.LeftTop() == Vector2D(0, 1));
    CHECK(rect.RightTop() == Vector2D(5.5, 1));
    CHECK(rect.LeftBottom() == Vector2D(0, 3.3));
    CHECK(rect.RightBottom() == Vector2D(5.5, 3.3));
}
TESTCASE_END

TESTCASE("Function Contain() test") {
    Rectangle rect = { 1, 1, 5, 6 };

    CHECK(rect.Contain(Vector2D(2, 2)));
    CHECK(rect.Contain(2, 2));
    CHECK(rect.Contain(1, 1));
    CHECK(rect.Contain(5, 6));
    CHECK(rect.Contain(3, 4));
    CHECK(rect.Contain(1.4, 5.33));
    CHECK(rect.Contain(6, 7));
    CHECK(!rect.Contain(-1, -1));
    CHECK(!rect.Contain(6.1, 7.1));
    CHECK(!rect.Contain(3, 19));
    CHECK(!rect.Contain(100, 7));

    CHECK(rect.Contain(Rectangle(2, 2, 1, 1)));
    CHECK(rect.Contain(Rectangle(rect)));
    CHECK(rect.Contain(Rectangle(3, 3, 3, 4)));
    CHECK(!rect.Contain(Rectangle(-1, -1, 100, 99)));
    CHECK(!rect.Contain(Rectangle(1, 1, 34, 12)));
    CHECK(!rect.Contain(Rectangle(2, 3, 1, 100.34)));
    CHECK(!rect.Contain(Rectangle(6, 7, 1, 1)));
}
TESTCASE_END

TESTCASE("Function Contain() test") {
    Rectangle rect = { 1, 1, 5, 6 };

    CHECK(rect.Contain(Vector2D(2, 2)));
    CHECK(rect.Contain(2, 2));
    CHECK(rect.Contain(1, 1));
    CHECK(rect.Contain(5, 6));
    CHECK(rect.Contain(3, 4));
    CHECK(rect.Contain(1.4, 5.33));
    CHECK(rect.Contain(6, 7));
    CHECK(!rect.Contain(-1, -1));
    CHECK(!rect.Contain(6.1, 7.1));
    CHECK(!rect.Contain(3, 19));
    CHECK(!rect.Contain(100, 7));

    CHECK(rect.Contain(Rectangle(2, 2, 1, 1)));
    CHECK(rect.Contain(Rectangle(rect)));
    CHECK(rect.Contain(Rectangle(3, 3, 3, 4)));
    CHECK(!rect.Contain(Rectangle(-1, -1, 100, 99)));
    CHECK(!rect.Contain(Rectangle(1, 1, 34, 12)));
    CHECK(!rect.Contain(Rectangle(2, 3, 1, 100.34)));
    CHECK(!rect.Contain(Rectangle(6, 7, 1, 1)));

    CHECK(Rectangle(1, 1, 100, 100).Contain(1, 1));
    CHECK(Rectangle(1, 1, 100, 100).Contain(34, 57));
    CHECK(!Rectangle(2, 1, 100, 100).Contain(1, 1));
    CHECK(!Rectangle(1, 1, 100, 100).Contain(233, 10086.456));

    CHECK(Rectangle(100, 100, 100, 100).Contain(Rectangle(110, 101, 54, 34)));
    CHECK(Rectangle(1, 1, 100, 100).Contain(Rectangle(5, 47, 1, 1)));
    CHECK(Rectangle(100, 100, 100, 100).Contain(Rectangle(100, 100, 0, 0)));
    CHECK(!Rectangle(1, 1, 100, 100).Contain(Rectangle(110, 101, 54, 34)));
    CHECK(!Rectangle(100, 100, 100, 100).Contain(Rectangle(90, 101, 54, 34)));
    CHECK(!Rectangle(23, 23, 1, 1).Contain(Rectangle(25, 24, 0, 0)));
}
TESTCASE_END

TESTCASE("Function IntersectWith() test") {
    Rectangle rect = { 3.5, 4.4, 5, 6 };

    CHECK(rect.IntersectWith(Rectangle(1, 1, 100, 100)));
    CHECK(rect.IntersectWith(Rectangle(5, 5, 100, 100)));
    CHECK(rect.IntersectWith(Rectangle(1, 1, 3, 7)));

    CHECK(!rect.IntersectWith(Rectangle(9, 12, 1.233, 1.233)));
    CHECK(!rect.IntersectWith(Rectangle(1, 1, 2, 3)));
    CHECK(!rect.IntersectWith(Rectangle(-1, -1, -2, -2)));

    CHECK(Rectangle(1, 1, 100, 100).IntersectWith(Rectangle(2, 2, 1, 1)));
    CHECK(Rectangle(1, 1, 2, 2).IntersectWith(Rectangle(2, 2, 1, 1)));
    CHECK(Rectangle(1, 1, 5, 5).IntersectWith(Rectangle(0, 0, 7, 7)));
    CHECK(Rectangle(1, 1, 2, 2).IntersectWith(Rectangle(3, 3, 1, 1)));
    CHECK(!Rectangle(1, 1, 0, 0).IntersectWith(Rectangle(2, 2, 1, 1)));
    CHECK(!Rectangle(1, 1, 2, 2).IntersectWith(Rectangle(4, 4, 1, 1)));
    CHECK(!Rectangle(1, 1, 5, 5).IntersectWith(Rectangle(0, 0, 0.5, 0.5)));
}
TESTCASE_END

TESTCASE("Function Offest() and Inflate() test") {
    Rectangle rect = { 2, 2, 2, 2 };

    ASSERT(rect.Position == Vector2D(2, 2));
    ASSERT(rect.Size == Vector2D(2, 2));

    rect.Offest(1, 1);
    ASSERT(rect.Position == Vector2D(3, 3));
    ASSERT(rect.Size == Vector2D(2, 2));

    rect.Offest(-2, -1);
    ASSERT(rect.Position == Vector2D(1, 2));
    ASSERT(rect.Size == Vector2D(2, 2));

    rect.Offest(Vector2D(1.5, 2.5));
    ASSERT(rect.Position == Vector2D(2.5, 4.5));
    ASSERT(rect.Size == Vector2D(2, 2));

    rect.Offest(-rect.Position);
    ASSERT(rect.Position == Vector2D(0, 0));
    ASSERT(rect.Size == Vector2D(2, 2));

    rect.Inflate(5, 6);
    ASSERT(rect.Position == Vector2D(0, 0));
    ASSERT(rect.Size == Vector2D(7, 8));

    rect.Inflate(-1, -2);
    ASSERT(rect.Position == Vector2D(0, 0));
    ASSERT(rect.Size == Vector2D(6, 6));

    rect.Inflate(-1.5, -2.3);
    ASSERT(rect.Position == Vector2D(0, 0));
    ASSERT(rect.Size == Vector2D(4.5, 3.7));

    rect.Inflate(-rect.Size);
    ASSERT(rect.Position == Vector2D(0, 0));
    ASSERT(rect.Size == Vector2D(0, 0));
}
TESTCASE_END

TESTCASE("Operator == and != test") {
    Rectangle rect1 = { 1, 1, 2, 2 };
    Rectangle rect2 = { 1, 1, 2, 2 };
    Rectangle rect3 = { 3, 3, 1, 1 };

    CHECK(rect1 == rect2);
    CHECK(rect1 != rect3);
    CHECK(rect2 != rect3);
}
TESTCASE_END

TESTCASE("Copy and move constructor test") {
    Rectangle rect = { 1, 2, 3, 4 };
    Rectangle rect_copy1(rect);
    Rectangle rect_copy2 = rect;
    Rectangle rect_move1(std::move(rect));
    Rectangle rect_move2(std::move(rect));

    CHECK(rect_copy1 == rect);
    CHECK(rect_copy2 == rect);
    CHECK(rect_move1 == rect);
    CHECK(rect_move2 == rect);
}
TESTCASE_END

TESTCASE("ToString and HashCode test") {
    Rectangle rect1 = { 1, -1, 2, 2 };
    Rectangle rect2 = { 1, 1, 2, 2.1 };
    Rectangle rect3 = { 3.23, 3.44, 1, 1 };

    CHECK(rect1.ToString() == "(X = 1, Y = -1, Width = 2, Height = 2)");
    CHECK(rect2.ToString() == "(X = 1, Y = 1, Width = 2, Height = 2.1)");
    CHECK(rect3.ToString() == "(X = 3.23, Y = 3.44, Width = 1, Height = 1)");
    CHECK(rect1.HashCode() != rect2.HashCode());
    CHECK(rect2.HashCode() != rect3.HashCode());
    CHECK(rect3.HashCode() != rect1.HashCode());
    CHECK(rect1.HashCode() == Rectangle(1, -1, 2, 2).HashCode());
}
TESTCASE_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
