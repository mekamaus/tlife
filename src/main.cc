#include "constants.h"
#include "loop.h"
#include "terminal.h"

int main() {
  Persistence persistence = {PLAYER_FILE, MAP_FILE};
  Game game(MAP_SIZE.x, MAP_SIZE.y);
  Input input(CONTROL_BINDINGS);
  Output output;

  system("tput civis");

  persistence >> game;

  Loop loop(game, input, output, persistence);
  loop.Run();

  system("tput cnorm");

  return 0;
}
