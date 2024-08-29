#include "convert.h"

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
            temperature_main();
            break;
        case 'p':
            temperature_main();
            break;
        case 'x':
            return 0;
        default:
            printf("\n %c isn't valid. Please try again.\n", choice);
        }
    }
}