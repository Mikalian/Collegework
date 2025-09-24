#include "high_scores.h"



int32_t latest(const int32_t *scores, size_t scores_len){
    
    return scores[scores_len - 1];
    
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t max = 0;
    for (size_t i = 0 ; i < scores_len ; i++) {

        if ( max < scores[i] ){
            max = scores[i];
        }
    }
    return max;
}


size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    int32_t first = 0;
    int32_t second = 0;
    int32_t third = 0;
    size_t count = 0;

    for (size_t i = 0; i < scores_len; i++) {
        int32_t val = scores[i];

        // check for first
        if (val >= first) {
            third = second;
            second = first;
            first = val;
        }

        // check for second
        if (val < first && val >= second) {
            third = second;
            second = val;
        }

        // check for third
        if (val < second && val >= third) {
            third = val;
        }
    }

    if (scores_len > 0) output[count++] = first;
    if (scores_len > 1) output[count++] = second;
    if (scores_len > 2) output[count++] = third;

    return count;
}

    
