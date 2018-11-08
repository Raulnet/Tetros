#include <SDL/SDL.h>
#include "list.h"

#ifndef TETRIS_TETRIMINOS_H
#define TETRIS_TETRIMINOS_H

typedef struct Block Block;
struct Block {
    int content;
    int nextDirection;
    Block *next;
};

typedef struct Tetrominos Tetrominos;
struct Tetrominos {
    int img;
    int orientation;
    Sint16 positionX;
    Sint16 positionY;
    Block *templateTop;
    Block *templateBottom;
    Block *templateLeft;
    Block *templateRight;
};

Block *getNewBlock();

Tetrominos *newTetrominos();

void setTetrominosI(Tetrominos *tetrominos);

void setTetrominosT(Tetrominos *tetrominos);

void setTetrominosL(Tetrominos *tetrominos);

void setTetrominosJ(Tetrominos *tetrominos);

void setTetrominosS(Tetrominos *tetrominos);

void setTetrominosZ(Tetrominos *tetrominos);

void setTetrominosO(Tetrominos *tetrominos);

void setRandomTetrominos(Tetrominos *tetrominos, List *list);

int getRandomId();

void pushBlock(Block *block, int content, int nextDirection);

void renderTetrominos(Tetrominos *tetrominos, SDL_Surface **pSurfaces);

#endif //TETRIS_TETRIMINOS_H
