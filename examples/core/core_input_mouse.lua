
    local screenWidth = 800
    local screenHeight = 450

    Window.Init(screenWidth, screenHeight, "raylib [core] example - mouse input")

    Window.HideCursor()

    local ballPosition = Vector2(-100.0, -100.0)
    ballColor = COLOR_DARKBLUE

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        ballPosition = Input.GetMousePosition()

        if (Input.IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) then ballColor = COLOR_MAROON
        elseif (Input.IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) then ballColor = COLOR_LIME
        elseif (Input.IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) then ballColor = COLOR_DARKBLUE
        elseif (Input.IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) then ballColor = COLOR_PURPLE
        elseif (Input.IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) then ballColor = COLOR_YELLOW
        elseif (Input.IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) then ballColor = COLOR_ORANGE
        elseif (Input.IsMouseButtonPressed(MOUSE_BUTTON_BACK)) then ballColor = COLOR_BEIGE end

        Window.BeginDrawing()

            Window.ClearBackground(COLOR_RAYWHITE)

            Graphics2D.DrawCircleV(ballPosition, 40, ballColor)

            Graphics2D.DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, COLOR_DARKGRAY)

        Window.EndDrawing()

    end

    Window.Close()


