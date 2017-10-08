#ifndef TERRAIN_HPP
#define TERRAIN_CPP

#include <vector>
#include <sprite.hpp>

struct Tile;

struct Image;
struct Engine;

class Terrain {
public:
    Terrain(Engine *engine);
    void draw();
    ~Terrain();
private:
    Image tile_grass;
    Engine *_engine;
    std::vector<std::vector<Tile> > tiles;
};

#endif