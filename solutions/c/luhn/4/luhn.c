#include "luhn.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 50

/*Extracts digits into a given array (must make sure the array is long enough for the digits)
returns 0 - FALSE if the given num string is not legal. 
returns the count of digits if everything is legal */
static int extract_and_validate(int arr[] , const char *num);
static int sum(int length, int arr[]);

bool luhn(const char *num){
    
    int buffer[MAX_DIGITS];
    memset(buffer, 0, sizeof(buffer));
    
    int digit_count = extract_and_validate(buffer ,num);
    if (!digit_count){
        return false;
    } 
    for (int i = digit_count - 1 ; i >= 0 ; i-- ) {  
        int position_from_right = digit_count - i;  
        int digit_value = buffer[i];

        if (position_from_right % 2 == 0) {
            digit_value = buffer[i] * 2;
            digit_value = (digit_value > 9) ? digit_value - 9 : digit_value;
        }
    buffer[i] = digit_value;
    }
    return !(sum(digit_count, buffer) % 10); //True if divisible by 10.
}

static int extract_and_validate(int arr[] , const char *num){

    //Checks for digits and SPACE.
    const char * curr = num;
    int num_count_index = 0;
    while (*curr != '\0'){
        if ((!isdigit(*curr) && *curr != ' ')){
            return 0; //FALSE
        }
        if (isdigit(*curr)){
            if (num_count_index >= MAX_DIGITS) return 0; 
            arr[num_count_index] = *curr - '0';
            num_count_index++;
        }
        curr++;
    }
    if (num_count_index < 2){
        return 0; //FALSE
    }
    return num_count_index;
}
static int sum(int length, int arr[]){
    
    int sum = 0;
    
    for (int i = 0 ; i < length ; i++){
        sum += arr[i];
    }
    return sum;
}
