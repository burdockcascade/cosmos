#include <sol/sol.hpp>
#include <raylib.h>

void bind_raylib_graphics2d(sol::state& lua) {
    sol::table graphics2dNamespace = lua.create_named_table("Graphics2D");
    graphics2dNamespace.set_function("DrawFPS", DrawFPS);

    // Text
    graphics2dNamespace.set_function("DrawText", DrawText);
    graphics2dNamespace.set_function("DrawTextEx", DrawTextEx);

    // Rectangle
    graphics2dNamespace.set_function("DrawRectangle", DrawRectangle);
    graphics2dNamespace.set_function("DrawRectangleLines", DrawRectangleLines);
    graphics2dNamespace.set_function("DrawRectangleRec", DrawRectangleRec);
    graphics2dNamespace.set_function("DrawRectangleLinesEx", DrawRectangleLinesEx);
    graphics2dNamespace.set_function("DrawRectangleRounded", DrawRectangleRounded);
    graphics2dNamespace.set_function("DrawRectangleRoundedLines", DrawRectangleRoundedLines);
    graphics2dNamespace.set_function("DrawRectangleGradientV", DrawRectangleGradientV);
    graphics2dNamespace.set_function("DrawRectangleGradientH", DrawRectangleGradientH);
    graphics2dNamespace.set_function("DrawRectangleGradientEx", DrawRectangleGradientEx);

    // Poly
    graphics2dNamespace.set_function("DrawPoly", DrawPoly);
    graphics2dNamespace.set_function("DrawPolyLines", DrawPolyLines);

    // Line
    graphics2dNamespace.set_function("DrawLine", DrawLine);
    graphics2dNamespace.set_function("DrawLineV", DrawLineV);
    graphics2dNamespace.set_function("DrawLineEx", DrawLineEx);

    // Circle
    graphics2dNamespace.set_function("DrawCircle", DrawCircle);
    graphics2dNamespace.set_function("DrawCircleV", DrawCircleV);
    graphics2dNamespace.set_function("DrawCircleLines", DrawCircleLines);
    graphics2dNamespace.set_function("DrawCircleSector", DrawCircleSector);
    graphics2dNamespace.set_function("DrawCircleSectorLines", DrawCircleSectorLines);
    graphics2dNamespace.set_function("DrawCircleGradient", DrawCircleGradient);

    // Triangle
    graphics2dNamespace.set_function("DrawTriangle", DrawTriangle);


}