#include "include/creature.h"

Creature::Creature(int x, int y) {}

int Creature::GetX() const { return this->x_; }

int Creature::GetY() const { return this->y_; }

void Creature::SetX(int x) { this->x_ = x; }

void Creature::SetY(int y) { this->y_ = y; }

void Creature::Die(Game* game) {
  game->Remove(this->x_, this->y_);
}

void Creature::Move(int direction, Game* game) {
  
}