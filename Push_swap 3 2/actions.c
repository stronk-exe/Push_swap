/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:49:39 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/05 13:57:46 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, char *s)
{
	t_stack	*temp;
	int		res;

	temp = a->next;
	res = temp->data;
	temp->data = a->data;
	a->data = res;
	ft_putstr(s);
}

void	ft_sb(t_stack *b, char *s)
{
	t_stack	*temp;
	int		res;

	temp = b->next;
	res = temp->data;
	temp->data = b->data;
	b->data = res;
	ft_putstr(s);
}

int	ft_pa(t_stack **a, t_stack **b, char *s)
{
	t_stack	*temp;
	t_stack	*t;

	if (!b)
		return (0);
	t = ft_lstnew((*b)->data);
	if (!t)
		return (0);
	if (b != NULL)
	{
		ft_lstadd_front(a, t);
		temp = *b;
		(*b) = (*b)->next;
		free(temp);
	}
	ft_putstr(s);
	return (1);
}

int	ft_pb(t_stack **a, t_stack **b, char *s)
{
	t_stack	*temp;
	t_stack	*t;

	if (!a)
		return (0);
	t = ft_lstnew((*a)->data);
	if (!t)
		return (0);
	if (a != NULL)
	{
		ft_lstadd_front(b, t);
		temp = *a;
		(*a) = (*a)->next;
		free(temp);
	}
	ft_putstr(s);
	return (1);
}
