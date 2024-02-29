/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef UPDFLOOD_H
#define UPDFLOOD_H

#include <sys/socket.h>
#include <netinet/in.h>

#ifdef __WIN32__
#warning "this file might not be compatible with windows"
#endif

int udp_send(const char *msg, int fd, struct sockaddr_in servaddr);
void udp_spam(char* hostname, int port, char* message);


#endif