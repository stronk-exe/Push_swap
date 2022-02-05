/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:26 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/05 15:07:50 by ael-asri         ###   ########.fr       */
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
	if (!special_strcmp(av) || !ft_strcmp(av, "\"\""))
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
	if (ft_lstsize(*a) < 5)
		small_sort(a);
	else if (ft_lstsize(*a) <= 100)
	{
		if (!recursive_sort(a))
			return (0);
	}
	else
	{
		if (!recursive_sort_2(a))
			return (0);
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
		// lstclear a, node


	/////////////////////////////////////// testing /////////////////////////////////////////////////
	/*	int count = 0;
		if (ft_is_sorted(a))
			printf("1\n");
		else
			printf("0\n");
		printf("----\n");
		while (a != NULL)
		{
	//		printf("%d\n", a->data);
			a = a->next;
			count++;
		}
		printf("count %d\n", count);
	//	system("leaks a.out");*/
	/////////////////////////////////////// testing /////////////////////////////////////////////////
	}
}

// 5 4 23 0 1
// 5 8 0 9 1
//-5 40 -30 20 10
// 82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 -9
//82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 72

