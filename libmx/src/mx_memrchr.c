#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    unsigned char* arr = (unsigned char*)s + mx_strlen(s);
    size_t counter = 0;

    while (arr && counter < n) {
		if (*arr == (unsigned char)c) {
			return arr;
		}
		arr--;
        counter++;
	}

	return NULL;    
}


