#include <sol/sol.hpp>
#include <raylib.h>

void bind_graphics(sol::state& lua) {

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
        "Unload", &UnloadTexture
    );

    // Namespace for drawing functions
    sol::table graphics = lua.create_named_table("Graphics");

    // Texture
    graphics.set_function("SetShapesTexture", SetShapesTexture);
    graphics.set_function("DrawTexture", DrawTexture);
    graphics.set_function("DrawTextureEx", DrawTextureEx);
    graphics.set_function("DrawTextureRec", DrawTextureRec);
    graphics.set_function("DrawTexturePro", DrawTexturePro);

    // Modes
    graphics.set_function("BeginDrawing", BeginDrawing);
    graphics.set_function("EndDrawing", EndDrawing);
    graphics.set_function("BeginMode2D", BeginMode2D);
    graphics.set_function("EndMode2D", EndMode2D);
    graphics.set_function("BeginMode3D", BeginMode3D);
    graphics.set_function("EndMode3D", EndMode3D);
    graphics.set_function("BeginScissorMode", BeginScissorMode);
    graphics.set_function("EndScissorMode", EndScissorMode);

    // FPS
    graphics.set_function("DrawFPS", DrawFPS);

    // Text
    graphics.set_function("DrawText", DrawText);
    graphics.set_function("DrawTextEx", DrawTextEx);

    // Pixel
    graphics.set_function("DrawPixel", DrawPixel);
    graphics.set_function("DrawPixelV", DrawPixelV);

    // Line
    graphics.set_function("DrawLine", DrawLine);
    graphics.set_function("DrawLineV", DrawLineV);
    graphics.set_function("DrawLineEx", DrawLineEx);
    graphics.set_function("DrawLineStrip", DrawLineStrip);
    graphics.set_function("DrawLineBezier", DrawLineBezier);

    // Circle
    graphics.set_function("DrawCircle", DrawCircle);
    graphics.set_function("DrawCircleV", DrawCircleV);
    graphics.set_function("DrawCircleLines", DrawCircleLines);
    graphics.set_function("DrawCircleLinesV", DrawCircleLinesV);
    graphics.set_function("DrawCircleSector", DrawCircleSector);
    graphics.set_function("DrawCircleSectorLines", DrawCircleSectorLines);
    graphics.set_function("DrawCircleGradient", DrawCircleGradient);

    // Ring
    graphics.set_function("DrawRing", DrawRing);
    graphics.set_function("DrawRingLines", DrawRingLines);

    // Rectangle
    graphics.set_function("DrawRectangle", DrawRectangle);
    graphics.set_function("DrawRectangleLines", DrawRectangleLines);
    graphics.set_function("DrawRectangleRec", DrawRectangleRec);
    graphics.set_function("DrawRectangleLinesEx", DrawRectangleLinesEx);
    graphics.set_function("DrawRectangleRounded", DrawRectangleRounded);
    graphics.set_function("DrawRectangleRoundedLines", DrawRectangleRoundedLines);
    graphics.set_function("DrawRectangleGradientV", DrawRectangleGradientV);
    graphics.set_function("DrawRectangleGradientH", DrawRectangleGradientH);
    graphics.set_function("DrawRectangleGradientEx", DrawRectangleGradientEx);

    // Triangle
    graphics.set_function("DrawTriangle", DrawTriangle);
    graphics.set_function("DrawTriangleLines", DrawTriangleLines);
    graphics.set_function("DrawTriangleFan", DrawTriangleFan);
    graphics.set_function("DrawTriangleStrip", DrawTriangleStrip);

    // Poly
    graphics.set_function("DrawPoly", DrawPoly);
    graphics.set_function("DrawPolyLines", DrawPolyLines);
    graphics.set_function("DrawPolyLinesEx", DrawPolyLinesEx);

    // Plane
    graphics.set_function("DrawPlane", DrawPlane);

    // Cube
    graphics.set_function("DrawCube", DrawCube);
    graphics.set_function("DrawCubeWires", DrawCubeWires);

    // Grid
    graphics.set_function("DrawGrid", DrawGrid);

    // Ray
    graphics.set_function("DrawRay", DrawRay);

    // Sphere
    graphics.set_function("DrawSphere", DrawSphere);
    graphics.set_function("DrawSphereWires", DrawSphereWires);

    // Cylinder
    graphics.set_function("DrawCylinder", DrawCylinder);
    graphics.set_function("DrawCylinderWires", DrawCylinderWires);
    
    // Capsule
    graphics.set_function("DrawCapsule", DrawCapsule);
    graphics.set_function("DrawCapsuleWires", DrawCapsuleWires);

}