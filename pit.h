#include <SDL/SDL.h>
#include "enum.h"

#ifndef TETRIS_PIT_H
#define TETRIS_PIT_H

void initPit(int (*pit)[PIT_NB_BLOCKS_WIDTH]);
void renderPit(int (*pit)[PIT_NB_BLOCKS_WIDTH], SDL_Surface **pSurfaces);

#endif //TETRIS_PIT_H
