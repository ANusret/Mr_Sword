#include "raylib.h"
#include "Enemy.h"
#include "raymath.h"
#include <string>

Enemy::Enemy(Vector2 worldPos, Texture2D idle, Texture2D run)
{
    this->worldPos = worldPos;
    this->texture = idle;
    this->idle = idle;
    this->run = run;
    width = texture.width / maxFrame;
    height = texture.height;
    this->speed = 2.5f;
}

void Enemy::tick(float dT)
{
    if (!getAlive())
        return;

    // get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());

    if (Vector2Length(velocity) < zone)
        velocity = {};

    BaseCharacter::tick(dT);

    if (CheckCollisionRecs(target->getWeaponColRec(), getRec()))
    {
        target->takeDamage(damage * dT);
    }
}

Vector2 Enemy::getScreenPos()
{
    return Vector2{Vector2Subtract(worldPos, target->getWorldPos())};
}
