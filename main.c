#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enum.h"
#include "assets.h"
#include "list.h"
#include "tetrominos.h"
#include "motorRender.h"
#include "game.h"
#include "move.h"
#include "pit.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Event event;
    int loopScreen = 1;
    SDL_Surface *pSurfaces[NB_ASSET_SURFACES] = {0};
    Tetrominos *pTetrominos[2] = {0};
    int pit[PIT_NB_BLOCKS_HEIGHT][PIT_NB_BLOCKS_WIDTH];
    int level[10];
    int currentLevel = LEVEL_1;
    int perfomance[PERFORMANCE_NB] = {0};
    Uint32 timeFrame = 0, currentTime = 0, previousTime = 0;
    TTF_Font *font = NULL;
    font = TTF_OpenFont("font/game_over.ttf", 82);



    List *list = initList();
    initPit(pit);
    initLevel(level);
    initAssetSurfaces(pSurfaces);
    initTetrominos(pTetrominos, list);
    // INIT PERFOMANCE
    perfomance[PERFORMANCE_SCORE] = 0;
    perfomance[PERFORMANCE_TOTAL_SCORE] = 0;
    perfomance[PERFORMANCE_LINE] = 0;
    perfomance[PERFORMANCE_COMBO] = 1;
    perfomance[PERFORMANCE_LEVEL] = 1;


    while (loopScreen) {
        currentTime = SDL_GetTicks();
        currentLevel = resolveLevel(perfomance[PERFORMANCE_LINE])+1;
        perfomance[PERFORMANCE_LEVEL] = currentLevel;
        while (SDL_PollEvent(&event)) {
            handleEvent(event, &loopScreen, pTetrominos, list, pit, perfomance);
        }
        if (currentTime - previousTime > level[currentLevel]) {
            moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, GO_BOTTOM, perfomance);
            previousTime = currentTime;
        }
        if(pTetrominos[CURRENT_TETROMINOS]->onLock) {
            lockTetrominos(pTetrominos[CURRENT_TETROMINOS], pit);
            swapTetrominos(pTetrominos, list);
            perfomance[PERFORMANCE_SCORE] ++;
            clearRowPit(pit, perfomance);
        }
        if(currentTime-timeFrame > TIME_FRAME) {
            renderFrame(pit, pSurfaces, pTetrominos, perfomance, font);
            timeFrame = currentTime;
            perfomance[PERFORMANCE_SCORE] = 0;
        } else {
            SDL_Delay(TIME_FRAME - (currentTime-timeFrame));
        }
    }

    SDL_Quit();

    TTF_CloseFont(font);
    TTF_Quit();

    if (list->last != NULL) {
        Element *currentElem = list->last;
        while (currentElem != NULL) {
            printf("%d\n", currentElem->id);
            currentElem = currentElem->previous;
        }
    }
    free(list);
    printf("done\n");
    return 0;
}