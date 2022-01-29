#include "push_swap.h"

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
	return (1);
}

int get_s_upper(t_stack *b)
{
	int max1, max2;
	t_stack *cp;

	cp = b;
	max1 = b->next->data;
	max2 = b->data;
	while (b != NULL)
	{
		if (b->data > max1)
		{
			return (0);
		}
		b = b->next;
	}
	b = cp;
	while (b != NULL)
	{
		if (b->data > max2 && max2 > max1)
		{
			return (0);
		}
		b = b->next;
	}
	printf("max1 %d\n", max1);
	printf("max2 %d\n", max2);
	printf("wtt\n");
	return (1);
}

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
	else if (a < b && b > c && a > c)
		ft_sa(*lst, "sa\n");
	else if (a < b && b > c && a < c)
	{
		ft_ra(*lst, "ra\n");
	}
	else if (a > b && b < c && a < c)
		ft_rra(lst, "rra\n");
	else if (a > b && b < c && a > c)
	{
		ft_sa(*lst, "sa\n");
		ft_ra(*lst, "ra\n");
	}
	else if (a > b && b > c)
	{
		return ;
	}
	else if (a > b && b < c)
		ft_ra(*lst, "ra\n");
}

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
//// get index
int get_index(t_stack **lst, int mid)
{
	t_stack *cp;
	cp = *lst;
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
	while (i < (ft_lstsize(*lst) / 2))
	{
		if (t[i] < mid)
		{
			break;
		}
		i++;
	}
	j = ft_lstsize(*lst)-1;
	while (j > (ft_lstsize(*lst) / 2))
	{
		if (t[j] < mid)
		{
			break;
		}
		
		j--;
	}
	if (i < ((ft_lstsize(*lst) - j)))
		return i;
	else
		return j;
}