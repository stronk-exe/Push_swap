/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:26 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 18:46:15 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *lst)
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

int	ft_is_sorted_v2(t_stack *lst)
{
	t_stack	*temp;

	while (lst->next != NULL)
	{
		temp = lst->next;
		if (temp->data > lst->data)
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

int	do_something(t_stack **a)
{
	if (ft_lstsize(*a) <= 5)
		small_sort(a);
	else
	{
		if (!new_sort(a))
		{
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*node;

	a = NULL;
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
		if (!check_error(a) || ft_is_sorted(a))
			return (0);
		if (!do_something(&a))
			return (0);
	}
}
