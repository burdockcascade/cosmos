#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_text(sol::state& lua) {

    // Text Namespace
    sol::table text_namespace = lua.create_named_table("Text");

    // Text
    text_namespace.set_function("Measure", MeasureText);

    // TextFormat
    text_namespace.set_function("Format", [](const char* text, sol::variadic_args va) {
        // Extract the variable arguments into a vector
        std::vector<std::string> args;
        for (auto arg : va) {
            // You might need to handle different argument types here
            args.push_back(arg.as<std::string>()); 
        }

        // Convert the vector to a C-style array of const char*
        std::vector<const char*> c_args;
        for (const auto& str : args) {
            c_args.push_back(str.c_str());
        }

        // Call the actual Raylib TextFormat function
        return TextFormat(text, c_args.data()); 
    });

}