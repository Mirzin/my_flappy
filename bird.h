#include "raylib.h"

class Bird
{
public:
    void tick(int windowHeight, float dT, bool gameOver);
    Rectangle getCollisionRec();
    void reset();

private:
    Texture2D texture{LoadTexture("assets/Bird.png")};
    Sound sound{LoadSound("assets/jump.mp3")};
    Rectangle source{
        0.f,
        static_cast<float>(texture.height) / 7,
        static_cast<float>(texture.width) / 4,
        static_cast<float>(texture.height) / 7,
    };
    Rectangle dest{};
    float destYpos{5.f};
    int maxFrames{4};
    int currentFrame{};
    float scale{4.f};
    float runningTime{};
    float updateTime{1.f / 12.f};
    float gravity{1000.f};
    float velocity{0.f};
    float jumpVelocity{-65000.f};
    void drawBird(int windowHeight, float dT, bool gameOver);
};