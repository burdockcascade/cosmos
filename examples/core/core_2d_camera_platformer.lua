G = 400
PLAYER_JUMP_SPD = 350.0
PLAYER_HOR_SPD = 200.0

local Player = {}

local EnvItem = {}

------------------------------------------------------------------------------------
-- Module functions declaration
------------------------------------------------------------------------------------
function UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);
function UpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
function UpdateCameraCenterInsideMap(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
function UpdateCameraCenterSmoothFollow(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
function UpdateCameraEvenOutOnLanding(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
function UpdateCameraPlayerBoundsPush(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);

--------------------------------------------------------------------------------------
-- Program main entry point
--------------------------------------------------------------------------------------
function main()

    -- Initialization
    ----------------------------------------------------------------------------------------
    local screenWidth = 800;
    local screenHeight = 450;

    Window.Init(screenWidth, screenHeight, "raylib [core] example - 2d camera");

    local player = { };
    player.position = Vector2( 400, 280 );
    player.speed = 0;
    player.canJump = false;
    local envItems = {
        {{ 0, 0, 1000, 400 }, 0, COLOR_LIGHTGRAY },
        {{ 0, 400, 1000, 200 }, 1, COLOR_GRAY },
        {{ 300, 200, 400, 10 }, 1, COLOR_GRAY },
        {{ 250, 300, 100, 10 }, 1, COLOR_GRAY },
        {{ 650, 300, 100, 10 }, 1, COLOR_GRAY }
    };

    int envItemsLength = #envItems;

    local camera = Camera2D();
    camera.target = player.position;
    camera.offset = Vector2( screenWidth/2.0, screenHeight/2.0 );
    camera.rotation = 0.0;
    camera.zoom = 1.0;

    -- Store pointers to the multiple update camera functions
    void (*cameraUpdaters[])(Camera2D*, Player*, EnvItem*, int, float, int, int) = {
        UpdateCameraCenter,
        UpdateCameraCenterInsideMap,
        UpdateCameraCenterSmoothFollow,
        UpdateCameraEvenOutOnLanding,
        UpdateCameraPlayerBoundsPush
    };

    local cameraOption = 0;
    local cameraUpdatersLength = sizeof(cameraUpdaters)/sizeof(cameraUpdaters[0]);

    local cameraDescriptions = {
        "Follow player center",
        "Follow player center, but clamp to map edges",
        "Follow player center; smoothed",
        "Follow player center horizontally; update player center vertically after landing",
        "Player push camera on getting too close to screen edge"
    };

    Window.SetTargetFPS(60);
    ----------------------------------------------------------------------------------------

    -- Main game loop
    while (!WindowShouldClose())
    {
        -- Update
        ------------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);

        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.25f) camera.zoom = 0.25f;

        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            player.position = (Vector2){ 400, 280 };
        }

        if (IsKeyPressed(KEY_C)) cameraOption = (cameraOption + 1)%cameraUpdatersLength;

        -- Call update camera function by its pointer
        cameraUpdaters[cameraOption](&camera, &player, envItems, envItemsLength, deltaTime, screenWidth, screenHeight);
        ------------------------------------------------------------------------------------

        -- Draw
        ------------------------------------------------------------------------------------
        Window.BeginDrawing();

            Window.ClearBackground(LIGHTGRAY);

            Window.BeginMode2D(camera);

                for (int i = 0; i < envItemsLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);

                Rectangle playerRect = { player.position.x - 20, player.position.y - 40, 40.0f, 40.0f };
                DrawRectangleRec(playerRect, RED);

                DrawCircleV(player.position, 5.0f, GOLD);

                Window.EndMode2D();

            Graphics2D.DrawText("Controls:", 20, 20, 10, BLACK);
            Graphics2D.DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
            Graphics2D.DrawText("- Space to jump", 40, 60, 10, DARKGRAY);
            Graphics2D.DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY);
            Graphics2D.DrawText("- C to change camera mode", 40, 100, 10, DARKGRAY);
            Graphics2D.DrawText("Current camera mode:", 20, 120, 10, BLACK);
            Graphics2D.DrawText(cameraDescriptions[cameraOption], 40, 140, 10, DARKGRAY);

            Window.EndDrawing();
        ------------------------------------------------------------------------------------
    }

    -- De-Initialization
    ----------------------------------------------------------------------------------------
    Window.Close();        -- Close window and OpenGL context
    ----------------------------------------------------------------------------------------

    return 0;
