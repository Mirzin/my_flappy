#include "bird.h"

void Bird::tick(int windowHeight, float dT)
{
    destYpos += velocity * dT;
    velocity += gravity * dT;
    drawBird(windowHeight, dT);
    if (IsKeyPressed(KEY_SPACE))
    {
        velocity = jumpVelocity * dT;
    }
}

void Bird::drawBird(int windowHeight, float dT)
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

    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
    // DrawRectangleLines(dest.x + 10, dest.y + 10, dest.width - 20, dest.height - 20, RED);
}

Rectangle Bird::getCollisionRec()
{
    return Rectangle{
        dest.x + 10, dest.y + 10, dest.width - 20, dest.height - 20};
}

void Bird::reset()
{
    destYpos = 5.f;
    velocity = 0;
}