#ifndef CONVERT_H
#define CONVERT_H

void display_intro();

void display_main_menu();

int unit_main(char unit_type);



// int temperature_main(char choices[], float input);
// int pressure_main(char choices[], float input);
// int volume_main(char choices[], float input);
int temperature_main(char choices[]);
int pressure_main(char choices[]);
int volume_main(char choices[]);
void display_temperature_menu();
void display_pressure_menu();
void display_volume_menu();

#endif // CONVERT_H
