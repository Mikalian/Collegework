#include "raindrops.h"
#include <string.h>
#include <stdio.h>

void convert(char result[], int drops){  

    result[0] = '\0';

    //If divisible by 3
    if (drops % 3 == 0) {
        strcat(result, "Pling");   
    }
    //If divisible by 5
    if (drops % 5 == 0) {
        strcat(result, "Plang"); 
    }
    //If divisible by 7
    if (drops % 7 == 0) {
        strcat(result, "Plong");
    }
    //If not divisible by 3, 5 or 7 length of the string would be 0
    if (strlen(result) == 0) { 
        //Inserts drops as string into the result array.
        sprintf(result, "%d", drops); 
        
    }    
}