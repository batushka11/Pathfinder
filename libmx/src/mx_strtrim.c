#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    char *tmp = mx_strnew(mx_strlen(str));
    tmp = mx_strncpy(tmp, str, mx_strlen(str));
    int start = 0;
    int end = mx_strlen(str) - 1;

    while(mx_isspace(str[start])) {
        start++;
    }
    while(mx_isspace(str[end])) {
        end--;
    }

    char *result = mx_strnew(end - start + 1);
    int j = 0;

    for (int i = start; i <= end; i++) {
        result[j] = tmp[i];
        j++;
    }
    mx_strdel(&tmp);

    return result;
}


