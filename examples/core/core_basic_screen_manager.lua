LOGO = 0
TITLE = 1
GAMEPLAY = 2
ENDING = 3

function main()

    local screenWidth = 800
    local screenHeight = 450

    Window.Init(screenWidth, screenHeight, "raylib [core] example - basic screen manager")

    local currentScreen = LOGO

    local framesCounter = 0

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        if currentScreen == LOGO then
            framesCounter = framesCounter + 1
            if framesCounter > 120 then
                currentScreen = TITLE
            end
        elseif currentScreen == TITLE then
            if Input.IsKeyPressed(KEY_ENTER) or Input.IsGestureDetected(GESTURE_TAP) then
                currentScreen = GAMEPLAY
            end
        elseif currentScreen == GAMEPLAY then
            if Input.IsKeyPressed(KEY_ENTER) or Input.IsGestureDetected(GESTURE_TAP) then
                currentScreen = ENDING
            end
        elseif currentScreen == ENDING then
            if Input.IsKeyPressed(KEY_ENTER) or Input.IsGestureDetected(GESTURE_TAP) then
                currentScreen = TITLE
            end
        end

        Graphics.BeginDrawing()

            Window.ClearBackground(COLOR_RAYWHITE)

            if currentScreen == LOGO then
                Graphics.DrawText("LOGO SCREEN", 20, 20, 40, COLOR_LIGHTGRAY)
                Graphics.DrawText("WAIT for 2 SECONDS...", 290, 220, 20, COLOR_GRAY)
            elseif currentScreen == TITLE then
                Graphics.DrawText("TITLE SCREEN", 20, 20, 40, COLOR_DARKGREEN)
                Graphics.DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, COLOR_DARKGREEN)
            elseif currentScreen == GAMEPLAY then
                Graphics.DrawText("GAMEPLAY SCREEN", 20, 20, 40, COLOR_MAROON)
                Graphics.DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, COLOR_MAROON)
            elseif currentScreen == ENDING then
                Graphics.DrawText("ENDING SCREEN", 20, 20, 40, COLOR_DARKBLUE)
                Graphics.DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, COLOR_DARKBLUE)
            end

        Graphics.EndDrawing()

    end

    Window.Close()

end

main()
