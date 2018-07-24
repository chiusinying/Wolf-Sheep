#include <windows.h>
#include <iostream>
#include "game.h"

int main() {
  int width;
  int wolfAmount;
  int sheepAmount;

  std::cin >> width >> wolfAmount >> sheepAmount;

  Game game(width, wolfAmount, sheepAmount);

  while (1) {
    game.Tick();
    game.Display();
    Sleep(1000);
  }

  return 0;
}