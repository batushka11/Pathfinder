#include "../inc/libmx.h"

char *mx_file_to_str (const char *filename) {
    char temp = 0;
    int count = 0;

    int fd = open (filename, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
        
    while (read (fd, &temp, 1) > 0) {
    	count++;
    }
    	
    if (close (fd) != 0) {
        return NULL;
    }
    close (fd);

    char *res = mx_strnew(count);
    fd = open (filename, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
    for (int i = 0; read (fd, &temp, 1) > 0; i++) {
        res[i] = temp;
    }
    if (close (fd) != 0) {
        return NULL;
    }
    close (fd);

    return res;
}


