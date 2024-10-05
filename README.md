# Cosmos

## Example
```lua
Window.Init(800, 450, "Basic Window")
Window.SetTargetFPS(60)

while not Window.ShouldClose() do
    Window.ClearBackground(COLOR_RAYWHITE)
    Window.BeginDrawing()
        Graphics2D.DrawText("Congrats! You created your first window!", 190, 200, 20, COLOR_DARKGRAY)
    Window.EndDrawing()
end

Window.Close()
```