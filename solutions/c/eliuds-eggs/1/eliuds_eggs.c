#include "eliuds_eggs.h"

unsigned int bitcount (unsigned int num){

   unsigned int count = 0;
    
   while (num != 0) {

       if ((num & 1) > 0 ){
           count++;
       }
       num = num >> 1;
   }
    return count;
}

unsigned int egg_count(unsigned int EggsBi){
    
    unsigned int eggs = 0;
    eggs = bitcount(EggsBi);

    return eggs;

    
    
}