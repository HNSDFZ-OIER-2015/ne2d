//
// Copyright 2015 riteme
//

#include "../src/Vector.hpp"

#include <cmath>
#include <cfloat>
#include <cassert>
#include <iostream>

using namespace std;
using namespace ne;

bool IsSame(float a, float b);

int main(/*int argc, char *argv[]*/) {
    Vector2D vec;
    assert(vec.X == 0.0f);
    assert(vec.Y == 0.0f);

    vec = Vector2D(1.0f, 2.0f);
    assert(vec.X == 1.0f);
    assert(vec.Y == 2.0f);

    vec = { 3.0f, 4.0f };
    assert(vec.X == 3.0f);
    assert(vec.Y == 4.0f);

    Vector2D vec2 = vec;
    Vector2D vec3 = { 1.0f, 1.0f };
    // cout << vec.ToString() << endl;
    // cout << vec2.ToString() << endl;
    // cout << vec3.ToString() << endl;
    assert(vec.ToString() == "(X = 3, Y = 4)");
    assert(vec2.ToString() == "(X = 3, Y = 4)");
    assert(vec3.ToString() == "(X = 1, Y = 1)");
    assert(vec.HashCode() == vec2.HashCode());
    assert(vec2.HashCode() != vec3.HashCode());
    assert(vec2 == vec);
    assert(vec3 != vec);

    assert(vec + vec2 == Vector2D(6.0f, 8.0f));
    assert(vec + vec3 == Vector2D(4.0f, 5.0f));
    assert(vec2 + vec3 == vec + vec3);
    assert(vec - vec2 == Vector2D(0.0f, 0.0f));
    assert(vec - vec == vec - vec2);
    assert(vec - vec3 == Vector2D(2.0f, 3.0f));

    assert(vec * 2 == Vector2D(6.0f, 8.0f));
    assert(vec2 * 2 == vec + vec2);
    assert(vec3 * 0.5f == Vector2D(0.5f, 0.5f));
    assert(vec3 * 0.5f == vec3 / 2.0f);

    assert(vec * vec2 == 25.0f);
    assert(vec * vec3 == 7.0f);
    assert(vec.operator%(vec2) == 0.0f);
    assert(IsSame(vec % vec3, -1.0f));
    assert(vec2 % vec == 0.0f);

    vec += { 1.0f, 1.0f };
    assert(vec == Vector2D(4.0f, 5.0f));

    vec -= { 1.0f, 1.0f };
    assert(vec == Vector2D(3.0f, 4.0));

    vec *= 2.0f;
    assert(vec == Vector2D(6.0f, 8.0f));

    vec /= 2.0f;
    assert(vec == Vector2D(3.0f, 4.0f));

    assert(Vector2D::Abs(Vector2D(-1.0f, -1.0f)) == Vector2D(1.0f, 1.0f));
    assert(Vector2D::Abs(Vector2D(-1.0f, 1.0f)) == Vector2D(1.0f, 1.0f));
    assert(Vector2D::Abs(Vector2D(1.0f, 1.0f)) == Vector2D(1.0f, 1.0f));

    assert(IsSame(Vector2D::Length(Vector2D(1.0f, 1.0f)), std::sqrt(2.0f)));
    assert(IsSame(Vector2D::Length(Vector2D(2.0f, 2.0f)), std::sqrt(8.0f)));
    assert(IsSame(Vector2D::Length(Vector2D(3.0f, 4.0f)), 5.0f));

    assert(Vector2D::Min(Vector2D(1.0f, 2.0f), Vector2D(2.0f, 1.0f)) ==
           Vector2D(1.0f, 1.0f));
    assert(Vector2D::Max(Vector2D(1.0f, 2.0f), Vector2D(2.0f, 1.0f)) ==
           Vector2D(2.0f, 2.0f));

    // auto v = Vector2D::Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f),
    // 90.0f);
    assert(Vector2D::Rotate(Vector2D(1.0f, 1.0f),
                            Vector2D(0.0f, 0.0f),
                            90.0f) == -Vector2D(1.0f, -1.0f));
    assert(Vector2D::Rotate(Vector2D(1.0f, 1.0f),
                            Vector2D(0.0f, 0.0f),
                            -90.0f) == -Vector2D(-1.0f, 1.0f));
    assert(
        Vector2D::Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f), 180.0f) ==
        Vector2D::Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f), -180.0f));
    assert(Vector2D::Rotate(Vector2D(1.0f, 1.0f),
                            Vector2D(1.0f, 1.0f),
                            90.0f) == Vector2D(1.0f, 1.0f));

    assert(Vector2D::Normalize(Vector2D(1.0f, 0.0f)) == Vector2D(1.0f, 0.0f));
    assert(Vector2D::Normalize(Vector2D(1.0f, 1.0f)) ==
           Vector2D(std::sqrt(2.0f) / 2.0f, std::sqrt(2.0f) / 2.0f));

    assert(Vector2D::Lerp(Vector2D(1.0f, 1.0f), Vector2D(3.0f, 3.0f), 0.5f) ==
           Vector2D(2.0f, 2.0f));
    assert(Vector2D::Lerp(Vector2D(0.0f, 0.0f), Vector2D(4.0f, 4.0f), 0.5f) ==
           Vector2D(2.0f, 2.0f));
    assert(Vector2D::Lerp(Vector2D(1.0f, 1.0f), Vector2D(3.0f, 3.0f), 2.0f) ==
           Vector2D(5.0f, 5.0f));

    cout << "PASSED" << endl;

    return 0;
}  // function main

bool IsSame(float a, float b) { return fabsf(a - b) < FLT_EPSILON; }
