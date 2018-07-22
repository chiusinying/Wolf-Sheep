#ifndef WOLF_SHEEP_INCLUDE_SHEEP_H_
#define WOLF_SHEEP_INCLUDE_SHEEP_H_

#include "creature.h"

class Sheep : public Creature {
 public:
  Sheep(int x, int y);
  ~Sheep() = default;

  virtual TYPE GetType() const;
  virtual void Breed(Game* game);
  virtual void Eat(int x, int y, Game* game);
  virtual bool Starve(Game* game);
};

#endif