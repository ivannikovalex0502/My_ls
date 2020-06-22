#include "uls.h"

static t_data *get_data(t_data *data, int size);
static void print(t_data *data, int size);
static void get_file(int size, t_data *data);

void mx_print_file_return_dir(t_data *data) {
    DIR *dir = NULL;
    int size = 0;
    int number = 0;

    data->file = malloc(sizeof(char *) * data->argc);
    for (int i = 1; i < data->argc; i++) {
        dir = opendir(data->argv[i]);
        if (!dir && errno == 20) {
            data->file[number++] = data->argv[i];  
            size++;
        }
        else if (errno == 2 && !dir) {
            printf("uls: %s: %s\n", data->argv[i], strerror(errno));
        }
        else if (dir) {
            data->flag = 1;
            closedir(dir);
        }
        else
            data->flag = 1;
    }
    if (size > 0) {
        data->flag_n = 1;
        data->argv_file = malloc(sizeof(char *) * size + 1);
        get_file(size, data);
        print(data, size);
    }
}

static void print(t_data *data, int size) {
    char **tmp = NULL;
    char **result = NULL;

    data = get_data(data, size);
    tmp = malloc(sizeof(char *) * data->size_all + 1);
    for (int i = 0; i <= data->size_all; i++)
        tmp[i] = NULL;
    for(int i = 0; data->argv_file[i] != NULL; i++)
        tmp[i] = data->argv_file[i];
    mx_sort_file(tmp, size);
    result = mx_get_result(tmp, data);
    data->file = result;
    mx_print_file(data);
    free(tmp);
    free(result);
}

static t_data *get_data(t_data *data, int size) {
    data->num_name = 0;
    for (int i = 0; i < size; i++)
        if (data->file[i] != NULL && data->num_name < mx_strlen(data->file[i]))
            data->num_name = mx_strlen(data->file[i]);
    data->num_name = data->num_name + (8 - (data->num_name % 8));
    data->size = size;
    data->width = data->colums / data->num_name;
    data->size_all = mx_size_a(data);
    return data;
}

static void get_file(int size, t_data *data) {  
    int number = 0;
    DIR *dir = NULL;

    data->argv_file[size] = NULL;
    for (int j = 0; j <= data->size_all; j++)
        data->argv_file[j] = NULL;
    for (int i = 1; i < data->argc; i++) {
        dir = opendir(data->argv[i]);
        if (!dir && errno == 20) {
            data->argv_file[number] = data->argv[i];
            number++;
        }
        else if (dir)
            closedir(dir);
    }
  
}
