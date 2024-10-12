function main()

    local screenWidth = 800
    local screenHeight = 450

    Window.Init(screenWidth, screenHeight, "raylib [core] example - keyboard input")

    local ballPosition = Vector2(screenWidth/2, screenHeight/2)

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        if (Input.IsKeyDown(KEY_RIGHT)) then ballPosition.x = ballPosition.x + 2.0 end
        if (Input.IsKeyDown(KEY_LEFT)) then ballPosition.x = ballPosition.x - 2.0 end
        if (Input.IsKeyDown(KEY_UP)) then ballPosition.y = ballPosition.y - 2.0 end
        if (Input.IsKeyDown(KEY_DOWN)) then ballPosition.y = ballPosition.y + 2.0 end

        Graphics.BeginDrawing()

            Window.ClearBackground(COLOR_RAYWHITE)

            Graphics.DrawText("move the ball with arrow keys", 10, 10, 20, COLOR_DARKGRAY)

            Graphics.DrawCircleV(ballPosition, 50, COLOR_MAROON)

        Graphics.EndDrawing()

    end

    Window.Close()

end

main()
