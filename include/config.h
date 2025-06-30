#ifndef CONFIG_H
#define CONFIG_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <vector>

#define ORIGINAL_TILE_SIZE 32
#define TILE_SCALE 3
#define TILE_SIZE ORIGINAL_TILE_SIZE * TILE_SCALE

#define WIN_WIDTH 13 * TILE_SIZE
#define WIN_HEIGHT 8 * TILE_SIZE

#define FPS 60
#define FRAME_DELAY 1000 / FPS

#endif