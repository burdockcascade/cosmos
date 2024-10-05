#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_structs(sol::state& lua) {

    // Vector2
    lua.new_usertype<Vector2>("Vector2",
        sol::call_constructor, sol::factories(
            []() {
                return Vector2{0.0f, 0.0f};
            },
            [](float x, float y) {
                return Vector2{x, y};
            }
        ),
        "x", &Vector2::x,
        "y", &Vector2::y
    );

    // Rectangle
    lua.new_usertype<Rectangle>("Rectangle",
        sol::call_constructor, sol::factories(
            []() {
                return Rectangle{0.0f, 0.0f, 0.0f, 0.0f};
            },
            [](float x, float y, float width, float height) {
                return Rectangle{x, y, width, height};
            }
        ),
        "x", &Rectangle::x,
        "y", &Rectangle::y,
        "width", &Rectangle::width,
        "height", &Rectangle::height
    );

    // Camera2D
    lua.new_usertype<Camera2D>("Camera2D",
        sol::call_constructor, sol::factories(
            []() {
                return Camera2D{Vector2{0.0f, 0.0f}, Vector2{0.0f, 0.0f}, 0.0f, 1.0f};
            },
            [](Vector2 offset, Vector2 target, float rotation, float zoom) {
                return Camera2D{offset, target, rotation, zoom};
            }
        ),
        "offset", &Camera2D::offset,
        "target", &Camera2D::target,
        "rotation", &Camera2D::rotation,
        "zoom", &Camera2D::zoom
    );

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
        "a", &Color::a
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