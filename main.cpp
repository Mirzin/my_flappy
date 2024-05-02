#include "raylib.h"
#include "background.h"
#include "pipe.h"
#include "bird.h"
int main()
{
    float mapScale{2.4f};
    int windowWidth{1366};
    int windowHeight{768};
    int score{0};
    int highScore{0};
    int nextPipe{0};
    bool gameOver{false};
    InitWindow(windowWidth, windowHeight, "Flappy");
    InitAudioDevice();

    Background background;
    Sound backgroundAudio{LoadSound("assets/wind.mp3")};
    Sound gameOverAudio{LoadSound("assets/game_over.mp3")};
    Sound scoreAudio{LoadSound("assets/score.mp3")};
    Bird bird;
    const int noOfPipes{3};
    Pipe pipes[noOfPipes];
    for (int i = 0; i < noOfPipes; i++)
        pipes[i].setXpos(windowWidth + (500 * i));

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (!IsSoundPlaying(backgroundAudio))
            PlaySound(backgroundAudio);

        const float dT{GetFrameTime()};

        background.tick(dT, mapScale);

        bird.tick(windowHeight, dT, gameOver);

        for (int i = 0; i < noOfPipes; i++)
        {
            pipes[i].drawPipe(windowWidth, windowHeight, dT, gameOver);
            if (!gameOver && (CheckCollisionRecs(pipes[i].getBottomPipeCollisionRec(), bird.getCollisionRec()) || CheckCollisionRecs(pipes[i].getTopPipeCollisionRec(), bird.getCollisionRec())))
            {
                gameOver = true;
                PlaySound(gameOverAudio);
                break;
            }
        }
        if (pipes[nextPipe].getScoreBarrier() <= bird.getXpos())
        {
            PlaySound(scoreAudio);
            score++;
            nextPipe == 2 ? nextPipe = 0 : nextPipe++;
        }
        if (!gameOver)
        {
            if (bird.getCollisionRec().y > windowHeight || bird.getCollisionRec().y < 0)
            {
                PlaySound(gameOverAudio);
                gameOver = true;
            }
        }
        else
        {
            if (score > highScore)
                highScore = score;
            DrawRectangle(windowWidth / 2 - 275, windowHeight / 2 - 55, 550, 100, BLACK);
            DrawRectangle(windowWidth / 2 - 270, windowHeight / 2 - 50, 540, 90, WHITE);
            DrawText("GAME OVER!", windowWidth / 2 - 250, windowHeight / 2 - 40, 80, RED);
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
            {
                gameOver = false;
                bird.reset();
                score = 0;
                nextPipe = 0;
                for (int i = 0; i < noOfPipes; i++)
                    pipes[i].setXpos(windowWidth + (500 * i));
            }
        }

        DrawText(TextFormat("Score: %i", score), 5, 5, 30, WHITE);
        DrawText(TextFormat("High Score: %i", highScore), 5, 40, 20, DARKGREEN);

        EndDrawing();
    }
    UnloadSound(backgroundAudio);
    UnloadSound(gameOverAudio);
    UnloadSound(scoreAudio);
    CloseWindow();
}