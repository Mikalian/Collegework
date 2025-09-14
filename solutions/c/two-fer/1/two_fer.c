#include "two_fer.h"
#include <stdio.h>

void two_fer(char *buffer, const char *name){


    if ( name == NULL ){ //If empty 
        name = "you";
    }
    snprintf(buffer ,100, "One for %s, one for me." , name); 
    //Allows us to insert a string into the buffer without accidentally overflowing
    
}