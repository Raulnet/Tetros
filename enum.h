//
// Created by raulnet on 05/11/18.
//

#ifndef TETRIS_ENUM_H
#define TETRIS_ENUM_H
#define SCREEN_HEIGHT 960
#define SCREEN_WIDTH 640
#define PIT_NB_BLOCKS_WIDTH 10
#define PIT_NB_BLOCKS_HEIGHT 22
#define NB_TETROMINOS 7

#define SIZE_BLOCK 42
#define PIT_WIDTH SIZE_BLOCK*PIT_NB_BLOCKS_WIDTH
#define PIT_HEIGHT SIZE_BLOCK*PIT_NB_BLOCKS_HEIGHT

#define DEFAULT_POSITION_TETROMINOS_HEIGHT 69
#define DEFAULT_POSITION_TETROMINOS_WIDTH 135

enum {
    CLEAR, BLOCK
};

// list index position/rotation Tetrominos
enum {
    TOP, RIGHT, BOTTOM, LEFT, NEUTRAL
};

enum {
    CURRENT_TETROMINOS, NEXT_TETROMINOS
};

// list index IMG assets
enum {
    SCREEN,
    BACKGROUND,
    BACK_WRAPPER,
    UI_WRAPPER,
    AQUA, AQUA_N,
    BLUE, BLUE_N,
    GREEN, GREEN_N,
    GREY, GREY_N,
    ORANGE, ORANGE_N,
    PINK, PINK_N,
    PURPLE, PURPLE_N,
    RED, RED_N,
    SKY, SKY_N,
    YELLOW, YELLOW_N
};

// list index Tetrominos
enum {
    J, I, O, T, L, Z, S
};


#endif //TETRIS_ENUM_H
