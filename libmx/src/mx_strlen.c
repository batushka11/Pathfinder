#include "../inc/libmx.h"

int mx_strlen(const char* s) {
	int dlina = 0;
	while(1) 
	{
  		if(s[dlina] != '\0'){ 
  		dlina++;
  		}
  	else {
  	return dlina;
  	}
 }
}


