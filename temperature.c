#include <stdio.h>
#include "temperature.h"

// Terminalbaseret enhedskonvertering - skal kunne konvertere imellem celcius og fahrenheit
// Modtager 3 kommandoer, der definerer hvilken enhedstype vi modtager efterfølgende:
// fahr (f), celcius (c), exit (e)
// Forventer efterfølgende et tal, som skal konverteres


int main(){
    display_intro();
    // vis menu
    
    display_menu();
    // tag imod valg (se linje 5)
    char choice = get_choice();
    printf("Du indtastede %c\n", choice);
    // hvis (f) eller (c)
        
        // tag efterfølgende imod den tilsvarende enhedstype
        printf("Indtast temperatur i fahrenheit: ");
        float fahr = get_value();
        float celcius = fahrenheit_to_celsius(fahr);
        printf("\nDu indtastede: %f fahrenheit. Det svarer til %f grader celsius", fahr, celcius);
        // omregn fra enhedstypen til den modsatte

        // udskriv resultatet

    // hvis (x) så exit

    // ellers repeat

    return 0;
}

void display_menu(){
    printf("Vælg funktion\n");
    printf("(f) Fahrenheit til Celsius\n");
    printf("(c) Celsius til Fahrenheit\n");
    printf("(x) Exit\n");
}

void display_intro(){
    printf("Velkommen til dette temperaturkonverteringsprogram\n");
    printf("--------------------------------------------------\n");
}

float celsius_to_fahrenheit(float celsius){
    float fahr = (celsius * 9/5) + 32;
    return fahr;
}
float fahrenheit_to_celsius(float fahr){
    float celsius = 5.0 / 9.0 * (fahr - 32);
    return celsius;
}
char get_choice(){
    char choice;
    scanf("%s", &choice);
    return choice;
}
float get_value(){
    float value;
    scanf("%f", &value);
    return value;
}
