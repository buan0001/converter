void display_temperature_menu();

float fahrenheit_to_celsius(float fahr);
float fahrenheit_to_kelvin(float fahr);
float celsius_to_fahrenheit(float celsius);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float kelvin_to_fahrenheit(float kelvin);

int validate_input(char input);
void print_temp_results(float org_val, float converted_val, char from[], char to[]);