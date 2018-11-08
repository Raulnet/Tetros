#include "motorRender.h"


void renderFrame(SDL_Surface **pSurfaces, Tetrominos **pTetrominos) {
    SDL_Rect positionBackground;
    positionBackground.x = 0;
    positionBackground.y = 0;

    SDL_BlitSurface(pSurfaces[BACK_WRAPPER], NULL, pSurfaces[SCREEN], &positionBackground);

    renderTetrominos(pTetrominos[CURRENT_TETROMINOS], pSurfaces);


    SDL_BlitSurface(pSurfaces[UI_WRAPPER], NULL, pSurfaces[SCREEN], &positionBackground);
    renderTetrominos(pTetrominos[NEXT_TETROMINOS], pSurfaces);


    SDL_Flip(pSurfaces[SCREEN]);
}