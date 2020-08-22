#include "constants.h"

#define DATA_FILE(x) (Filename) "/tmp/" #x

const Filename PLAYER_FILE = DATA_FILE(player);
const Filename MAP_FILE = DATA_FILE(map);

const Pos2 START_PLAYER_POS = {0, 0};
const Pos2 START_PLAYER_DELTA = {1, 0};
const Dim2 MAP_SIZE = {64, 64};

const Pos2 BODY_OFFSET = {0, 0};
const Pos2 HEAD_OFFSET = {0, -1};
