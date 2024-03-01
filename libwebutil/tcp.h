/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef TCP_H
#define TCP_H
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libsrc/types.h"
#include "libexc/err.h"

void sock_error() {
    goto error;
    error:
        perror("QUITTING!!!");
        exit(1);
}

REAL tcp_send(const char *host,int port){
    error:
        exit(1);
    int sockfd;
    struct sockaddr_in dest;    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
        
    if (sockfd < 0){
        perror("Tcp socket cannot be created");
        goto error;
        return -1;
    }
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&dest, sizeof(dest)) < 0){
        perror("Tcp socket cannot be connected");
        goto error;
        return -1;
    }
    return sockfd;
}

#endif