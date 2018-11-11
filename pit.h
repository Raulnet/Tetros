#include <SDL/SDL.h>
#include "enum.h"

#ifndef TETRIS_PIT_H
#define TETRIS_PIT_H

void initPit(int (*pit)[PIT_NB_BLOCKS_WIDTH]);
void renderPit(int (*pit)[PIT_NB_BLOCKS_WIDTH], SDL_Surface **pSurfaces);
void clearRowPit(int (*pit)[PIT_NB_BLOCKS_WIDTH], int performance[PERFORMANCE_NB]);
void dropRow(int (*pit)[PIT_NB_BLOCKS_WIDTH], int rowCleared);

#endif //TETRIS_PIT_H
