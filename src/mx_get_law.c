#include "uls.h"

static void get_type_file(t_const *cnst, struct stat st);

void mx_get_law(struct stat st, t_const *cnst) {
    cnst->strrwx = mx_strnew(10);
    cnst->strrwx[1] = (S_IRUSR & st.st_mode) ? 'r' : '-';        
    cnst->strrwx[2] = (S_IWUSR & st.st_mode) ? 'w' : '-';
    cnst->strrwx[3] = (S_IXUSR & st.st_mode) ? 'x' : '-';
    cnst->strrwx[4] = (S_IRGRP & st.st_mode) ? 'r' : '-';
    cnst->strrwx[5] = (S_IWGRP & st.st_mode) ? 'w' : '-';
    cnst->strrwx[6] = (S_IXGRP & st.st_mode) ? 'x' : '-';
    cnst->strrwx[7] = (S_IROTH & st.st_mode) ? 'r' : '-';
    cnst->strrwx[8] = (S_IWOTH & st.st_mode) ? 'w' : '-';
    cnst->strrwx[9] = (S_IXOTH & st.st_mode) ? 'x' : '-';
     if (S_ISGID & st.st_mode)
        cnst->strrwx[6] = cnst->strrwx[6] == 'x' ? 's' : 'S';
    if (S_ISUID & st.st_mode)
        cnst->strrwx[3] = cnst->strrwx[3] == 'x' ? 's' : 'S';
    if (S_ISVTX & st.st_mode)
        cnst->strrwx[9] = cnst->strrwx[9] == 'x' ? 't' : 'T';
    get_type_file(cnst, st);
}

static void get_type_file(t_const *cnst, struct stat st) {
    if (S_IFCHR == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = 'c';
    else if (S_IFBLK == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = 'b';
    else if (S_IFIFO == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = 'p';
    else if (S_IFREG == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = '-';
    else if (S_IFSOCK == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = 's';
    else if (S_IFLNK == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = 'l';
    else if (S_IFDIR == ( S_IFMT & st.st_mode))
        cnst->strrwx[0] = 'd';
}

