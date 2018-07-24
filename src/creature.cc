#include "creature.h"

Creature::Creature(int x, int y, Creature::TYPE type) {
  this->x_ = x;
  this->y_ = y;
  this->type_ = type;
  this->starve_checker_ = 0;
  this->breed_checker_ = 0;
  this->eat_ = 0;
}

void Creature::Die(Game* game) { game->Remove(this->x_, this->y_); }

void Creature::UpdateStarveChecker() {
  if (this->starve_checker_ < 3) {
    this->starve_checker_++;
  } else {
    this->starve_checker_ = 0;
    this->eat_ = 0;
  }
}

void Creature::UpdateBreedChecker() {
  if (this->breed_checker_ < 8) {
    this->breed_checker_++;
  } else {
    this->breed_checker_ = 0;
  }
}