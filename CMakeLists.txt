cmake_minimum_required(VERSION 3.12)
project(Tetris C)

set(CMAKE_C_STANDARD 99)
set(SDL_INCLUDE_DIR /usr/include/SDL)
set(SDL_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL.so)
set(SDL_IMAGE_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL_image.so)
set(SDL_TTF_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL_ttf.so)
find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

add_executable(
        Tetris main.c
        game.c game.h
        enum.h
        tetrominos.c tetrominos.h
        assets.c assets.h
        list.c list.h
        motorRender.c motorRender.h
        pit.c pit.h
        move.c move.h)
target_link_libraries(Tetris ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARY} ${SDL_TTF_LIBRARY})