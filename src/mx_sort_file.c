#include "uls.h"

void mx_sort_file(char **str, int size) {
    char *tmp = NULL;

    for (int j = 0; j < size - 1; j++)
        for (int i = 0; i < size - j - 1; i++)
            if (mx_strcmp(str[i], str[i + 1]) > 0) {
                tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
            }
}
