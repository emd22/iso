#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <SDL2/SDL.h>

class Image {
public:
    Image() = default;
    Image(const Image &other);
    void load(SDL_Renderer *renderer, std::string image_path);
    void draw();
    void destroy();

    int x = 0;
    int y = 0;
    SDL_Rect texr;
    SDL_Texture *img = NULL;
    SDL_Renderer *_renderer;
private:
    int width;
    int height;
};

#endif