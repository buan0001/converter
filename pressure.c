#include <stdio.h>
#include "pressure.h"
#include "common.h"
// #include "temperature_ui.c"
// #include "common.c"
// #include "common_ui.c"

void pressure_main(char choices[]){
    float input;

    if (choices[0] == 'k') {
        input = get_value("kilopascal");
        if (choices[1] == 'b') {
            print_results(input, kilopascal_to_bar(input), "kilopascal", "bar");
        }
        else if (choices[1] == 'p') {
            print_results(input, kilopascal_to_psi(input), "kilopascal", "psi");
        }
    }
    else if (choices[0] == 'b') {
        input = get_value("bar");
        if (choices[1] == 'p') {
            print_results(input, bar_to_psi(input), "bar", "psi");
        }
        else if (choices[1] == 'k') {
            print_results(input, bar_to_kilopascal(input), "bar", "kilopascal");
        }
    }
    else if (choices[0] == 'p') {
        input = get_value("psi");
        if (choices[1] == 'k') {
            print_results(input, psi_to_kilopascal(input), "psi", "kilopascal");
        }
        else if (choices[1] == 'b') {
            print_results(input, psi_to_bar(input), "psi", "bar");
        }
    }
}

float psi_to_kilopascal(float psi){
    return psi * 0.1450377377;
    }

float kilopascal_to_psi(float kpa){
    return kpa * 6.8947572932;
}

float bar_to_psi(float bar){
   return bar * 0.0689475729;
}

float psi_to_bar(float psi){
   return psi * 14.503773773;
}

float kilopascal_to_bar(float kpa){
   return kpa * 100;
}

float bar_to_kilopascal(float psi){
   return psi * 0.01;
}
