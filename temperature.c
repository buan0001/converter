#include <stdio.h>
#include "temperature.h"
#include "common.h"
// #include "temperature_ui.c"
// #include "common.c"
// #include "common_ui.c"

void temperature_main(char choices[]){
    float input;

    if (choices[0] == 'f') {
        input = get_value("fahrenheit");
        if (choices[1] == 'c') {
            print_results(input, fahrenheit_to_celsius(input), "fahrenheit", "celsius");
        }
        else if (choices[1] == 'k') {
            print_results(input, fahrenheit_to_kelvin(input), "fahrenheit", "kelvin");
        }
    }
    else if (choices[0] == 'c') {
        input = get_value("celsius");
        if (choices[1] == 'f') {
            print_results(input, celsius_to_fahrenheit(input), "celsius", "fahrenheit");
        }
        else if (choices[1] == 'k') {
            print_results(input, celsius_to_kelvin(input), "celsius", "kelvin");
        }
    }
    else if (choices[0] == 'k') {
        input = get_value("kelvin");
        if (choices[1] == 'f') {
            print_results(input, kelvin_to_fahrenheit(input), "kelvin", "fahrenheit");
        }
        else if (choices[1] == 'c') {
            print_results(input, kelvin_to_celsius(input), "kelvin", "celsius");
        }
    }
        
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