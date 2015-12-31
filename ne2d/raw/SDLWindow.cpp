//
// Copyright 2015 riteme
//

#include <stdexcept>

#include "ne2d/InvaildOperatorException.hpp"

#include "ne2d/raw/SDLWindow.hpp"
#include "ne2d/raw/SDLException.hpp"

namespace ne {
namespace raw {

std::string SDLWindow::DefaultTitle = "Window";
Integer SDLWindow::DefaultXPos = Undefined;
Integer SDLWindow::DefaultYPos = Undefined;
Integer SDLWindow::DefaultWidth = 800;
Integer SDLWindow::DefaultHeight = 600;
UInt32 SDLWindow::DefaultFlags = OpenGL;

SDLWindow::SDLWindow() {
    m_pWindow = SDL_CreateWindow(
        SDLWindow::DefaultTitle.c_str(), SDLWindow::DefaultXPos,
        SDLWindow::DefaultYPos, SDLWindow::DefaultWidth,
        SDLWindow::DefaultHeight, SDLWindow::DefaultFlags);

    if (m_pWindow == nullptr) throw SDLException("Cannot create a SDL window.");
}

SDLWindow::SDLWindow(const std::string &title, const Integer x, const Integer y,
                     const Integer width, const Integer height) {
    m_pWindow = SDL_CreateWindow(title.c_str(), x, y, width, height,
                                 SDLWindow::DefaultFlags);

    if (m_pWindow == nullptr) throw SDLException("Cannot create a SDL window.");
}

SDLWindow::SDLWindow(const std::string &title, const Integer x, const Integer y,
                     const Integer width, const Integer height,
                     const Uint32 flags) {
    m_pWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

    if (m_pWindow == nullptr) throw SDLException("Cannot create a SDL window.");
}

SDLWindow::~SDLWindow() { Destroy(); }

SDLWindow::SDLWindow(SDLWindow &&rhs) : m_pWindow(rhs.m_pWindow) {
    rhs.m_pWindow = nullptr;
}

auto SDLWindow::operator=(SDLWindow &&rhs) -> SDLWindow & {
    Destroy();

    m_pWindow = rhs.m_pWindow;
    rhs.m_pWindow = nullptr;

    return *this;
}

auto SDLWindow::GetID() const -> Uint32 {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetID()",
                                       "SDL window is invaild.");

    return SDL_GetWindowID(m_pWindow);
}

auto SDLWindow::GetPosition() const -> ne::math::Vector2D {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetPosition()",
                                       "SDL window is invaild.");

    int x, y;
    SDL_GetWindowPosition(m_pWindow, &x, &y);

    return ne::math::Vector2D(x, y);
}

auto SDLWindow::GetSize() const -> ne::math::Vector2D {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetSize()",
                                       "SDL window is invaild.");

    int w, h;
    SDL_GetWindowSize(m_pWindow, &w, &h);

    return ne::math::Vector2D(w, h);
}

auto SDLWindow::GetX() const -> Integer {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetX()",
                                       "Cannot SDL window is invaild.");

    return GetPosition().X();
}

auto SDLWindow::GetY() const -> Integer {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetY()",
                                       "Cannot SDL window is invaild.");

    return GetPosition().Y();
}

auto SDLWindow::GetWidth() const -> Integer {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetWidth()",
                                       "SDL window is invaild.");

    return GetSize().X();
}

auto SDLWindow::GetHeight() const -> Integer {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetHeight()",
                                       "SDL window is invaild.");

    return GetSize().Y();
}

auto SDLWindow::GetTitle() const -> std::string {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetTitle()",
                                       "SDL window is invaild.");

    return SDL_GetWindowTitle(m_pWindow);
}

auto SDLWindow::GetFlags() const -> UInt32 {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::GetFlags()",
                                       "SDL window is invaild.");

    return SDL_GetWindowFlags(m_pWindow);
}

auto SDLWindow::IsVaild() const -> Bool { return m_pWindow != nullptr; }

