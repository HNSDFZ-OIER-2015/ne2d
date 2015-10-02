//
// Copyright 2015 riteme
//

#ifndef NE2D_CLASS_ATTRIBUTE_HPP
#define NE2D_CLASS_ATTRIBUTE_HPP

#define NO_DEFAULT_CONSTRUCTOR(className) className() = delete;

#define NONCOPYABLE(className)             \
    className(const className &) = delete; \
    className &operator=(const className &) = delete;

#define NONMOVABLE(className)         \
    className(className &&) = delete; \
    className &operator=(className &&) = delete;

#define NO_EQUAL_OPERATOR(className)             \
    bool operator==(const className &) = delete; \
    bool operator!=(const className &) = delete;

#define NONCOMPARABLE(className)                 \
    bool operator>(const className &) = delete;  \
    bool operator<(const className &) = delete;  \
    bool operator>=(const className &) = delete; \
    bool operator<=(const className &) = delete;

#endif  // NE2D_CLASS_ATTRIBUTE_HPP
