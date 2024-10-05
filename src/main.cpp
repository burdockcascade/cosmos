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
        sol::lib::coroutine,
        sol::lib::utf8
    ); 

    bind_raylib(lua);

    lua.script_file(fileToLoad);
    
    return 0;
}