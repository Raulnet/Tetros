#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>

#include "list.h"
#include "tetriminos.h"
#include "enum.h"

Block *getNewBlock() {
    Block *block = malloc(sizeof(*block));
    block->next = NULL;
    block->nextDirection = NEUTRAL;
    block->content = CLEAR;
    return block;
}

Tetriminos *newTetriminos() {
    Tetriminos *tetriminos = malloc(sizeof(*tetriminos));
    tetriminos->img = GREY;
    tetriminos->positionX = 0;
    tetriminos->positionY = 0;
    tetriminos->orientation = TOP;
    tetriminos->templateTop = NULL;
    tetriminos->templateBottom = NULL;
    tetriminos->templateLeft = NULL;
    tetriminos->templateRight = NULL;

    return tetriminos;
}

void setTetriminosI(Tetriminos *tetriminos) {
    Block *horizontalBlock = getNewBlock();
    horizontalBlock->content = CLEAR;
    horizontalBlock->nextDirection = BOTTOM;
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    tetriminos->templateTop = horizontalBlock;
    tetriminos->templateBottom = horizontalBlock;

    Block *verticalBlock = getNewBlock();
    verticalBlock->content = CLEAR;
    verticalBlock->nextDirection = RIGHT;
    pushBlock(verticalBlock, CLEAR, RIGHT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, BOTTOM);

    tetriminos->templateLeft = verticalBlock;
    tetriminos->templateRight = verticalBlock;
}

void setTetriminosT(Tetriminos *tetriminos) {
    Block *horizontalTop = getNewBlock();
    horizontalTop->content = CLEAR;
    horizontalTop->nextDirection = BOTTOM;
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, BOTTOM);
    pushBlock(horizontalTop, CLEAR, LEFT);
    pushBlock(horizontalTop, BLOCK, LEFT);
    tetriminos->templateTop = horizontalTop;

    Block *horizontalBottom = getNewBlock();
    horizontalBottom->content = CLEAR;
    horizontalBottom->nextDirection = BOTTOM;
    pushBlock(horizontalBottom, CLEAR, BOTTOM);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, TOP);
    pushBlock(horizontalBottom, CLEAR, LEFT);
    pushBlock(horizontalBottom, BLOCK, LEFT);
    tetriminos->templateBottom = horizontalBottom;

    Block *verticalBlockRight = getNewBlock();
    verticalBlockRight->content = CLEAR;
    verticalBlockRight->nextDirection = RIGHT;
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, LEFT);
    pushBlock(verticalBlockRight, CLEAR, TOP);
    pushBlock(verticalBlockRight, BLOCK, TOP);

    tetriminos->templateRight = verticalBlockRight;

    Block *verticalBlockLeft = getNewBlock();
    verticalBlockLeft->content = CLEAR;
    verticalBlockLeft->nextDirection = RIGHT;
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, RIGHT);
    pushBlock(verticalBlockLeft, CLEAR, TOP);
    pushBlock(verticalBlockLeft, BLOCK, TOP);

    tetriminos->templateLeft = verticalBlockLeft;

}

void setTetriminosL(Tetriminos *tetriminos) {
    Block *horizontalTop = getNewBlock();
    horizontalTop->content = CLEAR;
    horizontalTop->nextDirection = BOTTOM;
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, BOTTOM);
    pushBlock(horizontalTop, CLEAR, LEFT);
    pushBlock(horizontalTop, CLEAR, LEFT);
    pushBlock(horizontalTop, BLOCK, LEFT);
    tetriminos->templateTop = horizontalTop;

    Block *horizontalBottom = getNewBlock();
    horizontalBottom->content = CLEAR;
    horizontalBottom->nextDirection = BOTTOM;
    pushBlock(horizontalBottom, CLEAR, BOTTOM);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, TOP);
    pushBlock(horizontalBottom, BLOCK, LEFT);
    tetriminos->templateBottom = horizontalBottom;

    Block *verticalBlockRight = getNewBlock();
    verticalBlockRight->content = BLOCK;
    verticalBlockRight->nextDirection = RIGHT;
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, LEFT);

    tetriminos->templateRight = verticalBlockRight;

    Block *verticalBlockLeft = getNewBlock();
    verticalBlockLeft->content = CLEAR;
    verticalBlockLeft->nextDirection = RIGHT;
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, RIGHT);
    pushBlock(verticalBlockLeft, BLOCK, TOP);

    tetriminos->templateLeft = verticalBlockLeft;

}

void setTetriminosJ(Tetriminos *tetriminos) {
    Block *horizontalTop = getNewBlock();
    horizontalTop->content = CLEAR;
    horizontalTop->nextDirection = BOTTOM;
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, BOTTOM);
    pushBlock(horizontalTop, BLOCK, NEUTRAL);
    tetriminos->templateTop = horizontalTop;

    Block *horizontalBottom = getNewBlock();
    horizontalBottom->content = CLEAR;
    horizontalBottom->nextDirection = BOTTOM;
    pushBlock(horizontalBottom, CLEAR, BOTTOM);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, TOP);
    pushBlock(horizontalBottom, BLOCK, NEUTRAL);
    tetriminos->templateBottom = horizontalBottom;

    Block *verticalBlockRight = getNewBlock();
    verticalBlockRight->content = CLEAR;
    verticalBlockRight->nextDirection = RIGHT;
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, RIGHT);
    pushBlock(verticalBlockRight, CLEAR, TOP);
    pushBlock(verticalBlockRight, CLEAR, TOP);
    pushBlock(verticalBlockRight, BLOCK, NEUTRAL);

    tetriminos->templateRight = verticalBlockRight;

    Block *verticalBlockLeft = getNewBlock();
    verticalBlockLeft->content = CLEAR;
    verticalBlockLeft->nextDirection = RIGHT;
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, LEFT);
    pushBlock(verticalBlockLeft, BLOCK, NEUTRAL);

    tetriminos->templateLeft = verticalBlockLeft;

}

