/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:37:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/02 15:38:57 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_index(t_stack **lst, int *t, int mid)
{
	int	i;

	i = 0;
	while (i < (ft_lstsize(*lst) / 2))
	{
		if (t[i] < mid)
			break ;
		i++;
	}
	return (i);
}

int	get_pos_index_rev(t_stack **lst, int *t, int mid)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(*lst) - 1;
	while (j > (ft_lstsize(*lst) / 2))
	{
		if (t[j] < mid)
			break ;
		j--;
	}
	return (j);
}

int	get_index(t_stack **lst, int mid)
{
	t_stack	*cp;
	int		i;
	int		j;
	int		*t;

	i = 0;
	cp = *lst;
	t = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
	while (cp != NULL)
	{
		t[i] = cp->data;
		cp = cp->next;
		i++;
	}
	t[i] = '\0';
	i = get_pos_index(lst, t, mid);
	j = get_pos_index_rev(lst, t, mid);
	if (i < ((ft_lstsize(*lst) - j)))
		return (i);
	return (j);
}
