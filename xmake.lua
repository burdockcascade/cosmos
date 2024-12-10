set_description("Cosmos Game Engine")
set_version("0.1.0")

set_languages("cxx20")

add_requires("raylib 5.5", "sol2 3.3.0")
add_rules("mode.debug", "mode.release")

target("cosmos")
    set_optimize("fastest")
    add_packages("raylib",  "sol2")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("src/modules/*.cpp")
