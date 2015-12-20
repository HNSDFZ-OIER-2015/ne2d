//
// Copyright 2015 riteme
//

#include <cassert>
#include <iostream>

#include "../src/math/Math.hpp"
#include "../src/math/Vector2D.hpp"

#include "../src/utility/FloatComparison.hpp"

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

int main(/*int argc, char *argv[]*/) {
    assert(IsSame(static_cast<Float>(M_PI) / 4.0f, ToRadians(45.0f)));
    assert(IsSame(static_cast<Float>(M_PI) / 2.0f, ToRadians(90.0f)));
    assert(IsSame(static_cast<Float>(M_PI), ToRadians(180.0f)));
    assert(IsSame(static_cast<Float>(M_PI) * 2.0f, ToRadians(360.0f)));
    assert(IsSame(static_cast<Float>(M_PI) * 4.0f, ToRadians(720.0f)));

    assert(IsSame(45.0f, ToAngle(static_cast<Float>(M_PI) / 4.0f)));
    assert(IsSame(90.0f, ToAngle(static_cast<Float>(M_PI) / 2.0f)));
    assert(IsSame(180.0f, ToAngle(static_cast<Float>(M_PI))));
    assert(IsSame(360.0f, ToAngle(static_cast<Float>(M_PI) * 2.0f)));
    assert(IsSame(720.0f, ToAngle(static_cast<Float>(M_PI) * 4.0f)));

    Vector2D vec1 = { 1.0, 2.0 };
    Vector2D vec2 = { 4.0, 233.33 };
    Vector2D vec3 = { -1.0, -233.77 };

    Matrix3 mat1 = IdentityMatrix();
    Matrix3 mat2 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    Matrix3 mat3 = { -9.0, 8.0, -76.5, 233.4, 123.321, 2.2, 0.0, 0.0, 4.3 };

    assert(Add(vec1, vec2) == vec1 + vec2);
    assert(Add(vec2, vec3) == vec2 + vec3);
    assert(Add(vec3, vec1) == vec3 + vec1);
    assert(Add(mat1, mat2) == mat1 + mat2);
    assert(Add(mat2, mat3) == mat2 + mat3);
    assert(Add(mat3, mat1) == mat3 + mat1);

    assert(Subtract(vec1, vec2) == vec1 - vec2);
    assert(Subtract(vec2, vec3) == vec2 - vec3);
    assert(Subtract(vec3, vec1) == vec3 - vec1);
    assert(Subtract(mat1, mat2) == mat1 - mat2);
    assert(Subtract(mat2, mat3) == mat2 - mat3);
    assert(Subtract(mat3, mat1) == mat3 - mat1);

    assert(Scale(vec1, 1) == vec1 * 1);
    assert(Scale(vec2, 2) == vec2 * 2);
    assert(Scale(vec3, 3) == vec3 * 3);
    assert(Scale(4, mat1) == mat1 * 4);
    assert(Scale(5, mat2) == mat2 * 5);
    assert(Scale(6, mat3) == mat3 * 6);

    assert(Multiply(mat1, mat2) == mat1 * mat2);
    assert(Multiply(mat2, mat3) == mat2 * mat3);
    assert(Multiply(mat3, mat1) == mat3 * mat1);
    assert(Multiply(mat2, mat3) != Multiply(mat3, mat2));
    assert(Multiply(mat1, mat2) == Multiply(mat2, mat1));
    assert(Multiply(mat1, mat3) == Multiply(mat3, mat1));

    assert(Multiply(mat1, ZeroMatrix()) == ZeroMatrix());
    assert(Multiply(ZeroMatrix(), mat3) == ZeroMatrix());
    assert(Multiply(ZeroMatrix(), mat2) == Multiply(mat2, ZeroMatrix()));

    assert(Add(vec1, vec2) != vec2 + vec3);
    assert(Subtract(mat2, mat3) != mat1 - mat3);
    assert(Scale(vec3, 3.4) != vec3 * 2.4);
    assert(Multiply(mat1, mat1) != mat1 * mat2);

    Vector2D vec = { 1.2, 55.98 };
    assert(IsSame(vec * vec2, DotMultiply(vec, vec2)));
    assert(IsSame(vec2 * vec3, DotMultiply(vec2, vec3)));
    assert(IsSame(vec3 * vec, DotMultiply(vec, vec3)));

    assert(IsSame(vec % vec2, CrossMultiply(vec, vec2)));
    assert(IsSame(vec % vec3, CrossMultiply(vec, vec3)));
    assert(IsSame(vec2 % vec, CrossMultiply(vec2, vec)));

    assert(Abs(Vector2D(-1.0f, -1.0f)) == Vector2D(1.0f, 1.0f));
    assert(Abs(Vector2D(-1.0f, 1.0f)) == Vector2D(1.0f, 1.0f));
    assert(Abs(Vector2D(1.0f, 1.0f)) == Vector2D(1.0f, 1.0f));

    assert(IsSame(Length(Vector2D(1.0f, 1.0f)), std::sqrt(2.0f)));
    assert(IsSame(Length(Vector2D(2.0f, 2.0f)), std::sqrt(8.0f)));
    assert(IsSame(Length(Vector2D(3.0f, 4.0f)), 5.0f));

    assert(Min(Vector2D(1.0f, 2.0f), Vector2D(2.0f, 1.0f)) ==
           Vector2D(1.0f, 1.0f));
    assert(Max(Vector2D(1.0f, 2.0f), Vector2D(2.0f, 1.0f)) ==
           Vector2D(2.0f, 2.0f));

    // auto v = Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f),
    // 90.0f);
    assert(Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f), 90.0f) ==
           -Vector2D(1.0f, -1.0f));
    assert(Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f), -90.0f) ==
           -Vector2D(-1.0f, 1.0f));
    assert(Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f), 180.0f) ==
           Rotate(Vector2D(1.0f, 1.0f), Vector2D(0.0f, 0.0f), -180.0f));
    assert(Rotate(Vector2D(1.0f, 1.0f), Vector2D(1.0f, 1.0f), 90.0f) ==
           Vector2D(1.0f, 1.0f));

    assert(Normalize(Vector2D(1.0f, 0.0f)) == Vector2D(1.0f, 0.0f));
    assert(Normalize(Vector2D(1.0f, 1.0f)) ==
           Vector2D(std::sqrt(2.0f) / 2.0f, std::sqrt(2.0f) / 2.0f));

    assert(Lerp(Vector2D(1.0f, 1.0f), Vector2D(3.0f, 3.0f), 0.5f) ==
           Vector2D(2.0f, 2.0f));
    assert(Lerp(Vector2D(0.0f, 0.0f), Vector2D(4.0f, 4.0f), 0.5f) ==
           Vector2D(2.0f, 2.0f));
    assert(Lerp(Vector2D(1.0f, 1.0f), Vector2D(3.0f, 3.0f), 2.0f) ==
           Vector2D(5.0f, 5.0f));

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

    assert(mat1 * vec == Multiply(mat1, vec));
    assert(mat2 * vec == Multiply(mat2, vec));
    assert(mat3 * vec == Multiply(mat3, vec));

    vec = { 1, 1 };
    assert(TranslateMatrix(1.0, 1.0) * vec == Vector2D(2, 2));
    assert(TranslateMatrix(-1.0, -1.0) * vec == Vector2D(0, 0));
    assert(TranslateMatrix(100.0, 1.0) * vec == Vector2D(101, 2));

    assert(ScaleMatrix(1.0, 1.0) * vec == vec);
    assert(ScaleMatrix(2.0, 2.0) * vec == Vector2D(2, 2));
    assert(ScaleMatrix(100.0, 0.5) * vec == Vector2D(100, 0.5));

    assert(RotateMatrix(90.0) * vec == Vector2D(1, -1));
    assert(RotateMatrix(-90.0) * vec == Vector2D(-1, 1));
    assert((RotateMatrix(360.0) * vec).ToString() == vec.ToString());
    assert((RotateMatrix(180.0) * vec).ToString() ==
           Vector2D(-1, -1).ToString());

    vec = Vector2D(1, 1);
    Matrix3 final = IdentityMatrix();
    final = TranslateMatrix(final, 5.0, 5.0);
    assert((final * vec).ToString() == Vector2D(6, 6).ToString());

    final = ScaleMatrix(final, 0.5, 2.0);
    assert((final * vec).ToString() == Vector2D(3, 12).ToString());

    final = RotateMatrix(final, 90.0);
    assert((final * vec).ToString() == Vector2D(12, -3).ToString());

    return 0;
}  // function main
