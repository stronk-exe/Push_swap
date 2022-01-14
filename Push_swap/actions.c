#include "push_swap.h"

void	ft_sa(t_stack *a, char *s)
{
	t_stack	*temp;
	int		res;

	temp = a->next;
	res = temp->data;
	temp->data = a->data;
	a->data = res;
    ft_putstr(s);
}

void	ft_sb(t_stack *b, char *s)
{
	t_stack	*temp;
	int		res;

	temp = b->next;
	res = temp->data;
	temp->data = b->data;
	b->data = res;
	ft_putstr(s);
}

void	ft_ss(t_stack *a, t_stack *b, char *s)
{
	ft_sa(a, "");
	ft_sb(b, "");
    ft_putstr(s);
}

void	ft_pa(t_stack **a, t_stack **b, char *s)
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
	ft_putstr(s);
}

void	ft_pb(t_stack **a, t_stack **b, char *s)
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
	ft_putstr(s);
}

void	ft_ra(t_stack *a, char *s)
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
	ft_putstr(s);
}

void	ft_rb(t_stack *b, char *s)
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
	ft_putstr(s);
}

void	ft_rr(t_stack *a, t_stack *b, char *s)
{
	ft_ra(a, "");
	ft_rb(b, "");
	ft_putstr(s);
}

void	ft_rra(t_stack **a, char *s)
{
	t_stack *temp;

	temp = ft_lstnew(ft_lstlast(*a)->data);
	ft_lstadd_front(a, temp);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr(s);
}

void	ft_rrb(t_stack **b, char *s)
{
	t_stack *temp;

	temp = ft_lstnew(ft_lstlast(*b)->data);
	ft_lstadd_front(b, temp);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr(s);
}

void	ft_rrr(t_stack **a, t_stack **b, char *s)
{
	ft_rra(a, "");
	ft_rrb(b, "");
	ft_putstr(s);
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