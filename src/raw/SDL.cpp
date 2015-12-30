//
// Copyright 2015 riteme
//

#include "SDL.hpp"

namespace ne {
namespace raw {

void SDL::Init(const SDLInitFlags flags) {
    if (SDL_Init(flags) < 0)
        throw SDLException(
            ne::utility::Format("Cannot init SDL with flags {}.", flags));
}

void SDL::InitSubsystem(const SDLInitFlags flags) {
    if (SDL_InitSubSystem(flags) < 0)
        throw SDLException(ne::utility::Format(
            "Cannot init SDL subsystem with flags {}.", flags));
}

void SDL::Quit() { SDL_Quit(); }

void SDL::QuitSubsystem(const SDLInitFlags flags) { SDL_QuitSubSystem(flags); }

auto SDL::CheckAllInitedSubsystem() -> Uint32 { return SDL_WasInit(0); }

auto SDL::WasInited(const SDLInitFlags &subsystem) -> Bool {
    return SDL_WasInit(subsystem);
}

}  // namespace raw
}  // namespace ne
