#include "game.h"

void initLevel(int *level) {
    level[LEVEL_1] = LEVEL_1_SPEED;
    level[LEVEL_2] = LEVEL_2_SPEED;
    level[LEVEL_3] = LEVEL_3_SPEED;
    level[LEVEL_4] = LEVEL_4_SPEED;
    level[LEVEL_5] = LEVEL_5_SPEED;
    level[LEVEL_6] = LEVEL_6_SPEED;
    level[LEVEL_7] = LEVEL_7_SPEED;
    level[LEVEL_8] = LEVEL_8_SPEED;
    level[LEVEL_9] = LEVEL_9_SPEED;
    level[LEVEL_10] = LEVEL_10_SPEED;
}

void initTetrominos(Tetrominos **pTetrominos, List *list) {

    pTetrominos[CURRENT_TETROMINOS] = newTetrominos();
    pTetrominos[CURRENT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[CURRENT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[CURRENT_TETROMINOS], list);
    SDL_Delay(42);
    pTetrominos[NEXT_TETROMINOS] = newTetrominos();
    pTetrominos[NEXT_TETROMINOS]->positionX = DEFAULT_POSITION_NEXT_TETROMINOS_WIDTH;
    pTetrominos[NEXT_TETROMINOS]->positionY = DEFAULT_POSITION_NEXT_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[NEXT_TETROMINOS], list);
}

void lockTetrominos(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH]) {
    Block *currentBlock = NULL;
    switch (tetrominos->orientation) {
        case TOP:
            currentBlock = tetrominos->templateTop;
            break;
        case RIGHT:
            currentBlock = tetrominos->templateRight;
            break;
        case BOTTOM:
            currentBlock = tetrominos->templateBottom;
            break;
        case LEFT:
            currentBlock = tetrominos->templateLeft;
            break;
        default:
            break;
    }
    int positionY = tetrominos->positionY - PIT_Y_ZERO - SIZE_BLOCK;
    int positionX = tetrominos->positionX - PIT_X_ZERO;
    int row = positionY / SIZE_BLOCK;
    int column = positionX / SIZE_BLOCK;
    while (currentBlock != NULL) {
        if (currentBlock->content == BLOCK) {
            pit[row][column] = tetrominos->img;
        }
        switch (currentBlock->nextDirection) {
            case TOP:
                row -= 1;
                break;
            case BOTTOM:
                row += 1;
                break;
            case LEFT:
                column -= 1;
                break;
            case RIGHT:
                column += 1;
                break;
            default:
                break;
        }
        currentBlock = currentBlock->next;
    }

}

void swapTetrominos(Tetrominos **pTetrominos, List *list) {
    Tetrominos *tetrominos = pTetrominos[CURRENT_TETROMINOS];
    pTetrominos[CURRENT_TETROMINOS] = pTetrominos[NEXT_TETROMINOS];
    pTetrominos[CURRENT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[CURRENT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;

    pTetrominos[NEXT_TETROMINOS] = newTetrominos();
    pTetrominos[NEXT_TETROMINOS]->positionX = DEFAULT_POSITION_NEXT_TETROMINOS_WIDTH;
    pTetrominos[NEXT_TETROMINOS]->positionY = DEFAULT_POSITION_NEXT_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[NEXT_TETROMINOS], list);
    free(tetrominos);
}