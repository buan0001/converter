

void display_temperature_menu(){
    printf("(f) Fahrenheit \n");
    printf("(c) Celsius\n");
    printf("(k) Kelvin\n");
    printf("(r) Return to the main menu\n");
    // printf("(m) To display this menu again\n");
    printf("(x) Exit\n");
}

void print_temp_results(float org_val, float converted_val, char from[], char to[]) {
    int org_decimals = count_decimal_places(org_val);
    int converted_decimals = count_decimal_places(converted_val);
    char format[50];
    sprintf(format, "%%.%df %s is equal to %%.%df %s\n", org_decimals, from, converted_decimals, to);
    printf(format, org_val, converted_val);
    printf("_____________________________\n\n");
    // printf("You have selected to convert from %c to %c.\n", from, to);
}