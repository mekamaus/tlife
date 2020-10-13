#include "keyboard.h"
#include <ncurses.h>

Keyboard::Keyboard() {
  initscr();
  cbreak();
  noecho();
  scrollok(stdscr, TRUE);
}

Keyboard::~Keyboard() {
  nocbreak();
  echo();
  scrollok(stdscr, FALSE);
  endwin();
}

int Keyboard::GetChar() { return getch(); }
