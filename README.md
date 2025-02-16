# Cosmos

## Feature Table
| Status | Feature | Description |
| --- | --- | --- |
| :heavy_check_mark: | Window | Create a window |
| :heavy_check_mark: | Graphics2D | Draw 2D graphics |
| :heavy_check_mark: | Input | Handle input events |

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