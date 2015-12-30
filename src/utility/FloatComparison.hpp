//
// Copyright 2015 riteme
//

#ifndef NE2D_UTILITY_FLOAT_COMPARISON_HPP_
#define NE2D_UTILITY_FLOAT_COMPARISON_HPP_

#include <cmath>
#include <limits>

#include "TypeConfiguration.hpp"

namespace ne {
namespace utility {

static Float DefaultEpsilon = 0.00001;
static Float FloatEpsilon = 0.00001;
static Double DoubleEpsilon = 0.0000001;
static LongDouble LongDoubleEpsilon = 0.000000001;

/**
 * 用于表示精度
 */
template <typename TFloat>
struct Epsilon {
    static auto Value() noexcept -> TFloat { return DefaultEpsilon; }
};  // struct Epsilon

template <>
struct Epsilon<Float> {
    static auto Value() noexcept -> Float { return FloatEpsilon; }
};  // struct Epsilon<Float>

template <>
struct Epsilon<Double> {
    static auto Value() noexcept -> Double { return DoubleEpsilon; }
};  // struct Epsilon<Double>

template <>
struct Epsilon<LongDouble> {
    static auto Value() noexcept -> LongDouble { return LongDoubleEpsilon; }
};  // struct Epsilon<LongDouble>

template <typename TFloat>
auto IsSame(const TFloat &a, const TFloat &b) noexcept -> Bool {
    return std::fabs(a - b) < Epsilon<TFloat>::Value();
}

template <typename TFloat>
auto IsGreater(const TFloat &a, const TFloat &b) noexcept -> Bool {
    return a > b && !IsSame(a, b);
}

template <typename TFloat>
auto IsLess(const TFloat &a, const TFloat &b) noexcept -> Bool {
    return a < b && !IsSame(a, b);
}

template <typename TFloat>
auto IsGreaterEqual(const TFloat &a, const TFloat &b) noexcept -> Bool {
    return a > b || IsSame(a, b);
}

template <typename TFloat>
auto IsLessEqual(const TFloat &a, const TFloat &b) noexcept -> Bool {
    return a < b || IsSame(a, b);
}

/**
 * 用于浮点型与整形比较
 */
template <typename TFloat, typename TOther>
auto IsSame(const TFloat &a, const TOther &b) noexcept -> Bool {
    return std::fabs(a - static_cast<TFloat>(b)) < Epsilon<TFloat>::Value();
}

template <typename TFloat, typename TOther>
auto IsGreater(const TFloat &a, const TOther &b) noexcept -> Bool {
    return a > static_cast<TFloat>(b) && !IsSame(a, static_cast<TFloat>(b));
}

template <typename TFloat, typename TOther>
auto IsLess(const TFloat &a, const TOther &b) noexcept -> Bool {
    return a < static_cast<TFloat>(b) && !IsSame(a, static_cast<TFloat>(b));
}

template <typename TFloat, typename TOther>
auto IsGreaterEqual(const TFloat &a, const TOther &b) noexcept -> Bool {
    return a > static_cast<TFloat>(b) || IsSame(a, static_cast<TFloat>(b));
}

template <typename TFloat, typename TOther>
auto IsLessEqual(const TFloat &a, const TOther &b) noexcept -> Bool {
    return a < static_cast<TFloat>(b) || IsSame(a, static_cast<TFloat>(b));
}

}  // namespace utility
}  // namespace ne

#endif  // NE2D_UTILITY_FLOAT_COMPARISON_HPP_
