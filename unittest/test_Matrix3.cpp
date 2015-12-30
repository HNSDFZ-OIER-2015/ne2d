//
// Copyright 2015 riteme
//

#include "test.hpp"

#include <ne2d/math/Matrix3.hpp>
#include <ne2d/utility/FloatComparison.hpp>

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

inline auto IdentityMatrix() -> Matrix3 {
    return { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
}

TESTCASE_GROUP_BEGIN

TESTCASE("Constructor, attributes and function Transpose() test") {
    Matrix3 mat = Matrix3();

    CHECK(IsSame(mat.M11(), 0));
    CHECK(IsSame(mat.M12(), 0));
    CHECK(IsSame(mat.M13(), 0));
    CHECK(IsSame(mat.M21(), 0));
    CHECK(IsSame(mat.M22(), 0));
    CHECK(IsSame(mat.M23(), 0));
    CHECK(IsSame(mat.M31(), 0));
    CHECK(IsSame(mat.M32(), 0));
    CHECK(IsSame(mat.M33(), 0));

    mat = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    CHECK(IsSame(mat.M11(), 1));
    CHECK(IsSame(mat.M12(), 1));
    CHECK(IsSame(mat.M13(), 1));
    CHECK(IsSame(mat.M21(), 1));
    CHECK(IsSame(mat.M22(), 1));
    CHECK(IsSame(mat.M23(), 1));
    CHECK(IsSame(mat.M31(), 1));
    CHECK(IsSame(mat.M32(), 1));
    CHECK(IsSame(mat.M33(), 1));

    mat = IdentityMatrix();
    CHECK(IsSame(mat.M11(), 1));
    CHECK(IsSame(mat.M12(), 0));
    CHECK(IsSame(mat.M13(), 0));
    CHECK(IsSame(mat.M21(), 0));
    CHECK(IsSame(mat.M22(), 1));
    CHECK(IsSame(mat.M23(), 0));
    CHECK(IsSame(mat.M31(), 0));
    CHECK(IsSame(mat.M32(), 0));
    CHECK(IsSame(mat.M33(), 1));

    mat = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat.Transpose();
    CHECK(IsSame(mat.M11(), 1));
    CHECK(IsSame(mat.M12(), 4));
    CHECK(IsSame(mat.M13(), 7));
    CHECK(IsSame(mat.M21(), 2));
    CHECK(IsSame(mat.M22(), 5));
    CHECK(IsSame(mat.M23(), 8));
    CHECK(IsSame(mat.M31(), 3));
    CHECK(IsSame(mat.M32(), 6));
    CHECK(IsSame(mat.M33(), 9));

    mat.Transpose();
    CHECK(IsSame(mat.M11(), 1));
    CHECK(IsSame(mat.M12(), 2));
    CHECK(IsSame(mat.M13(), 3));
    CHECK(IsSame(mat.M21(), 4));
    CHECK(IsSame(mat.M22(), 5));
    CHECK(IsSame(mat.M23(), 6));
    CHECK(IsSame(mat.M31(), 7));
    CHECK(IsSame(mat.M32(), 8));
    CHECK(IsSame(mat.M33(), 9));

    mat.M11() = mat.M12() = mat.M13() = mat.M21() = mat.M22() = mat.M23() =
        mat.M31() = mat.M32() = mat.M33() = 1;
    CHECK(IsSame(mat.M11(), 1));
    CHECK(IsSame(mat.M12(), 1));
    CHECK(IsSame(mat.M13(), 1));
    CHECK(IsSame(mat.M21(), 1));
    CHECK(IsSame(mat.M22(), 1));
    CHECK(IsSame(mat.M23(), 1));
    CHECK(IsSame(mat.M31(), 1));
    CHECK(IsSame(mat.M32(), 1));
    CHECK(IsSame(mat.M33(), 1));
}
TESTCASE_END

TESTCASE("Function GetMatrixArray() test") {
    Matrix3 mat = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    Float *m = mat.GetMatrixArray();
    CHECK(IsSame(m[0], 1));
    CHECK(IsSame(m[1], 2));
    CHECK(IsSame(m[2], 3));
    CHECK(IsSame(m[3], 4));
    CHECK(IsSame(m[4], 5));
    CHECK(IsSame(m[5], 6));
    CHECK(IsSame(m[6], 7));
    CHECK(IsSame(m[7], 8));
    CHECK(IsSame(m[8], 9));
}
TESTCASE_END

TESTCASE("Operator == and != test") {
    Matrix3 mat1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    Matrix3 mat2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    Matrix3 mat3 = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };

    CHECK(mat1 == mat2);
    CHECK(mat1 != mat3);
    CHECK(mat2 != mat3);
}
TESTCASE_END

TESTCASE("Copy and move constructor test") {
    Matrix3 mat1 = Matrix3();
    Matrix3 mat2 = IdentityMatrix();
    Matrix3 mat_copy1(mat1);
    Matrix3 mat_copy2 = mat2;

    ASSERT(mat_copy1 == mat1);
    ASSERT(mat_copy2 == mat2);

    Matrix3 mat_move1(std::move(mat1));
    Matrix3 mat_move2 = std::move(mat2);
    ASSERT(mat1.IsVaild() == false);
    ASSERT(mat2.IsVaild() == false);
    CHECK(mat_move1 == mat_copy1);
    CHECK(mat_move2 == mat_copy2);
}
TESTCASE_END

