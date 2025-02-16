#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_text(sol::state& lua) {

    // GlyphInfo
    lua.new_usertype<GlyphInfo>("GlyphInfo",
        "value", &GlyphInfo::value,
        "offsetX", &GlyphInfo::offsetX,
        "offsetY", &GlyphInfo::offsetY,
        "advanceX", &GlyphInfo::advanceX,
        "image", &GlyphInfo::image
    );

    // Font
    lua.new_usertype<Font>("Font",
        sol::call_constructor, sol::factories(
            [](const std::string& filename) {
                return LoadFont(filename.c_str());
            }
        ),
        "baseSize", &Font::baseSize,
        "glyphCount", &Font::glyphCount,
        "glyphPadding", &Font::glyphPadding,
        "texture", &Font::texture,
        "recs", &Font::recs,
        "glyphs", &Font::glyphs
    );

    // Text Namespace
    sol::table text_namespace = lua.create_named_table("Text");

    // TextFormat
    text_namespace.set_function("Format", [](const char* text, sol::variadic_args va) {
        
        // Extract the variable arguments into a vector
        std::vector<std::string> args;
        for (auto arg : va) {
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

    // Draw
    text_namespace.set_function("Draw", DrawText);
    text_namespace.set_function("DrawEx", DrawTextEx);
    text_namespace.set_function("DrawPro", DrawTextPro);

    // Info
    text_namespace.set_function("SetLineSpacing", SetTextLineSpacing);
    text_namespace.set_function("Measure", MeasureText);
    text_namespace.set_function("MeasureEx", MeasureTextEx);
    text_namespace.set_function("GetGlyphInfo", GetGlyphInfo);
    text_namespace.set_function("GetGlyphAtlasRec", GetGlyphAtlasRec);

}