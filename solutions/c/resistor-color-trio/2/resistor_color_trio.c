#include "resistor_color_trio.h"
#include <stdio.h>

//recieves a band with 3 colors and then returns the ohms value.
resistor_value_t color_code(resistor_band_t band[]){
    resistor_value_t code;

    long long multiplier = 1;
    for (int i = 0; i < (int)band[2]; i++) {
        multiplier *= 10;
    }

    code.value = (band[0] * 10 + band[1]) * multiplier;

    
    if (code.value >= GIGAOHMS) {
       code.value /= GIGAOHMS;
       code.unit = GIGAOHMS;
    }
    else if (code.value >= MEGAOHMS) {
      code.value /= MEGAOHMS;
      code.unit = MEGAOHMS;
   }
    else if (code.value >= KILOOHMS) {
       code.value /= KILOOHMS;
       code.unit = KILOOHMS;
   }
    else {
       code.unit = OHMS;
   }

    return code;
}