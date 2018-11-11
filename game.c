#include "game.h"

void launchGame() {
    SDL_Event event;
    int loopScreen = 1;
    int playGame = 0;
    TTF_Font *font = TTF_OpenFont("font/game_over.ttf", 82);
    char welcome[20] = "WELCOME";
    char startGame[20] = "PRESS ENTER !!!";
    SDL_Surface *pSurfaces[NB_ASSET_SURFACES] = {0};
    SDL_Rect position;

    initAssetSurfaces(pSurfaces);

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
                    case SDLK_RETURN:
                        loopScreen = 0;
                        printf("PRESS ENTER OK :) \n");
                        playGame = 1;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        position.x = 0;
        position.y = 0;

        SDL_BlitSurface(pSurfaces[BACK_WRAPPER], NULL, pSurfaces[SCREEN], &position);
        SDL_BlitSurface(pSurfaces[UI_WRAPPER], NULL, pSurfaces[SCREEN], &position);

        renderPerformance(pSurfaces[SCREEN], font, position, 125, 250, welcome);
        renderPerformance(pSurfaces[SCREEN], font, position, 95, 290, startGame);
        SDL_Flip(pSurfaces[SCREEN]);

    }
    if (playGame) {
        play(pSurfaces, font);
    }

    done(pSurfaces, font);
    TTF_CloseFont(font);
    TTF_Quit();
}

void play(
        SDL_Surface **pSurfaces,
        TTF_Font *font
) {
    SDL_Event event;

    do {
        Tetrominos *pTetrominos[2] = {0};
        int pit[PIT_NB_BLOCKS_HEIGHT][PIT_NB_BLOCKS_WIDTH];
        int level[10];

        int perfomance[PERFORMANCE_NB] = {0};
        int currentLevel = 0;
        int loopScreen = 1;
        Uint32 timeFrame = 0, currentTime = 0, previousTime = 0;

        List *list = initList();
        initPit(pit);
        initLevel(level);

        initTetrominos(pTetrominos, list);
        // INIT PERFOMANCE
        perfomance[PERFORMANCE_SCORE] = 0;
        perfomance[PERFORMANCE_TOTAL_SCORE] = 0;
        perfomance[PERFORMANCE_LINE] = 0;
        perfomance[PERFORMANCE_COMBO] = 1;
        perfomance[PERFORMANCE_LEVEL] = 1;

        while (loopScreen) {
            currentTime = SDL_GetTicks();
            currentLevel = resolveLevel(perfomance[PERFORMANCE_LINE]) + 1;
            perfomance[PERFORMANCE_LEVEL] = currentLevel;
            while (SDL_PollEvent(&event)) {
                handleEvent(event, &loopScreen, pTetrominos, list, pit, perfomance);
            }
            if (currentTime - previousTime > level[currentLevel]) {
                moveTetrominos(pTetrominos[CURRENT_TETROMINOS], pit, GO_BOTTOM, perfomance);
                previousTime = currentTime;
            }
            if (pTetrominos[CURRENT_TETROMINOS]->onLock) {
                lockTetrominos(pTetrominos[CURRENT_TETROMINOS], pit);
                swapTetrominos(pTetrominos, list);
                if (!availableToMove(pTetrominos[CURRENT_TETROMINOS], pit, GO_BOTTOM)) {
                    loopScreen = 0;
                }
                perfomance[PERFORMANCE_SCORE]++;
                clearRowPit(pit, perfomance);
            }
            if (currentTime - timeFrame > TIME_FRAME) {
                renderFrame(pit, pSurfaces, pTetrominos, perfomance, font);
                timeFrame = currentTime;
                perfomance[PERFORMANCE_SCORE] = 0;
            } else {
                SDL_Delay(TIME_FRAME - (currentTime - timeFrame));
            }
        }

    } while (askPlayAgain(pSurfaces, font));
}

int askPlayAgain(
        SDL_Surface **pSurfaces,
        TTF_Font *font
) {
    int playAgain = 0;
    SDL_Event event;
    int loopScreen = 1;
    char tryAgain[20] = "TRY AGAIN ???";
    char pressEnter[20] = "PRESS ENTER/ESCAPE";
    SDL_Rect position;

    while (loopScreen) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                loopScreen = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        playAgain = 0;
                        loopScreen = 0;
                        break;
                    case SDLK_RETURN:
                        printf("PRESS ENTER TO PLAY AGAIN!!! \n");
                        playAgain = 1;
                        loopScreen = 0;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        position.x = 0;
        position.y = 0;

        SDL_BlitSurface(pSurfaces[BACK_WRAPPER], NULL, pSurfaces[SCREEN], &position);
        SDL_BlitSurface(pSurfaces[UI_WRAPPER], NULL, pSurfaces[SCREEN], &position);

        renderPerformance(pSurfaces[SCREEN], font, position, 100, 250, tryAgain);
        renderPerformance(pSurfaces[SCREEN], font, position, 45, 290, pressEnter);
        SDL_Flip(pSurfaces[SCREEN]);
    }
    return playAgain;
}

