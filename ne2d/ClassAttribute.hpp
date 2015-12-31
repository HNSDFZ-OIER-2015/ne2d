//
// Copyright 2015 riteme
//

#ifndef NE2D_CLASS_ATTRIBUTE_HPP_
#define NE2D_CLASS_ATTRIBUTE_HPP_

#include <string>
#include <typeinfo>

#include "ne2d/TypeConfiguration.hpp"

/**
 * 表示没有默认构造函数
 * @param  className 类的名称
 */
#define NO_DEFAULT_CONSTRUCTOR(className) className() = delete;

/**
 * 表示没有复制构造函数和复制赋值函数
 * @param  className 类的名称
 */
#define NONCOPYABLE(className)             \
    className(const className &) = delete; \
    className &operator=(const className &) = delete;

/**
 * 表示没有移动构造函数和移动赋值函数
 * @param  className 类的名称
 */
#define NONMOVABLE(className)         \
    className(className &&) = delete; \
    className &operator=(className &&) = delete;

/**
 * 表示没有==和!=比较符
 * @param  className 类的名称
 */
#define NO_EQUAL_OPERATOR(className)             \
    bool operator==(const className &) = delete; \
    bool operator!=(const className &) = delete;

/**
 * 表示不可用>, <, >=和<=进行比较
 * @param  className 类的名称
 */
#define NONCOMPARABLE(className)                 \
    bool operator>(const className &) = delete;  \
    bool operator<(const className &) = delete;  \
    bool operator>=(const className &) = delete; \
    bool operator<=(const className &) = delete;

#endif  // NE2D_CLASS_ATTRIBUTE_HPP_
