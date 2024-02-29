/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <dirent.h>



#define AUTHOR "Heisenberg"
#define VERSION "1.1.3"
#define YEAR 2024

const char* Source_Code = "https://github.com/HeisenbergCipherCracker/ThisDos";


static int print_logo(){
        printf(

"██████████████████████████████████████\n"
"█─▄─▄─█─█─█▄─▄█─▄▄▄▄█▄─▄▄▀█─▄▄─█─▄▄▄▄█\n"
"███─███─▄─██─██▄▄▄▄─██─██─█─██─█▄▄▄▄─█\n"
"▀▀▄▄▄▀▀▄▀▄▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▀▄▄▄▄▀▄▄▄▄▄▀\n"
    );
    return 0;


}

void print_info_messages(){
    printf("Author: %s\n", AUTHOR);
    printf("Version: %s\n", VERSION);
    printf("Year: %d\n", YEAR);
    printf("Source:%s\n",Source_Code);
}

void print_program_banner(){
    print_logo();
    print_info_messages();
}




void print_red_alert_message(const char* message){
    printf("\033[1;31m");
    printf(message);
    printf("\033[0m");
}

void print_warn_yellow_message(const char* message){
    printf("\033[1;33m");
    printf(message);
    printf("\033[0m");
}


#endif