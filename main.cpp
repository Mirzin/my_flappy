#include "raylib.h"
#include "background.h"
#include "pipe.h"
#include "bird.h"

int main()
{
    float mapScale{2.4f};
    int windowWidth{1366};
    int windowHeight{768};
    bool gameOver{false};
    InitWindow(windowWidth, windowHeight, "Flappy");

    Background background;
    Bird bird;
    const int noOfPipes{3};
    Pipe pipes[noOfPipes];
    for (int i = 0; i < noOfPipes; i++)
        pipes[i].setXpos(windowWidth + (500 * i));
    SetTargetFPS(200);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        const float dT{GetFrameTime()};

        background.tick(dT, mapScale);
        if (!gameOver)
        {

            bird.tick(windowHeight, dT);

            for (int i = 0; i < noOfPipes; i++)
            {
                pipes[i].drawPipe(windowWidth, windowHeight, dT);
                if (CheckCollisionRecs(pipes[i].getBottomPipeCollisionRec(), bird.getCollisionRec()) || CheckCollisionRecs(pipes[i].getTopPipeCollisionRec(), bird.getCollisionRec()))
                {
                    gameOver = true;
                    break;
                }
            }
            if (bird.getCollisionRec().y > windowHeight || bird.getCollisionRec().y < 0)
                gameOver = true;
        }
        else
        {
            DrawText("GAME OVER!", windowWidth / 2 - 150, windowHeight / 2 - 10, 50, RED);
            if (IsKeyPressed(KEY_ENTER))
            {
                gameOver = false;
                bird.reset();
                for (int i = 0; i < noOfPipes; i++)
                    pipes[i].setXpos(windowWidth + (500 * i));
            }
        }

        EndDrawing();
    }
    CloseWindow();
}