#include "../inc/pathfinder.h"

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }

    int file = open(argv[1], O_RDONLY);

    if(file < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }

    if(mx_file_size(file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }
    
    char *arr = mx_file_to_str(argv[1]);
    mx_find_error_in_file(arr);
    mx_check_validated_name_of_island(arr);
    mx_check_valid_sum(arr);
    mx_check_validated_name_of_island_pair(arr);
    int count_of_island = mx_count_unique_islands(arr);
    int count_bridge = mx_count_of_bridge(arr);
    bridges *bridge_arr = (bridges*)malloc(sizeof(bridges)*(count_bridge));
    mx_create_char_bridges(arr,bridge_arr,count_bridge);
    char **str_of_isl = NULL;
    str_of_isl = mx_get_unique_islands(bridge_arr, count_bridge);
    int **matrix = mx_create_adj_matrix(str_of_isl,count_of_island, bridge_arr, count_bridge);
    int **matrix1 = mx_create_adj_matrix(str_of_isl,count_of_island, bridge_arr, count_bridge);
    mx_simple_pathfinding_algorithm(matrix1,count_of_island);
    mx_pathfinder_output(matrix,matrix1,count_of_island,str_of_isl);
    for(int i = 0; i < count_of_island;i++ ){
        free(matrix[i]);
    }
    free(matrix);
    for(int i = 0; i < count_of_island;i++ ){
        free(str_of_isl[i]);
    }
    for(int i = 0; i < count_of_island;i++ ){
        free(matrix1[i]);
    }
    free(str_of_isl);
    free(arr);
}





