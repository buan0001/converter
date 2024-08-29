#include <stdio.h>
#include "temperature.h"
#include "temperature_ui.c"
#include <math.h>


// Terminalbaseret enhedskonvertering - skal kunne konvertere imellem celcius og fahrenheit
// Modtager 3 kommandoer, der definerer hvilken enhedstype vi modtager efterfølgende:
// fahr (f), celcius (c), exit (e)
// Forventer efterfølgende et tal, som skal konverteres


int main(){
    display_intro();
    handle_input();
    return 0;
}

void handle_input(){
     display_menu();
     // Infinite loop
     while (1)
     {
        char choice = get_choice();
        switch (choice){
        case 'c':{
            printf("Du valgte celsius. Indtast nu værdien du vil konvertere:");
            float celsius = get_value();
            float converted_fahr = celsius_to_fahrenheit(celsius);

            // FANCY way to adapt decimals to output:
            int celsius_decimals = count_decimal_places(celsius);
            int fahr_decimals = count_decimal_places(converted_fahr);
            char format[50];
            sprintf(format, "%%.%df celsius er tilsvarende %%.%df fahrenheit\n", celsius_decimals, fahr_decimals);
            printf(format, celsius, converted_fahr);

            // less fancy solution:

                // if (is_effectively_int(celsius)){
                //     printf("%.0f celsius er tilsvarende %.2f fahrenheit\n", celsius, converted_fahr);
                // }
                // else {
                // printf("%.2f celsius er tilsvarende %.2f fahrenheit\n", celsius, converted_fahr);
                // }
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
        case 'm':{
            display_menu();
            break;
            }
        case 'x':{
            printf("Tak for denne gang");
            return;}
        default:{
            printf("Choice: %c", choice);
            printf("Ugyldig kommando, prøv igen\n");
         }
         printf("Vælg en ny enhed at konvertere\n");
        }    
    }
}

int count_decimal_places(float value) {
    int count = 0;
    while (value != floorf(value)) {
        value *= 10;
        count++;
    }
    return count;
}

int is_effectively_int(float value) {
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
