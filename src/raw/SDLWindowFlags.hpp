//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_WINDOW_FLAGS_HPP_
#define NE2D_RAW_SDL_WINDOW_FLAGS_HPP_

#include <SDL2/SDL.h>

namespace ne {
namespace raw {

enum SDLWindowFlags {
    Fullscreen = SDL_WINDOW_FULLSCREEN,
    FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    OpenGL = SDL_WINDOW_OPENGL,
    Hidden = SDL_WINDOW_HIDDEN,
    Borderless = SDL_WINDOW_BORDERLESS,
    Resizable = SDL_WINDOWEVENT_RESIZED,
    Minimized = SDL_WINDOW_MINIMIZED,
    Maximized = SDL_WINDOW_MAXIMIZED,
    InputGrabbed = SDL_WINDOW_INPUT_GRABBED,
    AllowHighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
    NotFullscreen = 0
};  // enum SDLWindowFlags

}  // namespace raw
}  // namespace ne

#endif  // NE2D_RAW_SDL_WINDOW_FLAGS_HPP_