void setTetriminosS(Tetriminos *tetriminos) {

    Block *horizontalBlock = getNewBlock();
    horizontalBlock->content = CLEAR;
    horizontalBlock->nextDirection = BOTTOM;
    pushBlock(horizontalBlock, CLEAR, BOTTOM);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, TOP);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, NEUTRAL);
    tetriminos->templateTop = horizontalBlock;
    tetriminos->templateBottom = horizontalBlock;

    Block *verticalBlock = getNewBlock();
    verticalBlock->content = BLOCK;
    verticalBlock->nextDirection = BOTTOM;
    pushBlock(verticalBlock, BLOCK, RIGHT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, NEUTRAL);

    tetriminos->templateLeft = verticalBlock;
    tetriminos->templateRight = verticalBlock;

}

void setTetriminosZ(Tetriminos *tetriminos) {

    Block *horizontalBlock = getNewBlock();
    horizontalBlock->content = CLEAR;
    horizontalBlock->nextDirection = BOTTOM;
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, BOTTOM);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, NEUTRAL);
    tetriminos->templateTop = horizontalBlock;
    tetriminos->templateBottom = horizontalBlock;

    Block *verticalBlock = getNewBlock();
    verticalBlock->content = CLEAR;
    verticalBlock->nextDirection = RIGHT;
    pushBlock(verticalBlock, CLEAR, RIGHT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, LEFT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, NEUTRAL);

    tetriminos->templateLeft = verticalBlock;
    tetriminos->templateRight = verticalBlock;

}

void setTetriminosO(Tetriminos *tetriminos) {
    Block *block = getNewBlock();
    block->content = CLEAR;
    block->nextDirection = RIGHT;
    pushBlock(block, CLEAR, BOTTOM);
    pushBlock(block, BLOCK, RIGHT);
    pushBlock(block, BLOCK, BOTTOM);
    pushBlock(block, BLOCK, LEFT);
    pushBlock(block, BLOCK, LEFT);

    tetriminos->templateTop = block;
    tetriminos->templateBottom = block;
    tetriminos->templateRight = block;
    tetriminos->templateLeft = block;
}

int getRandomId() {
    unsigned long

            num_bins = (unsigned long) NB_TETROMINOS,
            num_rand = (unsigned long) RAND_MAX + 1,
            bin_size = num_rand / num_bins,
            defect = num_rand % num_bins;

    long x;
    do {
        x = random();
    } while (num_rand - defect <= (unsigned long) x);

    return (int) (x / bin_size);
}

void setRandomTetrominos(Tetriminos *tetriminos, List *list) {
    int randomId = getRandomId();
    listUnshiftId(list, randomId);
    switch (randomId) {
        case I:
            tetriminos->img = RED;
            setTetriminosI(tetriminos);
            break;
        case J:
            tetriminos->img = BLUE;
            setTetriminosJ(tetriminos);
            break;
        case O:
            tetriminos->img = YELLOW;
            setTetriminosO(tetriminos);
            break;
        case T:
            tetriminos->img = AQUA;
            setTetriminosT(tetriminos);
            break;
        case L:
            tetriminos->img = ORANGE;
            setTetriminosL(tetriminos);
            break;
        case Z:
            tetriminos->img = GREEN;
            setTetriminosZ(tetriminos);
            break;
        case S:
            tetriminos->img = PINK;
            setTetriminosS(tetriminos);
            break;
        default:
            exit(EXIT_FAILURE);
    }
}

void pushBlock(Block *block, int content, int nextDirection) {
    Block *newBlock = getNewBlock();
    newBlock->content = content;
    newBlock->nextDirection = nextDirection;
    if (block->next != NULL) {
        Block *currentBlock = block->next;
        while (currentBlock->next != NULL) {
            currentBlock = currentBlock->next;
        }
        currentBlock->next = newBlock;
    } else {
        block->next = newBlock;
    }
}

void renderTetriminos(Tetriminos *tetriminos, SDL_Surface **pSurfaces) {
    SDL_Rect blockPosition;
    blockPosition.x = tetriminos->positionX;
    blockPosition.y = tetriminos->positionY;
    Block *currentBlock = NULL;
    if (tetriminos->orientation == TOP) {
        currentBlock = tetriminos->templateTop;
    }
    if (tetriminos->orientation == BOTTOM) {
        currentBlock = tetriminos->templateBottom;
    }
    if (tetriminos->orientation == RIGHT) {
        currentBlock = tetriminos->templateRight;
    }
    if (tetriminos->orientation == LEFT) {
        currentBlock = tetriminos->templateLeft;
    }
    if (currentBlock == NULL) {
        printf("failure next = NULL on Tetros %d", tetriminos->img);
        exit(EXIT_FAILURE);
    }
    do {
        if (currentBlock->content == BLOCK) {
            SDL_BlitSurface(pSurfaces[tetriminos->img], NULL, pSurfaces[SCREEN], &blockPosition);
        }
        switch (currentBlock->nextDirection) {
            case TOP:
                blockPosition.y -= SIZE_BLOCK;
                break;
            case BOTTOM:
                blockPosition.y += SIZE_BLOCK;
                break;
            case RIGHT:
                blockPosition.x += SIZE_BLOCK;
                break;
            case LEFT:
                blockPosition.x -= SIZE_BLOCK;
                break;
            default:
                currentBlock = NULL;
                break;
        }
        if (currentBlock != NULL) {
            currentBlock = currentBlock->next;
        }

    } while (currentBlock != NULL);
}
