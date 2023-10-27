#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "../libmx/inc/libmx.h"

typedef struct bridge{
    char *island_l;
    char *island_r;
    int price;
} bridges;

void mx_find_error_in_file(const char *arr);
void check_validated_name_of_island(const char *arr);
void check_valid_sum(const char *arr);
void check_validated_name_of_island_pair(const char *arr);
int count_unique_islands(const char *arr);
int **mx_create_adj_matrix(char *islands[], int num_islands, bridges bridge_array[], int num_bridges);
int mx_count_of_bridge(const char *arr);
void mx_create_char_bridges(const char *arr, bridges *bridge_array, int num_bridges);
char** mx_get_unique_islands(bridges* bridgeArray, int numBridges);
void mx_simple_pathfinding_algorithm(int** matrix,int size);
void mx_pathfinder_output(int **start_weight, int **end_weight, int size, char **str_of_isl) ;
void print_path(int **matrix, int **matrix1, int *path, char **str_of_isl ,int path_counter, int size);

#endif

