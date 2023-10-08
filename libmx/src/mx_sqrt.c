#include "../inc/libmx.h"

int mx_sqrt(int x) {
	if (x<=0) {
		return 0;
		}
	else {
		for (int j = 1; j < x; j++) {
        		if (j * j == x) {
            			return j;
            			}
		}
	}
	return 0;
}


