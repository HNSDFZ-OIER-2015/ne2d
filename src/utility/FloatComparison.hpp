//
// Copyright 2015 riteme
//

#ifndef NE2D_FLOAT_COMPARISON_HPP_
#define NE2D_FLOAT_COMPARISON_HPP_

#include <cmath>
#include <limits>

namespace ne::utility {
    template <typename TFloat>
    auto IsSame(const TFloat &a, const TFloat &b) noexcept->bool {
        return fabs(a - b) < std::numeric_limits<TFloat>::epsilon();
    }

    template <typename TFloat>
    auto IsGreater(const TFloat &a, const TFloat &b) noexcept->bool {
        return a > b && !IsSame(a, b);
    }

    template <typename TFloat>
    auto IsLess(const TFloat &a, const TFloat &b) noexcept->bool {
        return a < b && !IsSame(a, b);
    }

    template <typename TFloat>
    auto IsGreaterEqual(const TFloat &a, const TFloat &b) noexcept->bool {
        return a > b || IsSame(a, b);
    }

    template <typename TFloat>
    auto IsLessEqual(const TFloat &a, const TFloat &b) noexcept->bool {
        return a < b || IsSame(a, b);
    }

    /**
     * 用于浮点型与整形比较
     */
    template <typename TFloat, typename TOther>
    auto IsSame(const TFloat &a, const TOther &b) noexcept->bool {
        return fabs(a - static_cast<TFloat>(b)) <
               std::numeric_limits<TFloat>::epsilon();
    }

    template <typename TFloat, typename TOther>
    auto IsGreater(const TFloat &a, const TOther &b) noexcept->bool {
        return a > static_cast<TFloat>(b) && !IsSame(a, static_cast<TFloat>(b));
    }

    template <typename TFloat, typename TOther>
    auto IsLess(const TFloat &a, const TOther &b) noexcept->bool {
        return a < static_cast<TFloat>(b) && !IsSame(a, static_cast<TFloat>(b));
    }

    template <typename TFloat, typename TOther>
    auto IsGreaterEqual(const TFloat &a, const TFloat &b) noexcept->bool {
        return a > static_cast<TFloat>(b) || IsSame(a, static_cast<TFloat>(b));
    }

    template <typename TFloat, typename TOther>
    auto IsLessEqual(const TFloat &a, const TOther &b) noexcept->bool {
        return a < static_cast<TFloat>(b) || IsSame(a, static_cast<TFloat>(b));
    }
}  // namespace ne::utility

#endif  // NE2D_FLOAT_COMPARISON_HPP_
