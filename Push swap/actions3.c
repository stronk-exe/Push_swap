/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:41:35 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/08 21:12:23 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss(t_stack *a, t_stack *b, char *s)
{
	if (ft_lstsize(a) < 2 || ft_lstsize(b) < 2)
		return (0);
	ft_sa(a, "");
	ft_sb(b, "");
	ft_putstr(s);
	return (1);
}

int	ft_rr(t_stack *a, t_stack *b, char *s)
{
	if (ft_lstsize(a) < 2 || ft_lstsize(b) < 2)
		return (0);
	ft_ra(a, "");
	ft_rb(b, "");
	ft_putstr(s);
	return (1);
}

int	ft_rrr(t_stack **a, t_stack **b, char *s)
{
	if (!ft_rra(a, ""))
		return (0);
	if (!ft_rrb(b, ""))
		return (0);
	ft_putstr(s);
	return (1);
}
