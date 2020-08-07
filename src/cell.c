#include "cell.h"

const unsigned char COLOR_INDEX = 7;

const Cell EMPTY_CELL = {
    {{'\033', '[', '3', '8', ';', '5', ';', '2', '5', '5', 'm'}},
    {{'\033', '[', '4', '8', ';', '5', ';', '0', '0', '0', 'm'}},
    {{{' ', '\b', ' '}}, {{' ', '\b', ' '}}},
};

const Cell NEWLINE_CELL = {
    {{'\033', '[', '3', '8', ';', '5', ';', '2', '5', '5', 'm'}},
    {{'\033', '[', '4', '8', ';', '5', ';', '0', '0', '0', 'm'}},
    {{{'\r', '\r', '\r'}}, {{'\r', '\r', '\n'}}},
};

const Cell NULL_CELL = {
    {{'\033', '[', '3', '8', ';', '5', ';', '2', '5', '5', 'm'}},
    {{'\033', '[', '4', '8', ';', '5', ';', '0', '0', '0', 'm'}},
    {{{'\r', '\r', '\r'}}, {{'\r', '\r', '\0'}}},
};

// 
const Shape PLAYER_HEAD = {{{0xEE, 0x82, 0xB6}}, {{0xEE, 0x82, 0xB4}}};

// ▜▛
const Shape PLAYER_BODY_FRONT = {{{0xE2, 0x96, 0x9C}}, {{0xE2, 0x96, 0x9B}}};

// ▜▛
const Shape PLAYER_BODY_BACK = {{{0xE2, 0x96, 0x9C}}, {{0xE2, 0x96, 0x9B}}};

// ▜▍
const Shape PLAYER_BODY_LEFT = {{{0xE2, 0x96, 0x9C}}, {{0xE2, 0x96, 0x8D}}};

// ▐▛
const Shape PLAYER_BODY_RIGHT = {{{0xE2, 0x96, 0x90}}, {{0xE2, 0x96, 0x9B}}};

// 
const Shape EMPTY_TARGET = {{{0xEE, 0x82, 0xB3}}, {{0xEE, 0x82, 0xB1}}};

// " "
const Shape EMPTY_TARGET_LEFT = {{{0x20, 0x08, 0x20}}, {{0xEE, 0x82, 0xB3}}};

// " "
const Shape EMPTY_TARGET_RIGHT = {{{0xEE, 0x82, 0xB1}}, {{0x20, 0x08, 0x20}}};

// ██
const Shape BLOCK = {{{0xE2, 0x96, 0x88}}, {{0xE2, 0x96, 0x88}}};

// "  "
const Shape EMPTY = {{{0x20, 0x08, 0x20}}, {{0x20, 0x08, 0x20}}};
