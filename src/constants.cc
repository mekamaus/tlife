#include "constants.h"

#define DATA_FILE(x) (Filename) "/tmp/" #x

const Filename PLAYER_FILE = DATA_FILE(player);
const Filename MAP_FILE = DATA_FILE(map);

const Vector2<Pos> START_PLAYER_POS = {0, 0};
const Vector2<Pos> START_PLAYER_DELTA = {1, 0};

const Vector2<Dim> MAP_SIZE = {64, 64};

const Vector2<Dim> SCREEN_SIZE = {1, 1};

const Vector2<Pos> BODY_OFFSET = {0, 0};
const Vector2<Pos> HEAD_OFFSET = {0, -1};

const int TARGET_FPS = 8;

const std::vector<ControlBinding> CONTROL_BINDINGS{
    {
        Control::STEP,
        {'a', 's', 'w', 'd', 'h', 'j', 'k', 'l'},
    },
    {
        Control::STRIDE,
        {'A', 'S', 'W', 'D', 'H', 'J', 'K', 'L'},
    },
    {
        Control::MOVEMENT,
        {'a', 's', 'w', 'd', 'h', 'j', 'k', 'l', 'A', 'S', 'W', 'D', 'H', 'J',
         'K', 'L'},
    },
    {
        Control::L,
        {'a', 'A', 'h', 'H'},
    },
    {
        Control::D,
        {'s', 'S', 'j', 'J'},
    },
    {
        Control::U,
        {'w', 'W', 'k', 'K'},
    },
    {
        Control::R,
        {'d', 'D', 'l', 'L'},
    },
    {
        Control::BUILD,
        {'z', 'Z'},
    },
    {
        Control::DESTROY,
        {'x', 'X'},
    },
    {
        Control::CONSTRUCT,
        {'z', 'Z', 'x', 'X'},
    },
    {
        Control::EXIT,
        {'q', 'Q'},
    },
    {
        Control::STOP,
        {' '},
    },
};
