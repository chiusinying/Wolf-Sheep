#ifndef WOLF_SHEEP_INCLUDE_WOLF_H_
#define WOLF_SHEEP_INCLUDE_WOLF_H_

#include "creature.h"

class Wolf : public Creature {
 public:
  Wolf(int x, int y);
  ~Wolf() = default;

  virtual TYPE GetType() const;
  virtual void Breed(Game* game);
  virtual void Eat(int x, int y, Game* game);
  virtual bool Starve(Game* game);
};

#endif