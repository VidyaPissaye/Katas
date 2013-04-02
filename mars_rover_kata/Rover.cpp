

#include "Rover.h"
#include "Grid.h"



Location Rover::move(char* command, Grid & grid) {
    
    int i = 0;
    
    int length = strlen(command);
    
    Location previous_location;
    
    while (i < length) {
        
        set_position(previous_location, current_location);
        
        if(command[i] == 'f') {
            go_forward(grid);
        }
        else if(command[i] == 'b') {
            go_backward(grid);
        }
        else if(command[i] == 'l') {
            turn_left(grid);
        } 
        else if(command[i] == 'r') {
            turn_right(grid);
        } 
        
        i++;
        
        if(detect_obstacle(current_location, grid)) {
            cout << "Obstacle found at (" << current_location.y << "," << current_location.x << ")" << endl;
            set_position(current_location, previous_location);
            break;
        }
    }
    
    return current_location;
}

void Rover::go_forward(Grid & grid) {
    if(direction_facing == 'N') {
        grid.go_North(current_location);
    }
    else if(direction_facing == 'S') {
        grid.go_South(current_location);
    } 
    else if(direction_facing == 'E') {
        grid.go_East(current_location);
    } 
    else if(direction_facing == 'W') {
        grid.go_West(current_location);
    } 
}

void Rover::go_backward(Grid & grid) {
    if(direction_facing == 'N') {
        grid.go_South(current_location);
    }
    else if(direction_facing == 'S') {
        grid.go_North(current_location);
    } 
    else if(direction_facing == 'E') {
        grid.go_West(current_location);
    } 
    else if(direction_facing == 'W') {
        grid.go_East(current_location);
    }     
}

void Rover::turn_left(Grid & grid) {
    if(direction_facing == 'N') {
        direction_facing = 'W';
    }
    else if(direction_facing == 'S') {
        direction_facing = 'E';
    } 
    else if(direction_facing == 'E') {
        direction_facing = 'N';
    } 
    else if(direction_facing == 'W') {
        direction_facing = 'S';
    }
}

void Rover::turn_right(Grid & grid) {
    if(direction_facing == 'N') {
        direction_facing = 'E';
    }
    else if(direction_facing == 'S') {
        direction_facing = 'W';                
    } 
    else if(direction_facing == 'E') {
        direction_facing = 'S';
    } 
    else if(direction_facing == 'W') {
        direction_facing = 'N';
    } 
}

void Rover::set_position(Location &pos1, Location &pos2) {
    pos1.x = pos2.x;
    pos1.y = pos2.y;
}

bool Rover::detect_obstacle(Location position, Grid & grid) {
    Location *obstacle = grid.get_obstacles();
    if((position.x == obstacle[0].x) && (position.y == obstacle[0].y)) {
        return true;
    }
    else {
        return false;
    }
}