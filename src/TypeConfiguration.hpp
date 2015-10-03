//
// Copyright 2015 riteme
//

#ifndef NE2D_TYPE_CONFIGURATION_HPP_
#define NE2D_TYPE_CONFIGURATION_HPP_

#include <cstdlib>
#include <cstdint>

namespace ne {

////////////////////
// 原始类型的别名 //
///////////////////

typedef int Integer;
typedef unsigned int Unsigned;

typedef int8_t Int8;
typedef uint8_t UInt8;
typedef int16_t Int16;
typedef uint16_t UInt16;
typedef int32_t Int32;
typedef uint32_t UInt32;
typedef int64_t Int64;
typedef uint64_t UInt64;

typedef std::size_t SizeType;
typedef std::size_t IndexType;

typedef signed char SByte;
typedef unsigned char Byte;

typedef float Float;
typedef double Double;
typedef long double LongDouble;

typedef char Char;
typedef char16_t UnicodeChar;
typedef char UTF8Char;
typedef char16_t UTF16Char;
typedef char32_t UTF32Char;

// typedef UInt8 UTF8Char;
// typedef UInt16 UnicodeChar;
// typedef UInt16 UTF16Char;
// typedef UInt32 UTF32Char;

}  // namespace ne

#endif  // NE2D_TYPE_CONFIGURATION_HPP_
