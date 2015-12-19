//
// Copyright 2015 riteme
//

#include "../src/Math.hpp"
#include "../src/FloatComparison.hpp"

#include <cassert>
#include <iostream>

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
    assert(Scale(mat1, 4) == mat1 * 4);
    assert(Scale(mat2, 5) == mat2 * 5);
    assert(Scale(mat3, 6) == mat3 * 6);

    assert(Multiply(mat1, mat2) == mat1 * mat2);
    assert(Multiply(mat2, mat3) == mat2 * mat3);
    assert(Multiply(mat3, mat1) == mat3 * mat1);

    assert(Add(vec1, vec2) != vec2 + vec3);
    assert(Subtract(mat2, mat3) != mat1 - mat3);
    assert(Scale(vec3, 3.4) != vec3 * 2.4);
    assert(Multiply(mat1, mat1) != mat1 * mat2);

    return 0;
}  // function main
