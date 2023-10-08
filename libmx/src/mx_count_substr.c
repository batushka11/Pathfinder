#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	if(str == NULL || sub == NULL){
        return -1;
    }
	if(mx_strcmp(sub,"") == 0){
		return 0;
	}
	int counter = 0;
	while (mx_strstr(str,sub)) {
		str = mx_strstr(str,sub);
		str++;
		counter++;
	}
	return counter;
}


