local screenWidth = 800
local screenHeight = 450

Window.Init(screenWidth, screenHeight, "raylib [core] example - scissor test")

local scissorArea = Rectangle(0, 0, 300, 300)
local scissorMode = true

Window.SetTargetFPS(60)

while not Window.ShouldClose() do

    if (Input.IsKeyPressed(KEY_S)) then
         scissorMode = not scissorMode
    end

    scissorArea.x = Input.GetMouseX() - scissorArea.width/2
    scissorArea.y = Input.GetMouseY() - scissorArea.height/2

    Graphics.BeginDrawing()

        Window.ClearBackground(COLOR_RAYWHITE)

        if (scissorMode) then
            Graphics.BeginScissorMode(scissorArea.x, scissorArea.y, scissorArea.width, scissorArea.height)
        end

        Graphics.DrawRectangle(0, 0, Window.GetScreenWidth(), Window.GetScreenHeight(), COLOR_RED)
        Graphics.DrawText("Move the mouse around to reveal this text!", 190, 200, 20, COLOR_LIGHTGRAY)

        if (scissorMode) then
            Graphics.EndScissorMode()
        end

        Graphics.DrawRectangleLinesEx(scissorArea, 1, COLOR_BLACK)
        Graphics.DrawText("Press S to toggle scissor test", 10, 10, 20, COLOR_BLACK)

    Graphics.EndDrawing()

end

Window.Close()

