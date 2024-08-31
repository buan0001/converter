#include <stdio.h>
#include "pressure.h"
#include "common.h"
// #include "temperature_ui.c"
// #include "common.c"
// #include "common_ui.c"

int pressure_main(){
    // printf("Choose the unit to convert from: ");
    display_pressure_menu();
    char choices[2];
    char valid_input[] = {'k', 'b', 'p'};
    if (get_unit_choices(choices, valid_input) == 0) {
        return 0;
    }

    // Repeat until break or return is hit
    while (1) {
        printf("Enter the value you want to convert: ");
        float input = get_value();
  
        if (choices[0] == 'k') {
            if (choices[1] == 'b') {
                print_results(input, kilopascal_to_bar(input), "kilopascal", "bar");
            }
            else if (choices[1] == 'p') {
                print_results(input, kilopascal_to_psi(input), "kilopascal", "psi");
            }
        }
        else if (choices[0] == 'b') {
            if (choices[1] == 'p') {
                print_results(input, bar_to_psi(input), "bar", "psi");
            }
            else if (choices[1] == 'k') {
                print_results(input, bar_to_kilopascal(input), "bar", "kilopascal");
            }
        }
        else if (choices[0] == 'p') {
            if (choices[1] == 'k') {
                print_results(input, psi_to_kilopascal(input), "psi", "kilopascal");
            }
            else if (choices[1] == 'b') {
                print_results(input, psi_to_bar(input), "psi", "bar");
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
    pressure_main();
    return 0;
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
