#include "libmx.h"

void mx_printint(int n) {
    if(n == -2147483648) {
        mx_printchar('-');
        mx_printchar('2');
        n *= -1;
        n -= 2000000000;
    }
    else if(n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    if(n < 10) {
        mx_printchar(n + 48);
        return;
    }
    mx_printint(n / 10);
    mx_printchar(n % 10 + 48);
}
