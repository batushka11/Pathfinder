#include "../inc/pathfinder.h"

void mx_check_validated_name_of_island_pair(const char *arr){
    char** lines = mx_strsplit(arr, '\n');
    
    for(int i = 1 ;lines[i]; i++) {
        int defis = mx_char_index(lines[i], '-');
        int komma = mx_char_index(lines[i], ',');
        char island_l[1024];
        char island_r[1024];
        mx_strcpy(island_l, mx_strndup(lines[i], defis));
        mx_strcpy(island_r, mx_strndup(&lines[i][defis + 1], komma - defis - 1));

        for(int j = 2 ;lines[j]; j++){
            int defis1 = mx_char_index(lines[j], '-');
            int komma1 = mx_char_index(lines[j], ',');
            char island_l1[1024];
            char island_r1[1024];
            mx_strcpy(island_l1, mx_strndup(lines[j], defis1));
            mx_strcpy(island_r1, mx_strndup(&lines[j][defis1 + 1], komma1 - defis1 - 1));
            if(i != j && mx_strcmp(island_l,island_l1) == 0 && mx_strcmp(island_r,island_r1) == 0){
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
        }
    }
}






