/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef RANDOM_IP_H
#define RANDOM_IP_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char *random_ip() {

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* using nano-seconds instead of seconds */
    srand((time_t) ts.tv_nsec);

    char *str = malloc(20 * sizeof(char));  // Longest possible IP address is 20 bytes)

    sprintf(str, "%d.%d.%d.%d", rand() % 0xff, rand() % 0xff, rand() % 0xff, rand() % 0xff);

    return str;
}
#endif