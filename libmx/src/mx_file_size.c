#include "../inc/libmx.h"

int mx_file_size(int fd) {
    int size = 0;
    char temp;

    while (read (fd, &temp, 1) > 0) {
    	size++;
    }
    	
    if (close (fd) != 0) {
        return 0;
    }

    return size;
}

