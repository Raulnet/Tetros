#include "tetrominos.h"
#include "list.h"
#include "enum.h"

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

void initLevel(int *level);
void initTetrominos(Tetrominos **pTetrominos, List *list);
void swapTetrominos(Tetrominos **pTetrominos, List *list);
void lockTetrominos(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH]);
int resolveLevel(int performanceLine);

#endif //TETRIS_GAME_H
