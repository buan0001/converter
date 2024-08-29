#include <stdio.h>
#include "temperature.h"
#include "temperature_ui.c"
#include <math.h>
#include "convert.h"
// #include "convert_ui.c"


// Terminalbaseret enhedskonvertering - skal kunne konvertere imellem celcius og fahrenheit
// Modtager 3 kommandoer, der definerer hvilken enhedstype vi modtager efterfølgende:
// fahr (f), celcius (c), exit (e)
// Forventer efterfølgende et tal, som skal konverteres


int temperature_main(){
    // printf("Choose the unit to convert from: ");
    display_temperature_menu();
    char choices[2];
    if (get_choices(choices, validate_input_temperature) == 0) {
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
    // if 'n' is pressed, call the function again, getting new units
    temperature_main();
    return 0;
}



int validate_input_temperature(char input){
    if (input == 'f' || input == 'c' || input == 'k') {
        return 1;
    }
    else if (input == 'r') {
        return 0;
    }
    else {
        return -1;
    }
}

            // case 'm':{
            //     display_menu();
            //     break;
            //     }
            // case 'x':{
            //     printf("See you, bye!");
            //     return;
            //     }
                    // switch (choices[0]){
        //     case 'c':{
        //         printf("You selected celsius.:");
        //         float celsius = get_value();
        //         float converted_fahr = celsius_to_fahrenheit(celsius);
        //         // FANCY way to adapt decimals to output:
        //         int celsius_decimals = count_decimal_places(celsius);
        //         int fahr_decimals = count_decimal_places(converted_fahr);
        //         char format[50];
        //         sprintf(format, "%%.%df celsius er tilsvarende %%.%df fahrenheit\n", celsius_decimals, fahr_decimals);
        //         printf(format, celsius, converted_fahr);
        //         break;
        //     }
        //     case 'f':{
        //         printf("Du valgte fahrenheit. Indtast nu værdien du vil konvertere: ");
        //         float fahrenheit = get_value();
        //         float converted_celsius = fahrenheit_to_celsius(fahrenheit);
        //         int fahr_decimals = count_decimal_places(fahrenheit);
        //         int celsius_decimals = count_decimal_places(converted_celsius);
        //         char format[50];
        //         sprintf(format, "%%.%df celsius er tilsvarende %%.%df fahrenheit\n", celsius_decimals, fahr_decimals);
        //         printf(format, fahrenheit, converted_celsius);
        //         break;}
        //     case 'k': {
        //     }
        // }

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