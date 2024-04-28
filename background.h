#include "raylib.h"

class Background
{
public:
    void tick(float dT, float mapScale);
private:
    Texture2D background{LoadTexture("maps/1.png")};
    Texture2D midground{LoadTexture("maps/2.png")};
    Texture2D farCloud{LoadTexture("maps/3.png")};
    Texture2D closestCloud{LoadTexture("maps/4.png")};
    float bgX{};
    float mgX{};
    float fcX{};
    float ccX{};
    void moveBackground(float dT, float mapScale);
    void drawBackground(float mapScale);
};