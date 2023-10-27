#include "../inc/pathfinder.h"

void mx_find_and_print_paths(int **matrix, int **matrix1, int *path, char **str_of_isl, int path_counter, int size) {
    int start = path[0];
    int end = path[path_counter];

    for (int i = 0; i < size; i++) {
        if ((matrix[end][i] == matrix1[end][start] - matrix1[i][start]) && i != path[path_counter]) {
            path_counter += 1;
            path[path_counter] = i;

            mx_find_and_print_paths(matrix, matrix1, path, str_of_isl, path_counter, size);

            path_counter -= 1;
        }
    }

    if (path[path_counter] != start) {
        return;
    }

    mx_print_path(matrix, path, str_of_isl, path_counter);
}




