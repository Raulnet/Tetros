#include "game.h"

void initTetrominos(Tetrominos **pTetrominos, List *list) {

    pTetrominos[CURRENT_TETROMINOS] = newTetrominos();
    pTetrominos[CURRENT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[CURRENT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[CURRENT_TETROMINOS], list);

    pTetrominos[NEXT_TETROMINOS] = newTetrominos();
    pTetrominos[NEXT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[NEXT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[NEXT_TETROMINOS], list);
}

void swapTetrominos(Tetrominos **pTetrominos, List *list) {
    Tetrominos *tetrominos = pTetrominos[CURRENT_TETROMINOS];
    pTetrominos[CURRENT_TETROMINOS] = pTetrominos[NEXT_TETROMINOS];
    pTetrominos[CURRENT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[CURRENT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;

    pTetrominos[NEXT_TETROMINOS] = newTetrominos();
    pTetrominos[NEXT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[NEXT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[NEXT_TETROMINOS], list);
    free(tetrominos);
}