#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robot;
    robot.direction = direction;
    robot.position.x = x;
    robot.position.y = y;

    return robot;
}
void robot_move(robot_status_t *robot, const char *commands){
    const char * direct = commands;

    while (*direct != '\0') {

        if (*direct == 'R') {
             robot->direction = (robot->direction + 1) % 4; 
         }
        if (*direct == 'L') {
         robot->direction = (robot->direction + 3) % 4; 
         } 
        if (*direct == 'A') {
            
            switch (robot->direction) {
                    
                case DIRECTION_MAX:
                robot->direction = DIRECTION_NORTH;
                __attribute__((fallthrough)); 
                    
                case DIRECTION_NORTH:
                    robot->position.y += 1;
                    break;
                case DIRECTION_EAST:
                    robot->position.x += 1;
                    break;
                case DIRECTION_SOUTH:
                    robot->position.y -= 1;
                    break;
                case DIRECTION_WEST:
                    robot->position.x -=1;
                    break;   
                    
            }  
            
        }
        direct++;
     }
                
                
        
}
    
    

