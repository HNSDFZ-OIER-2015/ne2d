//
// Copyright 2015 riteme
//

#ifndef NE2D_MATRIX2_HPP_
#define NE2D_MATRIX2_HPP_

#include <utility>
#include <stdexcept>
#include <initializer_list>

#include "Vector2D.hpp"
#include "StringFormat.hpp"
#include "ClassAttribute.hpp"
#include "FloatComparison.hpp"
#include "TypeConfiguration.hpp"

namespace ne {

/**
 * 表示一个3x3的矩阵
 */
template <typename T>
struct BasicMatrix3 : public ne::IObject {
    NONCOMPARABLE(BasicMatrix3)

    typedef T ValueType;
    typedef ne::BasicVector2D<T> VectorType;

    // Identity Matrix:
    // [1, 0, 0]
    // [0, 1, 0]
    // [0, 0, 1]
    const static BasicMatrix3 Identity = BasicMatrix3();

    BasicMatrix3() {
        m_pMatrix = new ValueType[ArraySize];

        SetMatrix(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    }
    BasicMatrix3(const ValueType m11, const ValueType m12, const ValueType m13,
                 const ValueType m21, const ValueType m22, const ValueType m23,
                 const ValueType m31, const ValueType m32, const ValueType m33,
                 const bool transposed = false) {
        m_pMatrix = new ValueType[ArraySize];

        SetMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);

        m_bIsTransposed = transposed;
    }
    BasicMatrix3(const std::initializer_list<ValueType> &li,
                 const bool transposed = false) {
        if (li.size() != ArraySize)
            throw std::invalid_argument("Wrong initializer list.");

        m_pMatrix = new ValueType[ArraySize];

        SetMatrix(li[0], li[1], li[2], li[3], li[4], li[5], li[6], li[7],
                  li[8]);

        m_bIsTransposed = transposed;
    }

    auto M11() -> ValueType & { return m_pMatrix[0][0]; }
    auto M12() -> ValueType & {
        return m_bIsTransposed ? m_pMatrix[1][0] : m_pMatrix[0][1];
    }
    auto M13() -> ValueType & {
        return m_bIsTransposed ? m_pMatrix[2][0] : m_pMatrix[0][2];
    }
    auto M21() -> ValueType & {
        return m_bIsTransposed ? m_pMatrix[0][1] : m_pMatrix[1][0];
    }
    auto M22() -> ValueType & { return m_pMatrix[1][1]; }
    auto M23() -> ValueType & {
        return m_bIsTransposed ? m_pMatrix[2][1] : m_pMatrix[1][2];
    }
    auto M31() -> ValueType & {
        return m_bIsTransposed ? m_pMatrix[0][2] : m_pMatrix[2][0];
    }
    auto M32() -> ValueType & {
        return m_bIsTransposed ? m_pMatrix[1][2] : m_pMatrix[2][1];
    }
    auto M33() -> ValueType & { return m_pMatrix[2][2]; }

    void Transpose() { m_bIsTransposed = true; }
    auto GetMatrixArray() const -> ValueType * { return m_pMatrix; }
    auto IsVaild() const -> bool { return m_pMatrix != nullptr; }

    BasicMatrix3(const BasicMatrix3 &lhs) {
        SetMatrix(lhs.M11(), lhs.M12(), lhs.M13(), lhs.M21(), lhs.M22(),
                  lhs.M23(), lhs.M31(), lhs.M32(), lhs.M33());
    }
    auto operator=(const BasicMatrix3 &lhs) -> BasicMatrix3 & {
        SetMatrix(lhs.M11(), lhs.M12(), lhs.M13(), lhs.M21(), lhs.M22(),
                  lhs.M23(), lhs.M31(), lhs.M32(), lhs.M33());

        return *this;
    }

    BasicMatrix3(BasicMatrix3 &&lhs) : m_pMatrix(lhs.m_pMatrix) {
        lhs.m_pMatrix = nullptr;
    }
    auto operator=(BasicMatrix3 &&lhs) -> BasicMatrix3 & {
        if (m_pMatrix != nullptr) delete[] m_pMatrix;

        m_pMatrix = lhs.m_pMatrix;
        lhs.m_pMatrix = nullptr;

        return *this;
    }

    virtual ~BasicMatrix3() {
        if (m_pMatrix != nullptr) delete[] m_pMatrix;
    }

    auto operator+(const BasicMatrix3 &lhs) const -> BasicMatrix3 {
        BasicMatrix3 mat = { M11() + lhs.M11(), M12() + lhs.M12(),
                             M13() + lhs.M13(), M21() + lhs.M21(),
                             M22() + lhs.M22(), M23() + lhs.M23(),
                             M31() + lhs.M31(), M32() + lhs.M32(),
                             M33() + lhs.M33() };

        return mat;
    }

