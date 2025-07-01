#include "../include/game.h"

SDL_Texture *stone_texture, *light_grass_texture, *dark_grass_texture, *left_fence_texture, *fence_texture, *right_fence_texture;
SDL_Rect rect1, rect2;

int Game::init(const char* title, const int w, const int h) {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) return -1;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    rend = SDL_CreateRenderer(window, -1, render_flags);

    if(!window || !rend) return -1;

    define();

    running = true;

    return 0;
}

void Game::define() {
    // stone_texture = texture_manager::load(rend, "assets/textures/stone.png");
    // light_grass_texture = texture_manager::load(rend, "assets/textures/light_grass.png");
    // dark_grass_texture = texture_manager::load(rend, "assets/textures/dark_grass.png");
    // left_fence_texture = texture_manager::load(rend, "assets/textures/left_fence.png");
    // fence_texture = texture_manager::load(rend, "assets/textures/central_fence.png");
    // right_fence_texture = texture_manager::load(rend, "assets/textures/right_fence.png");
    
    rect1 = {0, 0, TILE_SIZE, TILE_SIZE};
} 

void Game::run() {
    while(running) {
        update();
    }
    clean();   
}

void Game::input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Game::draw() {
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderClear(rend);

    SDL_RenderCopy(rend, stone_texture, NULL, &rect1);
    SDL_RenderCopy(rend, light_grass_texture, NULL, &rect1);

    SDL_RenderPresent(rend);
}

void Game::vsync() {
    frame_time = SDL_GetTicks() - frame_start;

    if(FRAME_DELAY > frame_time) {
        SDL_Delay(FRAME_DELAY - frame_time);
    }
}

void Game::update() {
    frame_start = SDL_GetTicks();

    input();
    draw();
    vsync();
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);

    SDL_DestroyTexture(stone_texture);

    SDL_Quit();
}