#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,int c, size_t n){
    unsigned char* arr = (unsigned char*)dst;
    unsigned char* arr1 = (unsigned char*)src;
    
    for(size_t i = 0; i < n && arr1[i] != (unsigned char)c ;i++){
        arr[i] = arr1[i];
    }

    return dst; 
}


