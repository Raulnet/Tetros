#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    launchGame();
    SDL_Quit();



//    if (list->last != NULL) {
//        Element *currentElem = list->last;
//        while (currentElem != NULL) {
//            printf("%d\n", currentElem->id);
//            currentElem = currentElem->previous;
//        }
//    }
//    free(list);
    printf("done\n");
    return 0;
}