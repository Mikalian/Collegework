#include "allergies.h"


allergen_list_t get_allergens(int allergy_score){
    
    allergen_list_t result = {0};
    
    int mask = 1;
    int i = 0;
    while (i < ALLERGEN_COUNT) {
        if (allergy_score & mask) {
            result.allergens[i] = true;
            result.count++;
        }
        i++;
        mask <<= 1;
    }

    return result;
    
}

bool is_allergic_to(allergen_t allergen_index, int allergy_score){
    allergen_list_t allergies = get_allergens(allergy_score);
    return allergies.allergens[allergen_index];
}