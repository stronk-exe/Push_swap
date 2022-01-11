/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/01/11 23:06:07 by ael-asri         ###   ########.fr       */
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

	if (ft_lstsize(*lst) == 2)
	{
		if (!ft_is_sorted(*lst))
			ft_sa(*lst);
	}
	else if (ft_lstsize(*lst)  == 3)
		ft_sort_3(lst);
	else
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
}


//////////////////////////////////////////////
void recursive_sort(t_stack **lst)
{
	t_stack *b = NULL;
	t_stack *cp;
	int *t;
	int mid;
	int i=0, j=0;
	int x =0;
//	int y=0;
	int min;
	int ty=0;
//	int index =0;
//	t_stack *gg;
//	gg = *lst;

	min =0;
	cp = *lst;
	int len = ft_lstsize(cp);
//	printf("%d", len);
	i = 0;
	t = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
	//if (!t)
	//	return NULL;
	while (cp != NULL)
	{
		t[i] = cp->data;
		cp = cp->next;
		i++;
	}
	t[i] = '\0';
	ft_sort_array(t, len);
	mid = t[ft_lstsize(*lst) / 2];
//	printf("mid %d\n", mid);
	i = 0;
	
//	printf("len %d\n", len/2);
//	printf("i %d", i);
	ty = 0;
	while (i < len && ty < (len / 2))
	{
	/////////////////////////////////////////////////////////
	//	printf("i %d", i);
		if ((*lst)->data < mid)
		{
			ft_pb(lst, &b);
			ty++;
		}
		else if (ft_lstlast(*lst)->data < mid)
		{
			ft_rra(lst);
			ft_pb(lst, &b);
			ty++;
		}
		else
			ft_ra(*lst);
		///////////////////////////////////////////////////
	//	while (cb != NULL /*&& j < ft_lstsize(cb)*/)
	//	{
		//	min = get_small(*lst);
		//	if (min < mid)
		//	{
		/*		gg = *lst;
				index = get_index(gg, mid);
				printf("indexxx  %d\n", index);
//				printf("index  %d", index);
				//if (index >= 0)
				//{
					if (index < (ft_lstsize(*lst) / 2))
					{
						
						while (index > 0)
						{
							ft_ra(*lst);
							index--;
						}
					}
					else
					{
						while (index < len)
						{
							ft_rra(lst);
							index++;
						}
					}
					ft_pb(lst, &b);
					ty++;
				//}
		//	}
			gg = *lst;*/
		//	j++;
	//	}
		///////////////////////////////////////////////////
	//	(*lst) = (*lst)->next;  //////////// -- -2 2 4 -- 5 76 99 102 ////  || -2 4 2 ||  102 76 99 ----->>>  -2 4 2 5 76 99 102 
		i++;
	}
//	j = 0;
//	printf("finished\n");
//	printf("ty %d\n", ty);
//	printf("len/2 %d\n", len/2);
//	printf("chuncka\n");            ///////////////  -2 0 2 4 5 /6/ 76 99 102 899 --- ra-pb-pb-ra-pb-ra-pb-pb ---->>> 5 4 2 -2 0 || 899 6 76 99 102
	//// just dispplying

/*	while (cp != NULL)
	{
		printf("cp: %d\n", cp->data);
		cp = cp->next;
	}*/
	/////////////////
	if (ft_lstsize(*lst) > 5)
		recursive_sort(lst);
	else
	{
		ft_sort_5(lst);
	//	printf("yo\n");
	}
//	printf("end recu\n");
//	int x;
//	i = len/2;
//printf("-----------i %d", i);
//printf("size1 %d\n", (ft_lstsize(b)));
	x = ft_lstsize(b);
//	printf("-----------lst1 %d\n", ft_lstsize(b));
//	printf("-----------x %d", x);
	t_stack *cb;
	while (ft_lstsize(b) > 0)
	{
	//	x = get_upper(b);
		cb = b;
		j =0;
		x =0;
		min = cb->data;
		if (!get_upper(b))
		{
		/*	if (ft_lstsize(b) <= 5)
			{
				special_sort_5(&b);
				while (b->next != NULL)
				{
			//		ft_rrb(&b);
					ft_pa(lst, &b);
				//	printf("why\n");
				}
			//	ft_pa(lst, &b);
			}
			else
			{*/
		//		printf("oii\n");
				j =0;
				while (cb != NULL /*&& j < ft_lstsize(cb)*/)
				{

					if (min < cb->data)
					{
						min = cb->data;
						x = j;
					}
					cb = cb->next;
					j++;
				}
	//			printf("j     %d\n", j);
				if (x <= (j / 2))
				{
		//			y = x-1;
					while (x > 0)
					{
						ft_rb(b);
						x--;
					}
				//	ft_pa(lst, &b);
				/*	while (y > 0)
					{
						ft_rrb(&b);
						y--;
					}*/
				}
				else
				{
					while (x < j)
					{
						ft_rrb(&b);
						x++;
					}
				//	ft_pa(lst, &b);
				}
				ft_pa(lst, &b);
				
		//	}
		}
		else
			ft_pa(lst, &b);
//		printf("then whatt??\n");



	/*		while (x > 0)
			{
				ft_rb(b);
				x--;
			}*/
			
		/*	ft_pa(lst, &b);
			x = get_upper(b);
			while (x > 0)
			{
				ft_rrb(&b);
				x--;
			}*/
	//	}
	//	b = b->next;
		x--;
	//	printf("%d\n", x);
	}
//	printf("size2 %d\n", (ft_lstsize(b)));
//	printf("wa sf\n");
}
//////////////////////////////////////////////

