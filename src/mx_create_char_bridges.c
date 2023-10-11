#include "../inc/pathfinder.h"

void mx_create_char_bridges(const char *arr, bridges *bridge_array, int num_bridges) {
    char** lines = mx_strsplit(arr, '\n');
    for (int i = 1; lines[i] && i - 1 < num_bridges; i++) {
        int defis = mx_char_index(lines[i], '-');
        int komma = mx_char_index(lines[i], ',');
        bridge_array[i - 1].island_l = mx_strndup(lines[i], defis);
        bridge_array[i - 1].island_r = mx_strndup(&lines[i][defis + 1], komma - defis - 1);
        bridge_array[i - 1].price = mx_atoi(&lines[i][komma + 1]);
    }
}

