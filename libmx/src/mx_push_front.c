#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *node = malloc(sizeof(t_list));

    node -> next = *list;
    node -> data = data;
    *list = node;
}
