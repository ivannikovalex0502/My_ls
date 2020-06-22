#include "uls.h"

static void print_error(t_data *data, char *name, t_sort *gen);
static t_sort *get_name(struct dirent *entry,t_data *data, t_sort *gen);
static void flag_a_A(DIR *dir, t_data *data, t_sort *gen);

int mx_read_dir(char *dirname, t_data *data) {
    DIR *dir = opendir(dirname);
    t_const *data_l = NULL;
    t_sort *general = malloc(sizeof(t_sort));
    t_sort *tmp = NULL;

    if (!dir) {
        print_error(data, dirname, general);
        return 0;
    }
    flag_a_A(dir, data, general);
    tmp = general;
    general = general->next;
    tmp->next = NULL;
    free(tmp);
    mx_sort_all(data, general);
    data_l = data->cnst;
    mx_get_is(data_l, data);
    mx_num_file(data_l, data);
    mx_get_file_col(data_l, data);
    return 1;
}

static void print_error(t_data *data, char *name, t_sort *gen) {
    while (mx_get_char_index(name, '/') >= 0)
        name++;
    mx_print_error("uls: ");
    mx_print_error(name);
    mx_print_error(": ");
    mx_print_error(strerror(errno));
    mx_print_error("\n");
    data->errors = 1;
    free(gen);
}

static void flag_a_A(DIR *dir, t_data *data, t_sort *gen) {
    struct dirent *entry = NULL;
    int *flags = data->flags;

    if (flags[0] == 1 || flags[9] == 1)
        while ((entry = readdir(dir)) != NULL)
            gen = get_name(entry, data, gen);
    else if (flags[1] == 1) {
        while ((entry = readdir(dir)) != NULL)
            if (strcmp(entry->d_name, ".") != 0 
                && strcmp(entry->d_name, "..") != 0) {
                gen = get_name(entry, data, gen);
            }
    }
    else
        while ((entry = readdir(dir)) != NULL)
            if (entry->d_name[0] != '.')
                gen = get_name(entry, data, gen);
    closedir(dir);
}

static t_sort *get_name(struct dirent *entry, t_data *data, t_sort *gen) {
    gen->next = malloc(sizeof(t_sort));
    gen->next->cnst = malloc(sizeof(t_const));
    gen->next->cnst->name = mx_strdup(entry->d_name);
    if (data->path !=  NULL) {
        char *tmp = mx_strjoin(data->path, "/");

        gen->next->cnst->ful_n = mx_strjoin(tmp, gen->next->cnst->name);
        free(tmp);
    }
    else
        gen->next->cnst->ful_n = NULL;
    mx_get_flag_l(gen->next->cnst, data);
    data->size += 1;
    gen = gen->next;
    gen->next = NULL;
    return gen;
}
