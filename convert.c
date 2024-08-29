#include "temperature.c"
#include "convert.h"
#include "convert_ui.c"

int main(){
    display_intro();
    display_main_menu();
    char choice = get_choice();
    temperature_main();
}