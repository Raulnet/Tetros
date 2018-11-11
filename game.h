#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "tetrominos.h"
#include "list.h"
#include "enum.h"
#include "assets.h"
#include "motorRender.h"
#include "move.h"
#include "pit.h"

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

void launchGame();

void play(
        SDL_Surface **pSurfaces,
        TTF_Font *font
        );

int askPlayAgain(
        SDL_Surface **pSurfaces,
        TTF_Font *font
);

void done(
        SDL_Surface **pSurfaces,
        TTF_Font *font
);

void initLevel(int *level);

void initTetrominos(Tetrominos **pTetrominos, List *list);

void swapTetrominos(Tetrominos **pTetrominos, List *list);

void lockTetrominos(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH]);

int resolveLevel(int performanceLine);

#endif //TETRIS_GAME_H
