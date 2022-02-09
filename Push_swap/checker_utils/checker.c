/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:49:59 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 11:57:20 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	ft_is_sortedd(t_stack *lst)
{
	t_stack	*temp;

	while (lst->next != NULL)
	{
		temp = lst->next;
		if (temp->data < lst->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_stack	*get_data(char *av)
{
	int		i;
	long	data;
	t_stack	*node;

	i = 0;
	node = NULL;
	if (!special_strcmp(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	data = ft_atoi(av);
	if (data > 2147483647 || data < -2147483648)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	node = ft_lstnew((int)data);
	return (node);
}

void	ok_ko(t_stack *a, t_stack *b)
{
	if (ft_is_sortedd(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*node;

	a = NULL;
	b = NULL;
	node = NULL;
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			node = get_data(argv[i]);
			if (!node)
				return (0);
			ft_lstadd_back(&a, node);
			i++;
		}
		if (!check_error(a))
			return (0);
		if (get_actions(&a, &b))
			ok_ko(a, b);
		return (0);
	}
}
