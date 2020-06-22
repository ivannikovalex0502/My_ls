#include "libmx.h"

static char *strnew(int lenstr, int nbr, int n) {
    char *new = mx_strnew(lenstr);

    for (int i = lenstr - 1; i >= 0; i--){
        nbr = n % 16;
        if (nbr > 9) 
            new[i] = nbr + 87;
        else if (nbr < 10)
            new[i] = nbr + 48;
        n /= 16;
    }
    return new;
}

char *mx_nbr_to_hex(unsigned long n) {
    int lenstr = 0;
    unsigned long nbr = n;

    if (n == 0) {
        char *s = mx_strnew(1);
        *s = '0';
        return s;
    }
    while (nbr != 0) {
        nbr /= 16;
        lenstr++;
    }
    return strnew(lenstr, nbr, n);
}
