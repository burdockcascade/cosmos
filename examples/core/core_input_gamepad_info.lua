function main()

    local screenWidth = 800
    local screenHeight = 450

    --Window.SetConfigFlags(FLAG_MSAA_4X_HINT);  // Set MSAA 4X hint before windows creation

    Window.Init(screenWidth, screenHeight, "raylib [core] example - gamepad information")

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        Window.BeginDrawing();

            Window.ClearBackground(COLOR_RAYWHITE);

            for (int i = 0, y = 5; i < 4; i++) do

                if Input.IsGamepadAvailable(i) then

                    Graphics2D.DrawText(Text.Format("Gamepad name: %s", Input.GetGamepadName(i)), 10, y, 10, COLOR_BLACK)
                    y += 11;
                    Graphics2D.DrawText(Text.Format("\tAxis count:   %d", Input.GetGamepadAxisCount(i)), 10, y, 10, COLOR_BLACK)
                    y += 11;

                    for (int axis = 0; axis < Input.GetGamepadAxisCount(i); axis++) do
                        Graphics2D.DrawText(Text.Format("\tAxis %d = %f", axis, Input.GetGamepadAxisMovement(i, axis)), 10, y, 10, BLACK)
                        y += 11
                    end

                    for (int button = 0; button < 32; button++) do
                        Graphics2D.DrawText(Text.Format("\tButton %d = %d", button, Input.IsGamepadButtonDown(i, button)), 10, y, 10, BLACK)
                        y += 11
                    end
                end

            end

            Graphics2D.DrawFPS(GetScreenWidth() - 100, 100)

        Window.EndDrawing()
    end

    CloseWindow();

end
