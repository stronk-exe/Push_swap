/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:26 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/03 22:56:16 by ael-asri         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		i;
	long		data;
	t_stack	*a = NULL;
	t_stack	*node = NULL;

	if (argc > 2)
	{
	//	printf("ac %d\n", argc);
		i = 1;
		while (i < argc)
		{
			if (!special_strcmp(argv[i]))
			{
				write(2, "Error\n", 6);
				return 0;
			}
			data = ft_atoi(argv[i]);
			if (data > 2147483647)
			{
				write(2, "Error\n", 6);
				return 0;
			}
			node = ft_lstnew((int)data);
			ft_lstadd_back(&a, node);
			i++;
		}
		if (ft_is_sorted(a))
			return (0);
		if (!check_error(a))
		{
			write(2,"Error\n", 6);
			return 0;
		}
		if (ft_lstsize(a) < 5)
			small_sort(&a);
		//	ft_sort_5(&a);
		else if (ft_lstsize(a) <= 100)
		{
			//if (!recursive_sort(&a))
			if (!recursive_sort(&a))
				return (0);
		}
		else
		{
			if (!recursive_sort_2(&a))
				return (0);
		}

	/////////////////////////////////////// testing /////////////////////////////////////////////////
	/*	int count = 0;
		if (ft_is_sorted(a))
			printf("1\n");
		else
			printf("0\n");
		while (a != NULL)
		{
			printf("%d\n", a->data);
			a = a->next;
			count++;
		}
		printf("count %d\n", count);*/
	/////////////////////////////////////// testing /////////////////////////////////////////////////
	}
}

// 5 4 23 0 1
// 5 8 0 9 1
//-5 40 -30 20 10
// 82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 -9
//82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 72

