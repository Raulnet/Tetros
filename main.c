#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enum.h"
#include "assets.h"
#include "list.h"
#include "tetriminos.h"

int main() {

    SDL_Event event;
    SDL_Rect positionBackground;
    int loopScreen = 1;
    SDL_Surface *pSurfaces[NB_ASSET_SURFACES] = {0};
    List *list = initList();

    initAssetSurfaces(pSurfaces);

    Tetriminos *tetriminos = newTetriminos();
    tetriminos->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    tetriminos->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(tetriminos, list);

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
                        tetriminos->orientation += 1;
                        if (tetriminos->orientation > 3) {
                            tetriminos->orientation = 0;
                        }
                        break;
                    case SDLK_LEFT:
                        tetriminos->orientation -= 1;
                        if (tetriminos->orientation < 0) {
                            tetriminos->orientation = 3;
                        }
                        break;
                    case SDLK_SPACE:
                        setRandomTetrominos(tetriminos, list );
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

        positionBackground.x = 0;
        positionBackground.y = 0;

        SDL_BlitSurface(pSurfaces[BACKGROUND], NULL, pSurfaces[SCREEN], &positionBackground);

        renderTetriminos(tetriminos, pSurfaces);
        SDL_Flip(pSurfaces[SCREEN]);
    }
    SDL_Quit();

    if(list->last != NULL) {
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