//
// Copyright 2015 riteme
//

#ifndef NE2D_INTERFACE_HPP_
#define NE2D_INTERFACE_HPP_

#include <string>

#include "TypeConfiguration.hpp"

namespace ne {
/**
 * 基础接口
 */
class IObject {
 public:
    virtual ~IObject();

    virtual auto ToString() const -> std::string = 0;

    virtual auto HashCode() const -> ne::SizeType = 0;
};  // class IObject
}  // namespace ne

#endif  // NE2D_INTERFACE_HPP_
