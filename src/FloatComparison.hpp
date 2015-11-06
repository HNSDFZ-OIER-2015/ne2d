//
// Copyright 2015 riteme
//

#ifndef NE2D_FLOAT_COMPARISON_HPP_
#define NE2D_FLOAT_COMPARISON_HPP_

#include <cmath>
#include <limits>

namespace ne {

template <typename TFloat>
auto IsSame(const TFloat a, const TFloat b) noexcept -> bool {
    return fabs(a - b) < std::numeric_limits<TFloat>::epsilon();
}

template <typename TFloat>
auto IsGreater(const TFloat a, const TFloat b) noexcept -> bool {
    return a > b && !IsSame(a, b);
}

template <typename TFloat>
auto IsLess(const TFloat a, const TFloat b) noexcept -> bool {
    return a < b && !IsSame(a, b);
}

template <typename TFloat>
auto IsGreaterEqual(const TFloat a, const TFloat b) noexcept -> bool {
    return a > b || IsSame(a, b);
}

template <typename TFloat>
auto IsLessEqual(const TFloat a, const TFloat b) noexcept -> bool {
    return a < b || IsSame(a, b);
}

}  // namespace ne

#endif  // NE2D_FLOAT_COMPARISON_HPP_
