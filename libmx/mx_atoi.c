#include "libmx.h"

int mx_atoi(char *str) { 
    long long result = 0;
    int flag = 0;

    if (str[0] == '-') {
        str++;
        flag = 1;
    }
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] < 48 || str[i] > 57 )
            return -1;
        result = (result + (str[i] - 48)) * 10;
    }
    if (flag == 1)
        result *= -1;
    return result /= 10;
}
