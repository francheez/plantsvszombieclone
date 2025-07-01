#include "config.h"

class TextureManager {
public:
    TextureManager(SDL_Renderer* rend);
    TextureManager(SDL_Renderer* rend, const std::string& path);
    TextureManager(SDL_Renderer* rend, const std::string& path, int x, int y, int w, int h);

    void set_dest_rect(int x, int y, int w, int h);
    void set_src_rect(int x, int y, int w, int h);

    void draw();
    void draw(int x, int y, int w, int h);

    void load_texture(const std::string& path);

    ~TextureManager();

private:
    SDL_Renderer* rend;
    SDL_Texture* texture;
    SDL_Rect dest_rect;
    SDL_Rect src_rect;
};
