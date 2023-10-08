#include "../inc/pathfinder.h"

void mx_find_error_in_file(char *arr){
        for(int i = 0; arr[i] != '\n';i++){
                if(mx_isdigit(arr[i]) == 0){
                    mx_printerr("error: line 1 is not valid\n");
                    exit(0);
                }
        }
        int counter_of_line = 0;
        int komma = 0;
        int defis = 0;
        for (int i = 0; arr[i]; i++) {
            if (arr[i] == '\n') {
                counter_of_line++;
                if (counter_of_line > 1) {
                    if (komma != 1 || defis != 1) {
                            mx_printerr("error: line ");
                            mx_printint(counter_of_line);
                            mx_printerr(" is not valid\n");
                            exit(0);
                    }
                    komma = 0;
                    defis = 0;
                }
            } else if (arr[i] == '-') {
                defis++;
            } else if (arr[i] == ',') {
                komma++;
            }
        }
        if (counter_of_line == 0 || komma != 0 || defis != 0) {
            mx_printerr("error: line ");
            mx_printint(counter_of_line);
            mx_printerr(" is not valid\n");
            exit(0);
        }
        
        counter_of_line = 0;

        for (int i = 0; arr[i]; i++) {
            if (arr[i] == '\n') {
                counter_of_line++;
            }
            if(mx_isalpha(arr[i]) == 0 && mx_isdigit(arr[i]) == 0 && arr[i] != '-' && arr[i] != ',' && arr[i] != '\n'){
                mx_printerr("error: line ");
                mx_printint(counter_of_line + 1);
                mx_printerr(" is not valid\n");
                exit(0);
            }
        }

        counter_of_line = 1;

        int size = 1;

        for(int i = 0; arr[i]!= '\n';i++){
            size++;
        }

        while(arr[size]){
            
        }

        mx_print_strarr(&arr, "\n");
}



