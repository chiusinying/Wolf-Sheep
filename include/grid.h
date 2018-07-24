#ifndef WOLF_SHEEP_INCLUDE_GRID_H_
#define WOLF_SHEEP_INCLUDE_GRID_H_

#include "creature.h"

class Grid {
 public:
  enum TYPE { WALL = 0, GRASS = 1 };
  Grid();
  ~Grid();

  int GetType() const;
  Creature* GetCreature() const;

  void SetType(int type);
  void SetCreature(Creature* creature);

 private:
  Creature* creature_;
  int type_;
};

#endif