void	ft_sort_100(t_stack **lst)
{
	t_stack	*b;
	t_stack *cp;
//	int		temp[100];
//	int		i;
	int		j;
//	int		min;
//	int		c;
//	int		m;

int min1;
int min2;
int total;
	int x;

//	i = 0;
	cp = *lst;
//	b = ft_lstnew(0);


//	min = (*lst)->data;
	
min1 = (*lst)->data;
min2 = (*lst)->data;

	while (*lst != NULL)
	{
		cp = *lst;
	//	min = cp->data;
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

	/*	while ((*lst)->data > b->data && b != NULL)
		{
			ft_ra(b);
			b = b->next;
		}*/
	//	}
		ft_pb(lst, &b);
		if (ft_lstsize(cp) <= 3)
		{
			ft_sort_3(lst);
			ft_pa(lst, &b);
	//		printf("ii\n");
			break;
		}
			
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
/*	while ((*lst) != NULL)
	{
		printf("%d\n", (*lst)->data);
		(*lst) = (*lst)->next;
	}*/
	while (b != NULL)
	{
		ft_pa(lst, &b);
	//	b = b->next;
	}
}



void my_new_100(t_stack **lst)
{
	t_stack *b;
	int *t;
	int i;
	int len;
	int mid;

	i = 0;
	while (ft_lstsize(*lst) > 5)
	{
		t = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
		while (lst != NULL)
		{
			t[i] = (*lst)->data;
			(*lst) = (*lst)->next;
			i++;
		}
		t[i] = '\0';
		len = ft_lstsize((*lst));
		ft_sort_array(t, len);

		mid = t[ft_lstsize(*lst) / 2];
		i = 0;
		while (i < (ft_lstsize(*lst) / 2))
		{
			if ((*lst)->data < mid)
				ft_pb(lst, &b);
			else if (ft_lstlast(*lst)->data < mid)
			{
				ft_rra(lst);
				ft_pb(lst, &b);
			}
			else
				ft_ra(*lst);
			i++;
		}
	}
	if (ft_lstsize(*lst) <= 5)
	{
		if (ft_lstsize(*lst) <= 3)
			ft_sort_3(lst);
		ft_sort_5(lst);
	}
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
	t_stack	*a = NULL;
//	t_stack	*b;	
	t_stack	*node = NULL;

	if (argc > 2)
	{
	//	b = ft_lstnew(0);
		i = 1;
		while (i < argc)
		{
			data = ft_atoi(argv[i]);
			node = ft_lstnew(data);
			ft_lstadd_back(&a, node);
			i++;
		}
		
	//	special_sort_5(&a);
		if (!ft_isdup(a))
			return (0);
		if (ft_lstsize(a) == 2)
		{
			if (!ft_is_sorted(a))
				ft_sa(a);
		}
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		if (ft_lstsize(a) <= 5)
			ft_sort_5(&a);
	//	else
	//		ft_sort_100(&a);
		else
			recursive_sort(&a);
			//my_new_100(&a);
		

	//	printf("/////////////////////////////////////\n");
		while (a != NULL)
		{
			printf("%d\n", a->data);
			a = a->next;
		}
	}
}

//ARG=""; ./a.out $ARG | ./checker_OS $ARG

//82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 72