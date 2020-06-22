#include "uls.h"

void mx_get_uid(struct stat st, t_const *cnst) {
    struct passwd *pw;

    pw = getpwuid(st.st_uid);
    if (pw == NULL)
        cnst->struid = mx_itoa((int)st.st_uid);
    else 
        cnst->struid = mx_strdup(pw->pw_name);
}
