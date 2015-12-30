//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_INIT_HPP_
#define NE2D_RAW_SDL_INIT_HPP_

#include <SDL2/SDL.h>

namespace ne::raw {
    enum SDLInitFlags {
        Timer = SDL_INIT_TIMER,
        Audio = SDL_INIT_AUDIO,
        Video = SDL_INIT_VIDEO,
        Joystick = SDL_INIT_JOYSTICK,
        Haptic = SDL_INIT_HAPTIC,
        GameController = SDL_INIT_GAMECONTROLLER,
        Events = SDL_INIT_EVENTS,
        Everything = SDL_INIT_EVERYTHING,
        NoParachute = SDL_INIT_NOPARACHUTE  // This flag is ignored.
    };  // enum SDLInitFlags
}  // namespace ne::raw

#endif  // NE2D_RAW_SDL_INIT_HPP_
