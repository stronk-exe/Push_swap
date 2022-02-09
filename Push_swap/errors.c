/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:19 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 15:11:20 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdup(t_stack *a)
{
	t_stack	*temp;
	int		res;

	while (a != NULL)
	{
		res = a->data;
		temp = a->next;
		while (temp != NULL)
		{
			if (temp->data == res)
			{
				return (0);
			}
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

int	is_max(t_stack *lst)
{
	while (lst != NULL)
	{
		if ((lst->data) > 2147483647)
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	special_strcmp(char *s)
{
	int		i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && (s[i + 1] != '\0'))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_error(t_stack *lst)
{
	t_stack	*cp;

	cp = lst;
	if (!ft_isdup(cp))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
