#include "../inc/pathfinder.h"

int mx_list_index_of(char *arr[], int size, const char *key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != NULL && strcmp(arr[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

int **mx_create_adj_matrix(char *islands[], int num_islands, bridges bridge_array[], int num_bridges) {
    int size = num_islands;
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for(int j = 0; j < size;j++){
            matrix[i][j] = 999;
        }
    }

    for (int i = 0; i < num_bridges; i++) {
        int left_index = mx_list_index_of(islands, num_islands, bridge_array[i].island_l);
        int right_index = mx_list_index_of(islands, num_islands, bridge_array[i].island_r);
        int cost = bridge_array[i].price;

        if (left_index != -1 && right_index != -1) {
            matrix[left_index][right_index] = matrix[right_index][left_index] = cost;
        }
    }

    return matrix;
}






