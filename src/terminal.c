#include "terminal.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

const char HIDE_CURSOR_COMMAND[] = "tput civis";
const char SCREEN_FORMAT[] = "\e[0;0H%s";

void draw_screen(Screen screen) { printf(SCREEN_FORMAT, (char *)screen); }

void hide_cursor() { system(HIDE_CURSOR_COMMAND); }

void get_terminal_size(Dim2 *size) {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  size->x = ws.ws_col;
  size->y = ws.ws_row;
}
