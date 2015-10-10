//
// Copyright 2015 riteme
//

#ifndef NE2D_FLOAT_COMPARISON_HPP_
#define NE2D_FLOAT_COMPARISON_HPP_

#include <cmath>
#include <limits>

namespace ne {

template <typename TFloat>
bool IsSame(const TFloat a, const TFloat b) noexcept {
    return fabs(a - b) < std::numeric_limits<TFloat>::epsilon();
}

template <typename TFloat>
bool IsGreater(const TFloat a, const TFloat b) noexcept {
    return a > b && !IsSame(a, b);
}

template <typename TFloat>
bool IsLess(const TFloat a, const TFloat b) noexcept {
    return a < b && !IsSame(a, b);
}

template <typename TFloat>
bool IsGreaterEqual(const TFloat a, const TFloat b) noexcept {
    return a > b || IsSame(a, b);
}

template <typename TFloat>
bool IsLessEqual(const TFloat a, const TFloat b) noexcept {
    return a < b || IsSame(a, b);
}

}  // namespace ne

#endif  // NE2D_FLOAT_COMPARISON_HPP_
