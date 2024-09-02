#ifndef COMMON_H
#define COMMON_H


int count_decimal_places(float value);
int is_effectively_int(float value);

int validate_input(char actual_input, char valid_input[]);
// float get_value();
char get_choice();
float get_value(char unit_type[]);
int get_unit_choices(char *choices, char valid_input[]);
void ask_repeat();
void print_results(float org_val, float converted_val, char from[], char to[]);

#endif // COMMON_H


// float get_value();

// int shouldContinue(char input);

