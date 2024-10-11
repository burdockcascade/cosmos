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

    // Vector3
    lua.new_usertype<Vector3>("Vector3",
        sol::call_constructor, sol::factories(
            []() {
                return Vector3{0.0f, 0.0f, 0.0f};
            },
            [](float x, float y, float z) {
                return Vector3{x, y, z};
            }
        ),
        "x", &Vector3::x,
        "y", &Vector3::y,
        "z", &Vector3::z
    );

    // Vector4
    lua.new_usertype<Vector4>("Vector4",
        sol::call_constructor, sol::factories(
            []() {
                return Vector4{0.0f, 0.0f, 0.0f, 0.0f};
            },
            [](float x, float y, float z, float w) {
                return Vector4{x, y, z, w};
            }
        ),
        "x", &Vector4::x,
        "y", &Vector4::y,
        "z", &Vector4::z,
        "w", &Vector4::w
    );

    // Matrix
    lua.new_usertype<Matrix>("Matrix",
        sol::call_constructor, sol::factories(
            []() {
                return Matrix{};
            },
            [](float m0, float m4, float m8, float m12, float m1, float m5, float m9, float m13, float m2, float m6, float m10, float m14, float m3, float m7, float m11, float m15) {
                return Matrix{m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15};
            }
        ),
        "m0", &Matrix::m0,
        "m4", &Matrix::m4,
        "m8", &Matrix::m8,
        "m12", &Matrix::m12,
        "m1", &Matrix::m1,
        "m5", &Matrix::m5,
        "m9", &Matrix::m9,
        "m13", &Matrix::m13,
        "m2", &Matrix::m2,
        "m6", &Matrix::m6,
        "m10", &Matrix::m10,
        "m14", &Matrix::m14,
        "m3", &Matrix::m3,
        "m7", &Matrix::m7,
        "m11", &Matrix::m11,
        "m15", &Matrix::m15
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

    // Camera3D
    lua.new_usertype<Camera3D>("Camera3D",
        sol::call_constructor, sol::factories(
            []() {
                return Camera3D{Vector3{0.0f, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}, 0.0f, 0};
            },
            [](Vector3 position, Vector3 target, Vector3 up) {
                return Camera3D{position, target, up, 0.0f, 0};
            },
            [](Vector3 position, Vector3 target, Vector3 up, float fovy) {
                return Camera3D{position, target, up, fovy, 0};
            },
            [](Vector3 position, Vector3 target, Vector3 up, float fovy, int type) {
                return Camera3D{position, target, up, fovy, type};
            }
        ),
        "position", &Camera3D::position,
        "target", &Camera3D::target,
        "up", &Camera3D::up,
        "fovy", &Camera3D::fovy,
        "projection", &Camera3D::projection
    );

    // Camera Mode
    lua["CAMERA_CUSTOM"] = CAMERA_CUSTOM;
    lua["CAMERA_FREE"] = CAMERA_FREE;
    lua["CAMERA_ORBITAL"] = CAMERA_ORBITAL;
    lua["CAMERA_FIRST_PERSON"] = CAMERA_FIRST_PERSON;
    lua["CAMERA_THIRD_PERSON"] = CAMERA_THIRD_PERSON;

    // Camera Projection
    lua["CAMERA_PERSPECTIVE"] = CAMERA_PERSPECTIVE;
    lua["CAMERA_ORTHOGRAPHIC"] = CAMERA_ORTHOGRAPHIC;

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