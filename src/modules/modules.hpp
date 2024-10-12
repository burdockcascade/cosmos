#pragma once

#include <sol/sol.hpp>

// These are split into separate files for organization and speed of compilation

void bind_raylib_structs(sol::state& lua);
void bind_graphics(sol::state& lua);
void bind_raylib_window(sol::state& lua);
void bind_raylib_input(sol::state& lua);
void bind_raylib_text(sol::state& lua);
void bind_math(sol::state& lua);
void bind_raylib_collision(sol::state& lua);

inline void bind_raylib(sol::state& lua) {
    bind_raylib_structs(lua);
    bind_graphics(lua);
    bind_raylib_window(lua);
    bind_raylib_input(lua);
    bind_raylib_text(lua);
    bind_math(lua);
    bind_raylib_collision(lua);
}