//
// Copyright 2015 riteme
//

#ifndef NE2D_STRING_HPP_
#define NE2D_STRING_HPP_

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <initializer_list>

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

    explicit String(const CharType c);
    explicit String(const CharType c, SizeType repeat);

    explicit String(const CharType *cstr);
    explicit String(const CharType *cstr, SizeType repeat);
    explicit String(const CharType *cstr, SizeType begin, SizeType end);

    String(const String &str, SizeType repeat);
    String(const String &str, SizeType begin, SizeType end);

    virtual ~String(void) = default;

    template <typename... Args>
    auto Format(const Args &... args) const -> ne::String;

    template <typename... Args>
    auto Join(const Args &... args) const -> ne::String;

    template <typename TForwardIterator>
    auto Join(TForwardIterator begin, TForwardIterator end) const -> ne::String;

    template <typename TElement>
    auto Join(const std::initializer_list<TElement> &il) const -> ne::String;

    template <typename TReturn>
    auto Split(const ne::String &separator) const -> TReturn;

    // template <>
    // auto Split(const ne::String &separator) const -> std::vector<ne::String>;

    auto PadLeft(const SizeType size, const CharType c = ' ') const
        -> ne::String;
    auto PadRight(const SizeType size, const CharType c = ' ') const
        -> ne::String;

    auto Remove(const CharType c, const SizeType count = 0) const -> ne::String;

    auto Replace(const CharType from, const CharType to) const -> ne::String;

    auto Replace(const ne::String from, const ne::String to) const
        -> ne::String;

    auto StartWith(const ne::String &str) const -> bool;

    auto EndWith(const ne::String &str) const -> bool;

    auto SubString(const SizeType from, const SizeType to) const -> ne::String;

    auto ToLower(void) const -> ne::String;

    auto ToUpper(void) const -> ne::String;

    auto Trim(void) const -> ne::String;

    auto TrimBegin(void) const -> ne::String;

    auto TrimEnd(void) const -> ne::String;

    auto Length(void) const -> SizeType;

    auto IndexOf(const SizeType index) const -> CharType;

    auto LastIndexOf(const Integer rindex) const -> CharType;

    auto CString(void) const -> CharType *;

    String(const ne::String &lhs);
    auto operator=(const ne::String &lhs) -> ne::String &;

    String(ne::String &&rhs);
    auto operator=(ne::String &&rhs) -> ne::String &;

    auto operator[](const SizeType index) const -> CharType;

    auto operator==(const ne::String &lhs) const -> bool;
    auto operator!=(const ne::String &lhs) const -> bool;

    auto operator<(const ne::String &lhs) const -> bool;
    auto operator>(const ne::String &lhs) const -> bool;
    auto operator<=(const ne::String &lhs) const -> bool;
    auto operator>=(const ne::String &lhs) const -> bool;

    friend auto operator+(const ne::String &a, const ne::String &b)
        -> ne::String;
    friend auto operator*(const ne::String &a, const SizeType repeat)
        -> ne::String;

    virtual auto ToString() const -> ne::String;
    virtual auto HashCode() const -> SizeType;

 private:
    std::shared_ptr<StringType> m_pString;
    SizeType m_nOffest;
    SizeType m_nLength;
};  // class String

}  // namespace ne

#endif  // NE2D_STRING_HPP_
