#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    unsigned char *ptr =(unsigned char*) dst;
    unsigned char *s_ptr =(unsigned char*) src;
    size_t count = 0;
    while (*s_ptr && count < len ) {
        *ptr++ = *s_ptr++;
        count++;
    }
    *ptr = 0;
    return dst;
}


