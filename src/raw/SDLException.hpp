//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_EXCEPTION_HPP_
#define NE2D_RAW_SDL_EXCEPTION_HPP_

#include <SDL2/SDL.h>

#include <string>

#include "Interface.hpp"
#include "TypeConfiguration.hpp"
#include "ClassAttribute.hpp"

namespace ne::raw {
    class SDLException : public IException {
     public:
        SDLException();
        SDLException(const std::string &desc);

        auto Description() const -> std::string;

        auto ToString() const -> std::string;
        auto HashCode() const -> ne::SizeType;

     private:
        std::string m_description;
        std::string m_error;
    };  // class SDLException
}  // namespace ne::raw

#endif  // NE2D_RAW_SDL_EXCEPTION_HPP_
