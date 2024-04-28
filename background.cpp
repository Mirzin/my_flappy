#include "background.h"

void Background::moveBackground(float dT, float mapScale)
{
    bgX -= 20 * dT;
    if (bgX <= -background.width * mapScale)
    {
        bgX = 0.0;
    }

    mgX -= 40 * dT;
    if (mgX <= -midground.width * mapScale)
    {
        mgX = 0.0;
    }

    fcX -= 60 * dT;
    if (fcX <= -farCloud.width * mapScale)
    {
        fcX = 0.0;
    }

    ccX -= 80 * dT;
    if (ccX <= -closestCloud.width * mapScale)
    {
        ccX = 0.0;
    }
}

void Background::drawBackground(float mapScale)
{
    Vector2 bgPos{bgX, 0.0};
    DrawTextureEx(background, bgPos, 0.0, mapScale, WHITE);
    Vector2 bg2Pos{bgX + background.width * mapScale, 0.0};
    DrawTextureEx(background, bg2Pos, 0.0, mapScale, WHITE);

    Vector2 mgPos{mgX, 0.0};
    DrawTextureEx(midground, mgPos, 0.0, mapScale, WHITE);
    Vector2 mg2Pos{mgX + midground.width * mapScale, 0.0};
    DrawTextureEx(midground, mg2Pos, 0.0, mapScale, WHITE);

    Vector2 fcPos{fcX, 0.0};
    DrawTextureEx(farCloud, fcPos, 0.0, mapScale, WHITE);
    Vector2 fc2Pos{fcX + farCloud.width * mapScale, 0.0};
    DrawTextureEx(farCloud, fc2Pos, 0.0, mapScale, WHITE);

    Vector2 ccPos{ccX, 0.0};
    DrawTextureEx(closestCloud, ccPos, 0.0, mapScale, WHITE);
    Vector2 cc2Pos{ccX + closestCloud.width * mapScale, 0.0};
    DrawTextureEx(closestCloud, cc2Pos, 0.0, mapScale, WHITE);
}

void Background::tick(float dT, float mapScale) {
    drawBackground(mapScale);
    moveBackground(dT, mapScale);
}