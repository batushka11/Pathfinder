#include "../inc/libmx.h"

int mx_char_index(char* str, char c) {
    int i = 0;
    while(str[i]) {
        if(str[i] == c) return i;
        i++;
    }

    return -1;
}


