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
    int loopScreen = 1;
    SDL_Surface *pSurfaces[NB_ASSET_SURFACES] = {0};
    Tetrominos *pTetrominos[2] = {0};
    List *list = initList();

    initAssetSurfaces(pSurfaces);
    initTetrominos(pTetrominos, list);

    while (loopScreen) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                loopScreen = 0;
                break;
            case SDL_KEYDOWN:
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

        renderFrame(pSurfaces, pTetrominos);
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