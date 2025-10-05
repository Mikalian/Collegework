#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
    
    if (length == 0){

        return NULL;
        
    }
    
    int middle = length / 2;
    int right = length;
    int left = 0;
    while (arr[middle] != value) {

        if ( arr[middle] > value  ) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
        
        middle = ( right + left ) / 2;


        if ( middle < left || middle > right ) {
            return NULL; // Did not find.
            
        }
    }
            
    return &arr[middle];
}