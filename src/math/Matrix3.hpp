//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_MATRIX3_HPP_
#define NE2D_MATH_MATRIX3_HPP_

#include <utility>
#include <initializer_list>

#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include "Vector2D.hpp"

#include "utility/StringFormat.hpp"

namespace ne::math {
    /**
     * 表示一个3x3的矩阵
     */
    struct Matrix3 : public ne::IObject {
        NONCOMPARABLE(Matrix3)

        typedef Float ValueType;
        typedef Vector2D VectorType;

        Matrix3() {
            m_pMatrix = new ValueType[ArraySize];

            SetMatrix(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        }
        Matrix3(const ValueType &m11, const ValueType &m12,
                const ValueType &m13, const ValueType &m21,
                const ValueType &m22, const ValueType &m23,
                const ValueType &m31, const ValueType &m32,
                const ValueType &m33, const bool transposed = false) {
            m_pMatrix = new ValueType[ArraySize];

            SetMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);

            m_bIsTransposed = transposed;
        }
        Matrix3(const std::initializer_list<ValueType> &li,
                const bool transposed = false) {
            if (li.size() != ArraySize)
                throw std::invalid_argument("Wrong initializer list.");

            m_pMatrix = new ValueType[ArraySize];

            SetMatrix(*(li.begin() + 0), *(li.begin() + 1), *(li.begin() + 2),
                      *(li.begin() + 3), *(li.begin() + 4), *(li.begin() + 5),
                      *(li.begin() + 6), *(li.begin() + 7), *(li.begin() + 8));

            m_bIsTransposed = transposed;
        }

        auto M11() const noexcept -> ValueType;
        auto M12() const noexcept -> ValueType;
        auto M13() const noexcept -> ValueType;
        auto M21() const noexcept -> ValueType;
        auto M22() const noexcept -> ValueType;
        auto M23() const noexcept -> ValueType;
        auto M31() const noexcept -> ValueType;
        auto M32() const noexcept -> ValueType;
        auto M33() const noexcept -> ValueType;

        // 可做左值
        auto M11() noexcept -> ValueType &;
        auto M12() noexcept -> ValueType &;
        auto M13() noexcept -> ValueType &;
        auto M21() noexcept -> ValueType &;
        auto M22() noexcept -> ValueType &;
        auto M23() noexcept -> ValueType &;
        auto M31() noexcept -> ValueType &;
        auto M32() noexcept -> ValueType &;
        auto M33() noexcept -> ValueType &;

        /**
         * 将矩阵倒置
         */
        void Transpose() noexcept;

        /**
         * 确认矩阵还是否有效
         * @return 返回一个布尔值
         * @remark:
         *     在std::move之后会导致矩阵失效
         */
        auto IsVaild() const noexcept -> bool;

        /**
         * 获取矩阵的底层数组
         * @return 返回数组指针
         * @remark:
         *     矩阵是倒置过的
         */
        auto GetMatrixArray() const noexcept -> ValueType *;

        Matrix3(const Matrix3 &lhs) {
            m_pMatrix = new ValueType[ArraySize];

            SetMatrix(lhs.M11(), lhs.M12(), lhs.M13(), lhs.M21(), lhs.M22(),
                      lhs.M23(), lhs.M31(), lhs.M32(), lhs.M33());
        }
        auto operator=(const Matrix3 &lhs) -> Matrix3 & {
            if (m_pMatrix == nullptr) m_pMatrix = new ValueType[ArraySize];

            SetMatrix(lhs.M11(), lhs.M12(), lhs.M13(), lhs.M21(), lhs.M22(),
                      lhs.M23(), lhs.M31(), lhs.M32(), lhs.M33());

            return *this;
        }

        Matrix3(Matrix3 &&lhs) : m_pMatrix(lhs.m_pMatrix) {
            lhs.m_pMatrix = nullptr;
        }
        auto operator=(Matrix3 &&lhs) -> Matrix3 & {
            if (m_pMatrix != nullptr) delete[] m_pMatrix;

            m_pMatrix = lhs.m_pMatrix;
            lhs.m_pMatrix = nullptr;

            return *this;
        }

        virtual ~Matrix3() noexcept {
            if (m_pMatrix != nullptr) delete[] m_pMatrix;
        }

        friend auto operator==(const Matrix3 &a, const Matrix3 &b) -> bool;
        friend auto operator!=(const Matrix3 &a, const Matrix3 &b) -> bool;

        friend auto operator+(const Matrix3 &a, const Matrix3 &b) -> Matrix3;
        friend auto operator-(const Matrix3 &a, const Matrix3 &b) -> Matrix3;

        friend auto operator+(Matrix3 a) -> Matrix3;
        friend auto operator-(Matrix3 a) -> Matrix3;

        friend auto operator*(const Matrix3 &a, const ValueType &b) -> Matrix3;
        friend auto operator*(const ValueType &b, const Matrix3 &a) -> Matrix3;
        friend auto operator/(const Matrix3 &a, const ValueType &b) -> Matrix3;
        friend auto operator/(const ValueType &b, const Matrix3 &a) -> Matrix3;

        friend auto operator*(const Matrix3 &a, const VectorType &b)
            -> VectorType;
        friend auto operator*(const Matrix3 &a, const Matrix3 &b) -> Matrix3;

        friend auto operator+=(Matrix3 &a, const Matrix3 &b) -> Matrix3 &;
        friend auto operator-=(Matrix3 &a, const Matrix3 &b) -> Matrix3 &;
        friend auto operator*=(Matrix3 &a, const ValueType &b) -> Matrix3 &;
        friend auto operator/=(Matrix3 &a, const ValueType &b) -> Matrix3 &;
        friend auto operator*=(Matrix3 &a, const Matrix3 &b) -> Matrix3 &;

        virtual auto ToString() const -> std::string {
            // [[a11, a12, a13] [a21, a22, a23] [a31, a32, a33]]

            return ne::utility::Format(
                "[[{}, {}, {}] [{}, {}, {}] [{}, {}, {}]]", M11(), M12(), M13(),
                M21(), M22(), M23(), M31(), M32(), M33());
        }

        virtual auto HashCode() const -> ne::SizeType {
            return (static_cast<SizeType>(M11() + M12() + M21()) *
                    static_cast<SizeType>(M33() + M23() + M32())) *
                   static_cast<SizeType>(M13() + M22() + M31());
        }

     private:
        constexpr static SizeType ArraySize = 9;
        constexpr static bool GL_IsTransposed = true;

        void SetMatrix(const ValueType &m11, const ValueType &m12,
                       const ValueType &m13, const ValueType &m21,
                       const ValueType &m22, const ValueType &m23,
                       const ValueType &m31, const ValueType &m32,
                       const ValueType &m33);

        ValueType *m_pMatrix = nullptr;
        bool m_bIsTransposed = false;
    };  // struct Matrix3
}  // namespace ne::math

#endif  // NE2D_MATH_MATRIX3_HPP_
