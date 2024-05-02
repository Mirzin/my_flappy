#include "raylib.h"

class Bird
{
public:
    Bird();
    void tick(int windowHeight, float dT, bool gameOver);
    Rectangle getCollisionRec();
    void reset();
    int getXpos();

private:
    Texture2D texture;
    Sound sound;
    Rectangle source;
    Rectangle dest{};
    float destYpos{5.f};
    int maxFrames{4};
    int currentFrame{};
    float scale{4.f};
    float runningTime{};
    float updateTime{1.f / 12.f};
    float gravity{1000.f};
    float velocity{0.f};
    float jumpVelocity{-20000.f};
    void drawBird(int windowHeight, float dT, bool gameOver);
};