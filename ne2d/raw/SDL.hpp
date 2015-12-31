//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_HPP_
#define NE2D_RAW_SDL_HPP_

#include <SDL2/SDL.h>

#include "ne2d/TypeConfiguration.hpp"

#include "ne2d/raw/SDLException.hpp"
#include "ne2d/raw/SDLInitFlags.hpp"

#include "ne2d/utility/StringFormat.hpp"

namespace ne {
namespace raw {

class SDL final {
 public:
    // This is a singleton:
    SDL() = delete;
    ~SDL() = delete;
    SDL(const SDL &) = delete;
    SDL(SDL &&) = delete;
    SDL &operator=(const SDL &) = delete;
    SDL &operator=(SDL &&) = delete;

    static void Init(const SDLInitFlags flags);
    static void InitSubsystem(const SDLInitFlags flags);
    static void Quit();
    static void QuitSubsystem(const SDLInitFlags flags);
    static auto CheckAllInitedSubsystem() -> Uint32;
    static auto WasInited(const SDLInitFlags &subsystem) -> Bool;

 private:
};  // singleton class SDL

}  // namespace raw
}  // namespace ne

#endif  // NE2D_RAW_SDL_HPP_
