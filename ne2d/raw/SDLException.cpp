//
// Copyright 2015 riteme
//

#include <functional>

#include "ne2d/raw/SDLException.hpp"

#include "ne2d/utility/StringFormat.hpp"

namespace ne {
namespace raw {

SDLException::SDLException() : m_error(SDL_GetError()) {}

SDLException::SDLException(const std::string &desc)
        : m_description(desc), m_error(SDL_GetError()) {}

auto SDLException::Description() const -> std::string {
    return ne::utility::Format("SDLException: {}\nSDL_GetError(): {}",
                               m_description, m_error);
}

auto SDLException::ToString() const -> std::string { return Description(); }

auto SDLException::HashCode() const -> ne::SizeType {
    return std::hash<std::string>()(Description());
}

}  // namespace raw
}  // namespace ne
