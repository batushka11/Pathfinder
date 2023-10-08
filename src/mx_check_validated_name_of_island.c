/*#include "../inc/pathfinder.h"

void check_validated_name_of_island(char *arr){
    int counter_of_line = 2;

    int size = 1;

    for(int i = 0; arr[i]!= '\n';i++){
        size++;
    }
    
    char first[1024] = "";
    char second[1024] = "";
    int i = 0;
    int j = 0;

    while(arr[size]){
        while(arr[size] != '-'){
                first[i] = arr[size];
                size++;
                i++;
        }
        if(arr[size] == '-'){
            size++;
        }
        while(arr[size] != ','){
                second[j] = arr[size];
                size++;
                j++;
        }
        if(mx_strcmp(first,second) == 0){
            mx_printerr("error: line ");
            mx_printint(counter_of_line );
            mx_printerr(" is not valid\n");
            exit(0);
        }
        if(arr[size] == ','){
            size++;
        }
        while(arr[size] != '\n'){
                size++;
        }
        if(arr[size] == '\n'){
            size++;
            counter_of_line++;
            i = 0;
            j = 0;
        }   
    }
}*/ 
#include "../inc/pathfinder.h"

void split_string(const char *str, char *first, char *second) {
    int i = 0;
    while (str[i] != '-' && str[i] != '\0') {
        first[i] = str[i];
        i++;
    }
    first[i] = '\0';
    i++;

    int j = 0;
    while (str[i] != ',' && str[i] != '\0') {
        second[j] = str[i];
        i++;
        j++;
    }
    second[j] = '\0';
}

void check_validated_name_of_island(char *arr) {
    int counter_of_line = 1;
    int i = 0;

    while (arr[i] != '\0') {
        char first[1024] = "";
        char second[1024] = "";

        int line_end = i;
        while (arr[line_end] != '\n' && arr[line_end] != '\0') {
            line_end++;
        }

        char line[1024];
        mx_strncpy(line, arr + i, line_end - i);
        line[line_end - i] = '\0';

        split_string(line, first, second);

        if (mx_strcmp(first, second) == 0) {
            mx_printerr("error: line ");
            mx_printint(counter_of_line );
            mx_printerr(" is not valid\n");
            exit(0);
        }

        i = line_end + 1;
        counter_of_line++;
    }
}



