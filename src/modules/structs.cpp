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

}