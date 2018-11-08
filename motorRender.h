#include <SDL/SDL_image.h>
#include "list.h"
#include "tetrominos.h"
#include "enum.h"

#ifndef TETRIS_MOTORRENDER_H
#define TETRIS_MOTORRENDER_H

void renderFrame(SDL_Surface **pSurfaces, Tetrominos **pTetrominos);

#endif //TETRIS_MOTORRENDER_H
