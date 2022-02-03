/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:51:11 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/02 15:38:07 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_array(int *t, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - 1))
		{
			if (t[j] > t[j + 1])
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_upper(t_stack *b, int data)
{
	while (b != NULL)
	{
		if (b->data > data)
		{
			return (0);
		}
		b = b->next;
	}
	return (1);
}

int	get_upper(t_stack *b)
{
	int	max;

	max = b->data;
	while (b != NULL)
	{
		if (b->data > max)
		{
			return (0);
		}
		b = b->next;
	}
	return (1);
}

int	get_s_upper(t_stack *b)
{
	int		max1;
	int		max2;
	t_stack	*cp;

	cp = b;
	max1 = b->next->data;
	max2 = b->data;
	while (b != NULL)
	{
		if (b->data > max1)
		{
			return (0);
		}
		b = b->next;
	}
	b = cp;
	while (b != NULL)
	{
		if (b->data > max2 && max2 > max1)
		{
			return (0);
		}
		b = b->next;
	}
	return (1);
}
