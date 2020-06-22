#include "uls.h"

void mx_check_control_char(char ***str) {
    for (int i = 0; *str != NULL && (*str)[i] != NULL; i++)
        for (int j = 0; (*str)[i][j] != '\0'; j++)
            if ((*str)[i][j] == '\t' 
                || (*str)[i][j] == '\n'
                || (*str)[i][j] == '\r' 
                || (*str)[i][j] == '\f'
                || (*str)[i][j] == '\a'
                || (*str)[i][j] == '\b'
                || (*str)[i][j] == '\v'
                || (*str)[i][j] == '\033')
            {
                (*str)[i][j] = '?';
            } 
}
