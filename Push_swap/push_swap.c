/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2021/12/15 22:27:33 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	//t_stack	*temp;

	if (b != NULL)
	{
		//temp = ft_lstlast(b);
		ft_lstadd_back(&a, ft_lstlast(b));
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	//t_stack	*temp;

	if (a != NULL)
	{
		//temp = ft_lstlast(b);
		ft_lstadd_back(&b, ft_lstlast(a));
	}
}

void	ft_ra(t_stack *a)
{
	t_stack	*temp;
	int		first;

	first = a->data;
	temp = a->next;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next)
		{
			a->data = first;
			break ;
		}
		a->data = temp->data;
		a = a->next;
	}
}

void	ft_rb(t_stack *b)
{
	t_stack	*temp;
	int		first;

	first = b->data;
	temp = b->next;
	while (b->next != NULL)
	{
		temp = temp->next;
		if (temp->next != NULL)
		{
			b->data = first;
			break ;
		}
		b->data = temp->data;
		b = b->next;
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}

void	ft_rra(t_stack *a)
{
	t_stack	*temp;
	int		last;
	int 	res;

	temp = ft_lstlast(a);
	last = temp->data;
	a->data = last;
	temp = a->next;
	while (a->next != NULL)
	{
		temp->data = a->data;
		a = a->next;
		res = a->data;
		temp->data = res;
		a->data = temp->data;
	}
}

int main(int argc, char **argv)
{
	int		i;
	int		data;
	t_stack	*a;
	t_stack	*b;	
	t_stack	*node;

	//a = ft_lstnew(20);
	b = ft_lstnew(0);
	i = 1;
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		node = ft_lstnew(data);
		//printf("%d\n", node->data);
		ft_lstadd_back(&a, node);
		//free(node);
		//node->data = 0;
		//printf("%d\n",i);
		i++;
	}
	ft_pa(a, b);
	//ft_pb(a, b);
	//t_stack *r;
	//r = ft_lstlast(a);
	// printf("data a :%d", a->data);
	// printf("\n");
	
	// while(a != NULL)
	// {
	// 	printf("data a :	%d\n", a->data);
	// 	a = a->next;
	// }
	printf("data a :	%d\n", ft_lstlast(a)->data);
}
