#include <sol/sol.hpp>
#include <raylib.h>

#include "binding_util.hpp"

void bind_graphic_structs(sol::state& lua) {

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
        "FromImage", &LoadTextureFromImage
    );

    // Model
    lua.new_usertype<Model>("Model",
        sol::call_constructor, [](const std::string& filename) {
            return LoadModel(filename.c_str());
        },
        "meshCount", &Model::meshCount,
        "materialCount", &Model::materialCount,
        "transform", &Model::transform,
        "meshes", &Model::meshes,
        "materials", &Model::materials,
        "meshMaterial", &Model::meshMaterial,
        "IsReady", &IsModelValid,
        "FromMesh", &LoadModelFromMesh,
        "GetMaterial", [](Model& model, int index) {
            if (index >= 0 && index < model.materialCount) {
                return &model.materials[index];
            }
            return static_cast<Material*>(nullptr);
        }
    );

    SET_GLOBAL_CONSTANT(MATERIAL_MAP_ALBEDO);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_METALNESS);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_NORMAL);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_ROUGHNESS);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_OCCLUSION);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_EMISSION);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_HEIGHT);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_CUBEMAP);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_IRRADIANCE);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_PREFILTER);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_BRDF);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_DIFFUSE);
    SET_GLOBAL_CONSTANT(MATERIAL_MAP_SPECULAR);


    // Mesh
    lua.new_usertype<Mesh>("Mesh",
        "vertexCount", &Mesh::vertexCount,
        "triangleCount", &Mesh::triangleCount,
        "vertices", &Mesh::vertices,
        "texcoords", &Mesh::texcoords,
        "normals", &Mesh::normals,
        "tangents", &Mesh::tangents,
        "colors", &Mesh::colors,
        "texcoords2", &Mesh::texcoords2,
        "indices", &Mesh::indices,
        "vaoId", &Mesh::vaoId,
        "vboId", &Mesh::vboId,
        "FromHeightmap", &GenMeshHeightmap
    );

    // Material
    lua.new_usertype<Material>("Material",
        sol::call_constructor, sol::factories(
            []() {
                return LoadMaterialDefault();
            },
            [](Shader shader) {
                return Material{shader};
            }
        ),
        "shader", &Material::shader,
        "maps", &Material::maps,
        "params", &Material::params,
        "GetMap", [](Material& material, int type) {
            return &material.maps[type];
        }
    );

    // MaterialMap
    lua.new_usertype<MaterialMap>("MaterialMap",
        "texture", &MaterialMap::texture,
        "color", &MaterialMap::color,
        "value", &MaterialMap::value
    );

}

void bind_graphic_functions(sol::state& lua) {

    // Namespace for drawing functions
    sol::table graphics = lua.create_named_table("Graphics");

    graphics.set_function("LoadModelFromMesh", LoadModelFromMesh);

    // == 2D Shapes ==

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

    // == 3D Shapes ==

    // Plane
    graphics.set_function("DrawPlane", DrawPlane);

    // Cube
    graphics.set_function("DrawCube", DrawCube);
    graphics.set_function("DrawCubeWires", DrawCubeWires);

    // Grid
    graphics.set_function("DrawGrid", DrawGrid);

    // Lines
    graphics.set_function("DrawLine3D", DrawLine3D);

    // Points
    graphics.set_function("DrawPoint3D", DrawPoint3D);

    // Ray
    graphics.set_function("DrawRay", DrawRay);

    // Sphere
    graphics.set_function("DrawSphere", DrawSphere);
    graphics.set_function("DrawSphereEx", DrawSphereEx);
    graphics.set_function("DrawSphereWires", DrawSphereWires);

    // Cylinder
    graphics.set_function("DrawCylinder", DrawCylinder);
    graphics.set_function("DrawCylinderWires", DrawCylinderWires);
    
    // Capsule
    graphics.set_function("DrawCapsule", DrawCapsule);
    graphics.set_function("DrawCapsuleWires", DrawCapsuleWires);

    // Model
    graphics.set_function("DrawModel", DrawModel);
    graphics.set_function("DrawModelEx", DrawModelEx);
    graphics.set_function("DrawModelWires", DrawModelWires);
    graphics.set_function("DrawModelWiresEx", DrawModelWiresEx);

}

void bind_graphics(sol::state& lua) {
    bind_graphic_structs(lua);
    bind_graphic_functions(lua);
}