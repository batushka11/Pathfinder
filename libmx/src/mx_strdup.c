#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
	if (str == NULL) {
        	return NULL;
    		}
    	char *ptr = mx_strnew(mx_strlen(str));
	return mx_strcpy(ptr, str);
	}


