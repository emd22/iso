#ifndef TERRAIN_HPP
#define TERRAIN_CPP

#include <vector>
#include <sprite.hpp>

struct Image;
struct Engine;

struct Tile {
    int x;
    int y;
};

class Terrain {
public:
    Terrain(Engine *engine);
    void draw();
    ~Terrain();

    int x = 0;
    int y = 0;
private:
    Image tile_grass;
    Engine *_engine;
    std::vector<std::vector<Tile> > tiles;
};

#endif