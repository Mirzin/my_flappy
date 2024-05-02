#include "bird.h"

Bird::Bird()
{
    texture = LoadTexture("assets/Bird.png");
    sound = LoadSound("assets/jump.mp3");
    SetSoundVolume(sound, 0.2f);
    source = Rectangle{
        0.f,
        static_cast<float>(texture.height) / 7,
        static_cast<float>(texture.width) / 4,
        static_cast<float>(texture.height) / 7,
    };
}

void Bird::tick(int windowHeight, float dT, bool gameOver)
{
    if (!gameOver)
    {
        destYpos += velocity * dT;
        velocity += gravity * dT;
        if (IsKeyPressed(KEY_SPACE))
        {
            PlaySound(sound);
            velocity = jumpVelocity * dT;
        }
    }
    drawBird(windowHeight, dT, gameOver);
}

void Bird::drawBird(int windowHeight, float dT, bool gameOver)
{
    if (!gameOver)
    {
        runningTime += dT;
        dest = {
            200.f,
            destYpos,
            source.width * scale,
            source.height * scale,
        };
        if (runningTime >= updateTime)
        {
            runningTime = 0;
            currentFrame++;
            if (currentFrame >= maxFrames)
                currentFrame = 0;
        }
        source.x = (static_cast<float>(texture.width) / 4) * currentFrame;
    }

    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
    // DrawRectangleLines(dest.x + 15, dest.y + 10, dest.width - 30, dest.height - 20, RED);
}

Rectangle Bird::getCollisionRec()
{
    return Rectangle{
        dest.x + 15, dest.y + 10, dest.width - 30, dest.height - 20};
}

void Bird::reset()
{
    destYpos = 5.f;
    velocity = 0;
}

int Bird::getXpos()
{
    return static_cast<int>(dest.x);
}