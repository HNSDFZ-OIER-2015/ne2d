//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_SURFACE_HPP_
#define NE2D_RAW_SDL_SURFACE_HPP_

#include <SDL2/SDL.h>

#include <string>

#include "ne2d/Interface.hpp"
#include "ne2d/TypeConfiguration.hpp"
#include "ne2d/ClassAttribute.hpp"

namespace ne {
namespace raw {

class SDLSurface : public ne::IObject {
 public:
    NONCOMPARABLE(SDLSurface)
    NONCOPYABLE(SDLSurface)
    NO_EQUAL_OPERATOR(SDLSurface)

    friend class SDLWindow;

    SDLSurface();
    SDLSurface(const std::string &filename);
    ~SDLSurface();

    SDLSurface(SDLSurface &&rhs);
    auto operator=(SDLSurface &&rhs) -> SDLSurface &;

    auto Width() const -> SizeType;
    auto Height() const -> SizeType;
    auto Pitch() const -> SizeType;

    auto GetPixels() -> void *;

    auto IsVaild() const -> Bool;

    void LoadFile(const std::string &filename);
    void SaveFile(const std::string &filename);
    void Destroy();

    virtual auto ToString() const -> std::string;
    virtual auto HashCode() const -> ne::SizeType;

 private:
    SDL_Surface *m_pSurface;
};  // class SDLSurface

}  // namespace raw
}  // namespace ne

#endif  // NE2D_RAW_SDL_SURFACE_HPP_
