#include "../include/texture_manager.h"

TextureManager::TextureManager(SDL_Renderer* rend) {
    this->rend = rend;
}

TextureManager::TextureManager(SDL_Renderer* rend, const std::string& path) {
    this->rend = rend;

    this->load_texture(path);

    this->set_src_rect(0, 0, 0, 0);
    this->set_dest_rect(0, 0, TILE_SIZE, TILE_SIZE);
}

TextureManager::TextureManager(SDL_Renderer* rend, const std::string& path, const int x, const int y, const int w, const int h) {
    this->rend = rend;

    this->load_texture(path);

    this->set_src_rect(0, 0, 0, 0);
    this->set_dest_rect(x, y, w, h);
}

void TextureManager::set_dest_rect(int x, int y, int w, int h) {
    this->dest_rect = {x, y, w, h};
}

void TextureManager::set_src_rect(int x, int y, int w, int h) {
    this->src_rect = {x, y, w, h};
}

void TextureManager::draw() {
    SDL_RenderCopy(this->rend, this->texture, &this->src_rect, &this->dest_rect);
}

void TextureManager::draw(int x, int y, int w, int h) {
    this->set_dest_rect(x, y, w, h);
    this->draw();
}

void TextureManager::load_texture(const std::string& path) {
    SDL_Surface* surf = IMG_Load(path.c_str());
    this->texture = SDL_CreateTextureFromSurface(rend, surf);
    SDL_FreeSurface(surf);
}

TextureManager::~TextureManager() {
    SDL_DestroyTexture(this->texture);
}