/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:49:59 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/05 12:33:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_utils/get_next_line.h"
#include "checker_utils/get_next_line.c"
#include "checker_utils/get_next_line_utils.c"
#include "actions.c"
#include "actions2.c"
#include "actions3.c"
#include "checker_utils/checker_utils.c"

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

int main(int argc, char **argv)
{
	int		i;
//	long		data;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*node = NULL;

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
		{
			if (ft_is_sortedd(a) && !b)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			return (0);
	/////////////////////////////// printing data //////////////////////////
		while (a != NULL || b != NULL)
		{
			if (a != NULL)
			{
				printf("%d", a->data);
				a = a->next;
			}
			else
			{
				printf(" ");
			//	a = a->next;
			}

			if (b != NULL)
			{
				printf(" %d\n", b->data);
				b = b->next;
			}
			else
			{
				printf("\n");
			//	b = b->next;
			}
		}
		printf("_  _\n");
		printf("a  b\n");
	/////////////////////////////// printing data //////////////////////////
	//	lstclear
	}
}
