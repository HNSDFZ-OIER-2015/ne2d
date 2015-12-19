//
// Copyright 2015 riteme
//

#include "../src/Rectangle.hpp"
#include "../src/Math.hpp"

#include <cassert>
#include <iostream>

#include "../src/FloatComparison.hpp"

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

int main(/*int argc, char *argv[]*/) {
    // assert(expr)
    // ...

    Rectangle r1;
    assert(r1.X() == 0.0f);
    assert(r1.Y() == 0.0f);
    assert(r1.Width() == 0.0f);
    assert(r1.Height() == 0.0f);

    Rectangle r2({ 1.0f, 2.0f }, { 3.0f, 4.0f });
    assert(r2.X() == 1.0f);
    assert(r2.Y() == 2.0f);
    assert(r2.Width() == 3.0f);
    assert(r2.Height() == 4.0f);

    Rectangle r3(0.0f, 1.0f, 5.5f, 2.3f);
    assert(IsSame(r3.Left(), 0.0f));
    assert(IsSame(r3.Right(), 5.5f));
    assert(IsSame(r3.Top(), 1.0f));
    assert(IsSame(r3.Bottom(), 3.3f));
    assert(r3.LeftTop() == Vector2D(0.0f, 1.0f));
    assert(r3.RightTop() == Vector2D(5.5f, 1.0f));
    assert(r3.LeftBottom() == Vector2D(0.0f, 3.3f));
    assert(r3.RightBottom() == Vector2D(5.5f, 3.3f));

    r1.X() = 1.0f;
    r1.Y() = 1.0f;
    r1.Width() = 1.0f;
    r1.Height() = 1.0;
    assert(IsSame(r1.X(), 1.0f));
    assert(IsSame(r1.Y(), 1.0f));
    assert(IsSame(r1.Width(), 1.0f));
    assert(IsSame(r1.Height(), 1.0f));

    r2 = r1;
    assert(r2.X() == 1.0f);
    assert(r2.Y() == 1.0f);
    assert(r2.Width() == 1.0f);
    assert(r2.Height() == 1.0f);

    assert(r1 == r2);
    assert(r1 != r3);
    assert(r2 != r3);
    assert(r2 == r1);
    assert(r1 == Rectangle(1.0f, 1.0f, 1.0f, 1.0f));
    assert(r3 != Rectangle(214.3043f, 23.0f, 0.0f, 23.0f));

    r1.Offest(1.0f, 1.0f);
    assert(IsSame(r1.X(), 2.0f));
    assert(IsSame(r1.Y(), 2.0f));
    assert(IsSame(r1.Width(), 1.0f));
    assert(IsSame(r1.Height(), 1.0f));

    r1.Offest(Vector2D(-2.0f, -2.0f));
    assert(IsSame(r1.X(), 0.0f));
    assert(IsSame(r1.Y(), 0.0f));
    assert(IsSame(r1.Width(), 1.0f));
    assert(IsSame(r1.Height(), 1.0f));

    r1.Inflate(1.0f, 1.0f);
    assert(IsSame(r1.X(), 0.0f));
    assert(IsSame(r1.Y(), 0.0f));
    assert(IsSame(r1.Width(), 2.0f));
    assert(IsSame(r1.Height(), 2.0f));

    r1.Inflate(Vector2D(-2.0f, -2.0f));
    assert(IsSame(r1.X(), 0.0f));
    assert(IsSame(r1.Y(), 0.0f));
    assert(IsSame(r1.Width(), 0.0f));
    assert(IsSame(r1.Height(), 0.0f));

    assert(r1.ToString() == "(X = 0, Y = 0, Width = 0, Height = 0)");
    assert(r2.ToString() == "(X = 1, Y = 1, Width = 1, Height = 1)");
    assert(r3.ToString() == "(X = 0, Y = 1, Width = 5.5, Height = 2.3)");

    assert(Rectangle(1.0f, 1.0f, 100.0f, 100.0f).Contain(1.0f, 1.0f) == true);
    assert(Rectangle(2.0f, 1.0f, 100.0f, 100.0f).Contain(1.0f, 1.0f) == false);
    assert(Rectangle(1.0f, 1.0f, 100.0f, 100.0f).Contain(34.0f, 57.0f) == true);
    assert(Rectangle(1.0f, 1.0f, 100.0f, 100.0f).Contain(233.0f, 10086.456f) ==
           false);

    assert(Rectangle(100.0f, 100.0f, 100.0f, 100.0f)
               .Contain(Rectangle(110.0f, 101.0f, 54.0f, 34.0f)) == true);
    assert(Rectangle(1.0f, 1.0f, 100.0f, 100.0f)
               .Contain(Rectangle(110.0f, 101.0f, 54.0f, 34.0f)) == false);
    assert(Rectangle(100.0f, 100.0f, 100.0f, 100.0f)
               .Contain(Rectangle(90.0f, 101.0f, 54.0f, 34.0f)) == false);
    assert(Rectangle(23.0f, 23.0f, 1.0f, 1.0f)
               .Contain(Rectangle(25.0f, 24.0f, 0.0f, 0.0f)) == false);
    assert(Rectangle(1.0f, 1.0f, 100.0f, 100.0f)
               .Contain(Rectangle(5.0f, 47.0f, 1.0f, 1.0f)) == true);
    assert(Rectangle(100.0f, 100.0f, 100.0f, 100.0f)
               .Contain(Rectangle(100.0f, 100.0f, 0.0f, 0.0f)) == true);

    assert(Rectangle(1.0f, 1.0f, 100.0f, 100.0f)
               .IntersectWith(Rectangle(2.0f, 2.0f, 1.0f, 1.0f)) == true);
    assert(Rectangle(1.0f, 1.0f, 2.0f, 2.0f)
               .IntersectWith(Rectangle(2.0f, 2.0f, 1.0f, 1.0f)) == true);
    assert(Rectangle(1.0f, 1.0f, 5.0f, 5.0f)
               .IntersectWith(Rectangle(0.0f, 0.0f, 7.0f, 7.0f)) == true);
    assert(Rectangle(1.0f, 1.0f, 0.0f, 0.0f)
               .IntersectWith(Rectangle(2.0f, 2.0f, 1.0f, 1.0f)) == false);
    assert(Rectangle(1.0f, 1.0f, 2.0f, 2.0f)
               .IntersectWith(Rectangle(3.0f, 3.0f, 1.0f, 1.0f)) == true);
    assert(Rectangle(1.0f, 1.0f, 2.0f, 2.0f)
               .IntersectWith(Rectangle(4.0f, 4.0f, 1.0f, 1.0f)) == false);
    assert(Rectangle(1.0f, 1.0f, 5.0f, 5.0f)
               .IntersectWith(Rectangle(0.0f, 0.0f, 0.5f, 0.5f)) == false);

    assert(Intersect(Rectangle(1.0f, 1.0f, 2.0f, 2.0f),
                     Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) ==
           Rectangle(2.0f, 2.0f, 1.0f, 1.0f));
    assert(Intersect(Rectangle(100.0f, 100.0f, 2.0f, 2.0f),
                     Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) ==
           Rectangle(0.0f, 0.0f, 0.0f, 0.0f));
    assert(Intersect(Rectangle(1.0f, 1.0f, 1.0f, 1.0f),
                     Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) ==
           Rectangle(2.0f, 2.0f, 0.0f, 0.0f));

    assert(Union(Rectangle(1.0f, 1.0f, 2.0f, 2.0f),
                 Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) ==
           Rectangle(1.0f, 1.0f, 3.0f, 3.0f));
    assert(Union(Rectangle(100.0f, 100.0f, 2.0f, 2.0f),
                 Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) ==
           Rectangle(2.0f, 2.0f, 100.0f, 100.0f));
    assert(Union(Rectangle(1.0f, 1.0f, 1.0f, 1.0f),
                 Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) !=
           Rectangle(1.0f, 1.0f, 4.0f, 4.0f));
    assert(Union(Rectangle(1.0f, 1.0f, 1.0f, 1.0f),
                 Rectangle(2.0f, 2.0f, 2.0f, 2.0f)) ==
           Rectangle(1.0f, 1.0f, 3.0f, 3.0f));

    assert(FromLTRB(0.0f, 0.0f, 10.0f, 10.0f) ==
           Rectangle(0.0f, 0.0f, 10.0f, 10.0f));
    assert(FromLTRB(1.0f, 1.0f, 10.0f, 10.0f) ==
           Rectangle(1.0f, 1.0f, 9.0f, 9.0f));
    assert(FromLTRB(1.0f, 1.0f, 10.0f, 10.0f) !=
           Rectangle(1.0f, 1.0f, 10.0f, 10.0f));

    assert(FromLTRB(0.0f, 0.0f, 10.0f, 10.0f) ==
           FromTwoVector(Vector2D(0.0f, 0.0f), Vector2D(10.0f, 10.0f)));
    assert(FromLTRB(1.0f, 1.0f, 10.0f, 10.0f) ==
           FromTwoVector(Vector2D(1.0f, 1.0f), Vector2D(10.0f, 10.0f)));
    assert(FromLTRB(1.0f, 1.0f, 10.0f, 10.0f) !=
           FromTwoVector(Vector2D(1.0f, 1.0f), Vector2D(9.0f, 9.0f)));

    return 0;
}  // function main
