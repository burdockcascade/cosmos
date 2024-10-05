function main()

    local screen_width = 800
    local screen_height = 450

    Window.Init(screen_width, screen_height, "Basic Window")
    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do
        Window.ClearBackground(COLOR_RAYWHITE)
        Window.BeginDrawing()
            Graphics2D.DrawText("Congrats! You created your first window!", 190, 200, 20, COLOR_DARKGRAY)
        Window.EndDrawing()
    end

    Window.Close()

end

main()