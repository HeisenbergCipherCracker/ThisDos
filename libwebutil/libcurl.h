/*
This program is licensed under the GNU General Public License v3.
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
See https://www.gnu.org/licenses/gpl-3.0.html for details.
*/
#ifndef CURL_H
#define CURL_H



#include <curl/curl.h>
#include <stdio.h> 
#include <string.h>
#include "../libz/common.h"



#define HTTP_SCHEME "http://"
#define HTTPS_SCHEME "https://"

int send_curl(const char* url,int count){
    do{
    char scheme[100];
    CURLcode status;
    if (!strstr(url, HTTP_SCHEME) || !strstr(url, HTTPS_SCHEME)) {
        pwarn("Scheme is not found, so it is assumed to be http://\n");
        strcpy(scheme, HTTP_SCHEME);
        strcat(scheme, url);
    }
    if (status != CURLE_OK){
        perror("[err] curl_easy_perform() failed");
        return -1;
    }
    else{
        printf("[inf] Could send a curl request\n");
    }
    }while(count--);
    return 0;

}
#endif
