#include <terrain/terrain.hpp>
#include <terrain/chunk.hpp>
#include <sprite.hpp>
#include <engine.hpp>

#include <stdio.h>

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

#define WIDTH 50
#define HEIGHT 50

Terrain::Terrain(Engine *engine) {
    _engine = engine;
    int tile_x = 0;
    int tile_y = 0;

    int x = -1000;
    int y = 200;

    std::vector<Tile> temp_tiles;

    tile_grass.load(engine->renderer, "./tile.png");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            
            tile_x += TILE_WIDTH*2;
            
            Tile tile;
            tile.x = x+tile_x-(TILE_WIDTH*j);
            tile.y = y+tile_y-((TILE_HEIGHT/2)*j);
            
            temp_tiles.push_back(tile);
        }
        tiles.push_back(temp_tiles);
        temp_tiles.clear();
        tile_y += (TILE_HEIGHT/2);
        tile_x = (TILE_WIDTH)*(i+1);
    }
}

void Terrain::draw() {
    // Image *tile;
    // for (int i = 0; i < HEIGHT; i++) {
    //     for (int j = 0; j < WIDTH; j++) {
    //         tile = &tiles[i][j];
    //         //std::printf("%d\n", tile->tile_y);
    //         //std::printf("tile tile_x:%d, tile_y:%d\n", tiles[i][j].tile_x, tiles[i][j].tile_y);
    //         //tile->tile_y = tile->tile_x;
    //         tile->draw();     
    //     }
    // }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (tiles[i][j].is_visible(_engine->win_w, _engine->win_h, _engine->world_x, _engine->world_y)) {
                tile_grass.x = tiles[i][j].x;
                tile_grass.y = tiles[i][j].y;
                //printf("x %d, y %d\n", tile_grass.x, tile_grass.y);
                tile_grass.draw();
            }
        }
    }
}

Terrain::~Terrain() {
    tile_grass.destroy();
}