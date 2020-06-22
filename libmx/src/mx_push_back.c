#include "libmx.h"

void mx_push_back(t_list **list, void *data) { 
    t_list *node = *list;

    if(*list == NULL) {
        t_list *node = malloc(sizeof(t_list));
        node -> data = data;
        node -> next = NULL;
        *list = node;
        return;
    }
    while(node -> next != NULL)
        node = node -> next;
    node -> next = malloc(sizeof(t_list));
    node -> next -> data = data;
    node -> next -> next = NULL;
}
