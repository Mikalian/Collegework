#include "isogram.h"
#include <stddef.h>

bool is_isogram(const char phrase[]){
    
    if (phrase == NULL) {
    return false; 
   }
    
    int counter[26] = {0};
    char curr = phrase[0];
    
    
    int i = 0;
    while ( curr != '\0' ){
        
        if ( curr >= 'a' && curr <= 'z' ){
        
            counter[curr - 'a'] += 1;
        }
            
        if ( curr >= 'A' && curr <= 'Z' ) {
            
            counter[curr - 'A'] += 1;
            
        }
        i++;
        curr = phrase[i];
        
    }

    for ( int j = 0 ; j < 26 ; j++ ){
        if ( counter[j] > 1 ){ //Checks if one letter appeared more than once.
            return false;
        }
    }

    return true; //If no letter that appears more than once was detected.
    
}