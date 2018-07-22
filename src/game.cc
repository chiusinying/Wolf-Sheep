#include "include/game.h"

// return random integer in [1, upper]
int random(int upper) { return rand() % upper + 1; }

Game::Game(int width, int wolfAmount, int sheepAmount) {
  this->map_ = new Grid*[width + 2];
  this->width_ = width;
  this->wolf_init_amount_ = wolfAmount;
  this->sheep_init_amount_ = sheepAmount;
  this->wolf_amount_ = 0;
  this->sheep_amount_ = 0;
  this->day_ = 0;

  for (int i = 0; i < width + 2; i++) {
    this->map_[i] = new Grid[width + 2];
  }

  for (int i = 0; i < width + 2; i++) {
    this->map_[i][0].SetType(Grid::WALL);
    this->map_[i][width + 1].SetType(Grid::WALL);
    this->map_[0][i].SetType(Grid::WALL);
    this->map_[width + 1][i].SetType(Grid::WALL);
  }

  srand(time(0));

  for (int i = 0; i < this->wolf_init_amount_; i++) {
    int x = random(this->width_);
    int y = random(this->width_);

    while (this->map_[x][y].GetType() == Creature::WOLF ||
           this->map_[x][y].GetType() == Creature::SHEEP) {
      x = random(this->width_);
      y = random(this->width_);
    }

    this->Add(x, y, Creature::WOLF);
  }

  for (int i = 0; i < this->sheep_init_amount_; i++) {
    int x = random(this->width_);
    int y = random(this->width_);

    while (this->map_[x][y].GetType() == Creature::WOLF ||
           this->map_[x][y].GetType() == Creature::SHEEP) {
      x = random(this->width_);
      y = random(this->width_);
    }

    this->Add(x, y, Creature::SHEEP);
  }
}

Game::~Game() {
  for (int i = 0; i < this->width_ + 2; i++) {
    delete[] this->map_[i];
  }

  delete[] this->map_;
}

Grid* Game::GetGrid(int x, int y) const { return &(this->map_[x][y]); }

void Game::Add(int x, int y, Creature::TYPE type) {
  switch (type) {
    case Creature::TYPE::SHEEP:
      this->map_[x][y].SetCreature(new Sheep(x, y));
      break;
    case Creature::TYPE::WOLF:
      this->map_[x][y].SetCreature(new Wolf(x, y));
      break;
  }

  this->UpdateAmount(type, 1);
}

void Game::Remove(int x, int y) {
  Creature* temp = this->map_[x][y].GetCreature();

  if (temp) {
    this->UpdateAmount(temp->GetType(), -1);
    delete temp;
  }

  this->map_[x][y].SetCreature(nullptr);
  this->map_[x][y].SetType(Grid::GRASS);
}

void Game::UpdateAmount(Creature::TYPE type, int delta) {
  switch (type) {
    case Creature::TYPE::SHEEP:
      this->sheep_amount_ += delta;
      break;
    case Creature::TYPE::WOLF:
      this->wolf_amount_ += delta;
      break;
  }
}

void Game::Refresh() {
  for (int i = 1; i <= this->width_; i++) {
    for (int j = 1; j <= this->width_; j++) {
      Creature* creature = this->map_[i][j].GetCreature();

      if (creature == nullptr) {
        continue;
      }

    }
  }

  this->day_++;
}
