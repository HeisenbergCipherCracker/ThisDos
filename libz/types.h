/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <string.h>


typedef struct{
        const char* RED;
        const char* GREEN;
        const char* YELLOW;
        const char* BLUE;
        const char* MAGENTA;
        const char* CYAN;
        const char* WHITE;
} Colors;

Colors color = {
        .RED = "\x1b[31m",
        .GREEN = "\x1b[32m",
        .YELLOW = "\x1b[33m",
        .BLUE = "\x1b[34m",
        .MAGENTA = "\x1b[35m",
        .CYAN = "\x1b[36m",
        .WHITE = "\x1b[37m"
};

#endif