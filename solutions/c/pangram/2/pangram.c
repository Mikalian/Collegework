#include "pangram.h"

bool is_pangram(const char *sentence){
    //Initializes an array of 26 zero's.
    int lett_presence[26] = {0}; 
    int curr_index = 0;
    char letter = '0';

    if (!sentence) return false; //If sentence NULL


    for (int i = 0 ; sentence[i] != '\0' ; i++) {

        letter = sentence[i];
     //Using ASCII logic to point to the correct letter position and place 1.
        if (letter >= 'A' && letter <= 'Z'){
            lett_presence[letter - 'A'] = 1;
        }
        if (letter >= 'a' && letter <= 'z'){
            lett_presence [letter - 'a'] = 1;
        }   
    }

    //Checks 1's in lett_presence in order to determine if the input sentence contained all 26 letters.
    for (curr_index = 0; curr_index < 26; curr_index++) {
    if (lett_presence[curr_index] == 0) {
        return false; // found a missing letter
    }
   }
    return true; // all letters are present
    
}