#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/errno.h>

typedef struct s_file {
    char *d_name;
    struct s_file *next;
} t_file;

typedef struct s_big_data {
    int *flags;
    char **d_name;
    int num;
    int colums;
    int size;
} t_data;

//void mx_print_file(int size, char **file);
void mx_sort_file(char ***str, int size);
int mx_size_a(int num, int columns, int size);
char **mx_get_result(char **file, char **result, int size_all, int width);
int mx_print_file_return_dir(char **argv, int argc, char ***argv_dir);
int mx_head_size(t_file *head);
int mx_columns();
void mx_file_to_arr(t_file *head, int numfile, int culumns, int size);
void mx_print_file(char **file, int size, int width, int num);
int mx_num_file(t_file *head);
t_file *mx_read_dir(char *dirname, int *flags, t_data *data);

#endif 
