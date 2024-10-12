Window.Init(800, 600, "Geometric Shapes")

-- Camera
local camera = Camera3D()
camera.position = Vector3(0.0, 10.0, 10.0)
camera.target = Vector3(0.0, 0.0, 0.0)
camera.up = Vector3(0.0, 1.0, 0.0)
camera.fovy = 45.0
camera.projection = CAMERA_PERSPECTIVE

Window.SetTargetFPS(60)

while not Window.ShouldClose() do

    Window.ClearBackground(COLOR_RAYWHITE)

    Graphics.BeginDrawing()

        Graphics.BeginMode3D(camera)

            Graphics.DrawCube(Vector3(-4.0, 0.0, 2.0), 2.0, 2.0, 2.0, COLOR_GOLD)
            Graphics.DrawCubeWires(Vector3(-4.0, 0.0, 2.0), 2.0, 2.0, 2.0, COLOR_MAROON)

            Graphics.DrawSphere(Vector3(-1.0, 0.0, 2.0), 1.0, COLOR_RED)
            Graphics.DrawSphereWires(Vector3(-1.0, 0.0, 2.0), 1.0, 16, 16, COLOR_MAROON)

            Graphics.DrawCylinder(Vector3(4.0, 0.0, -2.0), 1.0, 2.0, 3.0, 4, COLOR_GREEN)
            Graphics.DrawCylinderWires(Vector3(4.0, 0.0, -2.0), 1.0, 2.0, 3.0, 4, COLOR_LIME)

            Graphics.DrawGrid(10, 1.0)

        Graphics.EndMode3D()

    Graphics.EndDrawing()
end

Window.Close()
