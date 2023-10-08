#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
     if(nbr == 0) {
          char * result = malloc(1);
          result[0] = '0';
          return result;
        }
      unsigned long nbr2 = nbr;
      int l = 0;
      int temp;

      while (nbr != 0) {
          nbr /= 16;
          l++;
        }
      if (l == 0)
          return 0;
        
      char *string = malloc(l+1);
      for (int i = l - 1; i >= 0; i--) {
          temp = nbr2 % 16;

          if (temp < 10)
                string[i] = temp + 48;
          else
                string[i] = temp + 87;

          nbr2 /= 16;
        }
      return string;
}


