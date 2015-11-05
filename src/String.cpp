//
// Copyright 2015 riteme
//

#include "String.hpp"

namespace ne {

String::String() : m_pString(nullptr), m_nOffest(0), m_nLength(0) {}

String::String(const std::string &stdstr)
        : m_nOffest(0), m_nLength(stdstr.size()) {
    m_pString = std::make_shared<std::string>(new std::string());

    *m_pString = stdstr;
}

String::String(const std::string &stdstr, ne::SizeType repeat)
        : m_nOffest(0), m_nLength(stdstr.size()) {
    m_pString = std::make_shared<std::string>(new std::string());

    m_pString->reserve(m_nLength * repeat);

    for (ne::SizeType i = 0; i < repeat; i++) {
        m_pString->append(stdstr);
    }  // for
}

String::String(const std::string &stdstr, ne::SizeType begin, ne::SizeType end)
        : m_nOffest(begin), m_nLength(end - begin) {
    m_pString = std::make_shared<std::string>(new std::string());

    *m_pString = stdstr;
}

String::String(const String &str, ne::SizeType repeat) {}

String::String(const String &str, ne::SizeType begin, ne::SizeType end) {}

String::String(const ne::String &lhs)
        : m_pString(lhs.m_pString)
        , m_nOffest(lhs.m_nOffest)
        , m_nLength(lhs.m_nLength) {}

ne::String &String::operator=(const ne::String &lhs) {
    m_pString = lhs.m_pString;
    m_nOffest = lhs.m_nOffest;
    m_nLength = lhs.m_nLength;

    return *this;
}

String::String(ne::String &&rhs)
        : m_pString(std::move(rhs.m_pString))
        , m_nOffest(rhs.m_nOffest)
        , m_nLength(rhs.m_nLength) {}

ne::String &String::operator=(ne::String &&rhs) {
    m_pString = std::move(rhs.m_pString);
    m_nOffest = rhs.m_nOffest;
    m_nLength = rhs.m_nLength;

    return *this;
}

ne::String String::ToString() const { return *this; }

ne::SizeType String::HashCode() const {
    return std::hash<std::string>()(*m_pString);
}

}  // namespace ne
