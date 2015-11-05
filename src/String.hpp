//
// Copyright 2015 riteme
//

#ifndef NE2D_STRING_HPP_
#define NE2D_STRING_HPP_

#include <string>
#include <memory>
#include <utility>

#include "TypeConfiguration.hpp"

namespace ne {

// TODO: Iterators

/**
 * 表示一个字符串
 */
class String {
 public:
    typedef ne::SizeType SizeType;
    typedef ne::Char CharType;
    typedef std::basic_string<ne::Char> StringType;

    String();

    String(const StringType &stdstr);
    String(const StringType &stdstr, SizeType repeat);
    String(const StringType &stdstr, SizeType begin, SizeType end);

    explicit String(const CharType *cstr);
    explicit String(const CharType *cstr, SizeType repeat);
    explicit String(const CharType *cstr, SizeType begin, SizeType end);

    String(const String &str, SizeType repeat);
    String(const String &str, SizeType begin, SizeType end);

    virtual ~String() = default;

    SizeType Length() const;

    ne::String SubString(const SizeType from, const SizeType to) const;

    CharType IndexOf(const SizeType index) const;
    CharType *CString() const;

    String(const ne::String &lhs);
    ne::String &operator=(const ne::String &lhs);

    String(ne::String &&rhs);
    ne::String &operator=(ne::String &&rhs);

    CharType operator[](const SizeType index) const;

    bool operator==(const ne::String &lhs) const;
    bool operator!=(const ne::String &lhs) const;

    bool operator<(const ne::String &lhs) const;
    bool operator>(const ne::String &lhs) const;
    bool operator<=(const ne::String &lhs) const;
    bool operator>=(const ne::String &lhs) const;

    friend ne::String operator+(const ne::String &a, const ne::String &b);
    friend ne::String operator*(const ne::String &a, const SizeType repeat);

    virtual ne::String ToString() const;
    virtual SizeType HashCode() const;

 private:
    std::shared_ptr<StringType> m_pString;
    SizeType m_nOffest;
    SizeType m_nLength;
};  // class String

}  // namespace ne

#endif  // NE2D_STRING_HPP_
