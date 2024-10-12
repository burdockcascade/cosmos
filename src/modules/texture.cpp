#include <sol/sol.hpp>
#include <raylib.h>

void bind_texture(sol::state& lua) {

    // Texture2D
    lua.new_usertype<Texture2D>("Texture2D",
        sol::call_constructor, [](const std::string& filename) {
            return LoadTexture(filename.c_str());
        },
        "id", &Texture2D::id,
        "width", &Texture2D::width,
        "height", &Texture2D::height,
        "mipmaps", &Texture2D::mipmaps,
        "format", &Texture2D::format,
        "Unload", &UnloadTexture,
        "Draw", [](Texture2D texture, int posX, int posY, Color tint) {
            DrawTexture(texture, posX, posY, tint);
        },
        "DrawEx", [](Texture2D texture, Vector2 position, float rotation, float scale, Color tint) {
            DrawTextureEx(texture, position, rotation, scale, tint);
        },
        "DrawPro", [](Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint) {
            DrawTexturePro(texture, sourceRec, destRec, origin, rotation, tint);
        }
    );

}