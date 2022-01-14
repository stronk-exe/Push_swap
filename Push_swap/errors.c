#include "push_swap.h"

int	ft_isdup(t_stack *a)
{
	t_stack	*temp;
	int		res;

	while (a != NULL)
	{
		res = a->data;
		temp = a->next;
		while (temp != NULL)
		{
			if (temp->data == res)
			{
			//	write(2, "Error\n", 6);
				return (0);
			}
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

int is_max(t_stack *lst)
{
    while (lst != NULL)
    {
        if ((lst->data) > 2147483647)
        {
            return (0);
        }
        lst = lst->next;
        printf("hi\n");
    }
    return (1);
}
int check_error(t_stack *lst)
{
    t_stack *cp;
    cp = lst;
    if (!is_max(cp))
        return (0);
    return (1);
}