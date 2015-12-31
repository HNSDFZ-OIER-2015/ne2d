//
// Copyright 2015 riteme
//

#include "ne2d/InvaildOperatorException.hpp"

#include "ne2d/utility/StringFormat.hpp"

namespace ne {

const std::string UnknownOperator = "<Unknown operator>";

InvaildOperatorException::InvaildOperatorException()
        : m_description("No description."), m_operator(UnknownOperator) {}

InvaildOperatorException::InvaildOperatorException(
    const std::string &description)
        : m_description(description), m_operator(UnknownOperator) {}

InvaildOperatorException::InvaildOperatorException(
    const std::string &op, const std::string &description)
        : m_description(description), m_operator(op) {}

InvaildOperatorException::~InvaildOperatorException() = default;

auto InvaildOperatorException::Description() const -> std::string {
    return ne::utility::Format(
        "InvaildOperatorException: In operator '{}'\n"
        "Description: {}",
        m_operator, m_description);
}

auto InvaildOperatorException::ToString() const -> std::string {
    return Description();
}

auto InvaildOperatorException::HashCode() const -> ne::SizeType {
    return std::hash<std::string>()(Description());
}

}  // namespace ne
