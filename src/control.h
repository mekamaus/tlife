#pragma once

#include "bool.h"

typedef unsigned char Control;

extern const Control CONTROL_STRIDE_LEFT;
extern const Control CONTROL_STRIDE_DOWN;
extern const Control CONTROL_STRIDE_UP;
extern const Control CONTROL_STRIDE_RIGHT;
extern const Control CONTROL_STEP_LEFT;
extern const Control CONTROL_STEP_DOWN;
extern const Control CONTROL_STEP_UP;
extern const Control CONTROL_STEP_RIGHT;
extern const Control CONTROL_BUILD;
extern const Control CONTROL_DESTROY;
extern const Control CONTROL_EXIT;

/** Initializes controls. */
void start_controls();

/** Gets the most recently activated control. */
Control get_control();

/** Stops controls. */
void stop_controls();

/** Returns whether the control is for stepping (left, down, up, or right). */
int is_step_control(Control control);

/**
 * Returns whether the control is for striding, a.k.a continuous movement (left,
 * down, up, or right).
 */
int is_stride_control(Control control);

/** Returns whether the control is for stopping stride movement. */
int is_stop_control(Control control);

/** Returns whether the control is for building. */
int is_building_control(Control control);
