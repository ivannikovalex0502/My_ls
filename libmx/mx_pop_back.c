#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *nodetmp = *head;
    t_list *headsave = *head;

    if(*head == NULL)
        return;
    if(headsave->next == NULL) {
        free(headsave);
        headsave = NULL;
        return;
    }
    while(headsave->next != NULL) {
        nodetmp = headsave;
        headsave = headsave->next;
    }
    nodetmp->next = NULL;
    free(headsave);
}
