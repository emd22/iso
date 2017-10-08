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

    int win_w;
    int win_h;

    int world_x =0;
    int world_y = 0;
};

#endif