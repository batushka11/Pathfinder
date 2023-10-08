#include "../inc/pathfinder.h"

void check_valid_sum(char *arr){
    char** lines = mx_strsplit(arr, '\n');
    long sum = 0;
    
    for(int i = 1 ;lines[i]; i++) {
        int komma = mx_char_index(lines[i], ',');
        sum += mx_atoi(&lines[i][komma + 1]);
    }
    if(sum > 2147483647){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
}


