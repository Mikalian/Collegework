#include "gigasecond.h"


void gigasecond(time_t input, char *output, size_t size){
    //Adds gigasecond
    time_t after_giga = input + 1000000000; 
    struct tm * gmt_time = gmtime(&after_giga);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", gmt_time);

    
}