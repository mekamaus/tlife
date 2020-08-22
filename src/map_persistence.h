#pragma once

#include "block.h"
#include "filename.h"
#include "map.h"
#include "scalar.h"
#include <stdio.h>
#include <unistd.h>

// Reads a map from a file.
void read_map(Filename filename, Map map, const Dim2 *size);

// Writes a map to a file.
void write_map(Filename filename, Map map, const Dim2 *size);
