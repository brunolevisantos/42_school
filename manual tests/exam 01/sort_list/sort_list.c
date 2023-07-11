#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *curr;

	curr = lst;
	while (curr)
	{
		cmp(curr->data, curr->next->data);
		curr = curr->next;
	}
}