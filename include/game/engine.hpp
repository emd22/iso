#ifndef ENGINE_HPP
#define ENGINE_HPP

#define TITLE "Ethan's Game"

struct SDL_Window;
struct SDL_Renderer;

class Engine {
public:
    Engine();
    void game_loop();
    ~Engine();
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif