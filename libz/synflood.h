/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef SYN_FLOOD_H
#define SYN_FLOOD_H

#include <netinet/tcp.h>

struct csum_hdr
{
	unsigned int source_addr;
	unsigned int dest_addr;
	unsigned char placeholder;
	unsigned char protocol;
	unsigned short tcp_length;

	struct tcphdr tcp;
};

unsigned short csum(unsigned short *ptr,int nbytes);
struct iphdr* configure_packet(char* source_ip, char* datagram, struct sockaddr_in sin);
int tcp_send(char *datagram, int sfd, struct sockaddr_in servaddr, struct iphdr* iph);
void syn_flood(char* hostname, int port, char* sourcec_ip);

#endif