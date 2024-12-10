#pragma once

#include <sol/sol.hpp>

#define SET_GLOBAL_CONSTANT(name) \
    lua[#name] = name

// These are split into separate files for organization and speed of compilation

void bind_raylib_structs(sol::state& lua);
void bind_raylib_color(sol::state& lua);
void bind_graphics(sol::state& lua);
void bind_image(sol::state& lua);
void bind_raylib_window(sol::state& lua);
void bind_raylib_input(sol::state& lua);
void bind_raylib_text(sol::state& lua);
void bind_math(sol::state& lua);
void bind_raylib_collision(sol::state& lua);
void bind_camera(sol::state& lua);
