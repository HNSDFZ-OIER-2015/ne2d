//
// Copyright 2015 riteme
//

#include "../src/Matrix3.hpp"
#include "../src/Math.hpp"
#include "../src/FloatComparison.hpp"

#include <cassert>
#include <utility>
#include <iostream>

using namespace std;
using namespace ne;
using namespace ne::math;
using namespace ne::utility;

int main(/*int argc, char *argv[]*/) {
    BasicMatrix3<double> mat = Identity<double>();
    BasicMatrix3<double> mat2 = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

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

    BasicMatrix3<double> mat3 = move(mat2);
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

    mat3 = BasicMatrix3<double>(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
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
    assert(Transpose(mat1) == mat);
    assert(Transpose(mat2) != mat2);
    assert(Transpose(mat3) != mat3);

    double *m = mat3.GetMatrixArray();
    assert(m[0] == 1.0);
    assert(m[1] == 2.0);
    assert(m[2] == 3.0);
    assert(m[3] == 4.0);
    assert(m[4] == 5.0);
    assert(m[5] == 6.0);
    assert(m[6] == 7.0);
    assert(m[7] == 8.0);
    assert(m[8] == 9.0);

    assert(mat + mat2 == BasicMatrix3<double>(2, 3, 1, 3, 2, 1, 1, 4.5, 2));
    assert(mat2 + mat3 == BasicMatrix3<double>(2, 5, 4, 7, 6, 7, 8, 12.5, 10));
    assert(mat + mat3 == BasicMatrix3<double>(2, 2, 3, 4, 6, 6, 7, 8, 10));

    assert(mat - mat2 ==
           BasicMatrix3<double>(0, -3, -1, -3, 0, -1, -1, -4.5, 0));
    assert(mat3 - mat2 == BasicMatrix3<double>(0, -1, 2, 1, 4, 5, 6, 3.5, 8));
    assert(mat1 - mat == BasicMatrix3<double>(0, 0, 0, 0, 0, 0, 0, 0, 0));

    assert(mat * mat2 == mat2);
    assert(mat * mat3 == mat3);

    assert(mat1 * 3 == BasicMatrix3<double>(3, 0, 0, 0, 3, 0, 0, 0, 3));
    assert(mat3 * 2 == BasicMatrix3<double>(2, 4, 6, 8, 10, 12, 14, 16, 18));
    assert(mat2 / 2 ==
           BasicMatrix3<double>(0.5, 1.5, 0.5, 1.5, 0.5, 0.5, 0.5, 2.25, 0.5));

    assert(mat2 * mat3 ==
           BasicMatrix3<double>(20, 25, 30, 14, 19, 24, 26, 32.5, 39));

    BasicVector2D<double> vec = { 1, 1, 1 };
    assert(mat3 * vec == BasicVector2D<double>(6, 15, 24));

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

    assert(mat1 * vec == Multiply(mat1, vec));
    assert(mat2 * vec == Multiply(mat2, vec));
    assert(mat3 * vec == Multiply(mat3, vec));

    assert(MatrixTranslate(1.0, 1.0) * vec == BasicVector2D<double>(2, 2));
    assert(MatrixTranslate(-1.0, -1.0) * vec == BasicVector2D<double>(0, 0));
    assert(MatrixTranslate(100.0, 1.0) * vec == BasicVector2D<double>(101, 2));

    assert(MatrixScale(1.0, 1.0) * vec == vec);
    assert(MatrixScale(2.0, 2.0) * vec == BasicVector2D<double>(2, 2));
    assert(MatrixScale(100.0, 0.5) * vec == BasicVector2D<double>(100, 0.5));

    assert(MatrixRotate(90.0) * vec == BasicVector2D<double>(1, -1));
    assert(MatrixRotate(-90.0) * vec == BasicVector2D<double>(-1, 1));
    assert((MatrixRotate(360.0) * vec).ToString() == vec.ToString());
    assert((MatrixRotate(180.0) * vec).ToString() ==
           BasicVector2D<double>(-1, -1).ToString());

    BasicMatrix3<double> final;
    final = MatrixTranslate(final, 5.0, 5.0);
    assert((final * vec).ToString() == BasicVector2D<double>(6, 6).ToString());

    final = MatrixScale(final, 0.5, 2.0);
    assert((final * vec).ToString() == BasicVector2D<double>(3, 12).ToString());

    final = MatrixRotate(final, 90.0);
    assert((final * vec).ToString() ==
           BasicVector2D<double>(12, -3).ToString());

    return 0;
}  // function main
