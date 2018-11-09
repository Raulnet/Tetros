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

int main() {

    SDL_Event event;
    int loopScreen = 1, currentTime = 0, previousTime = 0;
    SDL_Surface *pSurfaces[NB_ASSET_SURFACES] = {0};
    Tetrominos *pTetrominos[2] = {0};
    int pit[PIT_NB_BLOCKS_HEIGHT][PIT_NB_BLOCKS_WIDTH];
    int level[10];
    List *list = initList();

    initPit(pit);
    initLevel(level);
    initAssetSurfaces(pSurfaces);
    initTetrominos(pTetrominos, list);

    while (loopScreen) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                loopScreen = 0;
                break;
            case SDL_KEYDOWN:
                printf("key down:\n");
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        loopScreen = 0;
                        break;
                    case SDLK_RIGHT:
                        pTetrominos[CURRENT_TETROMINOS]->orientation += 1;
                        if (pTetrominos[CURRENT_TETROMINOS]->orientation > 3) {
                            pTetrominos[CURRENT_TETROMINOS]->orientation = 0;
                        }
                        break;
                    case SDLK_LEFT:
                        pTetrominos[CURRENT_TETROMINOS]->orientation -= 1;
                        if (pTetrominos[CURRENT_TETROMINOS]->orientation < 0) {
                            pTetrominos[CURRENT_TETROMINOS]->orientation = 3;
                        }
                        printf("switch left:\n");
                        break;
                    case SDLK_SPACE:
                        swapTetrominos(pTetrominos, list);
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

        currentTime = SDL_GetTicks();
        if (currentTime - previousTime > level[LEVEL_5]) {
            dropTetrominos(pTetrominos[CURRENT_TETROMINOS]);
            previousTime = currentTime;
        }

        renderFrame(pit, pSurfaces, pTetrominos);
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