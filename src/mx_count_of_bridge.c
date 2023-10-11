#include "../inc/pathfinder.h"

int mx_count_of_bridge(const char *arr){
    char** lines = mx_strsplit(arr, '\n');
    int counter = -1;
    int i = 0;
    while(lines[i]){
        counter++;
        i++;
    }
    return counter;
}

