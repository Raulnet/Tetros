#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enum.h"
#include "tetriminos.h"

int main() {


    SDL_Surface *screen = NULL, *backGround = NULL;
    SDL_Event event;
    SDL_Rect positionBackground;
    int loopScreen = 1;
    int currentTetros = J;
    SDL_Surface *blockImg[20] = {0};
    Tetriminos *tetriminosList[NB_TETROMINOS] = {0};

    blockImg[AQUA] = IMG_Load("./img/blocks/aqua.png");
    blockImg[AQUA_N] = IMG_Load("./img/blocks/aqua_n.png");
    blockImg[BLUE] = IMG_Load("./img/blocks/blue.png");
    blockImg[BLUE_N] = IMG_Load("./img/blocks/blue_n.png");
    blockImg[GREEN] = IMG_Load("./img/blocks/green.png");
    blockImg[GREEN_N] = IMG_Load("./img/blocks/green_n.png");
    blockImg[GREY] = IMG_Load("./img/blocks/grey.png");
    blockImg[GREY_N] = IMG_Load("./img/blocks/grey_n.png");
    blockImg[ORANGE] = IMG_Load("./img/blocks/orange.png");
    blockImg[ORANGE_N] = IMG_Load("./img/blocks/orange_n.png");
    blockImg[PINK] = IMG_Load("./img/blocks/pink.png");
    blockImg[PINK_N] = IMG_Load("./img/blocks/pink_n.png");
    blockImg[PURPLE] = IMG_Load("./img/blocks/purple.png");
    blockImg[PURPLE_N] = IMG_Load("./img/blocks/purple_n.png");
    blockImg[RED] = IMG_Load("./img/blocks/red.png");
    blockImg[RED_N] = IMG_Load("./img/blocks/red_n.png");
    blockImg[SKY] = IMG_Load("./img/blocks/sky.png");
    blockImg[SKY_N] = IMG_Load("./img/blocks/sky_n.png");
    blockImg[YELLOW] = IMG_Load("./img/blocks/yellow.png");
    blockImg[YELLOW_N] = IMG_Load("./img/blocks/yellow_n.png");

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    Tetriminos *tetriminos = newTetriminos();
    tetriminos->positionX = DEFAULT_POSITION_TETROMINOS_WIDTH;
    tetriminos->positionY = DEFAULT_POSITION_TETROMINOS_HEIGHT;
    setRandomTetrominos(tetriminos);

    backGround = IMG_Load("./img/backgrounds/background1.png");
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
                        setRandomTetrominos(tetriminos);
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

        positionBackground.x = 0;
        positionBackground.y = 0;

        SDL_BlitSurface(backGround, NULL, screen, &positionBackground);

        renderTetriminos(tetriminos, blockImg, screen);
        SDL_Flip(screen);
    }
    SDL_Quit();

    printf("done\n");
    return 0;
}