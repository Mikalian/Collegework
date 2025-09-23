#include "perfect_numbers.h"


kind classify_number(int number) {
    int isFactor = 1;
    int aliquot = 0;
    
    //Checks at the beginning if the number is valid positive integer else returns error
    if ( !number || number < 0 ) {
      return ERROR;
    }
        
    while (isFactor != number) {

        if (number % isFactor == 0) {

            aliquot += isFactor;    
        }
        isFactor++;
    }


    //Checks for PERFECT, ABUNDANT and DEFICIENT kind ---> returns kind.
    if (aliquot == number) {
        return PERFECT_NUMBER;
        }
    if (aliquot < number) {
        return DEFICIENT_NUMBER;
        }
    if (aliquot > number) {
        return ABUNDANT_NUMBER;
        }

   //Catches an error if all the conditions above are not met for some reason.
   return ERROR;
}
