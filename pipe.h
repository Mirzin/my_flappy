#include "raylib.h"

class Pipe
{
public:
    void drawPipe(int windowWidth, int windowHeight, float dT);
    void setXpos(int windowWidth);
    Rectangle getTopPipeCollisionRec();
    Rectangle getBottomPipeCollisionRec();

private:
    Texture2D texture{LoadTexture("assets/Pipes.png")};
    float pipeEndHeight{16.f};
    Rectangle pipeSource{
        0.f,
        pipeEndHeight,
        static_cast<float>(texture.width) / 4.f,
        (static_cast<float>(texture.height) / 2.f) - 2 * pipeEndHeight};
    Rectangle topPipeEndSource{
        0.f,
        0.f,
        static_cast<float>(texture.width) / 4.f,
        -1.f * pipeEndHeight};
    Rectangle bottomPipeEndSource{
        0.f,
        0.f,
        static_cast<float>(texture.width) / 4.f,
        pipeEndHeight};
    Rectangle topPipeDest{};
    Rectangle topPipeEndDest{};
    Rectangle bottomPipeDest{};
    Rectangle bottomPipeEndDest{};
    float scale{4.f};
    float speed{250};
    float xPos;
    int pipeHeight{0};
};