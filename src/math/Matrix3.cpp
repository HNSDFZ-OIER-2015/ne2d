//
// Copyright 2015 riteme
//

#include "Matrix3.hpp"

#include "utility/FloatComparison.hpp"

namespace ne::math {
    // 索引方式为先行后列
    // 数组索引表
    //  |0 1 2
    // -+-----
    // 0|0 1 2
    // 1|3 4 5
    // 2|6 7 8
    auto Matrix3::M11() const noexcept->ValueType { return m_pMatrix[0]; }

    auto Matrix3::M12() const noexcept->ValueType {
        return m_bIsTransposed ? m_pMatrix[3] : m_pMatrix[1];
    }

    auto Matrix3::M13() const noexcept->ValueType {
        return m_bIsTransposed ? m_pMatrix[6] : m_pMatrix[2];
    }

    auto Matrix3::M21() const noexcept->ValueType {
        return m_bIsTransposed ? m_pMatrix[1] : m_pMatrix[3];
    }

    auto Matrix3::M22() const noexcept->ValueType { return m_pMatrix[4]; }

    auto Matrix3::M23() const noexcept->ValueType {
        return m_bIsTransposed ? m_pMatrix[7] : m_pMatrix[5];
    }

    auto Matrix3::M31() const noexcept->ValueType {
        return m_bIsTransposed ? m_pMatrix[2] : m_pMatrix[6];
    }

    auto Matrix3::M32() const noexcept->ValueType {
        return m_bIsTransposed ? m_pMatrix[5] : m_pMatrix[7];
    }

    auto Matrix3::M33() const noexcept->ValueType { return m_pMatrix[8]; }

    // 可做左值
    auto Matrix3::M11() noexcept->ValueType & { return m_pMatrix[0]; }

    auto Matrix3::M12() noexcept->ValueType & {
        return m_bIsTransposed ? m_pMatrix[3] : m_pMatrix[1];
    }

    auto Matrix3::M13() noexcept->ValueType & {
        return m_bIsTransposed ? m_pMatrix[6] : m_pMatrix[2];
    }

    auto Matrix3::M21() noexcept->ValueType & {
        return m_bIsTransposed ? m_pMatrix[1] : m_pMatrix[3];
    }

    auto Matrix3::M22() noexcept->ValueType & { return m_pMatrix[4]; }

    auto Matrix3::M23() noexcept->ValueType & {
        return m_bIsTransposed ? m_pMatrix[7] : m_pMatrix[5];
    }

    auto Matrix3::M31() noexcept->ValueType & {
        return m_bIsTransposed ? m_pMatrix[2] : m_pMatrix[6];
    }

    auto Matrix3::M32() noexcept->ValueType & {
        return m_bIsTransposed ? m_pMatrix[5] : m_pMatrix[7];
    }

    auto Matrix3::M33() noexcept->ValueType & { return m_pMatrix[8]; }

    void Matrix3::Transpose() noexcept { m_bIsTransposed = !m_bIsTransposed; }

    auto Matrix3::IsVaild() const noexcept->bool {
        return m_pMatrix != nullptr;
    }

    auto Matrix3::GetMatrixArray() const noexcept->ValueType * {
        return m_pMatrix;
    }

    auto operator==(const Matrix3 &a, const Matrix3 &b)->bool {
        return ne::utility::IsSame(a.M11(), b.M11()) and
               ne::utility::IsSame(a.M12(), b.M12()) and
               ne::utility::IsSame(a.M13(), b.M13()) and
               ne::utility::IsSame(a.M21(), b.M21()) and
               ne::utility::IsSame(a.M22(), b.M22()) and
               ne::utility::IsSame(a.M23(), b.M23()) and
               ne::utility::IsSame(a.M31(), b.M31()) and
               ne::utility::IsSame(a.M32(), b.M32()) and
               ne::utility::IsSame(a.M33(), b.M33());
    }

    auto operator!=(const Matrix3 &a, const Matrix3 &b)->bool {
        return !(a == b);
    }

    auto operator+(const Matrix3 &a, const Matrix3 &b)->Matrix3 {
        Matrix3 mat = {
            a.M11() + b.M11(), a.M12() + b.M12(), a.M13() + b.M13(),
            a.M21() + b.M21(), a.M22() + b.M22(), a.M23() + b.M23(),
            a.M31() + b.M31(), a.M32() + b.M32(), a.M33() + b.M33()
        };

        return mat;
    }

