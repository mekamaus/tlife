#pragma once

#include "control.h"
#include "vector.h"

/** Determines the player delta from a movement control. */
const Pos2 *delta_from_movement_control(Control control);
