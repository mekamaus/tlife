#include "bool.h"
#include "screen.h"

/** Draws the screen to the terminal. */
void draw_screen(Screen screen);

/** Sets the cursor visibility. */
void set_cursor_visibility(int visible);

/** Gets the terminal dimensions. */
void get_terminal_size(Dim2 *size);
