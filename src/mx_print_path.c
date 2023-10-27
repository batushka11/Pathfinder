#include "../inc/pathfinder.h"

void print_path(int **matrix, int **matrix1, int *path, char **str_of_isl ,int path_counter, int size) {
    int start = path[0];
    int end = path[path_counter];
    int sum_of_price = 0;

    for (int i = 0; i < size; i++) {
        if ((matrix[end][i] == matrix1[end][start] - matrix1[i][start]) && i != path[path_counter]) {
            path_counter += 1;
            path[path_counter] = i;

            print_path(matrix, matrix1, path, str_of_isl,path_counter, size);

            path_counter-= 1;
        }
    }

    if (path[path_counter] != start) {
        return;
    }
    mx_printstr("====================");
    mx_printstr("====================");
    mx_printstr("\nPath: ");
    mx_printstr(str_of_isl[path[1]]);
    mx_printstr(" -> ");
    mx_printstr(str_of_isl[path[0]]);
    mx_printstr("\nRoute: ");
    for (int i = 1; i < path_counter + 1; i++) {
        mx_printstr(str_of_isl[path[i]]);
        if (i < path_counter) {
            mx_printstr(" -> ");
        }
    }

    mx_printstr("\nDistance: ");
    for (int i = 1; i < path_counter; i++) {
        int price = matrix[path[i]][path[i + 1]];
        mx_printint(price);
        sum_of_price += price;
        if (i < path_counter - 1) {
            mx_printstr(" + ");
        }
    }

    if (path_counter != 2) {
        mx_printstr(" = ");
        mx_printint(sum_of_price);
    }

    mx_printstr("\n====================");
    mx_printstr("====================\n");
}

