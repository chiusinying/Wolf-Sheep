#ifndef WOLF_SHEEP_INCLUDE_CREATURE_H_
#define WOLF_SHEEP_INCLUDE_CREATURE_H_

#include "game.h"

class Creature {
 public:
  enum TYPE { WOLF, SHEEP };

  Creature(int x, int y);
  virtual ~Creature() = default;

  int GetX() const;
  int GetY() const;
  virtual TYPE GetType() const = 0;

  void SetX(int x);
  void SetY(int y);

  void Die(Game* game);
  void Move(int direction, Game* game);
  virtual void Breed(Game* game) = 0;
  virtual void Eat(int x, int y, Game* game) = 0;
  virtual bool Starve(Game* game) = 0;

 private:
  int x_;
  int y_;
  TYPE type_;
};

#endif