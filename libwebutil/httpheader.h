/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "libsrc/types.h"
#ifndef HTTPHEADER_H
#define HTTPHEADER_H
#endif

#define SERVER_REPLAY 2000


int setup_header(){
    static int response,header;
}