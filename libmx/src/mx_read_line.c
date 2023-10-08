#include "../inc/libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr == NULL || buf_size == 0 || fd < 0) {
        return -2; 
    }

    ssize_t total_bytes = 0;
    ssize_t bytes_read = 0;
    char* buffer = (char*)malloc(buf_size);

    if (buffer == NULL) {
        return -2; 
    }

    while (1) {
        bytes_read = read(fd, buffer + total_bytes, 1);

        if (bytes_read == -1) {
            free(buffer);
            return -2; 
        } else if (bytes_read == 0) {
            free(buffer);

            if (total_bytes == 0) {
                return -1;
            } else {
                return total_bytes;
            }
        } else {
            total_bytes += bytes_read;

            if (buffer[total_bytes - 1] == delim) {
                buffer[total_bytes - 1] = '\0';
                *lineptr = buffer;
                return total_bytes - 1;
            }

            if (total_bytes >= (ssize_t)buf_size) {
                buf_size *= 2;
                char* new_buffer = (char*)mx_realloc(buffer, buf_size);

                if (new_buffer == NULL) {
                    free(buffer);
                    return -2;
                } else {
                    buffer = new_buffer;
                }
            }
        }
    }
}


