#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_color(sol::state& lua) {

    // Color
    lua.new_usertype<Color>("Color",
        sol::call_constructor, sol::factories(
            []() {
                return Color{static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(255)};
            },
            [](int r, int g, int b, int a) {
                return Color{static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), static_cast<unsigned char>(a)};
            }
        ),
        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::a,
        "Random", []() {
            return Color{static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(255)};
        },
        "Fade", [](Color color, float alpha) {
            return Fade(color, alpha);
        }
    );

    lua["COLOR_LIGHTGRAY"] = LIGHTGRAY;
    lua["COLOR_GRAY"] = GRAY;
    lua["COLOR_DARKGRAY"] = DARKGRAY;
    lua["COLOR_YELLOW"] = YELLOW;
    lua["COLOR_GOLD"] = GOLD;
    lua["COLOR_ORANGE"] = ORANGE;
    lua["COLOR_PINK"] = PINK;
    lua["COLOR_RED"] = RED;
    lua["COLOR_MAROON"] = MAROON;
    lua["COLOR_GREEN"] = GREEN;
    lua["COLOR_LIME"] = LIME;
    lua["COLOR_DARKGREEN"] = DARKGREEN;
    lua["COLOR_SKYBLUE"] = SKYBLUE;
    lua["COLOR_BLUE"] = BLUE;
    lua["COLOR_DARKBLUE"] = DARKBLUE;
    lua["COLOR_PURPLE"] = PURPLE;
    lua["COLOR_VIOLET"] = VIOLET;
    lua["COLOR_DARKPURPLE"] = DARKPURPLE;
    lua["COLOR_BEIGE"] = BEIGE;
    lua["COLOR_BROWN"] = BROWN;
    lua["COLOR_DARKBROWN"] = DARKBROWN;
    lua["COLOR_WHITE"] = WHITE;
    lua["COLOR_BLACK"] = BLACK;
    lua["COLOR_BLANK"] = BLANK;
    lua["COLOR_MAGENTA"] = MAGENTA;
    lua["COLOR_RAYWHITE"] = RAYWHITE;

}