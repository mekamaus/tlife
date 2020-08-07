#include "screen.h"

const int COLOR_LENGTH = 3;
const int COLORS_LENGTH = 22;

Screen create_screen(int rows, int columns) {
  int row_length = columns + 1;

  Screen screen = (Screen)malloc(sizeof(Cell) * row_length * rows);

  for (int i = 0; i < rows; ++i) {
    int row_start = row_length * i;
    for (int j = 0; j <= row_length; ++j) {
      screen[row_start + j] = j < row_length - 1
                                  ? EMPTY_CELL
                                  : i < rows - 1 ? NEWLINE_CELL : NULL_CELL;
    }
  }

  return screen;
}

void resize_screen(Screen *screen, int rows, int columns) {
  free(*screen);
  *screen = create_screen(rows, columns);
}
