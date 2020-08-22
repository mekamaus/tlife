#include "terminal.h"
#include "bool.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

const char HIDE_CURSOR_COMMAND[] = "tput civis";
const char SHOW_CURSOR_COMMAND[] = "tput cnorm";
const char SCREEN_PREFIX[] = "\e[0;0H";

void draw_screen(const Screen screen, const Dim2 *size) {
  write(STDOUT_FILENO, SCREEN_PREFIX, sizeof(SCREEN_PREFIX));
  write(STDOUT_FILENO, screen, get_screen_bytes(size));
}

void set_cursor_visibility(int visible) {
  system(visible ? SHOW_CURSOR_COMMAND : HIDE_CURSOR_COMMAND);
}

void get_terminal_size(Dim2 *size) {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  size->x = ws.ws_col;
  size->y = ws.ws_row;
}
