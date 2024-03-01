/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PING_H
#define PING_H
#endif
#include <stdbool.h>

bool ping_host(const char *host){
    char command[50];
    printf("started pinging %s\n", host);
    char* ping_result = snprintf(command, sizeof(command), "ping -c 1 %s", host);
    return system(command) == 0;
}