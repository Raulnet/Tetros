//
// Created by raulnet on 08/11/18.
//

#include "pit.h"

void initPit(int (*pit)[PIT_NB_BLOCKS_WIDTH]) {
    for (int row = 0; row < PIT_NB_BLOCKS_HEIGHT; ++row) {
        for (int column = 0; column < PIT_NB_BLOCKS_WIDTH; ++column) {
            pit[row][column] = EMPTY;
        }
    }
}

void renderPit(int (*pit)[PIT_NB_BLOCKS_WIDTH], SDL_Surface **pSurfaces){
    int block = 0;
    SDL_Rect blockPosition;
    blockPosition.x = PIT_X;
    blockPosition.y = PIT_Y;
    for (int row = 0; row < PIT_NB_BLOCKS_HEIGHT; ++row) {
        for (int column = 0; column < PIT_NB_BLOCKS_WIDTH; ++column) {
           block = pit[row][column];
            if(block != EMPTY) {
                SDL_BlitSurface(pSurfaces[block], NULL, pSurfaces[SCREEN], &blockPosition);
            }
            blockPosition.x += SIZE_BLOCK;
        }
        blockPosition.x = PIT_X;
        blockPosition.y += 42;
    }
}

void clearRowPit(int (*pit)[PIT_NB_BLOCKS_WIDTH], int performance[4]){
    int countRowDroped = 0;
    int countBlock = 0;
    for (int row = 0; row < PIT_NB_BLOCKS_HEIGHT; ++row) {
        for (int column = 0; column < PIT_NB_BLOCKS_WIDTH; ++column) {
            if(pit[row][column] != CLEAR) {
                countBlock++;
            }
        }
        if(countBlock == PIT_NB_BLOCKS_WIDTH) {
            for (int column = 0; column < PIT_NB_BLOCKS_WIDTH; ++column) {
                pit[row][column] = CLEAR;
                performance[PERFORMANCE_SCORE] ++;
            }
            performance[PERFORMANCE_LINE]++;
            countRowDroped ++;
            dropRow(pit, row);
        }
        countBlock = 0;
    }
    if(countRowDroped > 0) {
        performance[PERFORMANCE_COMBO]*=countRowDroped;
    } else {
        performance[PERFORMANCE_COMBO] = 1;
    }
}

void dropRow(int (*pit)[PIT_NB_BLOCKS_WIDTH], int rowCleared) {
    for (int row = rowCleared; row >= 0 ; --row) {
        for (int column = 0; column < PIT_NB_BLOCKS_WIDTH; ++column) {
            int previousRow = row-1;
            if(previousRow >= 0) {
                pit[row][column] = pit[row-1][column];
            }
        }
    }
}
