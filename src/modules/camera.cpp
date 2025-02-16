#include <sol/sol.hpp>
#include <raylib.h>

void bind_camera(sol::state& lua) {

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

}