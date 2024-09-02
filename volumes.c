#include <stdio.h>
#include "volume.h"
#include "common.h"
// #include "temperature_ui.c"
// #include "common.c"
// #include "common_ui.c"

void volume_main(char choices[]){
// void volume_main(char choices[], float input){
    // printf("Choose the unit to convert from: ");
    float input;

    if (choices[0] == 'l') {
        input = get_value("liter");
        if (choices[1] == 'g') {
            print_results(input, liter_to_gallon(input), "liter", "gallon");
        }
        else if (choices[1] == 't') {
            print_results(input, liter_to_teaspoon(input), "liter", "teaspoon");
        }
    }
    else if (choices[0] == 'g') {
        input = get_value("gallon");
        if (choices[1] == 't') {
            print_results(input, gallon_to_teaspoon(input), "gallon", "teaspoon");
        }
        else if (choices[1] == 'l') {
            print_results(input, gallon_to_liter(input), "gallon", "liter");
        }
    }
    else if (choices[0] == 't') {
        input = get_value("teaspoon");
        if (choices[1] == 'l') {
            print_results(input, teaspoon_to_liter(input), "teaspoon", "liter");
        }
        else if (choices[1] == 'g') {
            print_results(input, teaspoon_to_gallon(input), "teaspoon", "gallon");
        }
    }


}

float liter_to_gallon(float liter){
    return liter * 0.2641720524;
}
float liter_to_teaspoon(float liter){
    return liter * 0.2028841362 * 1000;
}
float gallon_to_teaspoon(float gallon){
    return gallon * 768;
}
float gallon_to_liter(float gallon){
    return gallon * 3.785411784;
}
float teaspoon_to_liter(float teaspoon){
    return teaspoon * 0.0049289216;
}
float teaspoon_to_gallon(float teaspoon){
    return teaspoon * 0.0013020833;
}
