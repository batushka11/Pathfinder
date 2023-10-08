#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);

    char *result = (char *)malloc(len + replace_len + 1);
    if (result == NULL) {
    }

    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < len) {
        if (mx_strncmp(str + i, sub, sub_len) == 0) {
            mx_strncpy(result + j, replace, replace_len);
            i += sub_len;
            j += replace_len;
            k += replace_len;
        } else {
            result[j] = str[i];
            i++;
            j++;
            k++;
        }
    }

    result[k] = '\0';

    return result;
}


