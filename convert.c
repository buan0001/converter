#include <stdio.h>
#include "convert.h"
#include "common.h"
// #include "common_ui.c"
// #include "convert_ui.c"
// #include "temperature.c"

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
            temperature_main();
            break;
        case 'v':
            // volume_main();
            volume_main();
            break;
        case 'p':
            pressure_main();
            break;
        case 'x':
            printf("Bye!!!");
            return 0;
        default:
            printf("\n %c isn't a valid input. Please try again.\n", choice);
        }
    }
}