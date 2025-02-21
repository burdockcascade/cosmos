MAX_COLUMNS = 20

function main(void)

    local screenWidth = 800
    local screenHeight = 450

    Window.Init(screenWidth, screenHeight, "3d camera first person")

    local camera = Camera3D()
    camera.position = Vector3( 0.0, 2.0, 4.0 )
    camera.target = Vector3( 0.0, 2.0, 0.0 )
    camera.up = Vector3( 0.0, 1.0, 0.0 )
    camera.fovy = 60.0
    camera.projection = CAMERA_PERSPECTIVE

    local cameraMode = CAMERA_FIRST_PERSON

    local heights = {}
    local positions = {}
    local colors = {}

    for i = 0, MAX_COLUMNS - 1 do
        heights[i] = Math.GetRandomValue(1, 12)
        positions[i] = Vector3(Math.GetRandomValue(-15, 15), heights[i]/2.0, Math.GetRandomValue(-15, 15) )
        colors[i] = Color( Math.GetRandomValue(20, 255), Math.GetRandomValue(10, 55), 30, 255 )
    end

    Window.DisableCursor()

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        if Input.IsKeyPressed(KEY_ONE) then
            cameraMode = CAMERA_FREE
            camera.up = Vector3( 0.0, 1.0, 0.0 )
        end

        if Input.IsKeyPressed(KEY_TWO) then
            cameraMode = CAMERA_FIRST_PERSON
            camera.up = Vector3( 0.0, 1.0, 0.0 )
        end

        if Input.IsKeyPressed(KEY_THREE) then
            cameraMode = CAMERA_THIRD_PERSON
            camera.up = Vector3( 0.0, 1.0, 0.0 )
        end

        if Input.IsKeyPressed(KEY_FOUR) then
            cameraMode = CAMERA_ORBITAL
            camera.up = Vector3( 0.0, 1.0, 0.0 )
        end

        if (Input.IsKeyPressed(KEY_P)) then

            if (camera.projection == CAMERA_PERSPECTIVE) then

                -- Create isometric view
                cameraMode = CAMERA_THIRD_PERSON
                -- Note: The target distance is related to the render distance in the orthographic projection
                camera.position = Vector3( 0.0, 2.0, -100.0 )
                camera.target = Vector3( 0.0, 2.0, 0.0 )
                camera.up = Vector3( 0.0, 1.0, 0.0 )
                camera.projection = CAMERA_ORTHOGRAPHIC
                camera.fovy = 20.0 -- near plane width in CAMERA_ORTHOGRAPHIC
                --CameraYaw(camera, -135 * DEG2RAD, true)
                --CameraPitch(camera, -45 * DEG2RAD, true, true, false)

            elseif (camera.projection == CAMERA_ORTHOGRAPHIC) then

                -- Reset to default view
                cameraMode = CAMERA_THIRD_PERSON
                camera.position = Vector3( 0.0, 2.0, 10.0 )
                camera.target = Vector3( 0.0, 2.0, 0.0 )
                camera.up = Vector3( 0.0, 1.0, 0.0 )
                camera.projection = CAMERA_PERSPECTIVE
                camera.fovy = 60.0
            end
        end

        -- Update camera computes movement internally depending on the camera mode
        -- Some default standard keyboard/mouse inputs are hardcoded to simplify use
        -- For advance camera controls, it's reecommended to compute camera movement manually
        Window.UpdateCamera(camera, cameraMode)

        Graphics.BeginDrawing()

            Window.ClearBackground(COLOR_RAYWHITE)

            Graphics.BeginMode3D(camera)

                Graphics.DrawPlane(Vector3( 0.0, 0.0, 0.0 ), Vector2( 32.0, 32.0 ), COLOR_LIGHTGRAY)
                Graphics.DrawCube(Vector3( -16.0, 2.5, 0.0 ), 1.0, 5.0, 32.0, COLOR_BLUE)
                Graphics.DrawCube(Vector3( 16.0, 2.5, 0.0 ), 1.0, 5.0, 32.0, COLOR_LIME)
                Graphics.DrawCube(Vector3( 0.0, 2.5, 16.0 ), 32.0, 5.0, 1.0, COLOR_GOLD)

                -- Draw cubes for MAX_COLUMNS
                for i = 0, MAX_COLUMNS - 1 do
                    Graphics.DrawCube(positions[i], 2.0, heights[i], 2.0, colors[i])
                    Graphics.DrawCubeWires(positions[i], 2.0, heights[i], 2.0, COLOR_MAROON)
                end

                -- Draw player cube
                if (cameraMode == CAMERA_THIRD_PERSON) then
                    Graphics.DrawCube(camera.target, 0.5, 0.5, 0.5, COLOR_PURPLE)
                    Graphics.DrawCubeWires(camera.target, 0.5, 0.5, 0.5, COLOR_DARKPURPLE)
                end

            Graphics.EndMode3D()

            -- Draw info boxes
            Graphics.DrawRectangle(5, 5, 330, 100, COLOR_SKYBLUE, 0.5) -- fade
            Graphics.DrawRectangleLines(5, 5, 330, 100, COLOR_BLUE)

            Graphics.DrawText("Camera controls:", 15, 15, 10, COLOR_BLACK)
            Graphics.DrawText("- Move keys: W, A, S, D, Space, Left-Ctrl", 15, 30, 10, COLOR_BLACK)
            Graphics.DrawText("- Look around: arrow keys or mouse", 15, 45, 10, COLOR_BLACK)
            Graphics.DrawText("- Camera mode keys: 1, 2, 3, 4", 15, 60, 10, COLOR_BLACK)
            Graphics.DrawText("- Zoom keys: num-plus, num-minus or mouse scroll", 15, 75, 10, COLOR_BLACK)
            Graphics.DrawText("- Camera projection key: P", 15, 90, 10, COLOR_BLACK)

            Graphics.DrawRectangle(600, 5, 195, 100, COLOR_SKYBLUE, 0.5) -- fade
            Graphics.DrawRectangleLines(600, 5, 195, 100, COLOR_BLUE)

            Graphics.DrawText("Camera status:", 610, 15, 10, COLOR_BLACK)

            if (cameraMode == CAMERA_FREE) then
                Graphics.DrawText("- FREE camera mode", 610, 30, 10, COLOR_BLACK)
            elseif (cameraMode == CAMERA_FIRST_PERSON) then
                Graphics.DrawText("- FIRST_PERSON camera mode", 610, 30, 10, COLOR_BLACK)
            elseif (cameraMode == CAMERA_THIRD_PERSON) then
                Graphics.DrawText("- THIRD_PERSON camera mode", 610, 30, 10, COLOR_BLACK)
            elseif (cameraMode == CAMERA_ORBITAL) then
                Graphics.DrawText("- ORBITAL camera mode", 610, 30, 10, COLOR_BLACK)
            else
                Graphics.DrawText("- CUSTOM camera mode", 610, 30, 10, COLOR_BLACK)
            end

            if (camera.projection == CAMERA_PERSPECTIVE) then
                Graphics.DrawText("- Perspective PROJECTION", 610, 45, 10, COLOR_BLACK)
            elseif (camera.projection == CAMERA_ORTHOGRAPHIC) then
                Graphics.DrawText("- Orthographic PROJECTION", 610, 45, 10, COLOR_BLACK)
            else
                Graphics.DrawText("- Custom PROJECTION", 610, 45, 10, COLOR_BLACK)
            end

            Graphics.DrawText(Text.Format("- Position: (%06.3, %06.3, %06.3f)", camera.position.x, camera.position.y, camera.position.z), 610, 60, 10, COLOR_BLACK)
            Graphics.DrawText(Text.Format("- Target: (%06.3, %06.3, %06.3f)", camera.target.x, camera.target.y, camera.target.z), 610, 75, 10, COLOR_BLACK)
            Graphics.DrawText(Text.Format("- Up: (%06.3, %06.3, %06.3f)", camera.up.x, camera.up.y, camera.up.z), 610, 90, 10, COLOR_BLACK)

        Graphics.EndDrawing()

    end

    Window.Close()
end

main()
