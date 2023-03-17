#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"
#include "Character.h"
#include <string>

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 worldPos, Texture2D idle, Texture2D run);
    void tick(float dT) override;
    void setTarget(Character* target) {this->target = target;}
    Vector2 getScreenPos() override;

private:
    Character* target;
    float damage{10.0f};
    float zone{30.0f};
};
