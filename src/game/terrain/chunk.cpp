#include <terrain/chunk.hpp>
#include <stdio.h>

bool Tile::is_visible(int win_w, int win_h, int world_x, int world_y) {
    int r = world_x+(win_w); /*right*/
    int l = world_x;         /*left*/
    int u = world_y;         /*up*/
    int d = world_y+(win_h); /*down*/
    
    if (x > r/1.2 || x < l || y < u || y > d/1.2) {
        //printf("%d x %d\n", r, d);
        return false;
    }
    else {
        return true;
    }
}