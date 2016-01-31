#include "Data.hpp"
#include "Game.hpp"

int main(int argc, char const* argv[]) {
  Data::init();

  Game game;
  game.run(30);

  return 0;
}