TESTCASE("Matrix operators test") {
    Matrix3 mat1 = Matrix3();
    Matrix3 mat2 = IdentityMatrix();
    Matrix3 mat3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix3 mat4 = { 1.1, 7.8, 4, 5, 1, 0, 2.33, 0.7, -1 };

    CHECK(mat2 + mat1 == mat2);
    CHECK(mat1 + mat3 == mat3);
    CHECK(mat2 + mat3 == Matrix3(2, 2, 3, 4, 6, 6, 7, 8, 10));
    CHECK(mat3 + mat4 == Matrix3(2.1, 9.8, 7, 9, 6, 6, 9.33, 8.7, 8));

    CHECK(mat1 - mat2 == -mat2);
    CHECK(mat1 - mat4 == -mat4);
    CHECK(mat3 - mat2 == Matrix3(0, 2, 3, 4, 4, 6, 7, 8, 8));
    CHECK(mat3 - mat4 == Matrix3(-0.1, -5.8, -1, -1, 4, 6, 4.67, 7.3, 10));

    CHECK(+mat3 == mat3);
    CHECK(+mat4 == mat4);
    CHECK(-mat3 == Matrix3(-1, -2, -3, -4, -5, -6, -7, -8, -9));
    CHECK(-mat4 == Matrix3(-1.1, -7.8, -4, -5, -1, 0, -2.33, -0.7, 1));

    CHECK(mat3 * 2 == Matrix3(2, 4, 6, 8, 10, 12, 14, 16, 18));
    CHECK(mat4 * 2 == Matrix3(2.2, 15.6, 8, 10, 2, 0, 4.66, 1.4, -2));
    CHECK(2 * mat3 == mat3 * 2);
    CHECK(-1 * mat3 == -mat3);
    CHECK(3 * mat4 == mat4 * 3);
    CHECK(mat3 / 0.5 == mat3 * 2);
    CHECK(mat4 / 0.25 == mat4 * 4);

    CHECK(mat3 * Vector2D(2, 3) == Vector2D(11, 29));
    CHECK(mat3 * Vector2D(4, 5) == Vector2D(17, 47));
    CHECK(mat4 * Vector2D(4, 5) == Vector2D(47.4, 25));
    CHECK(mat4 * Vector2D(4, -1) == Vector2D(0.6, 19));

    CHECK(mat1 * mat2 == mat1);
    CHECK(mat1 * mat3 == mat1);
    CHECK(mat2 * mat3 == mat3);
    CHECK(mat2 * mat4 == mat4);
    CHECK(mat3 * mat4 ==
          Matrix3(18.09, 11.9, 1, 43.38, 40.4, 10, 68.67, 68.9, 19));
    CHECK(mat4 * mat3 ==
          Matrix3(60.3, 73.2, 86.1, 9, 15, 21, -1.87, 0.16, 2.19));

    Matrix3 mat = mat1;
    ASSERT(mat == mat1);

    mat += mat2;
    ASSERT(mat == mat1 + mat2);

    mat -= mat3;
    ASSERT(mat == mat1 + mat2 - mat3);

    mat = mat3;
    ASSERT(mat == mat3);

    mat *= 4.5;
    ASSERT(mat == mat3 * 4.5);

    mat /= 6.7;
    ASSERT(mat == (mat3 * 4.5) / 6.7);

    mat = mat4;
    ASSERT(mat == mat4);

    mat *= mat3;
    ASSERT(mat == mat4 * mat3);

    mat *= mat4;
    ASSERT(mat == mat4 * mat3 * mat4);
}
TESTCASE_END

TESTCASE("ToString and HashCode test") {
    Matrix3 mat1 = IdentityMatrix();
    Matrix3 mat2 = Matrix3();
    Matrix3 mat3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix3 mat4 = { 1.1, 7.8, 4, 5, 1, 0, 2.33, 0.7, -1 };

    CHECK(mat1.ToString() == "[[1, 0, 0] [0, 1, 0] [0, 0, 1]]");
    CHECK(mat2.ToString() == "[[0, 0, 0] [0, 0, 0] [0, 0, 0]]");
    CHECK(mat3.ToString() == "[[1, 2, 3] [4, 5, 6] [7, 8, 9]]");
    CHECK(mat4.ToString() == "[[1.1, 7.8, 4] [5, 1, 0] [2.33, 0.7, -1]]");

    CHECK(mat1.HashCode() != mat2.HashCode());
    CHECK(mat2.HashCode() != mat3.HashCode());
    CHECK(mat3.HashCode() != mat4.HashCode());
    CHECK(mat4.HashCode() != mat1.HashCode());
    CHECK(mat1.HashCode() == IdentityMatrix().HashCode());
    CHECK(mat2.HashCode() == Matrix3().HashCode());
}
TESTCASE_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
