#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    	int l = 0;
    	unsigned long num = 0;
    	unsigned long b = 1;

    	if (hex != NULL) {
        	while (hex[l])
            	l++;
    		}
    	else {
        	return num;
    		}

    	for (int i = l - 1; i >= 0; i--) {
        	if (hex[i] >= 48 && hex[i] <= 57) {
            		num = num + (hex[i] - 48) * b;
        		}
        	else if (hex[i] >= 65 && hex[i] <= 70 ) {
            		num = num + (hex[i] - 55) * b;
        		}		
        	else if (hex[i] >= 97 && hex[i] <= 102) {
            		num = num + (hex[i] - 87) * b;
        		}
        	else {
        		return 0;
        		}
        	b = b * 16;
     
    		}
    	
    	return num;
}


