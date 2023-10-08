#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool(*cmp)(void*, void*)) {
	bool end = false;
	while (!end) {
		end = true;
        	for (t_list *temp1 = lst; temp1 -> next != NULL; temp1 = temp1->next) {
            		if (cmp(temp1->data, temp1->next->data)) {
                   		end = false;
                   		void *temp = temp1 -> data;
                		temp1 -> data = temp1 -> next -> data; 
                		temp1 -> next ->data = temp; 
                   		}
                   	}
                   }
                    
    return lst;
}


