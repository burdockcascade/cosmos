function main(void)

    local screenWidth = 800;
    local screenHeight = 450;

    Window.Init(screenWidth, screenHeight, "3d camera free");

    -- Define the camera to look into our 3d world
    local camera = Camera3D();
    camera.position = Vector3( 10.0, 10.0, 10.0 )
    camera.target = Vector3( 0.0, 0.0, 0.0 )  
    camera.up = Vector3( 0.0, 1.0, 0.0 );          
    camera.fovy = 45.0;                                
    camera.projection = CAMERA_PERSPECTIVE;             

    local cubePosition = Vector3( 0.0, 0.0, 0.0 );

    Window.DisableCursor();      

    Window.SetTargetFPS(60);    


    -- Main game loop
    while not Window.ShouldClose() do
    
        Window.UpdateCamera(camera, CAMERA_FREE);

        if Input.IsKeyPressed('Z') then
            camera.target = Vector3( 0.0, 0.0, 0.0 )
        end

        Window.BeginDrawing();

            Window.ClearBackground(COLOR_RAYWHITE);

            Window.BeginMode3D(camera);

                Graphics3D.DrawCube(cubePosition, 2.0, 2.0, 2.0, COLOR_RED);
                Graphics3D.DrawCubeWires(cubePosition, 2.0, 2.0, 2.0, COLOR_MAROON);

                Graphics3D.DrawGrid(10, 1.0);

            Window.EndMode3D();

            Graphics2D.DrawRectangle( 10, 10, 320, 93, Color.Fade(COLOR_SKYBLUE, 0.5));
            Graphics2D.DrawRectangleLines( 10, 10, 320, 93, COLOR_BLUE);

            Graphics2D.DrawText("Free camera default controls:", 20, 20, 10, COLOR_BLACK);
            Graphics2D.DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, COLOR_DARKGRAY);
            Graphics2D.DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, COLOR_DARKGRAY);
            Graphics2D.DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, COLOR_DARKGRAY);

        Window.EndDrawing();
    end

    Winxow.Close()

end

main()