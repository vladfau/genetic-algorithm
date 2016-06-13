#include "util.h"

uint8_t randr(uint8_t min, uint8_t max) {
    double scaled = (double)rand()/RAND_MAX;
    return (max - min + 1) * scaled + min;
}

char inverse(char ch) {
    return (ch == '1')? '0':'1';
}

float getChance() {
    return (float) rand() / (float) (RAND_MAX / 1.0);
}


