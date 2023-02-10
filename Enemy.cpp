#include "raylib.h"
#include "Enemy.h"
#include "raymath.h"
#include <string>

Enemy::Enemy(Vector2 worldPos, Texture2D idle, Texture2D run){
    this->worldPos = worldPos;
    this->texture = idle;
    this->idle = idle;
    this->run = run;
    width = texture.width / maxFrame;
    height = texture.height;
}

void Enemy::tick(float dT)
{
    BaseCharacter::tick(dT);
}
