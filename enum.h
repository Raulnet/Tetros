//
// Created by raulnet on 05/11/18.
//

#ifndef TETRIS_ENUM_H
#define TETRIS_ENUM_H
#define SCREEN_HEIGHT 960
#define SCREEN_WIDTH 640

#define PIT_NB_BLOCKS_WIDTH 10
#define PIT_NB_BLOCKS_HEIGHT 20
#define RANDOM_ID_MAX_TRY 3
#define NB_TETROMINOS 7

#define SIZE_BLOCK 42

#define DEFAULT_POSITION_TETROMINOS_HEIGHT 69
#define DEFAULT_POSITION_TETROMINOS_WIDTH 135
#define PIT_X DEFAULT_POSITION_TETROMINOS_WIDTH-42*3
#define PIT_Y DEFAULT_POSITION_TETROMINOS_HEIGHT+42
#define PIT_X_ZERO 9
#define PIT_Y_ZERO 69

#define DEFAULT_POSITION_NEXT_TETROMINOS_HEIGHT 125
#define DEFAULT_POSITION_NEXT_TETROMINOS_WIDTH 450

enum {
    CLEAR, BLOCK
};

// list index position/orientation Tetrominos
enum {
    TOP, RIGHT, BOTTOM, LEFT, NEUTRAL
};

// list index Movement Tetrominos
enum {
    GO_LEFT, GO_RIGHT, GO_BOTTOM, FLIP_LEFT, FLIP_RIGHT
};

enum {
    CURRENT_TETROMINOS, NEXT_TETROMINOS
};

// list index IMG assets
enum {
    EMPTY,
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

#define LEVEL_1_SPEED 1000
#define LEVEL_2_SPEED 900
#define LEVEL_3_SPEED 800
#define LEVEL_4_SPEED 700
#define LEVEL_5_SPEED 600
#define LEVEL_6_SPEED 500
#define LEVEL_7_SPEED 400
#define LEVEL_8_SPEED 300
#define LEVEL_9_SPEED 200
#define LEVEL_10_SPEED 100

enum {
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    LEVEL_6,
    LEVEL_7,
    LEVEL_8,
    LEVEL_9,
    LEVEL_10
};


#endif //TETRIS_ENUM_H
