local api = require("autobind/raylib_api")

local modules = {
    window = {
        functions = {},
        structs = {}
    },
    shapes = {},
    textures = {},
    text = {},
}

-- create a file for each module
for module, functions in pairs(modules) do
    local file = io.open("src/mods2/raylib_" .. module .. ".cpp", "w")

    -- write header
    file:write("#include <raylib.h>\n")
    file:write("#include <sol/sol.hpp>\n\n")

    -- open function
    file:write("void bind_raylib_" .. module .. "(sol::state& lua) {\n")

    -- capitalize first letter
    module = module:gsub("^%l", string.upper)

    -- create new table called "Raylib"
    file:write("    sol::table rl = lua.create_named_table(\"" .. module .. "\");\n\n");

    -- write each function
    for i, func in ipairs(functions) do
        file:write("    rl.set_function(\"" .. func.name .. "\", " .. func.name .. ");\n")
    end

    -- write constants
    for i, const in ipairs(api.constants or {}) do
        file:write("    lua[\"Raylib\"][\"" .. const.name .. "\"] = " .. const.value .. ";\n")
    end

    -- close function
    file:write("}\n")
end

