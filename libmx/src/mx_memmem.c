#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,size_t little_len){
    unsigned char *s1 = (unsigned char*)big;
    unsigned char *s2 = (unsigned char*)little;   
    
    while ( *s1 != '\0' ) {
		if (mx_memchr(s1, *s2, big_len) && mx_memcmp(s1, s2, little_len) == 0) {
				return s1;
				}
			s1++;
			}
		return NULL;
}


