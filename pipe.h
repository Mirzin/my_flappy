#include "raylib.h"

class Pipe
{
public:
    void drawPipe(int windowWidth, int windowHeight, float dT);
    void setXpos(int windowWidth);

private:
    Texture2D texture{LoadTexture("assets/Pipes.png")};
    float scale{4.f};
    float speed{200};
    float xPos;
};