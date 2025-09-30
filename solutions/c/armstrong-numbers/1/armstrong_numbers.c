#include "armstrong_numbers.h"
#include <math.h>
bool is_armstrong_number(int candidate){
    int curr = 0;
    int sum_pow = 0; //Holds the sum of powers. (according to Armstrong)
    int power = count_digit (candidate);
    
    // Saves the current digits of the candidate number after removing the last digit (during the loop). We start from the        candidate number. 
    int curr_digits = candidate;

    float base = 0;
    
    for ( int i = 1 ; i < (power + 1) ; i++ ){
        base = (float) curr_digits / (float) pow( 10 , power - i ); 
        curr = pow( (int) base , power );
        sum_pow += curr;
        curr_digits %= (int) pow(10, power - i);
    }
    
    //Checks if the sum of powers is equal to the candidate number. Equal - TRUE, Not Equal - FALSE.
    if ( sum_pow == candidate ) { 
        return true;
    }
    else {
        return false;
    }
        
        
}


int count_digit (int num){
    int count = 0;
    if (num == 0) return 1;            
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
    
}