#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long num = 0;
    int n = 0;
    unsigned long j = 1;

    while (hex[n + 1]) {
        n++;
        j *= 16;
    }
    for (int i = 0; hex[i]; i++) {
        if (hex[i] > 47 && hex[i] < 58)
            num += (hex[i] - 48) * j;
        else if (hex[i] > 64 && hex[i] < 71)
            num += (hex[i] - 55) * j;
        else
            num += (hex[i] - 87) * j;
        j /= 16;
    }
    return num;
}