    auto operator-(const BasicMatrix3 &lhs) const -> BasicMatrix3 {
        BasicMatrix3 mat = { M11() - lhs.M11(), M12() - lhs.M12(),
                             M13() - lhs.M13(), M21() - lhs.M21(),
                             M22() - lhs.M22(), M23() - lhs.M23(),
                             M31() - lhs.M31(), M32() - lhs.M32(),
                             M33() - lhs.M33() };

        return mat;
    }

    auto operator*(const ValueType lhs) const -> BasicMatrix3 {
        BasicMatrix3 mat = { M11() * lhs, M12() * lhs, M13() * lhs,
                             M21() * lhs, M22() * lhs, M23() * lhs,
                             M31() * lhs, M32() * lhs, M33() * lhs };

        return mat;
    }

    auto operator/(const ValueType lhs) const -> BasicMatrix3 {
        BasicMatrix3 mat = { M11() / lhs, M12() / lhs, M13() / lhs,
                             M21() / lhs, M22() / lhs, M23() / lhs,
                             M31() / lhs, M32() / lhs, M33() / lhs };

        return mat;
    }

    auto operator*(const VectorType &lhs) const -> VectorType {
        VectorType vec = { M11() * lhs.X + M12() * lhs.Y + M13() * lhs.Z,
                           M21() * lhs.X + M22() * lhs.Y + M23() * lhs.Z,
                           M31() * lhs.X + M32() * lhs.Y + M33() * lhs.Z };

        return vec;
    }

    auto operator*(const BasicMatrix3 &lhs) const -> BasicMatrix3 {
        BasicMatrix3 mat = {
            M11() * lhs.M11() + M12() * lhs.M21() + M13() * lhs.M13(),
            M11() * lhs.M12() + M12() * lhs.M22() + M13() * lhs.M32(),
            M11() * lhs.M13() + M12() * lhs.M23() + M13() * lhs.M33(),
            M21() * lhs.M11() + M22() * lhs.M21() + M23() * lhs.M13(),
            M21() * lhs.M12() + M22() * lhs.M22() + M23() * lhs.M32(),
            M21() * lhs.M13() + M22() * lhs.M23() + M23() * lhs.M33(),
            M31() * lhs.M11() + M32() * lhs.M21() + M33() * lhs.M13(),
            M31() * lhs.M12() + M32() * lhs.M22() + M33() * lhs.M32(),
            M31() * lhs.M13() + M32() * lhs.M23() + M33() * lhs.M33()
        };

        return mat;
    }

    auto operator+=(const BasicMatrix3 &lhs) -> BasicMatrix3 & {
        *this = std::move(*this + lhs);

        return *this;
    }

    auto operator-=(const BasicMatrix3 &lhs) -> BasicMatrix3 & {
        *this = std::move(*this - lhs);

        return *this;
    }

    auto operator*=(const ValueType lhs) -> BasicMatrix3 & {
        *this = std::move(*this * lhs);

        return *this;
    }

    auto operator/=(const ValueType lhs) -> BasicMatrix3 & {
        *this = std::move(*this / lhs);

        return *this;
    }

    auto operator*=(const BasicMatrix3 &lhs) -> BasicMatrix3 & {
        *this = std::move(*this * lhs);

        return *this;
    }

    virtual auto ToString() const -> std::string {
        // [[a11, a12] [a21, a22]]

        return ne::Format("[[{0}, {1}] [{2}, {3}]]", M11(), M12(), M21(),
                          M22());
    }

    virtual auto HashCode() const -> ne::SizeType {
        return static_cast<SizeType>(M11()) *
               (static_cast<SizeType>(M12() - M21()) /
                static_cast<SizeType>(M22()));
    }

 private:
    constexpr static SizeType ArraySize = 9;
    constexpr static Bool IsTransposed = true;

    void SetMatrix(const ValueType m11, const ValueType m12,
                   const ValueType m13, const ValueType m21,
                   const ValueType m22, const ValueType m23,
                   const ValueType m31, const ValueType m32,
                   const ValueType m33) {
        M11() = m11, M12() = m12, M13() = m13;
        M21() = m21, M22() = m22, M23() = m23;
        M31() = m31, M32() = m32, M33() = m33;
    }

    ValueType *m_pMatrix = nullptr;
    bool m_bIsTransposed = false;
};  // struct BasicMatrix3

/**
 * 单精度浮点数的模板特化
 */
typedef BasicMatrix3<Float> Matrix3;

}  // namespace ne

#endif  // NE2D_MATRIX2_HPP_
