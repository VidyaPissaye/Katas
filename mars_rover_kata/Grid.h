/* 
 * File:   Grid.h
 * Author: Vidya
 *
 * Created on March 30, 2013, 1:08 AM
 */

#ifndef GRID_H
#define	GRID_H
#include <iostream>
#include <vector>

#include "Rover.h"


class Grid {
    int dimension;
    Location *obstacles;
    
public:
    Grid(int dimension) : dimension(dimension) {
        obstacles = NULL; 
    }
    
    void wrap_around(int &val);
    void inject_obstacles(int x, int y);
    void check_grid_edge();
    void go_North(Location &loc);
    void go_South(Location &loc);
    void go_East(Location &loc);
    void go_West(Location &loc);
    Location* get_obstacles();
};

#endif	/* GRID_H */

