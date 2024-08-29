#include "temperature.c"
#include "convert.h"
#include "convert_ui.c"

int main(){
    display_intro();

    int should_continue = 1;
    while (should_continue)
    {
        display_main_menu();
        char choice = get_choice();
        switch (choice)
        {
        case 't':
            should_continue = temperature_main();
            break;
        case 'x':
            should_continue = 0;
            break;
        default:
            break;
        }
    }
}