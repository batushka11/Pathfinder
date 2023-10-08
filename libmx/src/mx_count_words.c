#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int word = 0;
    int i = 0;
    if ( *str != delimiter && *str != '\0') {
        word++;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] == delimiter) {
            while (str[i] != '\0' && str[i] == delimiter) {
                i++;
            }
            if(str[i] != delimiter && str[i] != '\0') {
                word++;
            }
        }
        i++;
    }
    return word;
}


