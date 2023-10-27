#include "../inc/pathfinder.h"

struct Island {
    char name[1024];
};

int mx_count_unique_islands(const char *arr){
    char** lines = mx_strsplit(arr, '\n');
    int total_unique_islands = 0;

    struct Island unique_islands[1024];
    for (int i = 0; i < 1024; i++) {
        unique_islands[i].name[0] = '\0';
    }

    int i = 1;
    while (lines[i] != NULL) {
        int defis = mx_char_index(lines[i], '-');
        int komma = mx_char_index(lines[i], ',');
        char island_l[1024];
        char island_r[1024];
        mx_strcpy(island_l, mx_strndup(lines[i], defis));
        mx_strcpy(island_r, mx_strndup(&lines[i][defis + 1], komma - defis - 1));

        bool found1 = false;
        for (int j = 0; j < 1024; j++) {
            if (unique_islands[j].name[0] && mx_strcmp(unique_islands[j].name, island_l) == 0) {
                found1 = true;
                break;
            }
        }

        if (!found1) {
            mx_strcpy(unique_islands[total_unique_islands].name, island_l);
            total_unique_islands++;
        }

        bool found2 = false;
        for (int j = 0; j < 1024; j++) {
            if (unique_islands[j].name[0] && mx_strcmp(unique_islands[j].name, island_r) == 0) {
                found2 = true;
                break;
            }
        }

        if (!found2) {
            mx_strcpy(unique_islands[total_unique_islands].name, island_r);
            total_unique_islands++;
        }

        i++;
    }
    int check_num = mx_atoi(lines[0]);
    if (total_unique_islands != check_num) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    
    return total_unique_islands;
}







