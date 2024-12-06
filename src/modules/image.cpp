#include <sol/sol.hpp>
#include <raylib.h>

void bind_image(sol::state& lua) {

    // Image
    lua.new_usertype<Image>("Image",
        sol::call_constructor, sol::factories(
            [](const std::string& filename) {
                return LoadImage(filename.c_str());
            }
        ),
        "FromColor", [](int width, int height, Color color) {
            return GenImageColor(width, height, color);
        },
        "FromScreen", [](int width, int height) {
            return LoadImageFromScreen();
        },
        "width", &Image::width,
        "height", &Image::height,
        "mipmaps", &Image::mipmaps,
        "format", &Image::format
    );

}