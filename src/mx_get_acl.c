#include "uls.h"

void mx_get_acl(t_const *cnst) {
    acl_t acl = NULL;
    ssize_t attr = 0;
    char *name = cnst->ful_n == NULL ? cnst->name : cnst->ful_n;

    cnst->stracl = NULL;
    attr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(name, ACL_TYPE_EXTENDED);
    if (attr > 0) {
        cnst->stracl = mx_strdup("@");
        acl_free(acl);
    }
    else if (acl != NULL) {
        cnst->stracl = mx_strdup("+");
        acl_free(acl);
    }
}

