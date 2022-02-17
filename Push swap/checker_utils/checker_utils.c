/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:10 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 11:58:13 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	mini_actions(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "pa\n"))
	{
		ft_pa(a, b, "");
	}
	else if (!ft_strcmp(s, "pb\n"))
	{
		ft_pb(a, b, "");
	}
	else if (!ft_strcmp(s, "sa\n"))
	{
		ft_sa(*a, "");
	}
	else if (!ft_strcmp(s, "sb\n"))
	{
		ft_sb(*b, "");
	}
	else
		return (0);
	return (1);
}

int	mini_actions2(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "ss\n"))
	{
		ft_ss(*a, *b, "");
	}
	else if (!ft_strcmp(s, "ra\n"))
	{
		ft_ra(*a, "");
	}
	else if (!ft_strcmp(s, "rb\n"))
	{
		ft_rb(*b, "");
	}
	else if (!ft_strcmp(s, "rr\n"))
	{
		ft_rr(*a, *b, "");
	}
	else
		return (0);
	return (1);
}

int	mini_actions3(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "rra\n"))
	{
		ft_rra(a, "");
	}
	else if (!ft_strcmp(s, "rrb\n"))
	{
		ft_rrb(b, "");
	}
	else if (!ft_strcmp(s, "rrr\n"))
	{
		ft_rrr(a, b, "");
	}
	else
		return (0);
	return (1);
}

int	get_actions(t_stack **a, t_stack **b)
{
	char	*s;
	int		d;

	d = 0;
	s = get_next_line(0);
	while (s)
	{
		if (mini_actions(a, b, s))
			d = 1;
		else if (mini_actions2(a, b, s))
			d = 1;
		else if (mini_actions3(a, b, s))
			d = 1;
		else
			d = 0;
		free(s);
		if (!d)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		s = get_next_line(0);
	}
	return (1);
}

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
