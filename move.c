#include "move.h"

void handleEvent(
        SDL_Event event,
        int *loopScreen,
        Tetrominos **pTetrominos,
        List *list,
        int (*pit)[PIT_NB_BLOCKS_WIDTH]
) {
    switch (event.type) {
        case SDL_QUIT:
            *loopScreen = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    *loopScreen = 0;
                    break;
                case SDLK_DOWN:
                    moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, FLIP_RIGHT);
                    break;
                case SDLK_UP:
                    moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, FLIP_LEFT);
                    break;
                case SDLK_RIGHT:
                    moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, GO_RIGHT);
                    break;
                case SDLK_LEFT:
                    moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, GO_LEFT);
                    break;
                case SDLK_SPACE:
                    swapTetrominos(pTetrominos, list);
                    // dropTetrominos(pTetrominos[CURRENT_TETROMINOS], pit);
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

void moveTetrominos(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH], int move) {
    if (availableToMove(tetrominos, pit, move)) {
        switch (move) {
            case GO_LEFT:
                tetrominos->positionX -= SIZE_BLOCK;
                break;
            case GO_RIGHT:
                tetrominos->positionX += SIZE_BLOCK;
                break;
            case GO_BOTTOM:
                tetrominos->positionY += SIZE_BLOCK;
                tetrominos->onLock = 0;
                break;
            case FLIP_RIGHT:
                tetrominos->orientation += 1;
                if (tetrominos->orientation > 3) {
                    tetrominos->orientation = 0;
                }
                break;
            case FLIP_LEFT:
                tetrominos->orientation -= 1;
                if (tetrominos->orientation < 0) {
                    tetrominos->orientation = 3;
                }
                break;
            default:
                break;
        }
    } else {
        if(move == GO_BOTTOM) {
            tetrominos->onLock = 1;
        }
    }

}

int availableToMove(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH], int move) {

    Block *currentBlock = NULL;
    int orientation = tetrominos->orientation;

    switch (move) {
        case FLIP_LEFT:
            orientation += 1;
            if (orientation > 3) {
                orientation = 0;
            }
            break;
        case FLIP_RIGHT:
            orientation -= 1;
            if (orientation < 0) {
                orientation = 3;
            }
            break;
        default:
            break;
    }
    printf("orientation %d\n", orientation);
    switch (orientation) {
        case TOP:
            printf("ORIENTATION TOP\n");
            currentBlock = tetrominos->templateTop;
            break;
        case RIGHT:
            printf("ORIENTATION RIGHT\n");
            currentBlock = tetrominos->templateRight;
            break;
        case BOTTOM:
            printf("ORIENTATION BOTTOM\n");
            currentBlock = tetrominos->templateBottom;
            break;
        case LEFT:
            printf("ORIENTATION LEFT\n");
            currentBlock = tetrominos->templateLeft;
            break;
        default:
            break;
    }
    int row = 0;
    int column = 0;
    int positionY = tetrominos->positionY - PIT_Y_ZERO - SIZE_BLOCK;
    int positionX = tetrominos->positionX - PIT_X_ZERO;
    switch (move) {
        case GO_RIGHT:
            row = positionY / SIZE_BLOCK;
            column = (positionX + SIZE_BLOCK) / SIZE_BLOCK;
            break;
        case GO_BOTTOM:
            row = (positionY + SIZE_BLOCK) / SIZE_BLOCK;
            column = positionX / SIZE_BLOCK;
            break;
        case GO_LEFT:
            row = positionY / SIZE_BLOCK;
            column = (positionX - SIZE_BLOCK) / SIZE_BLOCK;
            break;
        default:
            row = positionY / SIZE_BLOCK;
            column = positionX / SIZE_BLOCK;
            break;
    }
    printf("START => row: %d, column: %d\n", row, column);
    while (currentBlock != NULL) {
        if (currentBlock->content == BLOCK) {
            printf("block => row: %d, column: %d\n", row, column);
            if (column > PIT_NB_BLOCKS_WIDTH - 1 && move != GO_LEFT) {
                printf("GO RIGHT, column: %d, PitBlockWith: %d, row: %d, column: %d\n", column, PIT_NB_BLOCKS_WIDTH,
                       row, column);
                return 0;
            }
            if (column < 0 && move != GO_RIGHT) {
                printf("GO LEFT, column: %d, PitBlockWith: %d, row: %d, column: %d\n", column, PIT_NB_BLOCKS_WIDTH, row,
                       column);
                return 0;
            }
            if (row > PIT_NB_BLOCKS_HEIGHT - 1 && move == GO_BOTTOM) {
                printf("STOP BOTTOM\n");
                return 0;
            }
            if(pit[row][column] != EMPTY && row >=0) {
                printf("row: %d, column: %d\n", row, column);
                printf("rowcolum:%d\n", pit[row][column]);
                return 0;
            }
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
    return 1;
}


