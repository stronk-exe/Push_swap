#include "push_swap.h"


/*
int ft_strlen(int *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

*/

void  ft_sort_array(int *t, int n)
{
    int i = 0, j = 0;
    int temp;
    while (i < (n - 1)) 
    {
        j = 0;
        while (j < (n-1))
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
              	t[j] = t[j + 1];
                t[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int is_upper(t_stack *b, int data)
{
	while (b != NULL)
	{
		if (b->data > data)
		{
			return 0;
		}
		b = b->next;
	}
	return 1;
}

int get_upper(t_stack *b)
{
	int max;

	max = b->data;
	while (b != NULL)
	{
		if (b->data > max)
		{
			return 0;
		}
		b = b->next;
	}
	return 1;
}

///////////////////////////////////////////

/////// special sorting 3
void	special_sort_3(t_stack **lst)
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
	{
		ft_sa(*lst, "sa\n");
		ft_rra(lst, "rra\n");
	}
	//	return ;
	else if (a < b && b > c && a > c)
		ft_sa(*lst, "sa\n");
	//	ft_rra(lst);
	else if (a < b && b > c && a < c)
	{
	//	ft_sa(*lst);
		ft_ra(*lst, "ra\n");
	}
/*	else if (a < b && b < c)
	{
		ft_sa(*lst);
		ft_rra(lst);
	}*/
	else if (a > b && b < c && a < c)
		ft_rra(lst, "rra\n");
	//	ft_sa(*lst);
	else if (a > b && b < c && a > c)
	{
		ft_sa(*lst, "sa\n");
		ft_ra(*lst, "ra\n");
	}	//ft_ra(*lst);
	else if (a > b && b > c)
	{
		return ;
	//	ft_sa(*lst);
	//	ft_rra(lst);
	}
	else if (a > b && b < c)
		ft_ra(*lst, "ra\n");
}
/*
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
*/
// special sorting 5

void	special_sort_5(t_stack **lst)
{

	if (ft_lstsize(*lst) == 2)
	{
		if (ft_is_sorted(*lst))
			ft_sa(*lst, "sa\n");
	}
	else if (ft_lstsize(*lst)  == 3)
		special_sort_3(lst);
	else
	{
		t_stack	*b;

		b = NULL;
		if (ft_lstsize(*lst) == 5)
			ft_pb(lst, &b, "pb\n");
		ft_pb(lst, &b, "pb\n");
		
		special_sort_3(lst);

		if (b->data < ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data < (*lst)->data && b->data > ft_lstlast(*lst)->data)
		{
			if (b->data > (*lst)->next->data)
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
		if (b->data < ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data < (*lst)->data && b->data > ft_lstlast(*lst)->data)
		{
			if (b->data < (*lst)->next->data)
			{
				if (b->data > (*lst)->next->next->data)
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

/////////////////////////////////////////////////////
//// get small
/*
int get_small(t_stack *lst)
{
	int i =0;
	int min;

	min = lst->data;
	while (lst != NULL)
	{
		if (lst->data < min)
		{
			min = lst->data;
		}
		i++;
	}
	return min;
}
*/
/////////////////////////////////////////////////////
//// get index
int get_index(t_stack **lst, int mid)
{
//	int index1 = 0, index2 =0;
	t_stack *cp;
	cp = *lst;
//	int mid;
	int i =0, j=0;
	int *t;

	t = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
	while (cp != NULL)
	{
		t[i] = cp->data;
		cp = cp->next;
		i++;
	}
	t[i] = '\0';
	i = 0;
	
//	printf("looon  :%d\n", ft_lstsize(*lst));
//	for (int uu=0;uu < ft_lstsize(cp);uu++)
//	{
//		printf("data  :%d\n", (cp)->data);
//		(cp) = (cp)->next;
//	}
/*	while (i < ft_lstsize(*lst))
	{
		s[i] = t[i];
	//	printf("t[%d]\n", t[i]);
	//	printf("s[%d]\n", s[i]);
		i++;
	}
	s[i] = '\0';*/
//	new_s = t;
//	for (int uu=0;uu < ft_lstsize(lst);uu++)
//		printf("t[%d]\n", s[uu]);
	
//	ft_sort_array(s, ft_lstsize(*lst));
//	mid = s[(ft_lstsize(lst) / 2)+1];
//	for (int uu=0;uu < ft_lstsize(lst);uu++)
//		printf("after t[%d]\n", s[uu]);
//	printf("mid  %d\n", mid);
//	printf("len/2  %d\n", ft_lstsize(lst));
	i = 0;
	while (i < (ft_lstsize(*lst) / 2))
	{
		if (t[i] < mid)
		{
			
		//	i++;
			break;
		}
	//	printf("iwat %d\n", i);
//		printf("t[i]  %d\n", t[i]);
//		printf("dik i  %d\n", i);
		i++;
	}
	j = ft_lstsize(*lst)-1;
//	printf("size  %d\n", j-1);
//	printf("mid  %d\n", mid);
	while (j > (ft_lstsize(*lst) / 2))
	{
	//	j--;
//		printf("t[j]  %d\n", t[j]);
//		printf("dik j  %d\n", j);
		if (t[j] < mid)
		{
		//	printf("wat [%d]\n", t[j]);
		//	j--;
			break;
		}
		
		j--;
	}
/*	for (int uu=0;uu < ft_lstsize(*lst);uu++)
		printf("t %d\n", t[uu]);
	printf("i  %d\n", i);
	printf("j  %d\n", j);
	printf("total  %d\n", ft_lstsize(*lst) - j);*/
/*	for (int uu=0;uu < ft_lstsize(lst);uu++)
	{
		printf("data  :%d\n", lst->data);
		lst = lst->next;
	}*/
	if (i < ((ft_lstsize(*lst) - j)))
		return i;
	else
		return j;
//	return -1;
}