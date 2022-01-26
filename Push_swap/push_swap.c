/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/01/22 15:43:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "actions.c"
//#include "sorting.c"
//#include "errors.c"
//#include "push_swap_utils.c"
/*
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
				write(2, "Error\n", 6);
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
*/
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
		ft_rra(lst, "rra\n");
	else if (a < b && b > c && a < c)
	{
		ft_sa(*lst, "sa\n");
		ft_ra(*lst, "ra\n");
	}
	else if (a < b && b < c)
	{
		ft_sa(*lst, "sa\n");
		ft_rra(lst, "rra\n");
	}
	else if (a > b && b < c && a < c)
		ft_sa(*lst, "sa\n");
	else if (a > b && b < c && a > c)
		ft_ra(*lst, "ra\n");
	else if (a > b && b > c)
	{
		ft_sa(*lst, "sa\n");
		ft_rra(lst, "rra\n");
	}
	else if (a > b && b < c)
		ft_ra(*lst, "ra\n");
}

void	ft_sort_5(t_stack **lst)
{

	if (ft_lstsize(*lst) == 2)
	{
		if (!ft_is_sorted(*lst))
			ft_sa(*lst, "sa\n");
	}
	else if (ft_lstsize(*lst)  == 3)
		ft_sort_3(lst);
	else
	{
		t_stack	*b;

		b = NULL;
		if (ft_lstsize(*lst) == 5)
			ft_pb(lst, &b, "pb\n");
		ft_pb(lst, &b, "pb\n");
		
		ft_sort_3(lst);

		if (b->data > ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
		{
			if (b->data < (*lst)->next->data)
			{
				ft_pa(lst, &b, "pa\n");
				ft_sa(*lst, "sa\n");
			}
			else
			{
				ft_ra(*lst, "ra\n");
				ft_pa(lst, &b, "pa\n");
				ft_sa(*lst, "sa\n");
				ft_rra(lst, "rra\n");
			}
		}
		else
			ft_pa(lst, &b, "pa\n");
		if (b == NULL)
			return ;
		if (b->data > ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
		{
			if (b->data > (*lst)->next->data)
			{
				if (b->data < (*lst)->next->next->data)
				{
					ft_ra(*lst, "ra\n");
					ft_pa(lst, &b, "pa\n");
					ft_sa(*lst, "sa\n");
					ft_rra(lst, "rra\n");
				}
				else
				{
					ft_rra(lst, "rra\n");
					ft_pa(lst, &b, "pa\n");
					ft_ra(*lst, "ra\n");
					ft_ra(*lst, "ra\n");
				}
			}
			else
			{
				ft_pa(lst, &b, "pa\n");
				ft_sa(*lst, "sa\n");
			}
		}
		else
			ft_pa(lst, &b, "pa\n");
	}
}


//////////////////////////////////////////////
void recursive_sort(t_stack **lst)
{
	t_stack *b = NULL;
	t_stack *cp;
	int *t;
	int mid;
	int i=0;
	int j=0;
	int x =0;
	int min;
	int ty=0;

	min =0;
	cp = *lst;
	int len = ft_lstsize(cp);
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
	mid = t[ft_lstsize(*lst) / 4];
	i = 0;
	ty = 0;

	///////////////////////////////////////////////////////////////
	t_stack *gg;
	int index;
	gg = *lst;
/*	for (int uu=0;uu < ft_lstsize(*lst);uu++)
	{
		printf("gg lo  data  :%d\n", (gg)->data);
		(gg) = (gg)->next;
	}*/
//	printf("len gg  %d\n", ft_lstsize(gg));
	while (i < len && ty < (len / 4))
	{
		/*if (ft_lstsize(*lst) <= 5)
		{
			special_sort_5(lst);
//			printf("salina akhaa\n");
			break;
		}*/
//		printf("iiii  %d\n", i);
//		printf("ty  %d\n", ty);
		gg = *lst;
	
				index = get_index(&gg, mid);
//				printf("indexxx  %d\n", index);
				//if (index >= 0)
				//{
					if (index < (ft_lstsize(*lst) / 4))
					{
						
						while (index > 0)
						{
							ft_ra(*lst, "ra\n");
							index--;
						}
					//	ft_pb(lst, &b);
					//	ty++;
					}
					else
					{
						while (index < ft_lstsize(*lst))
						{
							ft_rra(lst, "rra\n");
						//	printf("yo\n");
							index++;
						}
					//	ft_pb(lst, &b);
					//	ty++;
					}
					ft_pb(lst, &b, "pb\n");
					ty++;
					
				//}
		//	}
		//	gg = *lst;
			i++;
		//	j++;
	}
//	printf("sf yaka\n");
/////////////////////////////////////////////////////////////////////

/*	while (i < len && ty < (len / 2))
	{
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
		i++;
	}*/
	if (ft_lstsize(*lst) > 5)
		recursive_sort(lst);
	else
	{
		ft_sort_5(lst);
	}
//	x = ft_lstsize(b);
	t_stack *cb;
//printf("----------ty %d\n", ty);
	while (ft_lstsize(b) > 0)
	{
		cb = b;
		j =0;
		x =0;
		min = cb->data;
		if (!get_upper(b))
		{
				j =0;
				while (cb != NULL)
				{

					if (min < cb->data)
					{
						min = cb->data;
						x = j;
					}
					cb = cb->next;
					j++;
				}
				if (x <= (j / 2))
				{
					while (x > 0)
					{
						ft_rb(b, "rb\n");
						x--;
					}
				}
				else
				{
					while (x < j)
					{
						ft_rrb(&b, "rrb\n");
						x++;
					}
				}
				ft_pa(lst, &b, "pa\n");
		}
		else
			ft_pa(lst, &b, "pa\n");
//		x--;
	//	printf("ty %d\n", ty);
	}
}
//////////////////////////////////////////////









void recursive_sort_500(t_stack **lst)
{
	t_stack *b = NULL;
	t_stack *cp;
	int *t;
	int mid;
	int i=0;
	int j=0;
	int x =0;
	int min;
	int ty=0;

	min =0;
	cp = *lst;
	int len = ft_lstsize(cp);
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
	mid = t[ft_lstsize(*lst) / 7];
	i = 0;
	ty = 0;

	///////////////////////////////////////////////////////////////
	t_stack *gg;
	int index;
	gg = *lst;
	while (i < len && ty < (len / 7))
	{
		/*if (ft_lstsize(*lst) <= 5)
		{
			special_sort_5(lst);
//			printf("salina akhaa\n");
			break;
		}*/
//		printf("iiii  %d\n", i);
//		printf("ty  %d\n", ty);
		gg = *lst;
	
				index = get_index(&gg, mid);
//				printf("indexxx  %d\n", index);
				//if (index >= 0)
				//{
					if (index < (ft_lstsize(*lst) / 7))
					{
						
						while (index > 0)
						{
							ft_ra(*lst, "ra\n");
							index--;
						}
					//	ft_pb(lst, &b);
					//	ty++;
					}
					else
					{
						while (index < ft_lstsize(*lst))
						{
							ft_rra(lst, "rra\n");
						//	printf("yo\n");
							index++;
						}
					//	ft_pb(lst, &b);
					//	ty++;
					}
					ft_pb(lst, &b, "pb\n");
					ty++;
					
			i++;
	}
	if (ft_lstsize(*lst) > 0)
		recursive_sort(lst);
/*	else
	{
		ft_sort_5(lst);
	}*/
//	x = ft_lstsize(b);
	t_stack *cb;
//printf("----------ty %d\n", ty)
	while (ft_lstsize(b) > 0)
	{
		cb = b;
		j =0;
		x =0;
		min = cb->data;
		if (!get_upper(b))
		{
				j =0;
				while (cb != NULL)
				{

					if (min < cb->data)
					{
						min = cb->data;
						x = j;
					}
					cb = cb->next;
					j++;
				}
				if (x <= (j / 2))
				{
					while (x > 0)
					{
						ft_rb(b, "rb\n");
						x--;
					}
				}
				else
				{
					while (x < j)
					{
						ft_rrb(&b, "rrb\n");
						x++;
					}
				}
				ft_pa(lst, &b, "pa\n");
		}
		else
			ft_pa(lst, &b, "pa\n");
//		x--;
	//	printf("ty %d\n", ty);
	}
}


//////////////////////////////////////////////
/*
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
		while (cp != NULL && j < total)
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
//		total = ft_lstsize(cp);
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
/*			min1 = cp->data;
			
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

		while ((*lst)->data > b->data && b != NULL)
		{
			ft_ra(b);
			b = b->next;
		}*/
	//	}
	/*	ft_pb(lst, &b);
		if (ft_lstsize(cp) <= 3)
		{
			ft_sort_3(lst);
			ft_pa(lst, &b);
	//		printf("ii\n");
			break;
		}
			
/////////////////////////////////////////////////////////	
	if (x < (j / 2))
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
//	}
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
/*	while (b != NULL)
	{
		ft_pa(lst, &b);
	//	b = b->next;
	}
}
*/

/*
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
*/
void	special_100(t_stack	**lst)
{
	t_stack *b = NULL;
	t_stack *cp;
	int *t;
	int mid;
	int i=0;
	int j=0;
	int x =0;
	int min;
	int ty=0;

	min =0;
	cp = *lst;
	int len = ft_lstsize(cp);
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
	
	i = 0;
	ty = 0;
	t_stack *gg;
	int index;
	gg = *lst;

	int chk =0;
	i = 0;
//	printf("------------len %d\n", len);
	ft_sort_array(t, len);
	mid = t[19];
//	printf("---------------tt %d\n", t[20]);
	chk = 19;
	while (ft_lstsize(*lst) > 5 && chk <= 99)
	{
//	printf("---------------tt %d\n", t[i]);
//	printf("---------------mid %d\n", mid);
		i = 0;
		while (i < len && ty < chk)
		{
			gg = *lst;
			index = get_index(&gg, mid);
//			printf("-------index%d\n", index);
			if (index < (ft_lstsize(*lst) / 2))
			{			
				while (index > 0)
				{
					ft_ra(*lst, "ra\n");
					index--;
				}
			}
			else
			{
				while (index < ft_lstsize(*lst))
				{
					ft_rra(lst, "rra\n");
					index++;
				}
			}
			ft_pb(lst, &b, "pb\n");
			ty++;
			i++;
		
		}
//		printf("i---------- %d\n", i);
//		printf("chk %d\n", chk);
		chk += 20;
		mid = t[chk];
	}
//	printf("------------lenwer\n");
//	special_sort_5(lst);


	x = ft_lstsize(b);
	t_stack *cb;
	while (ft_lstsize(b) > 0)
	{
		cb = b;
		j =0;
		x =0;
		min = cb->data;
		if (!get_upper(b))
		{
				j =0;
				while (cb != NULL)
				{
					if (min < cb->data)
					{
						min = cb->data;
						x = j;
					}
					cb = cb->next;
					j++;
				}
				if (x <= (j / 2))
				{
					while (x > 0)
					{
						ft_rb(b, "rb\n");
						x--;
					}
				}
				else
				{
					while (x < j)
					{
						ft_rrb(&b, "rrb\n");
						x++;
					}
				}
				ft_pa(lst, &b, "pa\n");
		/*	if (is_upper(cb, cb->data))
			{
				ft_pa(lst, &b);
			//	ty++;
			}
			else if (is_upper(cb, ft_lstlast(cb)->data))
			{
				ft_rrb(&b);
				ft_pa(lst, &b);
			//	ty++;
			}
			else
				ft_rb(b);*/
		}
		else
			ft_pa(lst, &b, "pa\n");
		x--;
	}
}

void	special_500(t_stack	**lst)
{
	///11 chrunck
	/*
	1   -> 45
	46  -> 90
	91  -> 135
	136 -> 180
	181 -> 225
	225 -> 270
	271 -> 315
	316 -> 360
	361 -> 405
	406 -> 450
	451 -> 495
	*/
	t_stack *b = NULL;
	t_stack *cp;
	int *t;
	int mid;
	int i=0;
	int j=0;
	int x =0;
	int min;
	int ty=0;

	min =0;
	cp = *lst;
	int len = ft_lstsize(cp);
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
	
	i = 0;
	ty = 0;
	t_stack *gg;
	int index;
	gg = *lst;

	int chk =0;
	i = 0;
//	printf("------------len %d\n", len);
	ft_sort_array(t, len);
	mid = t[44];
//	printf("---------------tt %d\n", t[20]);
	chk =44;
	while (chk <= 499)
	{
		
//		printf("---------------mid %d\n", mid);
		i = 0;

		while (i < len && ty < chk)
		{
			gg = *lst;
			index = get_index(&gg, mid);
			
			if (index < (ft_lstsize(*lst) / 2))
			{			
				while (index > 0)
				{
					ft_ra(*lst, "ra\n");
					index--;
				}
			}
			else
			{
				while (index < ft_lstsize(*lst))
				{
					ft_rra(lst, "rra\n");
					index++;
				}
			}
			ft_pb(lst, &b, "pb\n");
			ty++;
			i++;
		}
		chk += 45;
		mid = t[chk];
		
	}
//	printf("------------lenwer\n");
	ft_sort_5(lst);


	x = ft_lstsize(b);
	t_stack *cb;
	while (ft_lstsize(b) > 0)
	{
		cb = b;
		j =0;
		x =0;
		min = cb->data;
		if (!get_upper(b))
		{
				j =0;
				while (cb != NULL)
				{

					if (min < cb->data)
					{
						min = cb->data;
						x = j;
					}
					cb = cb->next;
					j++;
				}
				if (x <= (j / 2))
				{
					while (x > 0)
					{
						ft_rb(b, "rb\n");
						x--;
					}
				}
				else
				{
					while (x < j)
					{
						ft_rrb(&b, "rrb\n");
						x++;
					}
				}
				ft_pa(lst, &b, "pa\n");
		/*	if (is_upper(cb, cb->data))
			{
				ft_pa(lst, &b);
			//	ty++;
			}
			else if (is_upper(cb, ft_lstlast(cb)->data))
			{
				ft_rrb(&b);
				ft_pa(lst, &b);
			//	ty++;
			}
			else
				ft_rb(b);*/
		}
		else
			ft_pa(lst, &b, "pa\n");
		x--;
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
			if (!special_strcmp(argv[i]))
			{
				write(2, "Error\n", 6);
				return 0;
			}
			data = ft_atoi(argv[i]);
			node = ft_lstnew(data);
			ft_lstadd_back(&a, node);
			i++;
		}
		
	//	special_sort_5(&a);
		if (!check_error(a))
		{
			write(2,"Error\n", 6);
			return 0;
		}
//		if (!ft_isdup(a))
	//		return (0);
		if (ft_lstsize(a) == 2)
		{
			if (!ft_is_sorted(a))
				ft_sa(a, "sa\n");
		}
	//	else if (ft_lstsize(a) == 3)
	//		ft_sort_3(&a);

		if (ft_lstsize(a) <= 5)
			ft_sort_5(&a);
		else if (ft_lstsize(a) == 500)
			recursive_sort_500(&a);
	//	else if (ft_lstsize(a) == 100)
	//		special_100(&a);
		else
			recursive_sort(&a);
			//my_new_100(&a);
		

	//	printf("/////////////////////////////////////\n");
	/*	while (a != NULL)
		{
			printf("%d\n", a->data);
			a = a->next;
		}*/
	}
}

//ARG=""; ./a.out $ARG | ./checker_OS $ARG

//82 17 85 29 97 18 22 44 77 05 20 23 41 87 33 37 99 12 49 64 96 93 03 74 01 84 83 14 94 00 32 88 47 43 08 86 25 07 89 16 36 02 78 30 46 71 62 69 27 04 60 50 61 53 76 09 11 52 55 73 38 68 31 80 28 35 06 92 65 19 26 15 48 40 57 39 21 67 34 58 54 81 42 13 70 75 59 66 24 51 63 95 10 45 79 90 98 91 56 72