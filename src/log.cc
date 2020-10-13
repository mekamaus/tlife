#include "log.h"
#include <stdarg.h>
#include <stdio.h>

void flogf(const char *format, ...) {
  va_list args;
  va_start(args, format);

  FILE *f;
  f = fopen("/tmp/log", "a+");
  vfprintf(f, format, args);
  fclose(f);

  va_end(args);
}
