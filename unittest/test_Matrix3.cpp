//
// Copyright 2015 riteme
//

#include <cassert>
#include <utility>
#include <iostream>

#include "../src/math/Matrix3.hpp"

#include "../src/utility/FloatComparison.hpp"

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

inline auto IdentityMatrix() -> Matrix3 {
    return { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
}

int main(/*int argc, char *argv[]*/) {
    Matrix3 mat = Matrix3();
    Matrix3 mat2 = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    assert(mat.M11() == 0.0);
    assert(mat.M12() == 0.0);
    assert(mat.M13() == 0.0);
    assert(mat.M21() == 0.0);
    assert(mat.M22() == 0.0);
    assert(mat.M23() == 0.0);
    assert(mat.M31() == 0.0);
    assert(mat.M32() == 0.0);
    assert(mat.M33() == 0.0);

    Matrix3 mat4 = -mat2;
    assert(IsSame(mat4.M11(), -mat2.M11()));
    assert(IsSame(mat4.M12(), -mat2.M12()));
    assert(IsSame(mat4.M13(), -mat2.M13()));
    assert(IsSame(mat4.M21(), -mat2.M21()));
    assert(IsSame(mat4.M22(), -mat2.M22()));
    assert(IsSame(mat4.M23(), -mat2.M23()));
    assert(IsSame(mat4.M31(), -mat2.M31()));
    assert(IsSame(mat4.M32(), -mat2.M32()));
    assert(IsSame(mat4.M33(), -mat2.M33()));

    mat = IdentityMatrix();

    assert(mat.M11() == 1.0);
    assert(mat.M12() == 0.0);
    assert(mat.M13() == 0.0);
    assert(mat.M21() == 0.0);
    assert(mat.M22() == 1.0);
    assert(mat.M23() == 0.0);
    assert(mat.M31() == 0.0);
    assert(mat.M32() == 0.0);
    assert(mat.M33() == 1.0);

    assert(mat2.M11() == 1.0);
    assert(mat2.M12() == 1.0);
    assert(mat2.M13() == 1.0);
    assert(mat2.M21() == 1.0);
    assert(mat2.M22() == 1.0);
    assert(mat2.M23() == 1.0);
    assert(mat2.M31() == 1.0);
    assert(mat2.M32() == 1.0);
    assert(mat2.M33() == 1.0);

    Matrix3 mat3 = move(mat2);
    assert(mat2.IsVaild() == false);
    assert(mat3.IsVaild() == true);
    assert(mat3.M11() == 1.0);
    assert(mat3.M12() == 1.0);
    assert(mat3.M13() == 1.0);
    assert(mat3.M21() == 1.0);
    assert(mat3.M22() == 1.0);
    assert(mat3.M23() == 1.0);
    assert(mat3.M31() == 1.0);
    assert(mat3.M32() == 1.0);
    assert(mat3.M33() == 1.0);

    mat3.M21() = 3.0;
    mat3.M12() = 3.0;
    mat3.M32() = 4.5;
    assert(mat3.M11() == 1.0);
    assert(mat3.M12() == 3.0);
    assert(mat3.M13() == 1.0);
    assert(mat3.M21() == 3.0);
    assert(mat3.M22() == 1.0);
    assert(mat3.M23() == 1.0);
    assert(mat3.M31() == 1.0);
    assert(mat3.M32() == 4.5);
    assert(mat3.M33() == 1.0);

    mat2 = move(mat3);
    assert(mat3.IsVaild() == false);
    assert(mat2.IsVaild() == true);
    assert(mat2.M11() == 1.0);
    assert(mat2.M12() == 3.0);
    assert(mat2.M13() == 1.0);
    assert(mat2.M21() == 3.0);
    assert(mat2.M22() == 1.0);
    assert(mat2.M23() == 1.0);
    assert(mat2.M31() == 1.0);
    assert(mat2.M32() == 4.5);
    assert(mat2.M33() == 1.0);

    mat3 = Matrix3(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    assert(mat3.M11() == 1.0);
    assert(mat3.M12() == 2.0);
    assert(mat3.M13() == 3.0);
    assert(mat3.M21() == 4.0);
    assert(mat3.M22() == 5.0);
    assert(mat3.M23() == 6.0);
    assert(mat3.M31() == 7.0);
    assert(mat3.M32() == 8.0);
    assert(mat3.M33() == 9.0);

    auto mat1 = mat;
    assert(mat1 == mat);
    assert(mat2 != mat3);

    mat1.Transpose();
    mat2.Transpose();
    mat3.Transpose();
    assert(mat1 == mat);
    assert(mat2.M11() == 1.0);
    assert(mat2.M12() == 3.0);
    assert(mat2.M13() == 1.0);
    assert(mat2.M21() == 3.0);
    assert(mat2.M22() == 1.0);
    assert(mat2.M23() == 4.5);
    assert(mat2.M31() == 1.0);
    assert(mat2.M32() == 1.0);
    assert(mat2.M33() == 1.0);

    assert(mat3.M11() == 1.0);
    assert(mat3.M12() == 4.0);
    assert(mat3.M13() == 7.0);
    assert(mat3.M21() == 2.0);
    assert(mat3.M22() == 5.0);
    assert(mat3.M23() == 8.0);
    assert(mat3.M31() == 3.0);
    assert(mat3.M32() == 6.0);
    assert(mat3.M33() == 9.0);

    mat2.Transpose();
    mat3.Transpose();

    Float *m = mat3.GetMatrixArray();
    assert(m[0] == 1.0);
    assert(m[1] == 2.0);
    assert(m[2] == 3.0);
    assert(m[3] == 4.0);
    assert(m[4] == 5.0);
    assert(m[5] == 6.0);
    assert(m[6] == 7.0);
    assert(m[7] == 8.0);
    assert(m[8] == 9.0);

    assert(mat + mat2 == Matrix3(2, 3, 1, 3, 2, 1, 1, 4.5, 2));
    assert(mat2 + mat3 == Matrix3(2, 5, 4, 7, 6, 7, 8, 12.5, 10));
    assert(mat + mat3 == Matrix3(2, 2, 3, 4, 6, 6, 7, 8, 10));

    assert(mat - mat2 == Matrix3(0, -3, -1, -3, 0, -1, -1, -4.5, 0));
    assert(mat3 - mat2 == Matrix3(0, -1, 2, 1, 4, 5, 6, 3.5, 8));
    assert(mat1 - mat == Matrix3(0, 0, 0, 0, 0, 0, 0, 0, 0));

    assert(mat * mat2 == mat2);
    assert(mat * mat3 == mat3);

    assert(3 * mat1 == Matrix3(3, 0, 0, 0, 3, 0, 0, 0, 3));
    assert(mat3 * 2 == Matrix3(2, 4, 6, 8, 10, 12, 14, 16, 18));
    assert(mat2 / 2 == Matrix3(0.5, 1.5, 0.5, 1.5, 0.5, 0.5, 0.5, 2.25, 0.5));

    assert(mat2 * mat3 == Matrix3(20, 25, 30, 14, 19, 24, 26, 32.5, 39));

    Vector2D vec = { 1, 1 };
    assert(mat3 * vec == Vector2D(6, 15));

    mat2 *= 2;
    assert(mat2.M11() == 2.0);
    assert(mat2.M12() == 6.0);
    assert(mat2.M13() == 2.0);
    assert(mat2.M21() == 6.0);
    assert(mat2.M22() == 2.0);
    assert(mat2.M23() == 2.0);
    assert(mat2.M31() == 2.0);
    assert(mat2.M32() == 9.0);
    assert(mat2.M33() == 2.0);

    assert(mat1.HashCode() == mat.HashCode());
    assert(mat1.HashCode() != mat2.HashCode());

    assert(mat1.ToString() == "[[1, 0, 0] [0, 1, 0] [0, 0, 1]]");
    assert(mat2.ToString() == "[[2, 6, 2] [6, 2, 2] [2, 9, 2]]");
    assert(mat3.ToString() == "[[1, 2, 3] [4, 5, 6] [7, 8, 9]]");

    return 0;
}  // function main
