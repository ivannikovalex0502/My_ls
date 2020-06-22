#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *pointer = NULL;

    if(*head == NULL)
        return;
    pointer = (*head) -> next;
    free(*head);
    *head = NULL;
    *head =  pointer; 
}
