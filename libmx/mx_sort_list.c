#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    int len = mx_list_size(list);
    t_list *node = list;

    for(int i = 0; i < len - 1; i++) {
        node = list;
        for(int j = 0; j < len - i - 1; j++) {
            if(cmp(node -> data, node -> next -> data)) {
                void *tmp = node -> data;
                node -> data = node -> next -> data;
                node -> next -> data = tmp;
            }
            node = node -> next;
        }
    }
    return list;
}