void SDLWindow::SetPosition(const ne::math::Vector2D &pos) {
    if (!IsVaild())
        throw InvaildOperatorException(
            "ne::raw::SDLWindow::SetPosition(position)",
            "SDL window is invaild.");

    SDL_SetWindowPosition(m_pWindow, pos.X(), pos.Y());
}

void SDLWindow::SetPosition(const Integer x, const Integer y) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetPosition(x, y)",
                                       "SDL window is invaild.");

    SDL_SetWindowPosition(m_pWindow, x, y);
}

void SDLWindow::SetSize(const ne::math::Vector2D &size) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetSize(size)",
                                       "SDL window is invaild.");

    SDL_SetWindowSize(m_pWindow, size.X(), size.Y());
}

void SDLWindow::SetSize(const Integer width, const Integer height) {
    if (!IsVaild())
        throw InvaildOperatorException(
            "ne::raw::SDLWindow::SetSize(width, height)",
            "SDL window is invaild.");

    SDL_SetWindowSize(m_pWindow, width, height);
}

void SDLWindow::SetX(const Integer x) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetX(x)",
                                       "SDL window is invaild.");

    SDL_SetWindowPosition(m_pWindow, x, GetY());
}

void SDLWindow::SetY(const Integer y) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetY(y)",
                                       "SDL window is invaild.");

    SDL_SetWindowPosition(m_pWindow, GetX(), y);
}

void SDLWindow::SetWidth(const Integer width) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetWidth(width)",
                                       "SDL window is invaild.");

    SDL_SetWindowSize(m_pWindow, width, GetHeight());
}

void SDLWindow::SetHeight(const Integer height) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetHeight(height)",
                                       "SDL window is invaild.");

    SDL_SetWindowSize(m_pWindow, GetWidth(), height);
}

void SDLWindow::SetTitle(const std::string &title) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetTitle(title)",
                                       "SDL window is invaild.");

    SDL_SetWindowTitle(m_pWindow, title.c_str());
}

void SDLWindow::SetFullscreen(const SDLWindowFlags &mode) {
    if (!IsVaild())
        throw InvaildOperatorException(
            "ne::raw::SDLWindow::SetFullscreend(mode)",
            "SDL window is invaild.");

    SDL_SetWindowFullscreen(m_pWindow, mode);
}

void SDLWindow::SetIcon(const SDLSurface &icon) {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::SetIcon(icon)",
                                       "SDL window is invaild.");

    SDL_SetWindowIcon(m_pWindow, icon.m_pSurface);
}

void SDLWindow::Hide() {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::Hide()",
                                       "SDL window is invaild.");

    SDL_HideWindow(m_pWindow);
}

void SDLWindow::Show() {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::Show()",
                                       "SDL window is invaild.");

    SDL_ShowWindow(m_pWindow);
}

void SDLWindow::Raise() {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::Raise()",
                                       "SDL window is invaild.");

    SDL_RaiseWindow(m_pWindow);
}

void SDLWindow::Restore() {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::Restore()",
                                       "SDL window is invaild.");

    SDL_RestoreWindow(m_pWindow);
}

void SDLWindow::Maximize() {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow::Maximize()",
                                       "SDL window is invaild.");

    SDL_MaximizeWindow(m_pWindow);
}

void SDLWindow::Minimize() {
    if (!IsVaild())
        throw InvaildOperatorException("ne::raw::SDLWindow:Minimize()",
                                       "SDL window is invaild.");

    SDL_MinimizeWindow(m_pWindow);
}

void SDLWindow::Destroy() {
    if (IsVaild()) SDL_DestroyWindow(m_pWindow);

    m_pWindow = nullptr;
}

auto operator==(const SDLWindow &a, const SDLWindow &b) -> Bool {
    return a.GetID() == b.GetID();
}

auto operator!=(const SDLWindow &a, const SDLWindow &b) -> Bool {
    return a.GetID() != b.GetID();
}

auto SDLWindow::ToString() const -> std::string {
    return "<ne::raw::SDLWindow>";
}

auto SDLWindow::HashCode() const -> ne::SizeType { return GetID(); }

}  // namespace raw
}  // namespace ne
