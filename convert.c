#include <stdio.h>
#include <string.h>
#include "convert.h"
#include "common.h"

int main(){
    display_intro();

    // Infinite loop - breaks when user chooses to exit
    while (1)
    {
        display_main_menu();
        char choice = get_choice();
        
        switch (choice)
        {
        case 't':
        case'v':
        case'p':
            unit_main(choice);
            break;
        case 'x':
            printf("Bye!!!");
            return 0;
        default:
            printf("\n %c isn't a valid input. Please try again.\n", choice);
        }
    }
}

int unit_main(char unit_type){
    
    char choices[2];
    char valid_input[3];
    switch (unit_type)
    {
        case 't':
            display_temperature_menu();
            char temp_valid_input[] = {'f', 'c', 'k'};
            memcpy(valid_input, temp_valid_input, sizeof(temp_valid_input));
            break;
        case 'v':
            display_volume_menu();
            char vol_valid_input[] = {'l', 'g', 't'};
            memcpy(valid_input, vol_valid_input, sizeof(vol_valid_input));
            break;
        case 'p':
            display_pressure_menu();
            char pressure_valid_input[] = {'b', 'p', 'k'};
            memcpy(valid_input, pressure_valid_input, sizeof(pressure_valid_input));
            break;
    }

    // // (r) has been entered while getting units - return to main menu
    if (get_unit_choices(choices, valid_input) == 0) {
        return 0;
    }

    // Repeat until break or return is hit
    while (1) {
        if (unit_type == 'v') {
            volume_main(choices);
        }
        else if (unit_type == 't'){
            temperature_main(choices);
        }
        else if (unit_type == 'p'){
            pressure_main(choices);
        }
        
       ask_repeat();
       char shouldRepeat = get_choice();

       // Get new units of the same type
       if (shouldRepeat == 'n') {
        unit_main(unit_type);
        // break;
       }
       // Returns to the "main menu"
       else if (shouldRepeat == 'r') return 0;
    }
    
    return 0;
}