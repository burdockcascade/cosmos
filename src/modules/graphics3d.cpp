#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_graphics3d(sol::state& lua) {

    sol::table g3d = lua.create_named_table("Graphics3D");

    g3d.set_function("DrawPlane", DrawPlane);

    g3d.set_function("DrawCube", DrawCube);
    g3d.set_function("DrawCubeWires", DrawCubeWires);
    g3d.set_function("DrawGrid", DrawGrid);


}