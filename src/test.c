#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  // const char COLOR_STR[15] = "\033[1;33m\033[1;44m";
  const char BLOCK[7] = "██";
  // printf("%s%s\n", COLOR_STR, BLOCK);

  for (int i = 0; BLOCK[i] != '\0'; ++i) {
    printf("%c\n", (char)BLOCK[i]);
  }

  return 0;
}
