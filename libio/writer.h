/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef WRITER_H
#define WRITER_H
#endif
#include <stdio.h>

void stream_writer(const char *filename, char *data){
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL){
        perror("Could not open the file/or encountered an error");
        return;
    }
    fprintf(fp, "%s\n", data);
    fclose(fp);

}