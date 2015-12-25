//
// Copyright 2015 riteme
//

#include "test.hpp"

#include "../src/math/Math.hpp"
#include "../src/math/Vector2D.hpp"
#include "../src/utility/FloatComparison.hpp"

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

TESTCASE_GROUP_BEGIN

TESTCASE("ToRadians() and ToAngle() test") {
    CHECK(IsSame(M_PI / 4, ToRadians(45.0)));
    CHECK(IsSame(M_PI / 2, ToRadians(90.0)));
    CHECK(IsSame(M_PI, ToRadians(180.0)));
    CHECK(IsSame(M_PI * 2, ToRadians(360.0)));
    CHECK(IsSame(M_PI * 4, ToRadians(720.0)));

    CHECK(IsSame(45.0, ToAngle(M_PI / 4)));
    CHECK(IsSame(90.0, ToAngle(M_PI / 2)));
    CHECK(IsSame(180.0, ToAngle(M_PI)));
    CHECK(IsSame(360.0, ToAngle(M_PI * 2)));
    CHECK(IsSame(720.0, ToAngle(M_PI * 4)));
}
TESTCASE_END

TESTCASE("Sin, cos, tan and cot functions test") {
    CHECK(IsSame(Sin(0.0), 0));
    CHECK(IsSame(Sin(30.0), 0.5));
    CHECK(IsSame(Sin(45.0), sqrt(2) / 2));
    CHECK(IsSame(Sin(60.0), sqrt(3) / 2));
    CHECK(IsSame(Sin(90.0), 1));

    CHECK(IsSame(Cos(0.0), 1));
    CHECK(IsSame(Cos(30.0), sqrt(3) / 2));
    CHECK(IsSame(Cos(45.0), sqrt(2) / 2));
    CHECK(IsSame(Cos(60.0), 0.5));
    CHECK(IsSame(Cos(90.0), 0));

    CHECK(IsSame(Tan(0.0), 0));
    CHECK(IsSame(Tan(30.0), sqrt(3) / 3));
    CHECK(IsSame(Tan(45.0), 1));
    CHECK(IsSame(Tan(60.0), sqrt(3)));

    CHECK(IsSame(Cot(30.0), sqrt(3)));
    CHECK(IsSame(Cot(45.0), 1));
    CHECK(IsSame(Cot(60.0), sqrt(3) / 3));
    CHECK(IsSame(Cot(90.0), 0));
}
TESTCASE_END

TESTCASE("Common operators test") {
    Vector2D vec1 = { 1.0, 2.0 };
    Vector2D vec2 = { 4.0, 233.33 };
    Vector2D vec3 = { -1.0, -233.77 };

    Matrix3 mat1 = IdentityMatrix();
    Matrix3 mat2 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    Matrix3 mat3 = { -9.0, 8.0, -76.5, 233.4, 123.321, 2.2, 0.0, 0.0, 4.3 };

    CHECK(Add(vec1, vec2) == vec1 + vec2);
    CHECK(Add(vec2, vec3) == vec2 + vec3);
    CHECK(Add(vec3, vec1) == vec3 + vec1);
    CHECK(Add(mat1, mat2) == mat1 + mat2);
    CHECK(Add(mat2, mat3) == mat2 + mat3);
    CHECK(Add(mat3, mat1) == mat3 + mat1);

    CHECK(Subtract(vec1, vec2) == vec1 - vec2);
    CHECK(Subtract(vec2, vec3) == vec2 - vec3);
    CHECK(Subtract(vec3, vec1) == vec3 - vec1);
    CHECK(Subtract(mat1, mat2) == mat1 - mat2);
    CHECK(Subtract(mat2, mat3) == mat2 - mat3);
    CHECK(Subtract(mat3, mat1) == mat3 - mat1);

    CHECK(Scale(vec1, 1) == vec1 * 1);
    CHECK(Scale(vec2, 2) == vec2 * 2);
    CHECK(Scale(vec3, 3) == vec3 * 3);
    CHECK(Scale(4, mat1) == mat1 * 4);
    CHECK(Scale(5, mat2) == mat2 * 5);
    CHECK(Scale(6, mat3) == mat3 * 6);

    CHECK(Multiply(mat1, mat2) == mat1 * mat2);
    CHECK(Multiply(mat2, mat3) == mat2 * mat3);
    CHECK(Multiply(mat3, mat1) == mat3 * mat1);
    CHECK(Multiply(mat1, vec1) == mat1 * vec1);
    CHECK(Multiply(mat2, vec2) == mat2 * vec2);
    CHECK(Multiply(mat3, vec3) == mat3 * vec3);
    CHECK(Multiply(mat2, mat3) != Multiply(mat3, mat2));
    CHECK(Multiply(mat1, mat2) == Multiply(mat2, mat1));
    CHECK(Multiply(mat1, mat3) == Multiply(mat3, mat1));

    CHECK(Multiply(mat1, ZeroMatrix()) == ZeroMatrix());
    CHECK(Multiply(ZeroMatrix(), mat3) == ZeroMatrix());
    CHECK(Multiply(ZeroMatrix(), mat2) == Multiply(mat2, ZeroMatrix()));

    CHECK(Add(vec1, vec2) != vec2 + vec3);
    CHECK(Subtract(mat2, mat3) != mat1 - mat3);
    CHECK(Scale(vec3, 3.4) != vec3 * 2.4);
    CHECK(Multiply(mat1, mat1) != mat1 * mat2);
}
TESTCASE_END

