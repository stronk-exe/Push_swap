/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:46:13 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/08 13:04:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_m(int max, int len)
{
	if (max > (len / 2))
		return (len - max);
	else
		return (max);
}

t_stack	**b_to_a(t_stack **lst, t_stack *b)
{
	int	max1;
	int	max2;
	int	val;
	int	m1;
	int	m2;

	while (ft_lstsize(b) > 0)
	{
		max1 = get_max_index5(b);
		val = get_min_value5(b);
		max2 = get_2th_max_index5(b, val);
		m1 = check_m(max1, ft_lstsize(b));
		m2 = check_m(max2, ft_lstsize(b));
		if (m1 > m2)
		{
			b = do_action_bctoa5(lst, b, max2);
			max1 = get_max_index5(b);
			b = do_action_bctoa5(lst, b, max1);
			if ((*lst)->data > (*lst)->next->data)
				ft_sa(*lst, "sa\n");
		}
		else
			b = do_action_bctoa5(lst, b, max1);
	}
	return (lst);
}
