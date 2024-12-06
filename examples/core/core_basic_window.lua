function main()

    local screen_width = 800
    local screen_height = 450

    Window.Init(screen_width, screen_height, "Basic Window")
    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do
        Window.ClearBackground(COLOR_RAYWHITE)
        Graphics.BeginDrawing()
            Graphics.DrawText("Congrats! You created your first window!", 190, 200, 20, COLOR_DARKGRAY)
        Graphics.EndDrawing()
    end

    Window.Close()

end

main()
