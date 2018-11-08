#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>

#include "list.h"
#include "tetrominos.h"
#include "enum.h"

Block *getNewBlock() {
    Block *block = malloc(sizeof(*block));
    block->next = NULL;
    block->nextDirection = NEUTRAL;
    block->content = CLEAR;
    return block;
}

Tetrominos *newTetrominos() {
    Tetrominos *tetrominos = malloc(sizeof(*tetrominos));
    tetrominos->img = GREY;
    tetrominos->positionX = 0;
    tetrominos->positionY = 0;
    tetrominos->orientation = TOP;
    tetrominos->templateTop = NULL;
    tetrominos->templateBottom = NULL;
    tetrominos->templateLeft = NULL;
    tetrominos->templateRight = NULL;

    return tetrominos;
}

void setTetrominosI(Tetrominos *tetrominos) {
    Block *horizontalBlock = getNewBlock();
    horizontalBlock->content = CLEAR;
    horizontalBlock->nextDirection = BOTTOM;
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    tetrominos->templateTop = horizontalBlock;
    tetrominos->templateBottom = horizontalBlock;

    Block *verticalBlock = getNewBlock();
    verticalBlock->content = CLEAR;
    verticalBlock->nextDirection = RIGHT;
    pushBlock(verticalBlock, CLEAR, RIGHT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, BOTTOM);

    tetrominos->templateLeft = verticalBlock;
    tetrominos->templateRight = verticalBlock;
}

void setTetrominosT(Tetrominos *tetrominos) {
    Block *horizontalTop = getNewBlock();
    horizontalTop->content = CLEAR;
    horizontalTop->nextDirection = BOTTOM;
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, BOTTOM);
    pushBlock(horizontalTop, CLEAR, LEFT);
    pushBlock(horizontalTop, BLOCK, LEFT);
    tetrominos->templateTop = horizontalTop;

    Block *horizontalBottom = getNewBlock();
    horizontalBottom->content = CLEAR;
    horizontalBottom->nextDirection = BOTTOM;
    pushBlock(horizontalBottom, CLEAR, BOTTOM);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, TOP);
    pushBlock(horizontalBottom, CLEAR, LEFT);
    pushBlock(horizontalBottom, BLOCK, LEFT);
    tetrominos->templateBottom = horizontalBottom;

    Block *verticalBlockRight = getNewBlock();
    verticalBlockRight->content = CLEAR;
    verticalBlockRight->nextDirection = RIGHT;
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, LEFT);
    pushBlock(verticalBlockRight, CLEAR, TOP);
    pushBlock(verticalBlockRight, BLOCK, TOP);

    tetrominos->templateRight = verticalBlockRight;

    Block *verticalBlockLeft = getNewBlock();
    verticalBlockLeft->content = CLEAR;
    verticalBlockLeft->nextDirection = RIGHT;
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, RIGHT);
    pushBlock(verticalBlockLeft, CLEAR, TOP);
    pushBlock(verticalBlockLeft, BLOCK, TOP);

    tetrominos->templateLeft = verticalBlockLeft;

}

void setTetrominosL(Tetrominos *tetrominos) {
    Block *horizontalTop = getNewBlock();
    horizontalTop->content = CLEAR;
    horizontalTop->nextDirection = BOTTOM;
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, BOTTOM);
    pushBlock(horizontalTop, CLEAR, LEFT);
    pushBlock(horizontalTop, CLEAR, LEFT);
    pushBlock(horizontalTop, BLOCK, LEFT);
    tetrominos->templateTop = horizontalTop;

    Block *horizontalBottom = getNewBlock();
    horizontalBottom->content = CLEAR;
    horizontalBottom->nextDirection = BOTTOM;
    pushBlock(horizontalBottom, CLEAR, BOTTOM);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, TOP);
    pushBlock(horizontalBottom, BLOCK, LEFT);
    tetrominos->templateBottom = horizontalBottom;

    Block *verticalBlockRight = getNewBlock();
    verticalBlockRight->content = BLOCK;
    verticalBlockRight->nextDirection = RIGHT;
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, LEFT);

    tetrominos->templateRight = verticalBlockRight;

    Block *verticalBlockLeft = getNewBlock();
    verticalBlockLeft->content = CLEAR;
    verticalBlockLeft->nextDirection = RIGHT;
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, RIGHT);
    pushBlock(verticalBlockLeft, BLOCK, TOP);

    tetrominos->templateLeft = verticalBlockLeft;

}

