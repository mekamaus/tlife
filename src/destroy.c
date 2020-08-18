#include "destroy.h"
#include "bool.h"
#include "control.h"
#include "terminal.h"

void destroy_game(Screen screen) {
  destroy_screen(screen);
  stop_controls();
  set_cursor_visibility(true);
}
