#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    t_list *node = *list;
    while (node->next) {
        node = node->next;
    }
    node->next = mx_create_node(data);
}


