#ifndef PATHFINDER_H
#define PATHFINDER_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../libmx/inc/libmx.h"

void mx_printerr(const char* s);
void mx_find_error_in_file(char *arr);
bool mx_isalpha(int c);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
int mx_file_size(int fd);
void mx_printerr(const char *s);
void check_validated_name_of_island(char *arr);
void check_valid_sum(char *arr);

#endif

