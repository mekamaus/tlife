#pragma once

#include "filename.h"

/**
 * Persistence parameters, e.g. filenames, network config for sending/receiving
 * data, etc.
 */
typedef struct Persistence {
  /** File from which to read player state. */
  Filename player_file;

  /** File from which to read map state. */
  Filename map_file;
} Persistence;
