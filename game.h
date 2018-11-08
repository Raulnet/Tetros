#include "tetrominos.h"
#include "list.h"
#include "enum.h"

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

void initTetrominos(Tetrominos **pTetrominos, List *list);
void swapTetrominos(Tetrominos **pTetrominos, List *list);

#endif //TETRIS_GAME_H
