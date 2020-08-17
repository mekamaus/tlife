#include "controls.h"
#include <stdio.h>
#include <stdlib.h>

const Control CONTROL_LEFT = 'h';
const Control CONTROL_DOWN = 'j';
const Control CONTROL_UP = 'k';
const Control CONTROL_RIGHT = 'l';
const Control CONTROL_BUILD = 'a';
const Control CONTROL_DESTROY = 'x';
const Control CONTROL_EXIT = 'q';

void start_controls() {
  // TODO: Start a thread that reads controls.
}

// TODO: Get most recent control pressed.
Control get_control() {
  FILE *fp = popen("read -n 1 -r -s key; echo $key", "r");
  if (fp == NULL) {
    exit(1);
  }

  char c = fgetc(fp);
  pclose(fp);

  return c;
}

bool is_movement_control(Control control) {
  return control == CONTROL_LEFT || control == CONTROL_DOWN ||
         control == CONTROL_UP || control == CONTROL_RIGHT;
}

bool is_building_control(Control control) {
  return control == CONTROL_BUILD || control == CONTROL_DESTROY;
}
