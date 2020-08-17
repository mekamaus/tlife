#pragma once

#include "bool.h"

typedef unsigned char Control;

extern const Control CONTROL_LEFT;
extern const Control CONTROL_DOWN;
extern const Control CONTROL_UP;
extern const Control CONTROL_RIGHT;
extern const Control CONTROL_BUILD;
extern const Control CONTROL_DESTROY;
extern const Control CONTROL_EXIT;

void start_controls();

Control get_control();

bool is_movement_control(Control control);

bool is_building_control(Control control);
