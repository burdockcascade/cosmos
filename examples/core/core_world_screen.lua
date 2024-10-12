local screenWidth = 800
local screenHeight = 450

Window.Init(screenWidth, screenHeight, "raylib [core] example - core world screen")
Window.SetTargetFPS(60)

-- Define the camera to look into our 3d world
local camera = Camera3D()
camera.position = Vector3( 10.0, 10.0, 10.0 )
camera.target = Vector3( 0.0, 0.0, 0.0 )
camera.up = Vector3( 0.0, 1.0, 0.0 )
camera.fovy = 45.0
camera.projection = CAMERA_PERSPECTIVE

local cubePosition = Vector3( 0.0, 0.0, 0.0 )
local cubeScreenPosition = Vector2( 0.0, 0.0 )

Window.DisableCursor()

Window.SetTargetFPS(60)

while not Window.ShouldClose() do

    Window.UpdateCamera(camera, CAMERA_THIRD_PERSON)
    cubeScreenPosition = Window.GetWorldToScreen(Vector3(cubePosition.x, cubePosition.y + 2.5, cubePosition.z), camera)

    Window.BeginDrawing()

        Window.ClearBackground(COLOR_RAYWHITE)

        Window.BeginMode3D(camera)
            Draw.Cube(cubePosition, 2.0, 2.0, 2.0, COLOR_RED)
            Draw.CubeWires(cubePosition, 2.0, 2.0, 2.0, COLOR_MAROON)
            Draw.Grid(10, 1.0)
        Window.EndMode3D()

        Draw.Text("Enemy: 100 / 100", cubeScreenPosition.x - Text.Measure("Enemy: 100/100", 20)/2, cubeScreenPosition.y, 20, COLOR_BLACK)

        Draw.Text(Text.Format("Cube position in screen space coordinates: [%i, %i]", cubeScreenPosition.x, cubeScreenPosition.y), 10, 10, 20, COLOR_LIME)
        Draw.Text("Text 2d should be always on top of the cube", 10, 40, 20, COLOR_GRAY)

    Window.EndDrawing()

end

Window.Close()
