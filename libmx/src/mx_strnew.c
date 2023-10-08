#include "../inc/libmx.h"

char *mx_strnew(const int size) {
	if (size < 0 ) {
		return 0;
		}
	char *ptr = (char *)malloc(size + 1);
	if (ptr == NULL) {
		return ptr;
		}
	for (int i = 0; i <= size; i++) {
        	ptr[i] = '\0';
    	}
	return ptr;
	}


