#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"
#include <string>

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 worldPos, Texture2D idle, Texture2D run);
    void tick(float dT) override;

private:
};