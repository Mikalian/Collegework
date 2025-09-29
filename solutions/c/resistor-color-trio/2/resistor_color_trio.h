#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h> 


#define OHMS     0LL
#define KILOOHMS 1000LL
#define MEGAOHMS 1000000LL
#define GIGAOHMS 1000000000LL


typedef struct {
    long long value;
    long long unit;
} resistor_value_t;

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

resistor_value_t color_code(resistor_band_t band[]);


#endif

