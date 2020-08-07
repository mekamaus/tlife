#include "controls.h"
#include <stdio.h>
#include <stdlib.h>

const Key CONTROLS_LEFT = 'h';
const Key CONTROLS_DOWN = 'j';
const Key CONTROLS_UP = 'k';
const Key CONTROLS_RIGHT = 'l';

void start_controls() {
  // TODO: start a thread that reads controls
}

char readkey() {
  FILE *fp = popen("read -n 1 -r -s key; echo $key", "r");
  if (fp == NULL) {
    exit(1);
  }
  char c = fgetc(fp);
  pclose(fp);

  return c;
}
