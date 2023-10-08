#include "../inc/libmx.h"

void mx_pop_back(t_list **list) {
	if (*list == NULL || list == NULL) {
        	return;
    	}
    	if ((*list)->next == NULL) {
        	free(*list);
        	*list = NULL;
        	return;
    		}	
	t_list *node = *list;
    	while (node->next->next) {
        	node = node->next;
    		}
   	free(node->next);
    	node->next = NULL;
    	node = NULL;
}


