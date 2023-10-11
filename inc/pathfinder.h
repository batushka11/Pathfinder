#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
int **mx_create_adjacency_matrix(char *islands[], int num_islands, bridges bridge_array[], int num_bridges);
int mx_count_of_bridge(const char *arr);
void mx_create_char_bridges(const char *arr, bridges *bridge_array, int num_bridges);
char** getUniqueIslands(bridges* bridgeArray, int numBridges);

#endif

