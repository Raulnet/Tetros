#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "tetrominos.h"
#include "enum.h"
#include "pit.h"

#ifndef TETRIS_MOTORRENDER_H
#define TETRIS_MOTORRENDER_H

void renderFrame(
        int (*pit)[PIT_NB_BLOCKS_WIDTH],
        SDL_Surface **pSurfaces,
        Tetrominos **pTetrominos,
        int performance[PERFORMANCE_NB],
        TTF_Font *font
);
void renderPerformance(
        SDL_Surface *screen,
        TTF_Font *font,
        SDL_Rect position,
        Sint16 positionX,
        Sint16 positionY,
        char *performance
        );

#endif //TETRIS_MOTORRENDER_H
