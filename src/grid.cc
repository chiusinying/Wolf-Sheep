#include "grid.h"

Grid::Grid() : creature_(nullptr), type_(0) {}

Grid::~Grid() {
  Creature* temp = this->GetCreature();

  if (temp) {
    delete temp;
  }

  this->SetCreature(nullptr);
  this->SetType(0);
}

int Grid::GetType() const { return this->type_; }

Creature* Grid::GetCreature() const { return this->creature_; }

void Grid::SetType(int type) { this->type_ = type; }

void Grid::SetCreature(Creature* creature) { this->creature_ = creature; }