#include "config.h"

class texture_manager {
public:
    static SDL_Texture* load(SDL_Renderer* rend, const std::string& path);
};
