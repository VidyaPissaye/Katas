/* 
 * File:   Rover.h
 * Author: Vidya
 *
 * Created on March 30, 2013, 1:08 AM
 */

#ifndef ROVER_H
#define	ROVER_H

#include <iostream>

using namespace std;

class Grid;

struct Location {
    int x;
    int y;
};

class Rover {
    Location current_location;
    char direction_facing;
    
public:
    
    Rover() {
        current_location.x = 0;
        current_location.y = 0;
        direction_facing = 'N';
    }
   
    void set_position(Location & pos1, Location & pos2);
    Location move(char* command, Grid & grid);
    bool detect_obstacle(Location position, Grid & grid);
    void go_forward(Grid & grid);
    void go_backward(Grid & grid);
    void turn_left(Grid & grid);
    void turn_right(Grid & grid);
};

#endif	/* ROVER_H */

