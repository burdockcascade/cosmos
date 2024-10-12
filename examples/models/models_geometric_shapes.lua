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

    Window.BeginDrawing()
        Window.ClearBackground(COLOR_RAYWHITE)
        Window.BeginMode3D(camera)


            Draw.Cube(Vector3(-4.0, 0.0, 2.0), 2.0, 2.0, 2.0, COLOR_GOLD)
            Draw.CubeWires(Vector3(-4.0, 0.0, 2.0), 2.0, 2.0, 2.0, COLOR_MAROON)

            Draw.Sphere(Vector3(-1.0, 0.0, 2.0), 1.0, COLOR_RED)
            Draw.SphereWires(Vector3(-1.0, 0.0, 2.0), 1.0, 16, 16, COLOR_MAROON)

            Draw.Cylinder(Vector3(4.0, 0.0, -2.0), 1.0, 2.0, 3.0, 4, COLOR_GREEN)
            Draw.CylinderWires(Vector3(4.0, 0.0, -2.0), 1.0, 2.0, 3.0, 4, COLOR_LIME)

            Draw.Grid(10, 1.0)

        Window.EndMode3D()

    Window.EndDrawing()
end

Window.Close()
