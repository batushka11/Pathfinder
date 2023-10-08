#include "../inc/libmx.h"

void *mx_memchr(const void* s, int c, size_t n){
    unsigned char* arr = (unsigned char*)s;
    size_t counter = 0;

    while (*arr != '\0' && counter < n) {
		if (*arr == (unsigned char)c) {
			return arr;
		}
		arr++;
		counter++;
	}

	return NULL;
}


