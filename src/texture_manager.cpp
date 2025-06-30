#include "../include/texture_manager.h"

SDL_Texture* texture_manager::load(SDL_Renderer* rend, const std::string &path){
    SDL_Surface* surf = IMG_Load(path.c_str());
    SDL_Texture* text = SDL_CreateTextureFromSurface(rend, surf);
    SDL_FreeSurface(surf);

    return text;
}