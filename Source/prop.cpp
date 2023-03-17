#include "prop.h"
#include "raylib.h"
#include "raymath.h"
#include <string>

Prop::Prop(Vector2 worldPos, Texture2D textrue)
{
    this->worldPos = worldPos;
    this->texture = textrue;
}

void Prop::Render(Vector2 lordPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, lordPos)};
    DrawTextureEx(texture, screenPos, 0.0f, scale, WHITE);
}

Rectangle Prop::getPropRec(Vector2 lordPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, lordPos)};
    return Rectangle{screenPos.x,
                     screenPos.y,
                     texture.width * scale,
                     texture.height * scale};
}
