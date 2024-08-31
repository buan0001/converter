#ifndef COMMON_H
#define COMMON_H


int validate_input(char actual_input, char valid_input[]);
int count_decimal_places(float value);
int is_effectively_int(float value);
char get_choice();
float get_value();
void print_results(float org_val, float converted_val, char from[], char to[]);
int get_unit_choices(char *choices, char valid_input[]);
void ask_repeat();

#endif // COMMON_H