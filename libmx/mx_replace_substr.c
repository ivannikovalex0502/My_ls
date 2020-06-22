#include "libmx.h"

static void clear(char **res, int count, char *replace, char *tmp) {
    char *tmp_for_free = NULL;
    char *free_last = NULL;
    char *free_result = NULL;

    if(count == 0)
        *res = mx_strjoin(replace, tmp);
    else if(count > 0) {
        tmp_for_free = mx_strnew(count);
        mx_strncpy(tmp_for_free, *res, count);
        free_last = mx_strjoin(tmp_for_free, replace);
        free_result = *res;
        *res = mx_strjoin(free_last, tmp);
        free(free_last);
        free(tmp_for_free);
        free(free_result);
    }
}

static char *ret(char *str, char *replace, char *sub, int num) {
    int sublen = mx_strlen(sub);
    int count = mx_strlen(replace) * num;
    char *res = mx_strnew((mx_strlen(str) - count) + (sublen * num));
    char *tmp = str;
    char *rest = res;

    count = 0;
    for(int i = 0; i < num; i++) {
        str += mx_get_substr_index(str, sub);
        tmp += (mx_get_substr_index(str, sub) + sublen);
        count += mx_get_substr_index(str, sub);
        clear(&res, count, replace, tmp);
        count += mx_strlen(replace);
        str += sublen;
    }
    free(rest);
    return res;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int num = mx_count_substr(str, sub);

    if(str == NULL || sub == NULL || replace == NULL)
        return NULL;
    else if(!*sub)
        return (char *)str;
    return ret((char *)str, (char *)replace, (char *)sub, num);
}
