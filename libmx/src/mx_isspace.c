#include "../inc/libmx.h"

bool mx_isspace(char c) {
	if (c == 32 || c == '\t' || c == '\n' ||  c == '\v' ||  c == '\r' || c == '\f') {
		return 1;
		}
	return 0;
}


