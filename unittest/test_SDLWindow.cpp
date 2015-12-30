//
// Copyright 2015 riteme
//

#include "test.hpp"

#include "../src/raw/SDL.hpp"
#include "../src/raw/SDLWindow.hpp"

#include <utility>
#include <chrono>
#include <thread>

using namespace std;
using namespace ne;
using namespace ne::raw;
using namespace ne::math;
using namespace std::this_thread;
using namespace std::chrono;

TESTCASE_GROUP_BEGIN

PREPARE_BEGIN {
    try {
        SDL::Init(Everything);
    } catch (const SDLException &e) {
        DEBUG(e.Description());

        FATAL;
    }

    DEBUG(SDL::CheckAllInitedSubsystem());
    ASSERT(SDL::WasInited(Video));
}
PREPARE_END

TESTCASE("Constructor and operator test") {
    SDLWindow wnd;

    sleep_for(milliseconds(200));

    CHECK(wnd.GetTitle() == SDLWindow::DefaultTitle);
    CHECK(wnd.GetWidth() == SDLWindow::DefaultWidth);
    CHECK(wnd.GetHeight() == SDLWindow::DefaultHeight);

    SDLWindow wnd2("Test", Centered, Centered, 1024, 768);

    sleep_for(milliseconds(200));

    CHECK(wnd2.GetTitle() == "Test");
    CHECK(wnd2.GetWidth() == 1024);
    CHECK(wnd2.GetHeight() == 768);

    CHECK(wnd != wnd2);

    SDLWindow wnd3 = move(wnd2);

    sleep_for(milliseconds(200));

    CHECK(!wnd2.IsVaild());
    CHECK(wnd3.IsVaild());
    CHECK(wnd.IsVaild());
    CHECK(wnd != wnd3);

    SDLWindow &wnd4 = wnd;

    sleep_for(milliseconds(200));

    CHECK(wnd4.IsVaild());
    CHECK(wnd.IsVaild());
    CHECK(wnd == wnd4);
    CHECK(wnd4 != wnd3);

    SDLWindow wnd5 = wnd;

    sleep_for(milliseconds(200));

    CHECK(wnd5.GetTitle() == wnd.GetTitle());
    CHECK(wnd5.GetSize() == wnd.GetSize());
}
TESTCASE_END

TESTCASE("Functions test") {
    SDLWindow wnd;

    sleep_for(milliseconds(200));

    CHECK(wnd.GetTitle() == SDLWindow::DefaultTitle);
    CHECK(wnd.GetWidth() == SDLWindow::DefaultWidth);
    CHECK(wnd.GetHeight() == SDLWindow::DefaultHeight);

    wnd.SetPosition(Vector2D(34, 56));

    sleep_for(milliseconds(200));

    CHECK(wnd.GetX() == 34);
    CHECK(wnd.GetY() == 56);

    wnd.SetPosition(107, 107);

    sleep_for(milliseconds(200));

    CHECK(wnd.GetPosition() == Vector2D(107, 107));

    wnd.SetSize(Vector2D(340, 400));

    sleep_for(milliseconds(200));

    CHECK(wnd.GetWidth() == 340);
    CHECK(wnd.GetHeight() == 400);

    wnd.SetSize(1280, 800);

    sleep_for(milliseconds(200));

    CHECK(wnd.GetSize() == Vector2D(1280, 800));

    const string title = "Hello, ne2d!";
    wnd.SetTitle(title);

    sleep_for(milliseconds(200));

    CHECK(wnd.GetTitle() == title);

    wnd.Destroy();

    sleep_for(milliseconds(200));

    CHECK(!wnd.IsVaild());
}
TESTCASE_END

CLEANUP_BEGIN { SDL::Quit(); }
CLEANUP_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
