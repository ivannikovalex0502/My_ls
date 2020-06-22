#include "uls.h"

void mx_printstr_update(char *str1, char *str2, char *str3,
char *str4, char *str5) {
    if (str1 != NULL)
        mx_printstr(str1);
    if (str2 != NULL)
        mx_printstr(str2);
    if (str3 != NULL)
        mx_printstr(str3);
    if (str4 != NULL)
        mx_printstr(str4);
    if (str5 != NULL)
        mx_printstr(str5);
}
