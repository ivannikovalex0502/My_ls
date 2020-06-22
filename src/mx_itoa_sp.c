#include "libmx.h"

static char *str(int count, int flag, long long n) {
    char *new = mx_strnew(count);

    if (flag) {
        new[0] = '-';
        for (int i = count - 1; i > 0; i--) {
            new[i] = n % 10 + 48;
            n /= 10;
        }
    }
    else
        for (int i = count - 1; i >= 0; i--){
            new[i] = n % 10 + 48;
            n /= 10;
        }
    return new;
}

char *mx_itoa_sp(long long number) {   
    int count = 0;
    int flag = 0;
    long long n = number;

    if (number == 0) 
        return "0";
    if (number < 0) {
        number *= -1;
        count++;
        flag = 1;
    }
    while (number != 0) {
        number /= 10;
        count++;
    } 
    return str(count, flag, n);
}
