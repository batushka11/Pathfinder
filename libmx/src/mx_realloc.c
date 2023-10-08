#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size){
    if(ptr == NULL){
        return malloc(size);
    }
    if(size == 0){
        free(ptr);
        return NULL;
    }

    void *arr = malloc(size);
    mx_memcpy(arr,ptr,malloc_usable_size(ptr));
    free(ptr);
    ptr = arr;
    return ptr;
}


