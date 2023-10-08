#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n){
	if (s1 == NULL) {
        	return NULL;
    		}
	char *s2 = mx_strnew(n);

	return mx_strncpy(s2,s1,n);
	}


