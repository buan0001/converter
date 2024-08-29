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
    printf("Press (t) to convert temperatures\n");
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