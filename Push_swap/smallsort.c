#include "push_swap.h"

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