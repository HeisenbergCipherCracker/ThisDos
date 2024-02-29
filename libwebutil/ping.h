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
    snprintf(command, sizeof(command), "ping -c 1 %s", host);
    return system(command) == 0;
}