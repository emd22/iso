#ifndef CHUNK_HPP
#define CHUNK_HPP

class Tile {
public:
    bool is_visible(int win_w, int win_h, int world_x, int world_y);
    int x;
    int y;
};

#endif