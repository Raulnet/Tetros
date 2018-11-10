#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enum.h"
#include "assets.h"
#include "list.h"
#include "tetrominos.h"
#include "motorRender.h"
#include "game.h"
#include "move.h"

int main() {

    SDL_Event event;
    int loopScreen = 1;
    SDL_Surface *pSurfaces[NB_ASSET_SURFACES] = {0};
    Tetrominos *pTetrominos[2] = {0};
    int pit[PIT_NB_BLOCKS_HEIGHT][PIT_NB_BLOCKS_WIDTH];
    int level[10];
    Uint32 timeFrame = 0, currentTime = 0, previousTime = 0;

    SDL_Init(SDL_INIT_VIDEO);
    List *list = initList();
    initPit(pit);
    initLevel(level);
    initAssetSurfaces(pSurfaces);
    initTetrominos(pTetrominos, list);

    while (loopScreen) {
        currentTime = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            handleEvent(event, &loopScreen, pTetrominos, list, pit);
        }
        if (currentTime - previousTime > level[LEVEL_5]) {
            moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, GO_BOTTOM);
            previousTime = currentTime;
        }
        if(pTetrominos[CURRENT_TETROMINOS]->onLock) {
            lockTetrominos(pTetrominos[CURRENT_TETROMINOS], pit);
            swapTetrominos(pTetrominos, list);
        }
        if(currentTime-timeFrame > TIME_FRAME) {
            renderFrame(pit, pSurfaces, pTetrominos);
            timeFrame = currentTime;
        } else {
            SDL_Delay(TIME_FRAME - (currentTime-timeFrame));
        }
    }

    SDL_Quit();

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