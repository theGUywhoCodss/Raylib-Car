#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"

#include "player.h"
#include "road.h"

Texture2D _atlasPlayer;

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

static void UpdateDrawFrame(void);          // Update and draw one frame
int main()
{
    srand(time(0));
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Template");
    _atlasPlayer = LoadTexture("images/car.png");
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif
    UnloadTexture(_atlasPlayer);
    CloseWindow();                  // Close window and OpenGL context
    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void){
    UpdatePlayer();
    if (IsKeyDown(KEY_A)){
        MovePlayer(LEFT);
    }if (IsKeyDown(KEY_D)){
        MovePlayer(RIGHT);
    }
    BeginDrawing();
        ClearBackground(BLACK);
        DrawRoad();
        DrawPlayer();
        DrawFPS(0,0);
    EndDrawing();
}