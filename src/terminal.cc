#include "terminal.h"
#include <sys/ioctl.h>
#include <unistd.h>

Terminal &Terminal::operator>>(Vector2<Dim> &size) {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  size.x = ws.ws_col / 2;
  size.y = ws.ws_row;
  return *this;
}

Terminal &Terminal::operator<<(const char *str) {
  *out_ << str;
  return *this;
}
