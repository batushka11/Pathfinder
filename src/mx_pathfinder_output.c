#include "../inc/pathfinder.h"

void mx_pathfinder_output(int **matrix, int **matrix1, int size, char **str_of_isl) {
    int *path = (int*)malloc((size + 1) * sizeof(int));
    int path_counter = 1;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            path[1] = i;
            path[0] = j;
            find_and_print_paths(matrix, matrix1, path, str_of_isl, path_counter, size);
        }
    }

    free(path);
}








