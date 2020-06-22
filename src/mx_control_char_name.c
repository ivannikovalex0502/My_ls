#include "uls.h"

void mx_control_char_name(char **str) {
    for (int i = 0; (*str)[i] != '\0'; i++) {
        if ((*str)[i] == '\t' 
            || (*str)[i] == '\n'
            || (*str)[i] == '\r' 
            || (*str)[i] == '\f'
            || (*str)[i] == '\a'
            || (*str)[i] == '\b'
            || (*str)[i] == '\v'
            || (*str)[i] == '\033')
        {
                (*str)[i] = '?';
        }
    }
}
