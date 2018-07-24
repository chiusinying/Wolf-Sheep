#ifndef WOLF_SHEEP_INCLUDE_CREATURE_H_
#define WOLF_SHEEP_INCLUDE_CREATURE_H_

#include "game.h"

class Game;

class Creature {
 public:
  enum TYPE { WOLF = 2, SHEEP = 3 };

  Creature(int x, int y, Creature::TYPE type);
  virtual ~Creature() = default;

  virtual enum TYPE GetType() const = 0;

  void Die(Game* game);
  void UpdateStarveChecker();
  void UpdateBreedChecker();
  virtual void Move(Game* game) = 0;
  virtual void Breed(Game* game) = 0;
  virtual void Eat(int x, int y, Game* game) = 0;
  virtual bool Starve(Game* game) = 0;

 protected:
  int x_;
  int y_;
  TYPE type_;
  int starve_checker_;
  int breed_checker_;
  int eat_;
};

#endif