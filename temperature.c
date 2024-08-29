#include <stdio.h>
#include "temperature.h"
#include "temperature_ui.c"
#include <math.h>
#include "convert.h"
#include "convert_ui.c"


// Terminalbaseret enhedskonvertering - skal kunne konvertere imellem celcius og fahrenheit
// Modtager 3 kommandoer, der definerer hvilken enhedstype vi modtager efterfølgende:
// fahr (f), celcius (c), exit (e)
// Forventer efterfølgende et tal, som skal konverteres


int temperature_main(){
    printf("Choose the unit to convert from: ");
    display_menu();
    // Infinite loop
    char first_choice = get_choice();
    printf("Choose the unit to convert to: ");
    int continueCheck = shouldContinue(first_choice);
    if (continueCheck < 1) {return continueCheck;}
    char second_choice = get_choice();
    int repeat = 1;
    while (repeat) {
        switch (first_choice){
            case 'c':{
                printf("You selected celsius.:");
                float celsius = get_value();
                float converted_fahr = celsius_to_fahrenheit(celsius);

                // FANCY way to adapt decimals to output:
                int celsius_decimals = count_decimal_places(celsius);
                int fahr_decimals = count_decimal_places(converted_fahr);
                char format[50];
                sprintf(format, "%%.%df celsius er tilsvarende %%.%df fahrenheit\n", celsius_decimals, fahr_decimals);
                printf(format, celsius, converted_fahr);
                break;
            }
            case 'f':{
                printf("Du valgte fahrenheit. Indtast nu værdien du vil konvertere: ");
                float fahrenheit = get_value();
                float converted_celsius = fahrenheit_to_celsius(fahrenheit);
            
                int fahr_decimals = count_decimal_places(fahrenheit);
                int celsius_decimals = count_decimal_places(converted_celsius);
                char format[50];
                sprintf(format, "%%.%df celsius er tilsvarende %%.%df fahrenheit\n", celsius_decimals, fahr_decimals);
                printf(format, fahrenheit, converted_celsius);
                break;}
            case 'k': {

            }

        }
       ask_repeat();
       char shouldRepeat = get_choice();
       if (shouldRepeat == 'n') {
        repeat = 0;
       }
       else if (shouldRepeat == 'r') return;
    }
    temperature_main();
    return 0;
}

int shouldContinue(char input){

}

            // case 'm':{
            //     display_menu();
            //     break;
            //     }
            // case 'x':{
            //     printf("See you, bye!");
            //     return;
            //     }

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
float fahrenheit_to_celsius(float fahr){
    float celsius = 5.0 / 9.0 * (fahr - 32);
    return celsius;
}

float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

float fahrenheit_to_kelvin(float fahr) {
    float kelvin = 5.0 / 9.0 * (fahr - 32) + 273.15;
    return kelvin;
}
