#include "../inc/pathfinder.h"

void mx_split_string(const char *str, char *first, char *second) {
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

void mx_check_validated_name_of_island(const char *arr) {
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

        mx_split_string(line, first, second);

        if (mx_strcmp(first, second) == 0) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(counter_of_line));
            mx_printerr(" is not valid\n");
            exit(0);
        }

        i = line_end + 1;
        counter_of_line++;
    }
}





