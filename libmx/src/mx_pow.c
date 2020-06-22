#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double temp = n;

    if(pow == 0)
        return 1;
    for(int i = pow - 1; i != 0; i--)
        n *= temp;
    return n;
}
