#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
	int counter = 1;
	while (*s1 == *s2 && counter < n) {
		if (*s1 == '\0' && *s2 == '\0')
			return 0;
		s1++;
		s2++;
		counter++;
	}
	return *s1 - *s2;
}


