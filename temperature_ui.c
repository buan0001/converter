

void display_menu(){
    printf("Vælg funktion\n");
    printf("(f) Fahrenheit til Celsius\n");
    printf("(c) Celsius til Fahrenheit\n");
    printf("(x) Exit\n");
    printf("(m) For at vise menuen igen\n");
}

void display_intro(){
    printf("Velkommen til dette temperaturkonverteringsprogram\n");
    printf("--------------------------------------------------\n");
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
