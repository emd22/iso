#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include <sprite.hpp>

Image::Image(const Image &other) {
    x = other.x;
    y = other.y;
    width = other.width;  
    height = other.height;
    img = other.img;
    _renderer = other._renderer;    
    texr = other.texr;
}

void Image::load(SDL_Renderer *renderer, std::string image_path) {
    img = IMG_LoadTexture(renderer, image_path.c_str());
    SDL_QueryTexture(img, NULL, NULL, &width, &height);
    texr.x = x; 
    texr.y = y; 
    texr.w = width*2;
    texr.h = height*2;
    _renderer = renderer;
}

void Image::draw() {    
    texr.x = x;
    texr.y = y;
    //std::cout << "y:" << y << "\n";
    // copy the texture to the rendering context
    SDL_RenderCopy(_renderer, img, NULL, &texr);
}

void Image::destroy() {
    SDL_DestroyTexture(img);
}