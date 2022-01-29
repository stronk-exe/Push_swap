#include "push_swap.h"

void recursive_sort(t_stack **lst)
{
	t_stack *b = NULL;
	t_stack *c = NULL;
	t_stack *cp;
	int *t;
	int mid;
	int i=0;
	int j=0;
	int x =0;
	int min;
	int ty=0;
	int j2, min2, x2;

	min =0;
	cp = *lst;
	int len = ft_lstsize(cp);
	i = 0;
	t = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
//	if (!t)
//		return NULL;
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

	t_stack *gg;
	int index;
	gg = *lst;
	while (i < len && ty < (len / 4))
	{
		gg = *lst;
		index = get_index(&gg, mid);
		if (index < (ft_lstsize(*lst) / 4))
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
		if (ty < (len / 8))
			ft_pb(lst, &b, "pb\n");
		else
			ft_pb(lst, &c, "pb\n");
		ty++;
		i++;
	}
	if (ft_lstsize(*lst) > 5)
		recursive_sort(lst);
	else
	{
		ft_sort_5(lst);
	}
	t_stack *cb;
	t_stack *cc;
	while (ft_lstsize(b) > 0 || ft_lstsize(c) > 0)
	{
		cb = b;
		cc = c;
		j =0;
		j2 = 0;
		x =0;
		x2 = 0;

		if ((!ft_lstsize(b) && ft_lstsize(c)) || (ft_lstsize(b) && !ft_lstsize(c)))
		{
			if (ft_lstsize(b) && !ft_lstsize(c))
			{
				while (ft_lstsize(b) > 0)
				{
					cb = b;
					min = cb->data;
					j = 0;
					x = 0;
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
					if (!get_upper(b))
					{
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
					
				}
				
			}
			else if (!ft_lstsize(b) && ft_lstsize(c))
			{
				while (ft_lstsize(c) > 0)
				{
					cc = c;
					min2 = cc->data;
					j2 = 0;
					x2 = 0;
					while (cc != NULL)
					{
						if (min2 < cc->data)
						{
							min2 = cc->data;
							x2 = j2;
						}
						cc = cc->next;
						j2++;
					}
					if (!get_upper(c))
					{
						if (x2 <= (j2 / 2))
						{
							while (x2 > 0)
							{
								ft_rb(c, "rb\n");
								x2--;
							}
						}
						else
						{
							while (x2 < j2)
							{
								ft_rrb(&c, "rrb\n");
								x2++;
							}
						}
						ft_pa(lst, &c, "pa\n");
					}
					else
						ft_pa(lst, &c, "pa\n");
				}
			}
			break;
		}	
		min = cb->data;
		min2 = cc->data;

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
		while (cc != NULL)
		{
			if (min2 < cc->data)
			{
				min2 = cc->data;
				x2 = j2;
			}
			cc = cc->next;
			j2++;
		}
		if (min > min2)
		{
			if (!get_upper(b))
			{
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
		}
		else
		{
			if (!get_upper(c))
			{
				if (x2 <= (j2 / 2))
				{
					while (x2 > 0)
					{
						ft_rb(c, "rb\n");
						x2--;
					}
				}
				else
				{
					while (x2 < j2)
					{
						ft_rrb(&c, "rrb\n");
						x2++;
					}
				}
				ft_pa(lst, &c, "pa\n");
			}
			else
				ft_pa(lst, &c, "pa\n");
		}
	}
}
/*
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

	/////////////////////////////////////////////////////////////// 7 --> 8201    11 --> 8220
	t_stack *gg;
	int index;
	gg = *lst;
	while (i < len && ty < (len / 7))
	{
//		printf("iiii  %d\n", i);
//		printf("ty  %d\n", ty);
		gg = *lst;
	
		index = get_index(&gg, mid);
//				printf("indexxx  %d\n", index);
		if (index < (ft_lstsize(*lst) / 7))
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
					//	printf("yo\n");
				index++;
			}
		}
		ft_pb(lst, &b, "pb\n");
		ty++;		
		i++;
	}
	if (ft_lstsize(*lst) > 1)
		recursive_sort(lst);*/
/*	else
	{
		ft_sort_5(lst);
	}*/
//	x = ft_lstsize(b);
//	t_stack *cb;
//printf("----------ty %d\n", ty)
/*	while (ft_lstsize(b) > 0)
	{
		cb = b;
		j =0;
		x =0;
		min = cb->data;*/
	/*	if (get_s_upper(b))
		{
			printf("what\n");
			ft_pa(lst, &b, "pa\n");
			ft_pa(lst, &b, "pa\n");
		}
		else*//* if (!get_upper(b))
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
	//	printf("ty %d\n", ty);
	}
}
*/