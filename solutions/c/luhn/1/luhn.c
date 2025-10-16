#include "luhn.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*Checks if the number is a valid number, will also find and update the given int - `length` variable with the `length`
of the number itself without spaces*/
static bool is_number_valid(int *length, const char *num);
/* Fills the given buffer with the digits from the input string `num`. 
`buffer` must have size `length`. Spaces in `num` are skipped. */
static void insert_num_to_buffer(int buffer[], const char *num, int length);
static int sum(int length, int arr[]);

bool luhn(const char *num){
    

    int length = 0;
    if (!is_number_valid(&length, num)){
        return false;
    } 

    int buffer[length];
    memset(buffer, 0, sizeof(buffer));
    insert_num_to_buffer(buffer, num, length);


    for (int i = length - 1 ; i >= 0 ; i-- ) {
        
        int doubled = 0;

        if (length % 2) {
            doubled = (i % 2) ? buffer[i] * 2 : buffer[i];
            
        }
        else {
            doubled = !(i % 2) ? buffer[i] * 2 : buffer[i];
        }
     
        if(doubled <= 9) {
            buffer[i] = doubled;
        }
        else{
            buffer[i] = doubled - 9;
        }
    }
    return !(sum(length, buffer) % 10); //True if divisible by 10.
}

static bool is_number_valid(int * length, const char *num){

        
    

    //Checks for digits and SPACE.
    const char * curr = num;
    while (*curr != '\0'){
        if (!isdigit(*curr) && *curr != ' '){
            return false;
        }
             
        //If SPACE don't count it.
        if (*curr == ' '){
    
            curr++;
            //Skipping length++ to not count SPACE.
            continue; 
        }
        (*length) += 1;
        curr++;
        
    }
    //If number is too short
    if ((*length) < 2){
        return false;
    }
    
    return true;
}


static void insert_num_to_buffer(int buffer[], const char *num, int length){

    const char * curr = num;
    
    int i = 0;
    while (*curr != '\0' && i < length){
        if (*curr != ' '){
            buffer[i] = *curr - '0';
            i++;
        }
        curr++;
   }
}
        
static int sum(int length, int arr[]){
    
    int sum = 0;
    
    for (int i = 0 ; i < length ; i++){
        sum += arr[i];
    }
    return sum;
}