end

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
    if (Input.IsKeyDown(KEY_LEFT)) player.position.x -= PLAYER_HOR_SPD*delta;
    if (Input.IsKeyDown(KEY_RIGHT)) player.position.x += PLAYER_HOR_SPD*delta;
    if (Input.IsKeyDown(KEY_SPACE) and player.canJump)
    {
        player.speed = -PLAYER_JUMP_SPD;
        player.canJump = false;
    }

    bool hitObstacle = false;
    for (int i = 0; i < envItemsLength; i++)
    {
        EnvItem *ei = envItems + i;
        Vector2 *p = &(player.position);
        if (ei.blocking and
            ei.rect.x <= p.x and
            ei.rect.x + ei.rect.width >= p.x and
            ei.rect.y >= p.y and
            ei.rect.y <= p.y + player.speed*delta)
        {
            hitObstacle = true;
            player.speed = 0.0f;
            p.y = ei.rect.y;
            break;
        }
    }

    if (!hitObstacle)
    {
        player.position.y += player.speed*delta;
        player.speed += G*delta;
        player.canJump = false;
    }
    else player.canJump = true;
}

function UpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
    camera.offset = (Vector2){ width/2.0f, height/2.0f };
    camera.target = player.position;
end

function UpdateCameraCenterInsideMap(camera, player, envItems, envItemsLength, delta, width, height)

    camera.target = player.position;
    camera.offset = Vector2( width/2.0, height/2.0 );
    local minX = 1000,
    local minY = 1000,
    local maxX = -1000,
    local maxY = -1000;

    for (int i = 0; i < envItemsLength; i++) do
        EnvItem *ei = envItems + i;
        minX = fminf(ei.rect.x, minX);
        maxX = fmaxf(ei.rect.x + ei.rect.width, maxX);
        minY = fminf(ei.rect.y, minY);
        maxY = fmaxf(ei.rect.y + ei.rect.height, maxY);
    end

    local max = GetWorldToScreen2D(Vector2( maxX, maxY ), camera);
    local min = GetWorldToScreen2D(Vector2( minX, minY ), camera);

    if (max.x < width) camera.offset.x = width - (max.x - width/2);
    if (max.y < height) camera.offset.y = height - (max.y - height/2);
    if (min.x > 0) camera.offset.x = width/2 - min.x;
    if (min.y > 0) camera.offset.y = height/2 - min.y;
end

-- TODO: Add Vector2 functions to raylib
function UpdateCameraCenterSmoothFollow(camera, player, envItems, envItemsLength, delta, width, height)

    static float minSpeed = 30;
    static float minEffectLength = 10;
    static float fractionSpeed = 0.8f;

    camera.offset = (Vector2){ width/2.0f, height/2.0f };
    local diff = Vector2Subtract(player.position, camera.target);
    local length = Vector2Length(diff);

    if (length > minEffectLength) then
        float speed = fmaxf(fractionSpeed*length, minSpeed);
        camera.target = Vector2Add(camera.target, Vector2Scale(diff, speed*delta/length));
    end
end

function UpdateCameraEvenOutOnLanding(camera, player, envItems, envItemsLength, delta, width, height)

    local evenOutSpeed = 700;
    local eveningOut = false;
    local evenOutTarget;

    camera.offset = Vector2(width/2.0, height/2.0);
    camera.target.x = player.position.x;

    if (eveningOut) then

        if (evenOutTarget > camera.target.y) then

            camera.target.y += evenOutSpeed*delta;

            if (camera.target.y > evenOutTarget) then
                camera.target.y = evenOutTarget;
                eveningOut = 0;
            end

        else

            camera.target.y -= evenOutSpeed*delta;

            if (camera.target.y < evenOutTarget) then
                camera.target.y = evenOutTarget;
                eveningOut = 0;
            end
        end

    else

        if (player.canJump and (player.speed == 0) and (player.position.y ~= camera.target.y)) then
            eveningOut = 1;
            evenOutTarget = player.position.y;
        end
    end

end

function UpdateCameraPlayerBoundsPush(camera, player, envItems, envItemsLength, delta, width, height)

    local bbox = Vector2( 0.2, 0.2 );

    local bboxWorldMin = GetScreenToWorld2D(Vector2( (1 - bbox.x)*0.5*width, (1 - bbox.y)*0.5*height ), camera);
    local bboxWorldMax = GetScreenToWorld2D(Vector2( (1 + bbox.x)*0.5*width, (1 + bbox.y)*0.5*height ), camera);
    camera.offset = Vector2((1 - bbox.x)*0.5f * width, (1 - bbox.y)*0.5f*height );

    if (player.position.x < bboxWorldMin.x) camera.target.x = player.position.x;
    if (player.position.y < bboxWorldMin.y) camera.target.y = player.position.y;
    if (player.position.x > bboxWorldMax.x) camera.target.x = bboxWorldMin.x + (player.position.x - bboxWorldMax.x);
    if (player.position.y > bboxWorldMax.y) camera.target.y = bboxWorldMin.y + (player.position.y - bboxWorldMax.y);

end
