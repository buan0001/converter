#include "common.h"
#include <math.h>

int validate_input(char actual_input, char valid_input[]) {
    for (int i = 0; i < 3; i++) {
        if (valid_input[i] == actual_input) {
            return 1;
        }
    }
    if (actual_input == 'r') {
        return 0;
    }
    else {
        return -1;
    }
}


int count_decimal_places(float value) {
    int count = 0;
    // move the decimal one time to the right as long as the float to int conversion is lossy
    while (!is_effectively_int(value)) {
        value *= 10;
        count++;
    }
    return count;
}

int is_effectively_int(float value) {
    // checks if the float's 0's change the value of the number or not
    return (floorf(value) == value);
}