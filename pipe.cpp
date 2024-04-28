#include "pipe.h"

void Pipe::drawPipe(int windowWidth, int windowHeight, float dT)
{
    float pipeEndHeight{16.f};

    Rectangle pipeSource{
        0.f,
        pipeEndHeight,
        static_cast<float>(texture.width) / 4.f,
        (static_cast<float>(texture.height) / 2.f) - 2 * pipeEndHeight};

    Rectangle pipeEndSource{
        0.f,
        0.f,
        static_cast<float>(texture.width) / 4.f,
        pipeEndHeight};

    Rectangle topPipeDest{
        xPos,
        0,
        (texture.width / 4 * scale),
        (texture.height / 2 * scale) - (2 * pipeEndHeight)};

    Rectangle topPipeEndDest{
        xPos,
        topPipeDest.height,
        texture.width / 4 * scale,
        (pipeEndHeight * scale)};

    Rectangle bottomPipeDest{
        xPos,
        (windowHeight - texture.height / 2 * scale) + (5.f * pipeEndHeight),
        texture.width / 4 * scale,
        (texture.height / 2 * scale) - (5.f * pipeEndHeight)};

    Rectangle bottomPipeEndDest{
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
        setXpos(windowWidth);
}

void Pipe::setXpos(int windowWidth)
{
    xPos = static_cast<float>(windowWidth);
}