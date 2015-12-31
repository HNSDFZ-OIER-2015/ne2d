//
// Copyright 2015 riteme
//

#ifndef NE2D_INTERFACE_HPP_
#define NE2D_INTERFACE_HPP_

#include <string>

#include "ne2d/TypeConfiguration.hpp"

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

class IException : public IObject {
 public:
    virtual ~IException();

    virtual auto Description() const -> std::string = 0;
};  // class IException
}  // namespace ne

#endif  // NE2D_INTERFACE_HPP_
