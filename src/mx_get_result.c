#include "uls.h"

char **mx_get_result(char **file, t_data *data) {
    char **result = malloc(sizeof(char *) * (data->size_all + 1));
    int line = data->size_all / data->width;
    int counter[2];
    int i = 0;

    counter[0] = 0;
    counter[1] = 0;
    for (i = 0; i <= data->size_all; i++)
        result[i] = NULL;
    for (i = 0; i < data->width; i++) {
        counter[0] = i;
        for (int j = 0; j < line; j++) {
            result[counter[0]] = file[counter[1]];
            counter[0] += data->width;
            counter[1]++;
        }
    }
    return result;
}
