#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    unsigned char* arr1 = (unsigned char*)s1;
    unsigned char* arr2 = (unsigned char*)s2;
    size_t counter = 1;
	while (*arr1 == *arr2 && counter < n) {
		if (*arr1 == '\0' && *arr2 == '\0')
			return 0;
		arr1++;
		arr2++;
		counter++;
	}
	return *arr1 - *arr2;
}


