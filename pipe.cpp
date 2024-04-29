#include "pipe.h"

void Pipe::drawPipe(int windowWidth, int windowHeight, float dT)
{
    topPipeDest = {
        xPos,
        0,
        (texture.width / 4 * scale),
        (texture.height / 2 * scale) - (2 * pipeEndHeight) - pipeHeight};

    topPipeEndDest = {
        xPos,
        topPipeDest.height,
        texture.width / 4 * scale,
        (pipeEndHeight * scale)};

    bottomPipeDest = {
        xPos,
        (windowHeight - texture.height / 2 * scale) + (5.f * pipeEndHeight) - pipeHeight,
        texture.width / 4 * scale,
        (texture.height / 2 * scale) - (5.f * pipeEndHeight) + pipeHeight};

    bottomPipeEndDest = {
        xPos,
        bottomPipeDest.y - (pipeEndHeight * scale),
        texture.width / 4 * scale,
        pipeEndHeight * scale};

    DrawTexturePro(texture, pipeSource, topPipeDest, Vector2{}, 0.f, WHITE);
    DrawTexturePro(texture, pipeEndSource, topPipeEndDest, Vector2{}, 0.f, WHITE);
    DrawRectangleLines(topPipeDest.x, topPipeDest.y, topPipeDest.width, topPipeDest.height + topPipeEndDest.height, RED);

    DrawTexturePro(texture, pipeSource, bottomPipeDest, Vector2{}, 0.f, WHITE);
    DrawTexturePro(texture, pipeEndSource, bottomPipeEndDest, Vector2{}, 0.f, WHITE);
    DrawRectangleLines(bottomPipeDest.x, bottomPipeDest.y - bottomPipeEndDest.height, bottomPipeDest.width, bottomPipeDest.height + bottomPipeEndDest.height, RED);

    xPos -= speed * dT;
    if (xPos < 0.f - topPipeDest.width)
    {
        setXpos(windowWidth);
        pipeHeight = GetRandomValue(-200, 250);
    }
}

void Pipe::setXpos(int windowWidth)
{
    xPos = static_cast<float>(windowWidth);
}

Rectangle Pipe::getTopPipeCollisionRec()
{
    return Rectangle{
        topPipeDest.x,
        topPipeDest.y,
        topPipeDest.width,
        topPipeDest.height + topPipeEndDest.height};
}
Rectangle Pipe::getBottomPipeCollisionRec()
{
    return Rectangle{
        bottomPipeDest.x,
        bottomPipeDest.y - bottomPipeEndDest.height,
        bottomPipeDest.width,
        bottomPipeDest.height + bottomPipeEndDest.height};
}