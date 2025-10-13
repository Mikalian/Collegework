#include "triangle.h"

static int check_legal(triangle_t sides);

int is_scalene(triangle_t sides){
    if (check_legal(sides)){
         //return 1 if none are equal else 0
         return (sides.a != sides.b) && (sides.b != sides.c) && (sides.a != sides.c);
    } 
    else{
         return 0;
    }    
}

int is_isosceles(triangle_t sides){
    if (check_legal(sides)){
          //return 1 if at least two equal else 0
         return (sides.a == sides.b) || (sides.a == sides.c) || (sides.b == sides.c);
    } 
    else{
         return 0;
    }
}

int is_equilateral(triangle_t sides){
    if (check_legal(sides)){
          //returns 1 if all equal else 0
         return (sides.a == sides.b) && (sides.b == sides.c);
    } 
    else{
         return 0;
    }
}
//Checks if the triangle is a legal triangle
int check_legal(triangle_t sides){
    
    if ( (sides.a != 0 || sides.b != 0 || sides.c != 0) 
       &&
         (sides.a + sides.b >= sides.c)
       &&
         (sides.b + sides.c >= sides.a)
       &&
         (sides.a + sides.c >= sides.b)
       ) {
        return 1;
    }
    else {
        return 0;
    }    
}