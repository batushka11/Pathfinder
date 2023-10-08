#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n){
    unsigned char* arr = (unsigned char*)dst;
    unsigned char* arr1 = (unsigned char*)src;
    
    for(size_t i = 0; i < n ;i++){
        arr[i] = arr1[i];
    }

    return dst;   
}


