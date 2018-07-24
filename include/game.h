#ifndef WOLF_SHEEP_INCLUDE_GAME_H_
#define WOLF_SHEEP_INCLUDE_GAME_H_

#include <cstdlib>
#include <ctime>
#include "creature.h"
#include "grid.h"
#include "sheep.h"
#include "wolf.h"

class Game {
 public:
  Game(int width, int wolfAmount, int sheepAmount);
  ~Game();

  Grid* GetGrid(int x, int y) const;

  void Add(int x, int y, enum Creature::TYPE type);
  void Exchange(int x, int y, int newX, int newY);
  void Remove(int x, int y);
  void UpdateAmount(Creature::TYPE type, int delta);
  void Display() const;
  void Tick();

 private:
  Grid** map_;
  int width_;
  int wolf_init_amount_;
  int sheep_init_amount_;
  int wolf_amount_;
  int sheep_amount_;
  int day_;
};

#endif