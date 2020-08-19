#include "window.h"
#include "terminal.h"
#include "vector_math.h"

Dim terminal_to_window_x(Dim value) { return value / 2; }
Dim terminal_to_window_y(Dim value) { return value; }

void terminal_to_window(Dim2 *window, const Dim2 *terminal) {
  window->x = terminal_to_window_x(terminal->x);
  window->y = terminal_to_window_y(terminal->y);
}

bool get_window_size(Dim2 *size) {
  Dim2 terminal_size;
  get_terminal_size(&terminal_size);
  Dim2 window_size;
  terminal_to_window(&window_size, &terminal_size);
  return change_dim(size, &window_size);
}
