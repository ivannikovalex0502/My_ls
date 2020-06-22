#include "uls.h"

static void len(t_data *data, t_const *cnst);

void mx_get_flag_l(t_const *cnst, t_data *data) {
    struct stat st;

    cnst->ful_n == NULL ? lstat(cnst->name, &st) : lstat(cnst->ful_n, &st);
    mx_get_blocks(st, cnst); // -s
    mx_get_uid(st, cnst); 
    mx_get_gid(st, cnst);
    mx_get_link(st, cnst);
    mx_get_size_bytes(st, cnst); 
    mx_get_ino(st, cnst); // -i
    mx_get_time(st, cnst, data); // atime mtime 
    mx_get_law(st, cnst); //permissions
    mx_get_dev(st, cnst); 
    mx_get_rdev(st, cnst); // FOR CHAR SP
    mx_get_minmaj(cnst); // CHAR SP
    mx_get_acl(cnst); // ACL
    mx_read_link(cnst);
    len(data, cnst);
    data->total += cnst->blocks;
    if (mx_isspecial(cnst))
        data->flag_minmaj = 1;
}

static void len(t_data *data, t_const *cnst) {
    if (cnst->stracl != NULL)
        data->acl = 1;
    if (mx_strlen(cnst->struid) > data->max_len_uid)
        data->max_len_uid = mx_strlen(cnst->struid);
    if (mx_strlen(cnst->strgid) > data->max_len_gid)
        data->max_len_gid = mx_strlen(cnst->strgid);
    if (mx_strlen(cnst->strlinkcount) > data->max_len_link)
        data->max_len_link = mx_strlen(cnst->strlinkcount);
    if (mx_strlen(cnst->strbytes) > data->max_len_bytes)
        data->max_len_bytes = mx_strlen(cnst->strbytes);
    if (mx_strlen(cnst->strmaj) > data->max_len_maj && cnst->strmaj[1] != 'x')
        data->max_len_maj = mx_strlen(cnst->strmaj);
    if (mx_strlen(cnst->strmin) > data->max_len_min && cnst->strmin[1] != 'x')
        data->max_len_min = mx_strlen(cnst->strmin);
    if (mx_strlen(cnst->strino) > data->max_len_ino)
        data->max_len_ino = mx_strlen(cnst->strino);
    if (mx_strlen(cnst->strblocks) > data->max_len_blocks)
        data->max_len_blocks = mx_strlen(cnst->strblocks);
}
