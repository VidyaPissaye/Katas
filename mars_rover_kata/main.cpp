/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on March 30, 2013, 12:40 AM
 */

#include <cstdlib>
#include <iostream>
#include "Rover.h"
#include "Grid.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {   
    char command[100];
    Rover rover;
    int dimension;
    Location final_pos;
    
    cout << "Enter the dimension of the grid" << endl;
    cin >> dimension;
    
    Grid grid(dimension);
    
    grid.inject_obstacles(2,3);
    /*Location* obstacles = grid.get_obstacles();
    int length = sizeof(obstacles)/sizeof(Location);
    for(int k =0; k<length; k++) {
        cout << "Obstacles " << k << " is: " << obstacles[k].x << " & " << obstacles[k].y << endl;
    } */
    
    cout << "Enter the commands for the rover" << endl;
    cin >> command;
    
    final_pos = rover.move(command, grid);
    cout << "The rover is at (" << final_pos.y << "," << final_pos.x << ")" << endl;
    
}

