#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
      int i = 0;
      int start;
      char **result = (char**)mx_strnew(mx_count_words(s, c));
      
      while(s[i] == c) {
         if(s[i] == '\0') {
               return NULL;
         }
         i++;
      }
      
      for (int j = 0; j < mx_count_words(s, c); j++) {
          int length = 0;
          start = i;
          while (s[i] != c && s[i] != '\0') {
                length++;
                i++;
          }
          result[j] = mx_strnew(length);
          mx_strncpy(result[j], &s[start], length);
          while (s[i] == c) {
               i++;
          }
      }
      result[mx_count_words(s, c)] = NULL;
      
      return result;
}


