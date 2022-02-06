/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:41:35 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/06 20:58:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *a, t_stack *b, char *s)
{
	ft_sa(a, "");
	ft_sb(b, "");
	ft_putstr(s);
}

void	ft_rr(t_stack *a, t_stack *b, char *s)
{
	ft_ra(a, "");
	ft_rb(b, "");
	ft_putstr(s);
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
