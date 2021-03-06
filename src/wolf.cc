#include "wolf.h"

Wolf::Wolf(int x, int y) : Creature(x, y, Creature::WOLF) {}

enum Creature::TYPE Wolf::GetType() const { return Creature::WOLF; }

void Wolf::Move(Game* game) {
  int x = this->x_;
  int y = this->y_;
  int newX = -1;
  int newY = -1;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++) {
    Grid* grid = game->GetGrid(x + dx[i], y + dy[i]);

    if (grid->GetType() != Grid::WALL && grid->GetType() == Creature::SHEEP) {
      newX = x + dx[i];
      newY = y + dy[i];
      break;
    }
  }

  for (int i = 0; i < 4; i++) {
    Grid* grid = game->GetGrid(x + dx[i], y + dy[i]);

    if (grid->GetType() != Grid::WALL && grid->GetType() == Grid::GRASS) {
      newX = x + dx[i];
      newY = y + dy[i];
      break;
    }
  }

  if (newX == -1 && newY == -1) {
    return;
  }

  this->Eat(newX, newY, game);
  game->Exchange(x, y, newX, newY);
}

void Wolf::Breed(Game* game) {
  if (this->breed_checker_ < 8) {
    return;
  }

  int x = this->x_;
  int y = this->y_;
  int newX = -1;
  int newY = -1;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++) {
    Grid* grid = game->GetGrid(x + dx[i], y + dy[i]);

    if (grid->GetType() == Grid::GRASS) {
      newX = x + dx[i];
      newY = y + dy[i];
      break;
    }
  }

  if (newX == -1 && newY == -1) {
    return;
  }

  game->Add(newX, newY, this->type_);
}

void Wolf::Eat(int x, int y, Game* game) {
  Creature* creature = game->GetGrid(x, y)->GetCreature();

  if (creature == nullptr || creature->GetType() != Creature::SHEEP) {
    return;
  }

  game->Remove(x, y);
  this->eat_++;
}

bool Wolf::Starve(Game* game) {
  return this->breed_checker_ >= 3 && !this->eat_;
}