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
    }
    return (1);
}

int	special_strcmp(char *s1)
{
	int			i;
	int j =0, x=0;
	char	*s2;

	s2 = ft_strdup("0123456789");
	i = 0;
	if (s1[i] == '-' || s1[i] == '+')
	{
		x++;
		i++;
	}
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				x++;
			j++;
		}
		i++;
	}
	free (s2);
	if (x == ft_strlen(s1))
		return (1);
	return (0);
}

int check_error(t_stack *lst)
{
    t_stack *cp;
    cp = lst;
    if (!ft_isdup(cp) /*|| !is_max(cp)*/)
        return (0);
    return (1);
}