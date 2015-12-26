//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_WINDOW_POSITION_HPP_
#define NE2D_RAW_SDL_WINDOW_POSITION_HPP_

#include <SDL2/SDL.h>

namespace ne::raw {
    enum SDLWindowPosition {
        Centered = SDL_WINDOWPOS_CENTERED,
        Undefined = SDL_WINDOWPOS_UNDEFINED
    };  // enum SDLWindowPosition
}  // namespace ne::raw

#endif  // NE2D_RAW_SDL_WINDOW_POSITION_HPP_
