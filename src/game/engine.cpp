#include <SDL2/SDL.h>

#include <engine.hpp>
#include <terrain/terrain.hpp>

Engine::Engine() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    SDL_GL_SetSwapInterval(1);
    
    window = SDL_CreateWindow(
        TITLE,
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        1000, 
        650, 
        0
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 175, 0, 100, 255);
}

void Engine::game_loop() {
    Terrain terrain(this);

    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            return;
                            break;
                        case SDLK_d:
                            break;
                        case SDLK_a:
                            break;
                        case SDLK_w:
                            break;
                        case SDLK_s:
                            break;
                    }
                    break;
            }
        }

        SDL_RenderClear(renderer);
        terrain.draw();
        SDL_RenderPresent(renderer);
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}