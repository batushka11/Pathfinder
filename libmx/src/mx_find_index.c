#include "../inc/libmx.h"

int mx_find_index(char *arr[], int size, const char *c) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != NULL && mx_strcmp(arr[i], c) == 0) {
            return i;
        }
    }
    return -1;
}





