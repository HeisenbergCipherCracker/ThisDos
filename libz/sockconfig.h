#ifndef SOCK_CONFIG_H_
#define SOCK_CONFIG_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <err.h>
int get_tcp_sock_fd();
int get_udp_sock_fd();

struct sockaddr_in configure_sock(int port, char *hostname);
int check_args(char* hostname, char* message, int port, char* source_ip, char* attack_type);

#endif //SOCK_CONFIG_H_