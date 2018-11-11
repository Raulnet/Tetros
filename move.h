#include <SDL_events.h>
#include "tetrominos.h"
#include "list.h"
#include "enum.h"

#ifndef TETRIS_MOVE_H
#define TETRIS_MOVE_H

void handleEvent(
        SDL_Event event,
        int *loopScreen,
        Tetrominos **pTetrominos,
        List *list,
        int (*pit)[PIT_NB_BLOCKS_WIDTH],
        int performance[PERFORMANCE_NB]
);

void moveTetrominos(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH], int move, int performance[PERFORMANCE_NB]);

int availableToMove(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH], int move);
int resoleMovement(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH], int move, int performance[PERFORMANCE_NB]);

#endif //TETRIS_MOVE_H
