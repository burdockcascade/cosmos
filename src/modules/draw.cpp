#include <sol/sol.hpp>
#include <raylib.h>

void bind_draw(sol::state& lua) {

    sol::table draw = lua.create_named_table("Draw");
    draw.set_function("FPS", DrawFPS);

    // Text
    draw.set_function("Text", DrawText);
    draw.set_function("TextEx", DrawTextEx);

    // Pixel
    draw.set_function("Pixel", DrawPixel);
    draw.set_function("PixelV", DrawPixelV);

    // Line
    draw.set_function("Line", DrawLine);
    draw.set_function("LineV", DrawLineV);
    draw.set_function("LineEx", DrawLineEx);
    draw.set_function("LineStrip", DrawLineStrip);
    draw.set_function("LineBezier", DrawLineBezier);

    // Circle
    draw.set_function("Circle", DrawCircle);
    draw.set_function("CircleV", DrawCircleV);
    draw.set_function("CircleLines", DrawCircleLines);
    draw.set_function("CircleLinesV", DrawCircleLinesV);
    draw.set_function("CircleSector", DrawCircleSector);
    draw.set_function("CircleSectorLines", DrawCircleSectorLines);
    draw.set_function("CircleGradient", DrawCircleGradient);

    // Ring
    draw.set_function("Ring", DrawRing);
    draw.set_function("RingLines", DrawRingLines);

    // Rectangle
    draw.set_function("Rectangle", DrawRectangle);
    draw.set_function("RectangleLines", DrawRectangleLines);
    draw.set_function("RectangleRec", DrawRectangleRec);
    draw.set_function("RectangleLinesEx", DrawRectangleLinesEx);
    draw.set_function("RectangleRounded", DrawRectangleRounded);
    draw.set_function("RectangleRoundedLines", DrawRectangleRoundedLines);
    draw.set_function("RectangleGradientV", DrawRectangleGradientV);
    draw.set_function("RectangleGradientH", DrawRectangleGradientH);
    draw.set_function("RectangleGradientEx", DrawRectangleGradientEx);

    // Triangle
    draw.set_function("Triangle", DrawTriangle);
    draw.set_function("TriangleLines", DrawTriangleLines);
    draw.set_function("TriangleFan", DrawTriangleFan);
    draw.set_function("TriangleStrip", DrawTriangleStrip);

    // Poly
    draw.set_function("Poly", DrawPoly);
    draw.set_function("PolyLines", DrawPolyLines);
    draw.set_function("PolyLinesEx", DrawPolyLinesEx);

    // Plane
    draw.set_function("Plane", DrawPlane);

    // Cube
    draw.set_function("Cube", DrawCube);
    draw.set_function("CubeWires", DrawCubeWires);

    // Grid
    draw.set_function("Grid", DrawGrid);

    // Ray
    draw.set_function("Ray", DrawRay);

    // Sphere
    draw.set_function("Sphere", DrawSphere);
    draw.set_function("SphereWires", DrawSphereWires);

    // Cylinder
    draw.set_function("Cylinder", DrawCylinder);
    draw.set_function("CylinderWires", DrawCylinderWires);
    
    // Capsule
    draw.set_function("Capsule", DrawCapsule);
    draw.set_function("CapsuleWires", DrawCapsuleWires);

}