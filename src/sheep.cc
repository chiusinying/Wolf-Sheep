#include "include/sheep.h"

Sheep::Sheep(int x, int y) : Creature(x, y) {}

Creature::TYPE Sheep::GetType() const { return Creature::SHEEP; }

void Sheep::Breed(Game* game) {}

void Sheep::Eat(int x, int y, Game* game) {
  // Do nothing
}

bool Sheep::Starve(Game* game) {
  return false;
}