#include "raylib.h"
#include "raymath.h"
#include <string>

class Prop{
public:
    Prop(Vector2 worldPos, Texture2D texture);
    void Render(Vector2 lordPos);
    Rectangle getPropRec(Vector2 lordPos);
private:
    Texture2D texture{};
    Vector2 worldPos{};
    float scale{3.0f};
};