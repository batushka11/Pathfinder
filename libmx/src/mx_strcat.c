#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int counter = mx_strlen(s1);
    for(int j = 0; counter < mx_strlen(s1) + mx_strlen(s2); j++) {
        s1[counter] = s2[j];
        counter++;
    }
    return s1;
}


