#include "../inc/libmx.h"

char* mx_strncpy(char * dst, const char * src, int len) {
    char *tptr = dst;
    int count = 0;
    while (*src && count < len ) {
        *dst++ = *src++;
        count++;
    }
    *dst = 0;
    return (char*) tptr;
}


