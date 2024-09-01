#include <stdio.h>
#include "volume.h"
#include "common.h"
// #include "temperature_ui.c"
// #include "common.c"
// #include "common_ui.c"

int volume_main(){
    // printf("Choose the unit to convert from: ");
    display_volume_menu();
    char choices[2];
    char valid_input[] = {'l', 'g', 't'};
    if (get_unit_choices(choices, valid_input) == 0) {
        return 0;
    }

    // Repeat until break or return is hit
    while (1) {
        printf("Enter the value you want to convert: ");
        float input = get_value();
  
        if (choices[0] == 'l') {
            if (choices[1] == 'g') {
                print_results(input, liter_to_gallon(input), "liter", "gallon");
            }
            else if (choices[1] == 't') {
                print_results(input, liter_to_teaspoon(input), "liter", "teaspoon");
            }
        }
        else if (choices[0] == 'g') {
            if (choices[1] == 't') {
                print_results(input, gallon_to_teaspoon(input), "gallon", "teaspoon");
            }
            else if (choices[1] == 'l') {
                print_results(input, gallon_to_liter(input), "gallon", "liter");
            }
        }
        else if (choices[0] == 't') {
            if (choices[1] == 'l') {
                print_results(input, teaspoon_to_liter(input), "teaspoon", "liter");
            }
            else if (choices[1] == 'g') {
                print_results(input, teaspoon_to_gallon(input), "teaspoon", "gallon");
            }
        }
        // end of monster if clause
       ask_repeat();
       char shouldRepeat = get_choice();
       if (shouldRepeat == 'n') {
        break;
       }
       // returns to the "main menu"
       else if (shouldRepeat == 'r') return 0;
    }
    // if 'n' is pressed, exit the loop, call the function again, getting new units
    volume_main();
    return 0;
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
