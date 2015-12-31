//
// Copyright 2015 riteme
//

#include <SDL2/SDL_image.h>

#include "ne2d/raw/SDLSurface.hpp"

#include "ne2d/raw/SDLException.hpp"
#include "ne2d/InvaildOperatorException.hpp"

namespace ne {
namespace raw {

SDLSurface::SDLSurface() : m_pSurface(nullptr) {}

SDLSurface::SDLSurface(const std::string &filename) { LoadFile(filename); }

SDLSurface::~SDLSurface() { Destroy(); }

SDLSurface::SDLSurface(SDLSurface &&rhs) : m_pSurface(rhs.m_pSurface) {
    rhs.m_pSurface = nullptr;
}

auto SDLSurface::operator=(SDLSurface &&rhs) -> SDLSurface & {
    Destroy();

    m_pSurface = rhs.m_pSurface;
    rhs.m_pSurface = nullptr;

    return *this;
}

auto SDLSurface::Width() const -> SizeType {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLSurface::Width()",
                                       "SDL Surface is invaild.");

    return m_pSurface->w;
}

auto SDLSurface::Height() const -> SizeType {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLSurface::Height()",
                                       "SDL Surface is invaild.");

    return m_pSurface->h;
}

auto SDLSurface::Pitch() const -> SizeType {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLSurface::Pitch()",
                                       "SDL Surface is invaild.");

    return m_pSurface->pitch;
}

auto SDLSurface::GetPixels() -> void * {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLSurface::GetPixels()",
                                       "SDL Surface is invaild.");

    return m_pSurface->pixels;
}

auto SDLSurface::IsVaild() const -> Bool { return m_pSurface != nullptr; }

void SDLSurface::LoadFile(const std::string &filename) {
    // If this surface is vaild, destroy it first to handle the new one.
    Destroy();

    m_pSurface = IMG_Load(filename.c_str());

    if (m_pSurface == nullptr)
        throw SDLException("Cannot load file to create SDL Surface.");
}

void SDLSurface::SaveFile(const std::string &filename) {
    if (SDL_SaveBMP(m_pSurface, filename.c_str()) < 0)
        throw SDLException("Cannot save SDL Surface into BMP file.");
}

void SDLSurface::Destroy() {
    if (m_pSurface != nullptr) SDL_FreeSurface(m_pSurface);

    m_pSurface = nullptr;
}

auto SDLSurface::ToString() const -> std::string {
    return "<ne::raw::SDLSurface>";
}

auto SDLSurface::HashCode() const -> ne::SizeType {
    return reinterpret_cast<SizeType>(m_pSurface);
}

}  // namespace raw
}  // namespace ne
