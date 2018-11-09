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