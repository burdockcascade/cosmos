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

        Graphics.BeginDrawing();

            Window.ClearBackground(COLOR_RAYWHITE);

            Graphics.BeginMode3D(camera);

                if (collision.hit) then
                    Graphics.DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_RED);
                    Graphics.DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_MAROON);
                    Graphics.DrawCubeWires(cubePosition, cubeSize.x + 0.2, cubeSize.y + 0.2, cubeSize.z + 0.2, COLOR_GREEN);
                else
                    Graphics.DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_GRAY);
                    Graphics.DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, COLOR_DARKGRAY);
                end

                Graphics.DrawRay(ray, COLOR_MAROON);
                Graphics.DrawGrid(10, 1.0);

            Window.EndMode3D();

            Graphics.DrawText("Try clicking on the box with your mouse!", 240, 10, 20, COLOR_DARKGRAY);

            if (collision.hit) then
                Graphics.DrawText("BOX SELECTED", (screenWidth - Text.Measure("BOX SELECTED", 30)) / 2, (screenHeight * 0.1), 30, COLOR_GREEN);
            end

            Graphics.DrawText("Right click mouse to toggle camera controls", 10, 430, 10, COLOR_GRAY);

            Graphics.DrawFPS(10, 10);

        Graphics.EndDrawing();

    end

    Window.Close()
end

main()
