#include "control.h"
#include <fcntl.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

const Control CONTROL_STRIDE_LEFT = 'h';
const Control CONTROL_STRIDE_DOWN = 'j';
const Control CONTROL_STRIDE_UP = 'k';
const Control CONTROL_STRIDE_RIGHT = 'l';
const Control CONTROL_STEP_LEFT = 'H';
const Control CONTROL_STEP_DOWN = 'J';
const Control CONTROL_STEP_UP = 'K';
const Control CONTROL_STEP_RIGHT = 'L';
const Control CONTROL_BUILD = 'a';
const Control CONTROL_DESTROY = 'x';
const Control CONTROL_EXIT = 'q';
const Control CONTROL_STOP = ' ';

void start_controls() {
  //  initscr();
  //  cbreak();
  //  noecho();
  //  nodelay(stdscr, TRUE);
  //  scrollok(stdscr, TRUE);
}

int kbhit() {
  int ch = getch();
  if (ch != ERR) {
    ungetch(ch);
    return 1;
  }

  return 0;
}

Control get_control() {
  if (kbhit()) {
    return getchar();
  }
  return 0;
}

void stop_controls() {
  //  nocbreak();
  //  echo();
  //  nodelay(stdscr, FALSE);
  //  scrollok(stdscr, FALSE);
}

int is_step_control(Control control) {
  return control == CONTROL_STEP_LEFT || control == CONTROL_STEP_DOWN ||
         control == CONTROL_STEP_UP || control == CONTROL_STEP_RIGHT;
}

int is_stride_control(Control control) {
  return control == CONTROL_STRIDE_LEFT || control == CONTROL_STRIDE_DOWN ||
         control == CONTROL_STRIDE_UP || control == CONTROL_STRIDE_RIGHT;
}

int is_stop_control(Control control) { return control == CONTROL_STOP; }

int is_building_control(Control control) {
  return control == CONTROL_BUILD || control == CONTROL_DESTROY;
}
