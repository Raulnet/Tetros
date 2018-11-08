#include "motorRender.h"


void renderFrame(SDL_Surface **pSurfaces, Tetriminos *tetriminos) {
    SDL_Rect positionBackground;
    positionBackground.x = 0;
    positionBackground.y = 0;

    SDL_BlitSurface(pSurfaces[BACK_WRAPPER], NULL, pSurfaces[SCREEN], &positionBackground);

    renderTetriminos(tetriminos, pSurfaces);

    SDL_BlitSurface(pSurfaces[UI_WRAPPER], NULL, pSurfaces[SCREEN], &positionBackground);

    SDL_Flip(pSurfaces[SCREEN]);
}