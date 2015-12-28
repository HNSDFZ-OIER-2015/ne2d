//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_MATRIX3_HPP_
#define NE2D_MATH_MATRIX3_HPP_

#include <initializer_list>

#include "Interface.hpp"
#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include "Vector2D.hpp"

#include "utility/StringFormat.hpp"

namespace ne::math {
    /**
     * 表示一个3x3的矩阵
     */
    struct Matrix3 final : public ne::IObject {
        NONCOMPARABLE(Matrix3)

        typedef Float ValueType;
        typedef Vector2D VectorType;

        Matrix3();
        Matrix3(const ValueType &m11, const ValueType &m12,
                const ValueType &m13, const ValueType &m21,
                const ValueType &m22, const ValueType &m23,
                const ValueType &m31, const ValueType &m32,
                const ValueType &m33);
        Matrix3(const std::initializer_list<ValueType> &li);

        Matrix3(const Matrix3 &lhs);
        auto operator=(const Matrix3 &lhs) -> Matrix3 &;

        Matrix3(Matrix3 &&lhs);
        auto operator=(Matrix3 &&lhs) -> Matrix3 &;

        ~Matrix3() noexcept;

        /**
         * M11() ~ M33(): 访问矩阵上的元素
         * @return 元素值
         * @remark:
         *     索引方式为先行后列
         */
        auto M11() const noexcept -> ValueType;
        auto M12() const noexcept -> ValueType;
        auto M13() const noexcept -> ValueType;
        auto M21() const noexcept -> ValueType;
        auto M22() const noexcept -> ValueType;
        auto M23() const noexcept -> ValueType;
        auto M31() const noexcept -> ValueType;
        auto M32() const noexcept -> ValueType;
        auto M33() const noexcept -> ValueType;

        /**
         * M11() ~ M33(): 访问矩阵上的元素
         * @return 元素值
         * @remark:
         *     索引方式为先行后列
         *     这些函数是用于修改元素的
         */
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
        auto IsVaild() const noexcept -> Bool;

        /**
         * 获取矩阵的底层数组
         * @return 返回数组指针
         * @remark:
         *     矩阵是倒置过的
         */
        auto GetMatrixArray() const noexcept -> ValueType *;

        /**
         * 矩阵的比较运算
         */
        friend auto operator==(const Matrix3 &a, const Matrix3 &b) -> Bool;
        friend auto operator!=(const Matrix3 &a, const Matrix3 &b) -> Bool;

        /**
         * 矩阵的加法与减法
         */
        friend auto operator+(const Matrix3 &a, const Matrix3 &b) -> Matrix3;
        friend auto operator-(const Matrix3 &a, const Matrix3 &b) -> Matrix3;

        /**
         * 矩阵的正与负
         */
        friend auto operator+(Matrix3 a) -> Matrix3;
        friend auto operator-(Matrix3 a) -> Matrix3;

        /**
         * 矩阵与标量乘法
         */
        friend auto operator*(const Matrix3 &a, const ValueType &b) -> Matrix3;
        friend auto operator*(const ValueType &b, const Matrix3 &a) -> Matrix3;
        friend auto operator/(const Matrix3 &a, const ValueType &b) -> Matrix3;
        friend auto operator/(const ValueType &b, const Matrix3 &a) -> Matrix3;

        /**
         * 矩阵与向量乘法
         */
        friend auto operator*(const Matrix3 &a, const VectorType &b)
            -> VectorType;

        /**
         * 矩阵乘法
         */
        friend auto operator*(const Matrix3 &a, const Matrix3 &b) -> Matrix3;

        friend auto operator+=(Matrix3 &a, const Matrix3 &b) -> Matrix3 &;
        friend auto operator-=(Matrix3 &a, const Matrix3 &b) -> Matrix3 &;
        friend auto operator*=(Matrix3 &a, const ValueType &b) -> Matrix3 &;
        friend auto operator/=(Matrix3 &a, const ValueType &b) -> Matrix3 &;
        friend auto operator*=(Matrix3 &a, const Matrix3 &b) -> Matrix3 &;

        /**
         * 返回矩阵的字符串形式
         * @return 一个字符串
         * @remark:
         *     格式为：
         *     [[$M11, $M12, $M13] [$M21, $M22, $M23] [$M31, $M32, $M33]]
         */
        auto ToString() const -> std::string;

        /**
         * 计算矩阵的哈希值
         * @return 哈希值
         */
        auto HashCode() const -> ne::SizeType;

     private:
        constexpr static SizeType ArraySize = 9;
        constexpr static Bool GL_IsTransposed = true;

        void SetMatrix(const ValueType &m11, const ValueType &m12,
                       const ValueType &m13, const ValueType &m21,
                       const ValueType &m22, const ValueType &m23,
                       const ValueType &m31, const ValueType &m32,
                       const ValueType &m33);

        ValueType *m_pMatrix = nullptr;
        Bool m_bIsTransposed = false;
    };  // struct Matrix3
}  // namespace ne::math

#endif  // NE2D_MATH_MATRIX3_HPP_
