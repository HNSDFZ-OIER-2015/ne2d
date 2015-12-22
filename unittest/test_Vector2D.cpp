//
// Copyright 2015 riteme
//

#include "test.hpp"

#include <cmath>
#include <cfloat>

#include "../src/math/Vector2D.hpp"
#include "../src/utility/FloatComparison.hpp"

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

TESTCASE_GROUP_BEGIN

TESTCASE("Constructor test") {
    Vector2D vec;
    assert(vec.X() == 0.0f);
    assert(vec.Y() == 0.0f);
    assert(vec.Z() == 1.0f);

    vec = Vector2D(1.0f, 2.0f);
    assert(vec.X() == 1.0f);
    assert(vec.Y() == 2.0f);
    assert(vec.Z() == 1.0f);

    vec = { 3.0f, 4.0f };
    assert(vec.X() == 3.0f);
    assert(vec.Y() == 4.0f);
    assert(vec.Z() == 1.0f);
}
TESTCASE_END

TESTCASE("X, Y, Z attributes test") {
    Vector2D vec = { 1, 2 };
    assert(IsSame(vec.X(), 1));
    assert(IsSame(vec.Y(), 2));
    assert(IsSame(vec.Z(), 1));

    vec.X() = 3;
    vec.Y() = 233;
    assert(IsSame(vec.X(), 3));
    assert(IsSame(vec.Y(), 233));
    assert(IsSame(vec.Z(), 1));
}
TESTCASE_END

TESTCASE("Copy and move constructor test") {
    Vector2D vec1 = { 45, 23 };
    Vector2D vec2(vec1);
    Vector2D vec3 = vec1;
    Vector2D vec4(move(vec1));
    Vector2D vec5 = move(vec1);

    assert(vec1 == vec2);
    assert(vec1 == vec3);
    assert(vec1 == vec4);
    assert(vec1 == vec5);
}
TESTCASE_END

TESTCASE("Operator == test") {
    Vector2D vec1 = { 1, 2 };
    Vector2D vec2 = { 2, 3 };

    assert(vec1 != vec2);

    Vector2D vec3 = vec1;
    assert(vec3 == vec1);
    assert(vec2 != vec3);

    vec1.X() = 2;
    vec1.Y() = 3;
    assert(vec1 == vec2);
}
TESTCASE_END

TESTCASE("Operator +/- test") {
    Vector2D vec = { 1, 2 };

    assert(IsSame(vec.X(), 1));
    assert(IsSame(vec.Y(), 2));
    assert(+vec == vec);
    assert(-vec == Vector2D(-vec.X(), -vec.Y()));
}
TESTCASE_END

TESTCASE("Vector addition and subtraction test") {
    Vector2D vec1 = { 1, 2 };
    Vector2D vec2 = { 2, 3 };
    Vector2D vec3 = { 3, 4 };
    Vector2D vec4 = { -4, -5 };

    assert(vec1 + vec2 == Vector2D(3, 5));
    assert(vec1 - vec2 == Vector2D(-1, -1));
    assert(vec1 + vec2 != vec2 + vec3);
    assert(vec1 + vec3 == Vector2D(4, 6));
    assert(vec3 - vec1 == Vector2D(2, 2));
    assert(vec2 + vec4 == Vector2D(-2, -2));
    assert(vec2 - vec4 == Vector2D(6, 8));
}
TESTCASE_END

TESTCASE("Vector with Scalar multiplication test") {
    Vector2D vec = { 23, -12 };

    assert(vec * 2 == Vector2D(46, -24));
    assert(2 * vec == vec * 2);
    assert(vec * 0.5 == vec / 2);
    assert(vec * 0.5 != 0.6 * vec);
    assert(vec * -1 == -vec);
    assert(vec * 1 == vec);
    assert(vec * -2 == Vector2D(-46, 24));
}
TESTCASE_END

TESTCASE("Vector cross product and dot product test") {
    Vector2D vec1 = { 7, -9 };
    Vector2D vec2 = { 2, 3 };

    assert(IsSame(Vector2D(1, 1) * vec1, -2));
    assert(IsSame(Vector2D(-1, -1) * vec1, 2));
    assert(IsSame(Vector2D(2, 3) * vec1, -13));
    assert(IsSame(vec1 * Vector2D(1.5, 2), -7.5));

    assert(IsSame(vec1 % vec2, -vec2 % vec1));
    assert(IsSame(vec2 % vec1, -vec1 % vec2));
    assert(IsSame(Vector2D(1, 2) % Vector2D(2, 1), -3));
    assert(IsSame(Vector2D(2, 1) % Vector2D(1, 2), 3));
    assert(Vector2D(1, 2) % Vector2D(2, 1) < 0);
    assert(Vector2D(2, 1) % Vector2D(1, 2) > 0);
    assert(IsSame(Vector2D(0, 2) % Vector2D(2, 0), -4));
    assert(IsSame(Vector2D(2, 0) % Vector2D(0, 2), 4));
}
TESTCASE_END

TESTCASE("Operator +=, -=, *=, /= test") {
    Vector2D vec = { 1, -2 };
    Vector2D vec1 = vec;

    vec1 += Vector2D(1, 1);
    assert(vec1 != vec);
    assert(vec1 == vec + Vector2D(1, 1));

    vec1 -= Vector2D(2, 2);
    assert(vec1 != vec);
    assert(vec1 == vec + Vector2D(1, 1) - Vector2D(2, 2));
    assert(vec1 == vec - Vector2D(1, 1));

    vec1 *= 2;
    assert(vec1 != vec);
    assert(vec1 == (vec + Vector2D(1, 1) - Vector2D(2, 2)) * 2);
    assert(vec1 == (vec - Vector2D(1, 1)) * 2);

    vec1 /= 2;
    vec1 += Vector2D(1, 1);
    assert(vec1 == vec);
}
TESTCASE_END

TESTCASE("ToString and HashCode test") {
    Vector2D vec1 = { -1, -1 };
    Vector2D vec2 = { 1, 2 };
    Vector2D vec3 = { 23.5, -78.2 };

    assert(vec1.ToString() == "(X = -1, Y = -1)");
    assert(vec2.ToString() == "(X = 1, Y = 2)");
    assert(vec3.ToString() == "(X = 23.5, Y = -78.2)");
    assert(vec1.HashCode() != vec2.HashCode());
    assert(vec2.HashCode() != vec3.HashCode());
    assert(vec3.HashCode() != vec1.HashCode());
    assert(vec1.HashCode() == Vector2D(-1, -1).HashCode());
}
TESTCASE_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
