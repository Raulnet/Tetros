#include <SDL/SDL.h>

#ifndef TETRIS_TETRIMINOS_H
#define TETRIS_TETRIMINOS_H

typedef struct Block Block;
struct Block {
    int content;
    int nextDirection;
    Block *block;
};

typedef struct Tetriminos Tetriminos;
struct Tetriminos {
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

Tetriminos *newTetriminos();

void setTetriminosI(Tetriminos *tetriminos);
void setTetriminosT(Tetriminos *tetriminos);
void setTetriminosL(Tetriminos *tetriminos);
void setTetriminosJ(Tetriminos *tetriminos);
void setTetriminosS(Tetriminos *tetriminos);
void setTetriminosZ(Tetriminos *tetriminos);
void setTetriminosO(Tetriminos *tetriminos);
void setRandomTetrominos(Tetriminos *tetriminos);

void pushBlock(Block *block, int content, int nextDirection);

void renderTetriminos(Tetriminos *tetriminos, SDL_Surface *blockImg[], SDL_Surface *screen);

#endif //TETRIS_TETRIMINOS_H
