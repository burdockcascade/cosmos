Window.Init(800, 450, "heightmap loading and drawing")

local camera = Camera3D()
camera.position = Vector3( 18.0, 21.0, 18.0 )
camera.target = Vector3( 0.0, 0.0, 0.0 )
camera.up = Vector3( 0.0, 1.0, 0.0 )
camera.fovy = 45.0
camera.projection = CAMERA_PERSPECTIVE

local image = Image("C:/Workspace/cosmos/examples/models/resources/heightmap.png")

local tex2d = Texture2D.FromImage(image)
local mesh = Mesh.FromHeightmap(image, Vector3(16, 8, 16))
local model = Model.FromMesh(mesh)

print(model:GetMaterial(0):GetMap(MATERIAL_MAP_DIFFUSE).texture)

model:GetMaterial(0):GetMap(MATERIAL_MAP_DIFFUSE).texture = tex2d

Window.SetTargetFPS(60)

while not Window.ShouldClose() do

    Window.UpdateCamera(camera, CAMERA_ORBITAL)

    Graphics.BeginDrawing()

        Window.ClearBackground(COLOR_RAYWHITE)

        Graphics.BeginMode3D(camera)

            Graphics.DrawModel(model, Vector3(-8.0, 0.0, -8.0), 1.0, COLOR_LIME)
            Graphics.DrawGrid(16, 1.0)

        Graphics.EndMode3D()

        Graphics.DrawTexture(tex2d, 10, 10, COLOR_WHITE)
        Graphics.DrawRectangleLines(10, 10, tex2d.width, tex2d.height, COLOR_GREEN)

        Graphics.DrawFPS(10, 10)

    Graphics.EndDrawing()

end



