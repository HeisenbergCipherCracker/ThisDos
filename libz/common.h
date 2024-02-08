#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>


#define AUTHOR "Heisenberg"
#define VERSION "1.0.0"
#define YEAR 2024



inline void print_info_messages(){
    printf("Author: %s\n", AUTHOR);
    printf("Version: %s\n", VERSION);
    printf("Year: %d\n", YEAR);
}

void print_red_alert_message(const char* message){
    printf("\033[1;31m");
    printf(message);
    printf("\033[0m");
}

void print_warn_yellow_message(const char* message){
    sprintf("\033[1;33m");
    sprintf(message);
    sprintf("\033[0m");
}


#endif