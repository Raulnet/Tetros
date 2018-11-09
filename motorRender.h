#include <SDL/SDL_image.h>
#include "list.h"
#include "tetrominos.h"
#include "enum.h"
#include "pit.h"

#ifndef TETRIS_MOTORRENDER_H
#define TETRIS_MOTORRENDER_H

void renderFrame(
        int (*pit)[PIT_NB_BLOCKS_WIDTH],
        SDL_Surface **pSurfaces,
        Tetrominos **pTetrominos
);

#endif //TETRIS_MOTORRENDER_H
