#include "convert.h"
#include <stdio.h>

void display_intro(){
    printf("Welcome to this unit converter program\n");
    printf("--------------------------------------\n");
}

void ask_repeat(){
    printf("Press (n) to use new units\n");
    printf("Press (r) to return to the main menu\n");
    printf("Press any other key to enter a new value with the same units\n");
}

void display_main_menu(){
    printf("\n Main menu\n");
    printf("-------------\n");
    printf("\nPress (t) to convert temperatures\n");
    printf("Press (v) to convert volumes\n");
    printf("Press (p) to convert pressure\n");
    printf("Press (x) to exit\n");
}



char get_choice(){
    char choice;
    scanf(" %c", &choice);
    return choice;
}
float get_value(){
    float value;
    scanf("%f", &value);
    return value;
}

int get_choices(char *choices, validate_input_func validate_input){
    int same_values = 0;
    do {for (int i = 0; i < 2; i++)
        {
            if (i == 0) {
                printf("Choose the unit to convert from: ");
            }
            else {
                printf("Choose the unit to convert to: ");
            }
            int continueCheck = 1;
            while (continueCheck){
                choices[i] = get_choice();
                continueCheck = validate_input(choices[i]);
                if (continueCheck == 0) {
                    return 0;
                }
                else if (continueCheck == -1) {
                    printf("Invalid choice. Please try again.\n");
                }
                else {
                    continueCheck = 0;
                }
            }
        }
        if (choices[0] == choices[1]) {
            same_values = 1;
           printf("You have selected the same unit to convert from and to. Please select different units.\n");
        }
        else {
            same_values = 0;
        }
    } while (same_values);
    return 1;
}