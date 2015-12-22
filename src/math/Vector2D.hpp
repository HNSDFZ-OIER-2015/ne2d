//
// Copyright 2015 riteme
//

#ifndef NE2D_MATH_VECTOR2D_HPP_
#define NE2D_MATH_VECTOR2D_HPP_

#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include "utility/StringFormat.hpp"

namespace ne::math {
    /**
     * 二维向量的基本结构
     * 可以指定数据的类型
     * @remark:
     *     其中Z仅用于辅助与矩阵运算，
     *     不会参与二维向量的运算和比较运算
     */
    struct Vector2D : public ne::IObject {
        NONCOMPARABLE(Vector2D)

        typedef Float ValueType;

        Vector2D() : m_x(0.0f), m_y(0.0f) {}
        Vector2D(const ValueType &x, const ValueType &y) : m_x(x), m_y(y) {}

        Vector2D(const Vector2D &lhs) : m_x(lhs.X()), m_y(lhs.Y()) {}
        auto operator=(const Vector2D &lhs) -> Vector2D & {
            m_x = lhs.X();
            m_y = lhs.Y();

            return *this;
        }

        Vector2D(Vector2D &&rhs) : m_x(rhs.X()), m_y(rhs.Y()) {}
        auto operator=(Vector2D &&rhs) -> Vector2D & {
            m_x = rhs.X();
            m_y = rhs.Y();

            return *this;
        }

        /**
         * 访问二维向量的X与Y
         * @return 对应的值
         * @remark:
         *     Z仅用于参与矩阵与向量运算，永远返回1
         */
        auto X() const -> ValueType;
        auto Y() const -> ValueType;
        auto Z() const -> ValueType;

        /**
         * 访问二维向量的X与Y
         * @return 对应的值
         * @remark:
         *     Z不可修改
         */
        auto X() -> ValueType &;
        auto Y() -> ValueType &;

        /**
         * 二维向量的比较运算
         */
        friend auto operator==(const Vector2D &a, const Vector2D &b) -> bool;
        friend auto operator!=(const Vector2D &a, const Vector2D &b) -> bool;

        /**
         * 二维向量的正与负
         */
        friend auto operator+(Vector2D a) -> Vector2D;
        friend auto operator-(Vector2D a) -> Vector2D;

        /**
         * 向量加法与减法
         */
        friend auto operator+(const Vector2D &a, const Vector2D &lhs)
            -> Vector2D;
        friend auto operator-(const Vector2D &a, const Vector2D &lhs)
            -> Vector2D;

        /**
         * 向量与标量乘法
         */
        friend auto operator*(const Vector2D &a, const ValueType &lhs)
            -> Vector2D;
        friend auto operator/(const Vector2D &a, const ValueType &lhs)
            -> Vector2D;
        friend auto operator*(const ValueType &lhs, const Vector2D &a)
            -> Vector2D;
        friend auto operator/(const ValueType &lhs, const Vector2D &a)
            -> Vector2D;

        /**
         * 向量的叉乘与点乘
         */
        friend auto operator*(const Vector2D &a, const Vector2D &lhs)
            -> ValueType;
        friend auto operator%(const Vector2D &a, const Vector2D &lhs)
            -> ValueType;

        friend auto operator+=(Vector2D &a, const Vector2D &lhs) -> Vector2D &;
        friend auto operator-=(Vector2D &a, const Vector2D &lhs) -> Vector2D &;

        friend auto operator*=(Vector2D &a, const ValueType &lhs) -> Vector2D &;
        friend auto operator/=(Vector2D &a, const ValueType &lhs) -> Vector2D &;

        /**
         * 返回二维向量的字符串形式
         * @return 一个字符串
         * @remark:
         *     格式为：
         *     (X = $X, Y = $Y)
         */
        virtual auto ToString() const -> std::string {
            return ne::utility::Format("(X = {}, Y = {})", X(), Y());
        }

        /**
         * 计算二维向量的哈希值
         * @return 哈希值
         */
        virtual auto HashCode() const -> ne::SizeType {
            return static_cast<SizeType>(X() * Y()) /
                   (static_cast<SizeType>(X()) % 31);
        }

     private:
        ValueType m_x;
        ValueType m_y;
    };  // struct Vector2D
}  // namespace ne::math

#endif  // NE2D_MATH_VECTOR2D_HPP_
