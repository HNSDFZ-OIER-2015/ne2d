//
// Copyright 2015 riteme
//

#ifndef NE2D_RAW_SDL_WINDOW_HPP_
#define NE2D_RAW_SDL_WINDOW_HPP_

#include <SDL2/SDL.h>

#include <string>

#include "ClassAttribute.hpp"
#include "TypeConfiguration.hpp"

#include "raw/SDLWindowFlags.hpp"
#include "raw/SDLWindowPosition.hpp"

#include "math/Vector2D.hpp"

#include "utility/StringFormat.hpp"

namespace ne::raw {
    class SDLWindow : public ne::IObject {
     public:
        NONCOMPARABLE(SDLWindow)

        constexpr static Char DefaultTitle[] = "Window";
        const static Integer DefaultXPos = Undefined;
        const static Integer DefaultYPos = Undefined;
        const static Integer DefaultWidth = 800;
        const static Integer DefaultHeight = 600;
        const static UInt32 DefaultFlags = OpenGL | Resizable;

        SDLWindow();
        SDLWindow(const std::string &title, const Integer x, const Integer y,
                  const Integer width, const Integer height);
        SDLWindow(const std::string &title, const Integer x, const Integer y,
                  const Integer width, const Integer height,
                  const Uint32 flags);

        virtual ~SDLWindow();

        SDLWindow(const SDLWindow &lhs);
        auto operator=(const SDLWindow &lhs) -> SDLWindow &;

        SDLWindow(SDLWindow &&rhs);
        auto operator=(SDLWindow &&rhs) -> SDLWindow &;

        auto GetID() const -> Uint32;
        auto GetPosition() const -> ne::math::Vector2D;
        auto GetSize() const -> ne::math::Vector2D;
        auto GetX() const -> Integer;
        auto GetY() const -> Integer;
        auto GetWidth() const -> Integer;
        auto GetHeight() const -> Integer;
        auto GetTitle() const -> std::string;

        void SetPosition(const ne::math::Vector2D &pos);
        void SetPosition(const Integer x, const Integer y);
        void SetSize(const ne::math::Vector2D &size);
        void SetSize(const Integer width, const Integer height);
        void SetX(const Integer x);
        void SetY(const Integer y);
        void SetWidth(const Integer width);
        void SetHeight(const Integer height);
        void SetTitle(const std::string &title);

        // TODO(riteme): Complete SDLSurface first.
        void SetIcon();

        void SetFullscreen(const SDLWindowFlags &mode);

        void Hide();
        void Show();
        void Raise();
        void Restoe();
        void Maximize();
        void Minimize();

        friend auto operator==(const SDLWindow &a, const SDLWindow &b) -> Bool;
        friend auto operator!=(const SDLWindow &a, const SDLWindow &b) -> Bool;

        virtual auto ToString() const -> std::string {
            return std::string(typeid(*this).name());
        }

        virtual auto HashCode() const -> ne::SizeType {
            return reinterpret_cast<SizeType>(this);
        }

     private:
        SDL_Window *m_pWindow;
    };  // class SDLWindow
}  // namespace ne::raw

#endif  // NE2D_RAW_SDL_WINDOW_HPP_
