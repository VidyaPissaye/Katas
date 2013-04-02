
#include "Grid.h"

void Grid::wrap_around(int& val) {
    if(val >= dimension) {
        val = 0;
    }
    else if(val < 0) {
        val = dimension-1;
    }
}

void Grid::go_North(Location &loc) {
    loc.y += 1;
    
    if(loc.y >= dimension) {
        wrap_around(loc.y);
    }
}

void Grid::go_South(Location &loc) {
    loc.y -= 1;
    
    if(loc.y < 0) {
        wrap_around(loc.y);
    }
}

void Grid::go_East(Location &loc) {
    loc.x += 1;
    
    if(loc.x >= dimension) {
        wrap_around(loc.x);
    }
}

void Grid::go_West(Location &loc) {
    loc.x -= 1;
    
    if(loc.x < 0) {
        wrap_around(loc.x);
    }
}

void Grid::inject_obstacles(int x, int y) {
    int cols[10] = {0};
    int rows[10] = {0};
    
    int col = x, row = y, j = 0;
    while((col < dimension) && (row < dimension)) {
        cols[j] = col;
        rows[j] = row;
        j++;
        
        col = col*2;
        row = row*2;
    }
    
    if(row >= dimension) {
        row = row/2;
        while(col < dimension) {
            cols[j] = col;
            if(col > row) {
                rows[j] = col;
            }
            else {
                rows[j] = row;
            }
            j++;
            
            col = col*2;
        }
    }  
    else if(col >= dimension) {
        col = col/2;
        while(row < dimension) {
            rows[j] = row;
            if(row > col) {
                cols[j] = row;
            }
            else {
                cols[j] = col;
            }
            j++;
            
            row = row*2;
        }
    }
    
    int i=0;
    int len = sizeof(rows)/sizeof(int);
    Location* obs = new Location[len];
    
    while((i < len) && rows[i] > 0) {
        obs[i].x = cols[i];
        obs[i].y = rows[i];
        i++;
    }
    obstacles = obs;

}

Location* Grid::get_obstacles() {
    return obstacles;
}