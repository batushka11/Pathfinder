#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    if(arr == NULL){
        return -1;
    }
    int swap = 0;
    int i, j;
    char *x, *y;
    i = left;
    j = right;
    x = arr[(left + right) / 2];

    while (i <= j)
    {
        while (mx_strlen(arr[i]) < mx_strlen(x) && i < right)
            i++;
        while (mx_strlen(arr[j]) > mx_strlen(x) && j > left)
            j--;

        if (i <= j) {
                if(mx_strlen(arr[i]) > mx_strlen(arr[j])) {
                    y = arr[i];
                    arr[i] = arr[j];
                    arr[j] = y;
                    swap++;
                }
            
                i++;
                if (j > 0) {
                    j--;
                }
          }
    } 
    if (left < j){
        swap += mx_quicksort(arr, left, j);
    }
    if (i < right){
        swap += mx_quicksort(arr, i, right);
    }
    return swap;
}