    auto operator-(const Matrix3 &a, const Matrix3 &b)->Matrix3 {
        Matrix3 mat = {
            a.M11() - b.M11(), a.M12() - b.M12(), a.M13() - b.M13(),
            a.M21() - b.M21(), a.M22() - b.M22(), a.M23() - b.M23(),
            a.M31() - b.M31(), a.M32() - b.M32(), a.M33() - b.M33()
        };

        return mat;
    }

    auto operator+(Matrix3 a)->Matrix3 { return a; }

    auto operator-(Matrix3 a)->Matrix3 {
        a *= -1;

        return a;
    }

    auto operator*(const Matrix3 &a, const Matrix3::ValueType &b)->Matrix3 {
        Matrix3 mat = { a.M11() * b, a.M12() * b, a.M13() * b,
                        a.M21() * b, a.M22() * b, a.M23() * b,
                        a.M31() * b, a.M32() * b, a.M33() * b };

        return mat;
    }

    auto operator*(const Matrix3::ValueType &b, const Matrix3 &a)->Matrix3 {
        Matrix3 mat = { a.M11() * b, a.M12() * b, a.M13() * b,
                        a.M21() * b, a.M22() * b, a.M23() * b,
                        a.M31() * b, a.M32() * b, a.M33() * b };

        return mat;
    }

    auto operator/(const Matrix3 &a, const Matrix3::ValueType &b)->Matrix3 {
        Matrix3 mat = { a.M11() / b, a.M12() / b, a.M13() / b,
                        a.M21() / b, a.M22() / b, a.M23() / b,
                        a.M31() / b, a.M32() / b, a.M33() / b };

        return mat;
    }

    auto operator/(const Matrix3::ValueType &b, const Matrix3 &a)->Matrix3 {
        Matrix3 mat = { a.M11() / b, a.M12() / b, a.M13() / b,
                        a.M21() / b, a.M22() / b, a.M23() / b,
                        a.M31() / b, a.M32() / b, a.M33() / b };

        return mat;
    }

    auto operator*(const Matrix3 &a, const Matrix3::VectorType &b)
        ->Matrix3::VectorType {
        Matrix3::VectorType vec = {
            a.M11() * b.X() + a.M12() * b.Y() + a.M13() * b.Z(),
            a.M21() * b.X() + a.M22() * b.Y() + a.M23() * b.Z()
        };

        return vec;
    }

    auto operator*(const Matrix3 &a, const Matrix3 &b)->Matrix3 {
        Matrix3 mat = {
            a.M11() * b.M11() + a.M12() * b.M21() + a.M13() * b.M31(),
            a.M11() * b.M12() + a.M12() * b.M22() + a.M13() * b.M32(),
            a.M11() * b.M13() + a.M12() * b.M23() + a.M13() * b.M33(),
            a.M21() * b.M11() + a.M22() * b.M21() + a.M23() * b.M31(),
            a.M21() * b.M12() + a.M22() * b.M22() + a.M23() * b.M32(),
            a.M21() * b.M13() + a.M22() * b.M23() + a.M23() * b.M33(),
            a.M31() * b.M11() + a.M32() * b.M21() + a.M33() * b.M31(),
            a.M31() * b.M12() + a.M32() * b.M22() + a.M33() * b.M32(),
            a.M31() * b.M13() + a.M32() * b.M23() + a.M33() * b.M33()
        };

        return mat;
    }

    auto operator+=(Matrix3 & a, const Matrix3 &b)->Matrix3 & {
        a = std::move(a + b);

        return a;
    }

    auto operator-=(Matrix3 & a, const Matrix3 &b)->Matrix3 & {
        a = std::move(a - b);

        return a;
    }

    auto operator*=(Matrix3 & a, const Matrix3::ValueType &b)->Matrix3 & {
        a = std::move(a * b);

        return a;
    }

    auto operator/=(Matrix3 & a, const Matrix3::ValueType &b)->Matrix3 & {
        a = std::move(a / b);

        return a;
    }

    auto operator*=(Matrix3 & a, const Matrix3 &b)->Matrix3 & {
        a = std::move(a * b);

        return a;
    }

    void Matrix3::SetMatrix(
        const ValueType &m11, const ValueType &m12, const ValueType &m13,
        const ValueType &m21, const ValueType &m22, const ValueType &m23,
        const ValueType &m31, const ValueType &m32, const ValueType &m33) {
        M11() = m11, M12() = m12, M13() = m13;
        M21() = m21, M22() = m22, M23() = m23;
        M31() = m31, M32() = m32, M33() = m33;
    }
}  // namespace ne::math
