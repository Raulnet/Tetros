
#include "assets.h"
#include "enum.h"

void initAssetSurfaces(SDL_Surface **pSurfaces) {
    SDL_Init(SDL_INIT_VIDEO);
    pSurfaces[SCREEN] = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    pSurfaces[BACKGROUND] = IMG_Load("./img/backgrounds/background1.png");
    pSurfaces[BACK_WRAPPER] = IMG_Load("./img/backgrounds/back.png");
    pSurfaces[UI_WRAPPER] = IMG_Load("./img/backgrounds/wrapper_ui.png");
    pSurfaces[AQUA] = IMG_Load("./img/blocks/aqua.png");
    pSurfaces[AQUA_N] = IMG_Load("./img/blocks/aqua_n.png");
    pSurfaces[BLUE] = IMG_Load("./img/blocks/blue.png");
    pSurfaces[BLUE_N] = IMG_Load("./img/blocks/blue_n.png");
    pSurfaces[GREEN] = IMG_Load("./img/blocks/green.png");
    pSurfaces[GREEN_N] = IMG_Load("./img/blocks/green_n.png");
    pSurfaces[GREY] = IMG_Load("./img/blocks/grey.png");
    pSurfaces[GREY_N] = IMG_Load("./img/blocks/grey_n.png");
    pSurfaces[ORANGE] = IMG_Load("./img/blocks/orange.png");
    pSurfaces[ORANGE_N] = IMG_Load("./img/blocks/orange_n.png");
    pSurfaces[PINK] = IMG_Load("./img/blocks/pink.png");
    pSurfaces[PINK_N] = IMG_Load("./img/blocks/pink_n.png");
    pSurfaces[PURPLE] = IMG_Load("./img/blocks/purple.png");
    pSurfaces[PURPLE_N] = IMG_Load("./img/blocks/purple_n.png");
    pSurfaces[RED] = IMG_Load("./img/blocks/red.png");
    pSurfaces[RED_N] = IMG_Load("./img/blocks/red_n.png");
    pSurfaces[SKY] = IMG_Load("./img/blocks/sky.png");
    pSurfaces[SKY_N] = IMG_Load("./img/blocks/sky_n.png");
    pSurfaces[YELLOW] = IMG_Load("./img/blocks/yellow.png");
    pSurfaces[YELLOW_N] = IMG_Load("./img/blocks/yellow_n.png");
}