TESTCASE("Vector2D operators test") {
    CHECK(Abs(Vector2D(1, 1)) == Vector2D(1, 1));
    CHECK(Abs(Vector2D(-13, 1)) == Vector2D(13, 1));
    CHECK(Abs(Vector2D(1, -3)) == Vector2D(1, 3));
    CHECK(Abs(Vector2D(-1, -1)) == Vector2D(1, 1));

    CHECK(IsSame(Length(Vector2D(1, 1)), std::sqrt(2)));
    CHECK(IsSame(Length(Vector2D(2, 2)), std::sqrt(8)));
    CHECK(IsSame(Length(Vector2D(3, 4)), 5));

    Vector2D vec = { 1.2, 55.98 };
    Vector2D vec2 = { 2, 3 };
    Vector2D vec3 = { -5, 6 };
    CHECK(IsSame(vec * vec2, DotMultiply(vec, vec2)));
    CHECK(IsSame(vec2 * vec3, DotMultiply(vec2, vec3)));
    CHECK(IsSame(vec3 * vec, DotMultiply(vec, vec3)));

    CHECK(IsSame(vec % vec2, CrossMultiply(vec, vec2)));
    CHECK(IsSame(vec % vec3, CrossMultiply(vec, vec3)));
    CHECK(IsSame(vec2 % vec, CrossMultiply(vec2, vec)));

    CHECK(Min(Vector2D(1, 2), Vector2D(2, 1)) == Vector2D(1, 1));
    CHECK(Max(Vector2D(1, 2), Vector2D(2, 1)) == Vector2D(2, 2));

    CHECK(Rotate(Vector2D(1, 1), Vector2D(0, 0), 90) == -Vector2D(1, -1));
    CHECK(Rotate(Vector2D(1, 1), Vector2D(0, 0), -90) == -Vector2D(-1, 1));
    CHECK(Rotate(Vector2D(1, 1), Vector2D(0, 0), 180) ==
          Rotate(Vector2D(1, 1), Vector2D(0, 0), -180));
    CHECK(Rotate(Vector2D(1, 1), Vector2D(1, 1), 90) == Vector2D(1, 1));

    CHECK(Normalize(Vector2D(1, 0)) == Vector2D(1, 0));
    CHECK(Normalize(Vector2D(1, 1)) ==
          Vector2D(std::sqrt(2) / 2, std::sqrt(2) / 2));

    CHECK(Lerp(Vector2D(1, 1), Vector2D(3, 3), 0.5f) == Vector2D(2, 2));
    CHECK(Lerp(Vector2D(0, 0), Vector2D(4, 4), 0.5f) == Vector2D(2, 2));
    CHECK(Lerp(Vector2D(1, 1), Vector2D(3, 3), 2) == Vector2D(5, 5));
}
TESTCASE_END

