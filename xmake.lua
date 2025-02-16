set_description("Cosmos Game Framework")
set_version("0.1.0")

set_languages("cxx20")

add_requires("raylib 5.5", "lua 5.4.7", "sol2 3.3.0")
add_rules("mode.debug", "mode.release")

target("cosmos")
    add_packages("raylib", "lua",  "sol2")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("src/modules/*.cpp")
