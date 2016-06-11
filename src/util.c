#include "util.h"

void print_str(uint8_t * str) {
    for (uint8_t i = 0; i < sizeof(str)/sizeof(uint8_t); i++) printf("%"SCNu8, str[i]);
}