TESTCASE("Matrix operators test") {
    ASSERT(ZeroMatrix() == Matrix3(0, 0, 0, 0, 0, 0, 0, 0, 0));
    ASSERT(IdentityMatrix() == Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1));

    Vector2D vec = { 1, 1 };
    CHECK(TranslateMatrix(1.0, 1.0) * vec == Vector2D(2, 2));
    CHECK(TranslateMatrix(-1.0, -1.0) * vec == Vector2D(0, 0));
    CHECK(TranslateMatrix(100.0, 1.0) * vec == Vector2D(101, 2));

    CHECK(ScaleMatrix(1.0, 1.0) * vec == vec);
    CHECK(ScaleMatrix(2.0, 2.0) * vec == Vector2D(2, 2));
    CHECK(ScaleMatrix(100.0, 0.5) * vec == Vector2D(100, 0.5));

    CHECK(RotateMatrix(90.0) * vec == Vector2D(1, -1));
    CHECK(RotateMatrix(-90.0) * vec == Vector2D(-1, 1));
    CHECK((RotateMatrix(360.0) * vec).ToString() == vec.ToString());
    CHECK((RotateMatrix(180.0) * vec).ToString() ==
          Vector2D(-1, -1).ToString());

    vec = Vector2D(1, 1);
    Matrix3 final = IdentityMatrix();
    final = TranslateMatrix(final, 5.0, 5.0);
    ASSERT((final * vec).ToString() == Vector2D(6, 6).ToString());

    final = ScaleMatrix(final, 0.5, 2.0);
    ASSERT((final * vec).ToString() == Vector2D(3, 12).ToString());

    final = RotateMatrix(final, 90.0);
    ASSERT((final * vec).ToString() == Vector2D(12, -3).ToString());
}
TESTCASE_END

TESTCASE("Rectangle operators test") {
    CHECK(Intersect(Rectangle(1, 1, 2, 2), Rectangle(2, 2, 2, 2)) ==
          Rectangle(2, 2, 1, 1));
    CHECK(Intersect(Rectangle(100, 100, 2, 2), Rectangle(2, 2, 2, 2)) ==
          Rectangle(0, 0, 0, 0));
    CHECK(Intersect(Rectangle(1, 1, 1, 1), Rectangle(2, 2, 2, 2)) ==
          Rectangle(2, 2, 0, 0));

    CHECK(Union(Rectangle(1, 1, 2, 2), Rectangle(2, 2, 2, 2)) ==
          Rectangle(1, 1, 3, 3));
    CHECK(Union(Rectangle(100, 100, 2, 2), Rectangle(2, 2, 2, 2)) ==
          Rectangle(2, 2, 100, 100));
    CHECK(Union(Rectangle(1, 1, 1, 1), Rectangle(2, 2, 2, 2)) !=
          Rectangle(1, 1, 4, 4));
    CHECK(Union(Rectangle(1, 1, 1, 1), Rectangle(2, 2, 2, 2)) ==
          Rectangle(1, 1, 3, 3));

    CHECK(FromLTRB(0, 0, 10, 10) == Rectangle(0, 0, 10, 10));
    CHECK(FromLTRB(1, 1, 10, 10) == Rectangle(1, 1, 9, 9));
    CHECK(FromLTRB(1, 1, 10, 10) != Rectangle(1, 1, 10, 10));

    CHECK(FromLTRB(0, 0, 10, 10) ==
          FromTwoVector(Vector2D(0, 0), Vector2D(10, 10)));
    CHECK(FromLTRB(1, 1, 10, 10) ==
          FromTwoVector(Vector2D(1, 1), Vector2D(10, 10)));
    CHECK(FromLTRB(1, 1, 10, 10) !=
          FromTwoVector(Vector2D(1, 1), Vector2D(9, 9)));
}
TESTCASE_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
