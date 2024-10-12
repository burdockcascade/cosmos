#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_collision(sol::state& lua) {

    // Ray
    lua.new_usertype<Ray>("Ray",
        sol::call_constructor, sol::factories(
            []() {
                return Ray{Vector3{0.0f, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}};
            },
            [](Vector3 position, Vector3 direction) {
                return Ray{position, direction};
            }
        ),
        "position", &Ray::position,
        "direction", &Ray::direction
    );

    // Ray Collision
    lua.new_usertype<RayCollision>("RayCollision",
        sol::call_constructor, sol::factories(
            []() {
                return RayCollision{false, 0.0f, Vector3{0.0f, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}};
            },
            [](bool hit, float distance, Vector3 point, Vector3 normal, int triangleIndex) {
                return RayCollision{hit, distance, point, normal};
            }
        ),
        "hit", &RayCollision::hit,
        "distance", &RayCollision::distance,
        "point", &RayCollision::point,
        "normal", &RayCollision::normal
    );

    // Bounding Box
    lua.new_usertype<BoundingBox>("BoundingBox",
        sol::call_constructor, sol::factories(
            []() {
                return BoundingBox{Vector3{0.0f, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}};
            },
            [](Vector3 min, Vector3 max) {
                return BoundingBox{min, max};
            }
        ),
        "min", &BoundingBox::min,
        "max", &BoundingBox::max
    );

    // Collision namespace
    sol::table collision = lua.create_named_table("Collision");

    // 2D Collision Detection
    collision.set_function("CheckRecs", CheckCollisionRecs);
    collision.set_function("CheckCircles", CheckCollisionCircles);
    collision.set_function("CheckCircleRec", CheckCollisionCircleRec);
    collision.set_function("CheckPointRec", CheckCollisionPointRec);
    collision.set_function("CheckPointCircle", CheckCollisionPointCircle);
    collision.set_function("CheckPointTriangle", CheckCollisionPointTriangle);
    collision.set_function("CheckPointPoly", CheckCollisionPointPoly);
    collision.set_function("CheckLines", CheckCollisionLines);
    collision.set_function("CheckPointLine", CheckCollisionPointLine);

    // 3D Collision Detection
    collision.set_function("CheckSpheres", CheckCollisionSpheres);
    collision.set_function("CheckBoxes", CheckCollisionBoxes);
    collision.set_function("CheckBoxSphere", CheckCollisionBoxSphere);

    // Get collision info
    collision.set_function("GetCollisionRec", GetCollisionRec);
    //collision.set_function("GetRayCollisionSphere, GetRayCollisionSphere");
    collision.set_function("GetRayCollisionBox", GetRayCollisionBox);
    //collision.set_function("GetRayCollisionMesh", GetRayCollisionMesh);
    //collision.set_function("GetRayCollisionTriangle", GetRayCollisionTriangle);
    //collision.set_function("GetRayCollisionQuad", GetRayCollisionQuad);

}