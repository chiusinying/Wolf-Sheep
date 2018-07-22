#include "include/wolf.h"

Wolf::Wolf(int x, int y) : Creature(x, y) {}

Creature::TYPE Wolf::GetType() const { return Creature::WOLF; }

void Wolf::Breed(Game* game) {}

void Wolf::Eat(int x, int y, Game* game) {}

bool Wolf::Starve(Game* game) {}