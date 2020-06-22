#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if(str == NULL || sub == NULL)
         return -2;
     for(int i = 0; i < mx_strlen(str); i++) {
         int n = i;
         int flag = 0;

         for(int j = 0; j < mx_strlen(sub); j++, n++)
             if(str[n] == sub[j])
                 flag++;
         if(flag == mx_strlen(sub))
             return i;
     }
     return -1;
}
