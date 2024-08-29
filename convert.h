typedef int (*validate_input_func)(char);
void display_intro();

void display_main_menu();

int temperature_main();
void ask_repeat();

float get_value();

int shouldContinue(char input);

int is_effectively_int(float value);
int count_decimal_places(float value);
char get_choice();
int get_choices(char *choices, validate_input_func validate_input);