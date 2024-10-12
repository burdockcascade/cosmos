function main(void)

    local screenWidth = 800;
    local screenHeight = 450;

    Window.Init(screenWidth, screenHeight, "3d picking");

    local camera = Camera3D();
    camera.position = Vector3( 10.0, 10.0, 10.0 )
    camera.target = Vector3( 0.0, 0.0, 0.0 )
    camera.up = Vector3( 0.0, 1.0, 0.0 );
    camera.fovy = 45.0;
    camera.projection = CAMERA_PERSPECTIVE;

    local cubePosition = Vector3( 0.0, 0.0, 0.0 );
    local cubeSize = Vector3( 2.0, 2.0, 2.0 );

    local ray = Ray()
    local collision = RayCollision()

    Window.SetTargetFPS(60);

    while not Window.ShouldClose() do

        if (Window.IsCursorHidden()) then
            Window.UpdateCamera(camera, CAMERA_FIRST_PERSON);
        end


        if Input.IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) then
            if (Window.IsCursorHidden()) then
                Window.EnableCursor();
            else
                Window.DisableCursor();
            end
        end

        if (Input.IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) then

            if not collision.hit then

                ray = Input.GetMouseRay(Input.GetMousePosition(), camera);

                -- Check collision between ray and box
                local boundingBox = BoundingBox(Vector3(cubePosition.x - cubeSize.x/2, cubePosition.y - cubeSize.y/2, cubePosition.z - cubeSize.z/2),
                                                Vector3(cubePosition.x + cubeSize.x/2, cubePosition.y + cubeSize.y/2, cubePosition.z + cubeSize.z/2));
                collision = Collision.GetRayCollisionBox(ray, boundingBox);
            else
                collision.hit = false;
            end
        end

        Window.BeginDrawing();

            Window.ClearBackground(COLOR_RAYWHITE);

            Window.BeginMode3D(camera);

                if (collision.hit) then
                    Draw.Cube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_RED);
                    Draw.CubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_MAROON);
                    Draw.CubeWires(cubePosition, cubeSize.x + 0.2, cubeSize.y + 0.2, cubeSize.z + 0.2, COLOR_GREEN);
                else
                    Draw.Cube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_GRAY);
                    Draw.CubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_DARKGRAY);
                end

                Draw.Ray(ray, COLOR_MAROON);
                Draw.Grid(10, 1.0);

            Window.EndMode3D();

            Draw.Text("Try clicking on the box with your mouse!", 240, 10, 20, COLOR_DARKGRAY);

            if (collision.hit) then
                Draw.Text("BOX SELECTED", (screenWidth - Text.Measure("BOX SELECTED", 30)) / 2, (screenHeight * 0.1), 30, COLOR_GREEN);
            end

            Draw.Text("Right click mouse to toggle camera controls", 10, 430, 10, COLOR_GRAY);

            Draw.FPS(10, 10);

        Window.EndDrawing();

    end

    Window.Close()
end

main()
