#include <stdio.h>
#include "temperature.h"
#include "temperature_ui.c"
#include "common.h"
#include "common.c"
#include "common_ui.c"

int temperature_main(){
    // printf("Choose the unit to convert from: ");
    display_temperature_menu();
    char choices[2];
    char valid_input[] = {'f', 'c', 'k'};
    if (get_unit_choices(choices, valid_input) == 0) {
        return 0;
    }

    // Repeat until break or return is hit
    while (1) {
        printf("Enter the value you want to convert: ");
        float input = get_value();
  
        if (choices[0] == 'f') {
            if (choices[1] == 'c') {
                print_temp_results(input, fahrenheit_to_celsius(input), "fahrenheit", "celsius");
            }
            else if (choices[1] == 'k') {
                print_temp_results(input, fahrenheit_to_kelvin(input), "fahrenheit", "kelvin");
            }
        }
        else if (choices[0] == 'c') {
            if (choices[1] == 'f') {
                print_temp_results(input, celsius_to_fahrenheit(input), "celsius", "fahrenheit");
            }
            else if (choices[1] == 'k') {
                print_temp_results(input, celsius_to_kelvin(input), "celsius", "kelvin");
            }
        }
        else if (choices[0] == 'k') {
            if (choices[1] == 'f') {
                print_temp_results(input, kelvin_to_fahrenheit(input), "kelvin", "fahrenheit");
            }
            else if (choices[1] == 'c') {
                print_temp_results(input, kelvin_to_celsius(input), "kelvin", "celsius");
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
    temperature_main();
    return 0;
}

float celsius_to_fahrenheit(float celsius){
    float fahr = (celsius * 9/5) + 32;
    return fahr;
}

float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

float fahrenheit_to_celsius(float fahr){
    float celsius = 5.0 / 9.0 * (fahr - 32);
    return celsius;
}

float fahrenheit_to_kelvin(float fahr) {
    float kelvin = 5.0 / 9.0 * (fahr - 32) + 273.15;
    return kelvin;
}

float kelvin_to_celsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

float kelvin_to_fahrenheit(float kelvin) {
    float fahr = (kelvin - 273.15) * 9/5 + 32;
    return fahr;
}