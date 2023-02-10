#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"
#include <string>

class Character : public BaseCharacter
{
public:
    Character(int windowWidth, int windowHeight, Texture2D idle, Texture2D run);
    void tick(float dT) override;
private:
};