#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    	if (str == 0) {
        	return 0;
    		}	
    	char *c = mx_strtrim(str);
    	int count = 0;
    	int space = 0;
    	int words = 0;
    	int size = mx_strlen(c);
    	int i = 0;

    	while (c[i] != 0) {
        	if (!mx_isspace(c[i])) {
           	 	count = 0;
            		words++;
        		}
        	if (count == 0 && mx_isspace(c[i])) {
            		count = 1;
            		space++;
        		}
        	i++;
    		}
    		char *new = mx_strnew(words + space);
    		int j = 0;
    		count = 0;
    		for (int i = 0; i < size; i++) {
        		if (!mx_isspace(c[i])) {
            			new[j++] = c[i];
            			count = 0;
        			}
        		if (count == 0 && mx_isspace(c[i])) {
            			new[j++] = ' ';
            			count = 1;
        			}
    			}
    		mx_strdel(&c);
    		return new;
}


