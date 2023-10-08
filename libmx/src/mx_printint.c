#include "../inc/libmx.h"

void mx_printint(int n) {
	if (n == -2147483648){
 		write(1,"-2147483648",11);
 		return;
 		}
	if (n < 0) {
 		mx_printchar('-');
 		n *= -1;
 		}
 	if (n == 0){
 		mx_printchar('0');
 		}	
 	int start = n;
	int number_of_digits = 0;
	while(start != 0) {
 		start /= 10;
		number_of_digits++; 
		}
	int array[number_of_digits];
	int counter_arr = 0;
	while(n != 0) {
  		array[counter_arr] = n % 10;
		n /= 10;
		counter_arr++;
		}
	for(int j = counter_arr - 1; j >= 0; j--) {
 	mx_printchar(array[j] + 48);
 	}
}


