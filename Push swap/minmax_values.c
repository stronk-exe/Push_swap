/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:59:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 15:14:03 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value5(t_stack *lst)
{
	int	min;
	int	j;

	j = 0;
	min = lst->data;
	while (lst != NULL)
	{
		if (min < lst->data)
			min = lst->data;
		lst = lst->next;
		j++;
	}
	return (min);
}

int	get_2th_max_value5(t_stack *lst, int val)
{
	int	min;
	int	j;

	j = 0;
	min = lst->data;
	while (lst != NULL && lst->data != val)
	{
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
		j++;
	}
	return (min);
}
