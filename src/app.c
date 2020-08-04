#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

const int ROWS = 20;
const int COLUMNS = 20;
int MAP[ROWS][COLUMNS] = {
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

char readkey() {
  FILE *fp = popen("read -n 1 -r -s key; echo $key", "r");
  if (fp == NULL) {
    exit(1);
  }
  char c = fgetc(fp);
  pclose(fp);

  return c;
}

int is_empty(int r, int c) {
  return r < 0 || r >= ROWS || c < 0 || c >= COLUMNS || !MAP[r][c];
}

const char BG = '4';
const char FG = '3';
const char REGULAR = '0';
const char BLACK = '0';
const char RED = '1';
const char GREEN = '2';
const char WHITE = '7';

char BLOCK[7] = "██";

char AVATAR_BIG[2][7] = {
    "",
    "▜▛",
};

int main() {
  system("tput civis");

  int pr = 2;
  int pc = 2;
  int frame = 0;
  int moved = 1;

  const int BG_INDEX = 5;
  const int FG_INDEX = 8;
  const int COLOR_LENGTH = 10;
  const int CHAR_LENGTH = 3;
  const int CHARS_PER_CELL = 2;
  const int CELL_LENGTH = COLOR_LENGTH + CHARS_PER_CELL * CHAR_LENGTH;

  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  int rows = size.ws_row;
  int columns = size.ws_col / 2;

  int row_length = CELL_LENGTH * columns + 1;

  char *screen;

  screen = malloc(rows * row_length);

  const int COLOR_LENGTH = 3;
  const int FG_INDEX = 0;
  // rows * (2 * columns + 1) - 1
  for (int i = 0; i < rows; ++i) {
    int row_start = row_length * i;
    for (int j = 0; j < columns; ++j) {
      int cell_start = row_start + CELL_LENGTH * j;
      screen[cell_start] = '\033';
      screen[cell_start + 1] = '[';
      screen[cell_start + 2] = '4';
      screen[cell_start + 3] = '8';
      screen[cell_start + 4] = ';';
      screen[cell_start + 5] = '5';
      screen[cell_start + 6] = ';';
      screen[cell_start + 7] = '0';
      screen[cell_start + 8] = '2';
      screen[cell_start + 9] = '2';
      screen[cell_start + 10] = 'm';
      screen[cell_start + 11] = '\033';
      screen[cell_start + 12] = '3';
      screen[cell_start + 13] = '8';
      screen[cell_start + 14] = ';';
      screen[cell_start + 15] = '5';
      screen[cell_start + 16] = ';';
      screen[cell_start + 17] = '2';
      screen[cell_start + 18] = '3';
      screen[cell_start + 19] = '5';
      screen[cell_start + 20] = 'm';
    }
    screen[row_start + row_length - 1] = (i == rows - 1) ? '\0' : '\n';
  }

  while (1) {
    if (moved) {
      struct winsize size;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
      int rows = size.ws_row;
      int columns = size.ws_col / 2;

      int center_r = rows / 2;
      int center_c = columns / 2;

      ++frame;

      for (int i = 0; i < rows; ++i) {
        int row_start = row_length * i;
        for (int j = 0; j < columns; ++j) {
          int cell_start = row_start + CELL_LENGTH * j;
          int char_start = cell_start + COLOR_LENGTH;
          int a1 = char_start;
          int a2 = char_start + 1;
          int a3 = char_start + 2;
          int b1 = char_start + 3;
          int b2 = char_start + 4;
          int b3 = char_start + 5;

          screen[a1] = ' ';
          screen[a2] = '\b';
          screen[a3] = ' ';
          screen[b1] = ' ';
          screen[b2] = '\b';
          screen[b3] = ' ';

          int r = i - center_r + pr;
          int c = j - center_c + pc;
          int empty = is_empty(r, c);

          if (i == center_r - 1 && j == center_c) {
            screen[cell_start + BG_INDEX] = empty ? BLACK : WHITE;
            screen[cell_start + FG_INDEX] = GREEN;
            screen[a1] = AVATAR_BIG[0][0];
            screen[a2] = AVATAR_BIG[0][1];
            screen[a3] = AVATAR_BIG[0][2];
            screen[b1] = AVATAR_BIG[0][3];
            screen[b2] = AVATAR_BIG[0][4];
            screen[b3] = AVATAR_BIG[0][5];
          } else if (i == center_r && j == center_c) {
            screen[cell_start + FG_INDEX] = BLACK;
            screen[cell_start + FG_INDEX] = GREEN;
            screen[a1] = AVATAR_BIG[1][0];
            screen[a2] = AVATAR_BIG[1][1];
            screen[a3] = AVATAR_BIG[1][2];
            screen[b1] = AVATAR_BIG[1][3];
            screen[b2] = AVATAR_BIG[1][4];
            screen[b3] = AVATAR_BIG[1][5];
          } else if (!empty) {
            screen[cell_start + BG_INDEX] = BLACK;
            screen[cell_start + FG_INDEX] = WHITE;
            screen[a1] = BLOCK[0];
            screen[a2] = BLOCK[1];
            screen[a3] = BLOCK[2];
            screen[b1] = BLOCK[3];
            screen[b2] = BLOCK[4];
            screen[b3] = BLOCK[5];
          }
        }
      }

      printf("\e[0;0H%s", screen);
    }

    moved = 0;
    switch (readkey()) {
    case 'h':
    case 'H':
      if (is_empty(pr, pc - 1)) {
        --pc;
        moved = 1;
      }
      break;
    case 'j':
    case 'J':
      if (is_empty(pr + 1, pc)) {
        ++pr;
        moved = 1;
      }
      break;
    case 'k':
    case 'K':
      if (is_empty(pr - 1, pc)) {
        --pr;
        moved = 1;
      }
      break;
    case 'l':
    case 'L':
      if (is_empty(pr, pc + 1)) {
        ++pc;
        moved = 1;
      }
      break;
    }
  }

  free(screen);

  return 0;
}

// TODO: have two threads - one to read keys, one to do game loop
