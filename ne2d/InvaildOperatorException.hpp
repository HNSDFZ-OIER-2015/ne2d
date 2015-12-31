//
// Copyright 2015 riteme
//

#ifndef NE2D_INVAILD_OPERATOR_EXCEPTION_HPP_
#define NE2D_INVAILD_OPERATOR_EXCEPTION_HPP_

#include <string>

#include "ne2d/Interface.hpp"
#include "ne2d/TypeConfiguration.hpp"
#include "ne2d/ClassAttribute.hpp"

namespace ne {

class InvaildOperatorException : public ne::IException {
 public:
    NO_EQUAL_OPERATOR(InvaildOperatorException)
    NONCOMPARABLE(InvaildOperatorException)

    InvaildOperatorException();
    InvaildOperatorException(const std::string &description);
    InvaildOperatorException(const std::string &op,
                             const std::string &description);
    ~InvaildOperatorException();

    auto Description() const -> std::string;

    auto ToString() const -> std::string;
    auto HashCode() const -> ne::SizeType;

 private:
    std::string m_description;
    std::string m_operator;
};  // class InvaildOperatorException

}  // namespace ne

#endif  // NE2D_INVAILD_OPERATOR_EXCEPTION_HPP_
