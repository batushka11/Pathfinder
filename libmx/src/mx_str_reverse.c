#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int counter = 0;
    while(s[counter] != '\0') {
        counter++;
    }
    int counter1 = 0;
    while(counter1 != counter / 2) {
        char i = s[counter1];
        s[counter1] = s[counter - 1 - counter1];
        s[counter - 1 - counter1] = i;
        counter1++;
        }
}


