local screenWidth = 800
local screenHeight = 450

Window.Init(screenWidth, screenHeight, "window should close")

Window.SetExitKey(KEY_NULL)

local exitWindowRequested = false
local exitWindow = false
Window.SetTargetFPS(60)

while not exitWindow do

    if Window.ShouldClose() or Input.IsKeyPressed(KEY_ESCAPE) then
            exitWindowRequested = true
    end

    if (exitWindowRequested) then
        if Input.IsKeyPressed(KEY_Y) then
            exitWindow = true
        elseif (Input.IsKeyPressed(KEY_N)) then
            exitWindowRequested = false
        end
    end

    Window.BeginDrawing()

        Window.ClearBackground(COLOR_RAYWHITE)

        if (exitWindowRequested) then
            Draw.Rectangle(0, 100, screenWidth, 200, COLOR_BLACK)
            Draw.Text("Are you sure you want to exit program? [Y/N]", 40, 180, 30, COLOR_WHITE)
        else
            Draw.Text("Try to close the window to get confirmation message!", 120, 200, 20, COLOR_LIGHTGRAY)
        end

    Window.EndDrawing()

end

Window.Close()

