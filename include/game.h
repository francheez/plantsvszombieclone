#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "texture_manager.h"

class Game {
public:
    int init(const char* title, const int w, const int h);
    void run();

private:
    void define();

    void input();
    void draw();
    void vsync();

    void update();

    void clean();
    
    bool running = false;

    SDL_Window* window;
    SDL_Renderer* rend;

    Uint32 frame_start;
    Uint32 frame_time;
};

#endif