MAX_BUNNIES = 1000 -- lua struggles with more than 2000 bunnies, but it's still a good test for performance
MAX_BATCH_ELEMENTS = 8192

function main(void)

    local screenWidth = 800
    local screenHeight = 450

    Window.Init(screenWidth, screenHeight, "bunnymark")

    local texBunny = Texture2D("C:/Workspace/cosmos/examples/textures/resources/wabbit_alpha.png")

    local bunnies = {}

    Window.SetTargetFPS(60)

    while not Window.ShouldClose() do

        if Input.IsMouseButtonDown(MOUSE_BUTTON_LEFT) then

            for i = 1, MAX_BUNNIES, 1 do
                table.insert(bunnies, {
                    position = Input.GetMousePosition(),
                    speed = {
                        x = Math.GetRandomValue(-250, 250)/60.0,
                        y = Math.GetRandomValue(-250, 250)/60.0
                    },
                    color = Color(Math.GetRandomValue(50, 240), Math.GetRandomValue(80, 240), Math.GetRandomValue(100, 240), 255 )
                })
            end

        end

        for i = 1, #bunnies do

            bunnies[i].position.x = bunnies[i].position.x + bunnies[i].speed.x
            bunnies[i].position.y = bunnies[i].position.y + bunnies[i].speed.y

            if ((bunnies[i].position.x + texBunny.width/2) > Window.GetScreenWidth()) or ((bunnies[i].position.x + texBunny.width/2) < 0) then
                bunnies[i].speed.x = bunnies[i].speed.x * -1
            end

            if ((bunnies[i].position.y + texBunny.height/2) > Window.GetScreenHeight()) or ((bunnies[i].position.y + texBunny.height/2 - 40) < 0) then
                bunnies[i].speed.y = bunnies[i].speed.y * -1
            end
        end

        Window.ClearBackground(COLOR_RAYWHITE)

        Graphics.BeginDrawing()

            for i = 1, #bunnies do
                Graphics.DrawTexture(texBunny, bunnies[i].position.x, bunnies[i].position.y, bunnies[i].color)
            end

            Graphics.DrawRectangle(0, 0, screenWidth, 40, COLOR_BLACK)
            Graphics.DrawText(Text.Format("bunnies: %i", #bunnies), 120, 10, 20, COLOR_GREEN) -- fixme: numbers are not working
            Graphics.DrawText(Text.Format("batched draw calls: %i", 1 + #bunnies/MAX_BATCH_ELEMENTS), 320, 10, 20, COLOR_MAROON)

            Graphics.DrawFPS(10, 10)

        Graphics.EndDrawing()

    end

    Window.Close()

end

main()
