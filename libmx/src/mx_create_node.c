#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *node = malloc(sizeof(t_list));

    node->next = NULL;
    node->data = data;
    return node;
}
