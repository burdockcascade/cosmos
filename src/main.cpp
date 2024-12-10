#include <string>

#include <sol/sol.hpp>
#include <raylib.h>
#include "modules/modules.hpp"

int main(const int argc, char* argv[]) {

    if (argc < 2) {
        TraceLog(LOG_ERROR, "Usage: %s <file.lua>", argv[0]);
        return 0;
    }

    const std::string fileToLoad = argv[1];

    TraceLog(LOG_INFO, "Loading Lua file: %s", fileToLoad.c_str());

    if (!FileExists(fileToLoad.c_str())) {
        TraceLog(LOG_ERROR, "File not found: %s", fileToLoad.c_str());
        return 1;
    }

    if (!IsFileExtension(fileToLoad.c_str(), ".lua")) {
        TraceLog(LOG_ERROR, "File is not a Lua file: %s", fileToLoad.c_str());
        return 1;
    }

    sol::state lua;
    lua.open_libraries(
        sol::lib::base,
        sol::lib::table,
        sol::lib::string,
        sol::lib::coroutine,
        sol::lib::utf8
    ); 

    // bind modules
    bind_raylib_structs(lua);
    bind_raylib_color(lua);
    bind_graphics(lua);
    bind_image(lua);
    bind_raylib_window(lua);
    bind_raylib_input(lua);
    bind_raylib_text(lua);
    bind_math(lua);
    bind_raylib_collision(lua);
    bind_camera(lua);

    // load file
    sol::load_result result = lua.load_file(fileToLoad);

    // check for errors
    if (!result.valid()) {
        sol::error err = result;
        TraceLog(LOG_ERROR, "Error loading Lua file: %s", err.what());
        return 1;
    }

    // run the script
    sol::protected_function_result scriptResult = result();

    // check for errors
    if (!scriptResult.valid()) {
        sol::error err = scriptResult;
        TraceLog(LOG_ERROR, "Error running Lua file: %s", err.what());
        return 1;
    }
    
    return 0;
}