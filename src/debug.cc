#include "debug.h"
#include <stdio.h>

void debug_count() {
  static int count = 0;
  printf("\r%d\n", count++);
}
