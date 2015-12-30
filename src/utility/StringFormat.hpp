//
// Copyright 2015 riteme
//

#ifndef NE2D_UTILITY_STRING_FORMAT_HPP_
#define NE2D_UTILITY_STRING_FORMAT_HPP_

#include <string>

#define FMT_HEADER_ONLY
#include "thirdparty/cppformat/format.h"

namespace ne {
namespace utility {

/**
 * 格式化字符串
 * @param  fmt  格式化的字符串
 * @param  args 填充参数
 * @return      返回格式化的结果
 * @remark
 *     使用cppformat
 */
template <typename... Args>
std::string Format(const std::string &fmt, const Args &... args) {
    return fmt::format(fmt, args...);
}

}  // namesoace utility
}  // namespace ne

#endif  // NE2D_UTILITY_STRING_FORMAT_HPP_