void setTetrominosJ(Tetrominos *tetrominos) {
    Block *horizontalTop = getNewBlock();
    horizontalTop->content = CLEAR;
    horizontalTop->nextDirection = BOTTOM;
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, RIGHT);
    pushBlock(horizontalTop, BLOCK, BOTTOM);
    pushBlock(horizontalTop, BLOCK, NEUTRAL);
    tetrominos->templateTop = horizontalTop;

    Block *horizontalBottom = getNewBlock();
    horizontalBottom->content = CLEAR;
    horizontalBottom->nextDirection = BOTTOM;
    pushBlock(horizontalBottom, CLEAR, BOTTOM);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, RIGHT);
    pushBlock(horizontalBottom, BLOCK, TOP);
    pushBlock(horizontalBottom, BLOCK, NEUTRAL);
    tetrominos->templateBottom = horizontalBottom;

    Block *verticalBlockRight = getNewBlock();
    verticalBlockRight->content = CLEAR;
    verticalBlockRight->nextDirection = RIGHT;
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, BOTTOM);
    pushBlock(verticalBlockRight, BLOCK, RIGHT);
    pushBlock(verticalBlockRight, CLEAR, TOP);
    pushBlock(verticalBlockRight, CLEAR, TOP);
    pushBlock(verticalBlockRight, BLOCK, NEUTRAL);

    tetrominos->templateRight = verticalBlockRight;

    Block *verticalBlockLeft = getNewBlock();
    verticalBlockLeft->content = CLEAR;
    verticalBlockLeft->nextDirection = RIGHT;
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, BOTTOM);
    pushBlock(verticalBlockLeft, BLOCK, LEFT);
    pushBlock(verticalBlockLeft, BLOCK, NEUTRAL);

    tetrominos->templateLeft = verticalBlockLeft;

}

void setTetrominosS(Tetrominos *tetrominos) {

    Block *horizontalBlock = getNewBlock();
    horizontalBlock->content = CLEAR;
    horizontalBlock->nextDirection = BOTTOM;
    pushBlock(horizontalBlock, CLEAR, BOTTOM);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, TOP);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, NEUTRAL);
    tetrominos->templateTop = horizontalBlock;
    tetrominos->templateBottom = horizontalBlock;

    Block *verticalBlock = getNewBlock();
    verticalBlock->content = BLOCK;
    verticalBlock->nextDirection = BOTTOM;
    pushBlock(verticalBlock, BLOCK, RIGHT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, NEUTRAL);

    tetrominos->templateLeft = verticalBlock;
    tetrominos->templateRight = verticalBlock;

}

void setTetrominosZ(Tetrominos *tetrominos) {

    Block *horizontalBlock = getNewBlock();
    horizontalBlock->content = CLEAR;
    horizontalBlock->nextDirection = BOTTOM;
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, BOTTOM);
    pushBlock(horizontalBlock, BLOCK, RIGHT);
    pushBlock(horizontalBlock, BLOCK, NEUTRAL);
    tetrominos->templateTop = horizontalBlock;
    tetrominos->templateBottom = horizontalBlock;

    Block *verticalBlock = getNewBlock();
    verticalBlock->content = CLEAR;
    verticalBlock->nextDirection = RIGHT;
    pushBlock(verticalBlock, CLEAR, RIGHT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, LEFT);
    pushBlock(verticalBlock, BLOCK, BOTTOM);
    pushBlock(verticalBlock, BLOCK, NEUTRAL);

    tetrominos->templateLeft = verticalBlock;
    tetrominos->templateRight = verticalBlock;

}

void setTetrominosO(Tetrominos *tetrominos) {
    Block *block = getNewBlock();
    block->content = CLEAR;
    block->nextDirection = RIGHT;
    pushBlock(block, CLEAR, BOTTOM);
    pushBlock(block, BLOCK, RIGHT);
    pushBlock(block, BLOCK, BOTTOM);
    pushBlock(block, BLOCK, LEFT);
    pushBlock(block, BLOCK, LEFT);

    tetrominos->templateTop = block;
    tetrominos->templateBottom = block;
    tetrominos->templateRight = block;
    tetrominos->templateLeft = block;
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

void setRandomTetrominos(Tetrominos *tetrominos, List *list) {
    int randomId = getRandomId();
    listUnshiftId(list, randomId);
    switch (randomId) {
        case I:
            tetrominos->img = RED;
            setTetrominosI(tetrominos);
            break;
        case J:
            tetrominos->img = BLUE;
            setTetrominosJ(tetrominos);
            break;
        case O:
            tetrominos->img = YELLOW;
            setTetrominosO(tetrominos);
            break;
        case T:
            tetrominos->img = AQUA;
            setTetrominosT(tetrominos);
            break;
        case L:
            tetrominos->img = ORANGE;
            setTetrominosL(tetrominos);
            break;
        case Z:
            tetrominos->img = GREEN;
            setTetrominosZ(tetrominos);
            break;
        case S:
            tetrominos->img = PINK;
            setTetrominosS(tetrominos);
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

void renderTetrominos(Tetrominos *tetrominos, SDL_Surface **pSurfaces) {
    SDL_Rect blockPosition;
    blockPosition.x = tetrominos->positionX;
    blockPosition.y = tetrominos->positionY;
    Block *currentBlock = NULL;
    if (tetrominos->orientation == TOP) {
        currentBlock = tetrominos->templateTop;
    }
    if (tetrominos->orientation == BOTTOM) {
        currentBlock = tetrominos->templateBottom;
    }
    if (tetrominos->orientation == RIGHT) {
        currentBlock = tetrominos->templateRight;
    }
    if (tetrominos->orientation == LEFT) {
        currentBlock = tetrominos->templateLeft;
    }
    if (currentBlock == NULL) {
        printf("failure next = NULL on Tetros %d", tetrominos->img);
        exit(EXIT_FAILURE);
    }
    do {
        if (currentBlock->content == BLOCK) {
            SDL_BlitSurface(pSurfaces[tetrominos->img], NULL, pSurfaces[SCREEN], &blockPosition);
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
