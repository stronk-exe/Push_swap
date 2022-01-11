/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/01/08 12:10:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	t_stack	*temp = NULL;
	int		res = 0;

	temp = a->next;
	res = temp->data;
	temp->data = a->data;
	a->data = res;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b)
{
	t_stack	*temp = NULL;
	int		res = 0;

	temp = b->next;
	res = temp->data;
	temp->data = b->data;
	b->data = res;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp = NULL;
	t_stack	*t = NULL;

	t = ft_lstnew((*b)->data);
	if (b != NULL)
	{
		ft_lstadd_front(a, t);
		temp = *b;
		(*b) = (*b)->next;
		free(temp);
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp = NULL;
	t_stack	*t = NULL;

	t = ft_lstnew((*a)->data);
	if (a != NULL)
	{
		ft_lstadd_front(b, t);
		temp = *a;
		(*a) = (*a)->next;
		free(temp);
	}
	write(1, "pb\n", 3);
}

void	ft_ra(t_stack *a)
{
	t_stack	*temp = NULL;
	int		i = 0;
	int		res = 0;
	int		j = 0;

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
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	t_stack	*temp = NULL;
	int		i = 0;
	int		res = 0;
	int		j = 0;

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
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	write(1, "rr\n", 3);
}

void	ft_rra(t_stack **a)
{
	t_stack *temp = NULL;

	temp = ft_lstnew(ft_lstlast(*a)->data);
	ft_lstadd_front(a, temp);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	t_stack *temp = NULL;

	temp = ft_lstnew(ft_lstlast(*b)->data);
	ft_lstadd_front(b, temp);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
	write(1, "rrr\n", 4);
}

int	ft_isdup(t_stack *a)
{
	t_stack	*temp = NULL;
	int		res = 0;

	while (a != NULL)
	{
		res = a->data;
		temp = a->next;
		while (temp != NULL)
		{
			if (temp->data == res)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

int ft_is_sorted(t_stack *lst)
{
	t_stack	*temp = NULL;

	while (lst->next != NULL)
	{
		temp = lst->next;
		if (temp->data < lst->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_sort_3(t_stack **lst)
{
	t_stack	*v = NULL;
	int		a = 0;
	int		b = 0;
	int		c = 0;

	v = *lst;
	a = v->data;
	v = v->next;
	b = v->data;
	v = v->next;
	c = v->data;
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && a > c)
		ft_rra(lst);
	else if (a < b && b > c && a < c)
	{
		ft_sa(*lst);
		ft_ra(*lst);
	}
	else if (a < b && b < c)
	{
		ft_sa(*lst);
		ft_rra(lst);
	}
	else if (a > b && b < c && a < c)
		ft_sa(*lst);
	else if (a > b && b < c && a > c)
		ft_ra(*lst);
	else if (a > b && b > c)
	{
		ft_sa(*lst);
		ft_rra(lst);
	}
	else if (a > b && b < c)
		ft_ra(*lst);
}
/*
void	ft_sort_5(t_stack **lst)
{
	t_stack	*b;

	b = NULL;
	ft_pb(lst, &b);
	ft_pb(lst, &b);
	
	ft_sort_3(lst);
	//b
	while (b != NULL)
	{
		printf("data b:	%d\n", b->data);
		b = b->next;
	}*/
//	int i =0;
//	while (b != NULL)
//	{
/*		if (b->data > ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b);
			ft_ra(*lst);
		}*/
		/*else if (b->data > (*lst)->data)
		{
			ft_ra(*lst);
			if (b->data > (*lst)->data)
			{
				ft_ra(*lst);
			//	if (b->data < (*lst)->data)
			//	{
					ft_pa(lst, &b);
					ft_rra(lst);
					ft_rra(lst);
			/	}
				else
				{
					ft_ra(*lst);
					ft_pa(lst, &b);
					ft_ra(*lst);
				}*/
		/*	}
			else
			{
				ft_pa(lst, &b);
				ft_rra(lst);
			}
		}*/
	/*	else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
		{
			if(b->data < (*lst)->next->data)
			{
				ft_pa(lst, &b);
				ft_sa(*lst);
			}
			else
			{
				ft_ra(*lst);
				ft_pa(lst, &b);
				ft_sa(*lst);
				ft_rra(lst);
			}
		}
		
		else
			ft_pa(lst, &b);
*/

/*	if (b->data > (*lst)->data)
		{
			ft_ra(*lst);
			if (b->data > (*lst)->data)
			{
				ft_ra(*lst);
				if (b->data > (*lst)->data)
				{
					ft_ra(*lst);
					if (b->data < (*lst)->data)
					{
						ft_pa(lst, &b);
						ft_ra(*lst);
						ft_ra(*lst);
					}
					else
					{
						ft_ra(*lst);
						ft_pa(lst, &b);
						ft_ra(*lst);
					}
				}
				else
				{
					ft_pa(lst, &b);
					ft_rra(lst);
					ft_rra(lst);
				}
			}
			else
			{
				ft_pa(lst, &b);
				ft_rra(lst);
			}
		}
		else
			ft_pa(lst, &b);*//*
}
*/
int main(int argc, char **argv)
{
	int		i;
	int		data = 0;
	t_stack	*a = NULL;
//	t_stack	*b;
	t_stack	*node = NULL;

	if (argc > 2)
	{
//		b = ft_lstnew(0);
		i = 1;
		while (i < argc)
		{
			data = ft_atoi(argv[i]);
			node = ft_lstnew(data);
			ft_lstadd_back(&a, node);
			i++;
		}
		if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
//		if (ft_lstsize(a) == 5)
//			ft_sort_5(&a);
		while (a != NULL)
		{
			printf("%d\n", a->data);
			a = a->next;
		}
	}
}
