#include "../inc/pathfinder.h"

void mx_print_path(int **matrix, int *path, char **str_of_isl, int path_counter) {
    int sum_of_price = 0;

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




