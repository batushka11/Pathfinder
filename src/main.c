#include "../inc/pathfinder.h"

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }

    int file = open(argv[1], O_RDONLY);

    if(file < 0) {
        mx_printerr("error: file ");
        mx_printstr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }

    if(mx_file_size(file) == 0) {
        mx_printerr("error: file ");
        mx_printstr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }
    
    char *arr = mx_file_to_str(argv[1]);
    mx_find_error_in_file(arr); 
}

