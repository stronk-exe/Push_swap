/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/01/06 14:58:02 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	t_stack	*temp;
	int		res;

	temp = a->next;
	res = temp->data;
	temp->data = a->data;
	a->data = res;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b)
{
	t_stack	*temp;
	int		res;

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
	t_stack	*temp;
	t_stack	*t;

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
	t_stack	*temp;
	t_stack	*t;

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
	t_stack	*temp;
	int		i;
	int		res;
	int		j;

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
	t_stack	*temp;
	int		i;
	int		res;
	int		j;

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
	t_stack *temp;

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
	t_stack *temp;

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

int ft_is_sorted_v2(t_stack *lst)
{
	t_stack	*temp;

	while (lst->next != NULL)
	{
		temp = lst->next;
		if (temp->data > lst->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_sort_3(t_stack **lst)
{
	t_stack	*v;
	int		a;
	int		b;
	int		c;

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

void	ft_sort_5(t_stack **lst)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*lst) == 5)
		ft_pb(lst, &b);
	ft_pb(lst, &b);
	
	ft_sort_3(lst);

	if (b->data > ft_lstlast(*lst)->data)
	{
		ft_pa(lst, &b);
		ft_ra(*lst);
	}
	else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
	{
		if (b->data < (*lst)->next->data)
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
	if (b == NULL)
		return ;
	if (b->data > ft_lstlast(*lst)->data)
	{
		ft_pa(lst, &b);
		ft_ra(*lst);
	}
	else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
	{
		if (b->data > (*lst)->next->data)
		{
			if (b->data < (*lst)->next->next->data)
			{
				ft_ra(*lst);
				ft_pa(lst, &b);
				ft_sa(*lst);
				ft_rra(lst);
			}
			else
			{
				ft_rra(lst);
				ft_pa(lst, &b);
				ft_ra(*lst);
				ft_ra(*lst);
			}
		}
		else
		{
			ft_pa(lst, &b);
			ft_sa(*lst);
		}
	}
	else
		ft_pa(lst, &b);
}



void	ft_sort_100(t_stack **lst)
{
	t_stack	*b;
	t_stack *cp;
	int		temp[100];
	int		i;
	int		j;
	int		min;
//	int		c;
//	int		m;

int min1;
int min2;
int total;
	int x;

	i = 0;
	cp = *lst;
//	b = ft_lstnew(0);
	while (i < 100)
	{
		temp[i] = i;
		i++;
	}


	min = (*lst)->data;
	
min1 = (*lst)->data;
min2 = (*lst)->data;

	while (*lst != NULL)
	{
		cp = *lst;
		min = cp->data;
		total = ft_lstsize(cp);
		j = 0;
		x = 0;
	/*	while (cp != NULL && j < total)
		{
			if (min > cp->data)
			{
				min = cp->data;
				x = j;
			}
			cp = cp->next;
			j++;
		}*/
/////////////////////////////////////////////////////////
		total = ft_lstsize(cp);
	/*	if (total < 3)
		{
			if (ft_lstsize(cp) == 2)
			{
				if (!ft_is_sorted(cp))
					ft_sa(cp);
			}
		}
		else
		{*/
			min1 = cp->data;
			
			//j = 1;
			while (cp != NULL && j < (total / 3))
			{
				if (min1 > cp->data)
				{
					min1 = cp->data;
					x = j;
				}
				cp = cp->next;
				j++;
			}

			while (cp != NULL && j < (((total * 2) / 3)))
			{
				cp = cp->next;
				j++;
			}
			
			min2 = cp->data;
			while (cp != NULL && j <= total)
			{
				if (min2 > cp->data)
				{
					min2 = cp->data;
					x = j;
				}
				cp = cp->next;
				j++;
			}

			if (x < (j / 3))
			{
				while (x > 0)
				{
					ft_ra(*lst);
					x--;
				}
			}
			else
			{
				while (x < total)
				{
					ft_rra(lst);
					x++;
				}
			}

		if (b != NULL)
		{
			while ((*lst)->data > b->data && b != NULL)
			{
				ft_rb(b);
				b = b->next;
			}
		}
	//	}
		ft_pb(lst, &b);
	//	}
	//	ft_pb(lst, &b);
		
		/*	while (!ft_is_sorted_v2(b))
			{
				//if (ft_is_sorted_v2(b))
				//	break ;
				ft_ra(b);
				b = b->next;
			}
			ft_pb(lst, &b);*/
		//	ft_rrb(&b);
		//}
		//else
		//{
		/*	ft_pb(lst, &b);
			printf("%d\n", min1);
			printf("%d\n", min2);*/
		//}
			
/////////////////////////////////////////////////////////	
/*		if (x < (j / 2))
		{
			while (x > 0)
			{
				ft_ra(*lst);
				x--;
			}
		}
		else
		{
			while (x < j)
			{
				ft_rra(lst);
				x++;
			}
		}
		ft_pb(lst, &b);*/
	}
/*	while (b != NULL)
	{
		printf("%d\n", b->data);
		b = b->next;
	}*/
		
	while (b != NULL)
	{
		ft_pa(lst, &b);
	//	b = b->next;
	}
}

int main(int argc, char **argv)
{
	int		i;
	int		data;
	t_stack	*a;
	t_stack	*b;	
	t_stack	*node;

	if (argc > 2)
	{
		b = ft_lstnew(0);
		i = 1;
		while (i < argc)
		{
			data = ft_atoi(argv[i]);
			node = ft_lstnew(data);
			ft_lstadd_back(&a, node);
			i++;
		}
		if (!ft_isdup(a))
			return (0);
		//if (ft_is_sorted(a))
	//		return 0;
		if (ft_lstsize(a) == 2)
		{
			if (!ft_is_sorted(a))
				ft_sa(a);
		}
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else if (ft_lstsize(a) <= 5)
			ft_sort_5(&a);
		else if (ft_lstsize(a) <= 100)
			ft_sort_100(&a);


		
		while (a != NULL)
		{
			printf("%d\n", a->data);
			a = a->next;
		}
	}
}

//ARG=""; ./a.out $ARG | ./checker_OS $ARG

//82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 72