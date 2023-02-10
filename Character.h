#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int windowWidth,
              int windowHeight,
              Texture2D idle,
              Texture2D run,
              Texture2D weapon);
    void tick(float dT) override;
    Vector2 getScreenPos() override;
    Rectangle getWeaponColRec() { return weaponColRec; }
    float getHealth() const { return health; }
    void takeDamage(float damage);
    void playAgain(){  this->health = 100.0f; this->setAlive(true); }

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{};
    Rectangle weaponColRec{};
    float health{100.0f};
};

#endif