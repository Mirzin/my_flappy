#include "raylib.h"
#include "background.h"
#include "pipe.h"

int main()
{
    float mapScale{2.4f};
    int windowWidth{1366};
    int windowHeight{768};
    InitWindow(windowWidth, windowHeight, "Flappy");

    Background background;
    const int noOfPipes{3};
    Pipe pipes[noOfPipes];
    for (int i = 0; i < noOfPipes; i++)
        pipes[i].setXpos(windowWidth + (500 * i));
    SetTargetFPS(200);
    while (!WindowShouldClose())
    {
        const float dT{GetFrameTime()};

        background.tick(dT, mapScale);

        for (int i = 0; i < noOfPipes; i++)
            pipes[i].drawPipe(windowWidth, windowHeight, dT);

        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }
    CloseWindow();
}