void done(
        SDL_Surface **pSurfaces,
        TTF_Font *font
) {
    char tanks[20] = "THANKS FOR PLAYING";
    char bye[20] = "SEE YOU SOON";
    SDL_Rect position;
    position.x = 0;
    position.y = 0;

    SDL_BlitSurface(pSurfaces[BACK_WRAPPER], NULL, pSurfaces[SCREEN], &position);
    SDL_BlitSurface(pSurfaces[UI_WRAPPER], NULL, pSurfaces[SCREEN], &position);

    renderPerformance(pSurfaces[SCREEN], font, position, 45, 300, tanks);
    renderPerformance(pSurfaces[SCREEN], font, position, 105, 350, bye);
    SDL_Flip(pSurfaces[SCREEN]);
    SDL_Delay(4000);
}

void initLevel(int *level) {
    level[LEVEL_1] = LEVEL_1_SPEED;
    level[LEVEL_2] = LEVEL_2_SPEED;
    level[LEVEL_3] = LEVEL_3_SPEED;
    level[LEVEL_4] = LEVEL_4_SPEED;
    level[LEVEL_5] = LEVEL_5_SPEED;
    level[LEVEL_6] = LEVEL_6_SPEED;
    level[LEVEL_7] = LEVEL_7_SPEED;
    level[LEVEL_8] = LEVEL_8_SPEED;
    level[LEVEL_9] = LEVEL_9_SPEED;
    level[LEVEL_10] = LEVEL_10_SPEED;
}

void initTetrominos(Tetrominos **pTetrominos, List *list) {

    pTetrominos[CURRENT_TETROMINOS] = newTetrominos();
    pTetrominos[CURRENT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[CURRENT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[CURRENT_TETROMINOS], list);
    SDL_Delay(42);
    pTetrominos[NEXT_TETROMINOS] = newTetrominos();
    pTetrominos[NEXT_TETROMINOS]->positionX = DEFAULT_POSITION_NEXT_TETROMINOS_WIDTH;
    pTetrominos[NEXT_TETROMINOS]->positionY = DEFAULT_POSITION_NEXT_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[NEXT_TETROMINOS], list);
}

void lockTetrominos(Tetrominos *tetrominos, int (*pit)[PIT_NB_BLOCKS_WIDTH]) {
    Block *currentBlock = NULL;
    switch (tetrominos->orientation) {
        case TOP:
            currentBlock = tetrominos->templateTop;
            break;
        case RIGHT:
            currentBlock = tetrominos->templateRight;
            break;
        case BOTTOM:
            currentBlock = tetrominos->templateBottom;
            break;
        case LEFT:
            currentBlock = tetrominos->templateLeft;
            break;
        default:
            break;
    }
    int positionY = tetrominos->positionY - PIT_Y_ZERO - SIZE_BLOCK;
    int positionX = tetrominos->positionX - PIT_X_ZERO;
    int row = positionY / SIZE_BLOCK;
    int column = positionX / SIZE_BLOCK;
    while (currentBlock != NULL) {
        if (currentBlock->content == BLOCK) {
            pit[row][column] = tetrominos->img;
        }
        switch (currentBlock->nextDirection) {
            case TOP:
                row -= 1;
                break;
            case BOTTOM:
                row += 1;
                break;
            case LEFT:
                column -= 1;
                break;
            case RIGHT:
                column += 1;
                break;
            default:
                break;
        }
        currentBlock = currentBlock->next;
    }

}

void swapTetrominos(Tetrominos **pTetrominos, List *list) {
    Tetrominos *tetrominos = pTetrominos[CURRENT_TETROMINOS];
    pTetrominos[CURRENT_TETROMINOS] = pTetrominos[NEXT_TETROMINOS];
    pTetrominos[CURRENT_TETROMINOS]->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    pTetrominos[CURRENT_TETROMINOS]->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;

    pTetrominos[NEXT_TETROMINOS] = newTetrominos();
    pTetrominos[NEXT_TETROMINOS]->positionX = DEFAULT_POSITION_NEXT_TETROMINOS_WIDTH;
    pTetrominos[NEXT_TETROMINOS]->positionY = DEFAULT_POSITION_NEXT_TETROMINOS_HEIGHT;
    setRandomTetrominos(pTetrominos[NEXT_TETROMINOS], list);
    free(tetrominos);
}

int resolveLevel(int performanceLine) {
    if (performanceLine >= 100) {
        return LEVEL_10;
    }
    if (performanceLine >= 90) {
        return LEVEL_9;
    }
    if (performanceLine >= 80) {
        return LEVEL_8;
    }
    if (performanceLine >= 70) {
        return LEVEL_7;
    }
    if (performanceLine >= 60) {
        return LEVEL_6;
    }
    if (performanceLine >= 50) {
        return LEVEL_5;
    }
    if (performanceLine >= 40) {
        return LEVEL_4;
    }
    if (performanceLine >= 30) {
        return LEVEL_3;
    }
    if (performanceLine >= 20) {
        return LEVEL_2;
    }
    return LEVEL_1;

}