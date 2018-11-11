#include "motorRender.h"


void renderFrame(
        int (*pit)[PIT_NB_BLOCKS_WIDTH],
        SDL_Surface **pSurfaces,
        Tetrominos **pTetrominos,
        int performance[5],
        TTF_Font *font
) {
    char wordsPerformance[20] = "";



    SDL_Rect position;
    position.x = 0;
    position.y = 0;

    SDL_BlitSurface(pSurfaces[BACK_WRAPPER], NULL, pSurfaces[SCREEN], &position);

    renderPit(pit, pSurfaces);

    renderTetrominos(pTetrominos[CURRENT_TETROMINOS], pSurfaces);

    SDL_BlitSurface(pSurfaces[UI_WRAPPER], NULL, pSurfaces[SCREEN], &position);


    renderTetrominos(pTetrominos[NEXT_TETROMINOS], pSurfaces);

    int totalScore = performance[PERFORMANCE_TOTAL_SCORE]+=(performance[PERFORMANCE_SCORE]*performance[PERFORMANCE_COMBO]);
    sprintf(wordsPerformance, "Score: %d", totalScore);
    Sint16 positionY = 60;
    int lineHeight = 50;
    renderPerformance(pSurfaces[SCREEN], font, position, 345, positionY, wordsPerformance);

    positionY = 320;
    sprintf(wordsPerformance, "Combo: %d", performance[PERFORMANCE_COMBO]);
    renderPerformance(pSurfaces[SCREEN], font, position, 448, positionY, wordsPerformance);

    positionY+= lineHeight;
    sprintf(wordsPerformance, "Lines: %d", performance[PERFORMANCE_LINE]);
    renderPerformance(pSurfaces[SCREEN], font, position, 448, positionY, wordsPerformance);

    positionY+= lineHeight;
    sprintf(wordsPerformance, "Level: %d", performance[PERFORMANCE_LEVEL]);
    renderPerformance(pSurfaces[SCREEN], font, position, 448, positionY, wordsPerformance);

    SDL_Flip(pSurfaces[SCREEN]);
}

void renderPerformance(
        SDL_Surface *screen,
        TTF_Font *font,
        SDL_Rect position,
        Sint16 positionX,
        Sint16 positionY,
        char *performance)
{
    SDL_Surface *textScore = NULL;
    SDL_Color shadow = {0, 0, 0};
    position.x =positionX;
    position.y = positionY;
    textScore = TTF_RenderText_Solid(font, performance, shadow);
    SDL_BlitSurface(textScore, NULL, screen, &position);

    SDL_Color white = {255, 255, 255};
    position.x -= 2;
    position.y -= 2;
    textScore = TTF_RenderText_Solid(font, performance, white);
    SDL_BlitSurface(textScore, NULL, screen, &position);
}