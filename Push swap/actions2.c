/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:43:29 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 09:27:44 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_stack *a, char *s)
{
	t_stack	*temp;
	int		i;
	int		res;
	int		j;

	if (ft_lstsize(a) <= 0)
		return (0);
	i = 0;
	j = ft_lstsize(a) - 1;
	temp = a->next;
	while (i < j)
	{
		res = a->data;
		a->data = temp->data;
		temp->data = res;
		a = a->next;
		temp = temp->next;
		i++;
	}
	ft_putstr(s);
	return (1);
}

int	ft_rb(t_stack *b, char *s)
{
	t_stack	*temp;
	int		i;
	int		res;
	int		j;

	if (ft_lstsize(b) <= 0)
		return (0);
	i = 0;
	j = ft_lstsize(b) - 1;
	temp = b->next;
	while (i < j)
	{
		res = b->data;
		b->data = temp->data;
		temp->data = res;
		b = b->next;
		temp = temp->next;
		i++;
	}
	ft_putstr(s);
	return (1);
}

int	ft_rra(t_stack **a, char *s)
{
	t_stack	*temp;

	if (ft_lstsize(*a) <= 0)
		return (0);
	temp = ft_lstnew(ft_lstlast(*a)->data);
	if (!temp)
		return (0);
	ft_lstadd_front(a, temp);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr(s);
	return (1);
}

int	ft_rrb(t_stack **b, char *s)
{
	t_stack	*temp;

	if (ft_lstsize(*b) <= 0)
		return (0);
	temp = ft_lstnew(ft_lstlast(*b)->data);
	if (!temp)
		return (0);
	ft_lstadd_front(b, temp);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr(s);
	return (1);
}
