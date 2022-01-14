#include "push_swap.h"
#include "Checker_utils/get_next_line.h"
#include "Checker_utils/get_next_line.c"
#include "Checker_utils/get_next_line_utils.c"
#include "actions.c"
#include "Checker_utils/checker_utils.c"


int	get_actions(t_stack **a, t_stack **b)
{
	char *s;
	int d =1;

    s = get_next_line(0);
	while (s)
	{
		if (!ft_strcmp(s,"pa\n"))
			ft_pa(a, b, "");
		else if (!ft_strcmp(s,"pb\n"))
			ft_pb(a, b, "");
		else if (!ft_strcmp(s,"sa\n"))
			ft_sa(*a, "");
		else if (!ft_strcmp(s,"sb\n"))
			ft_sb(*b, "");
		else if (!ft_strcmp(s,"ss\n"))
			ft_ss(*a, *b, "");
		else if (!ft_strcmp(s,"ra\n"))
			ft_ra(*a, "");
		else if (!ft_strcmp(s,"rb\n"))
			ft_rb(*b, "");
		else if (!ft_strcmp(s,"rr\n"))
			ft_rr(*a, *b, "");
		else if (!ft_strcmp(s,"rra\n"))
			ft_rra(a, "");
		else if (!ft_strcmp(s,"rrb\n"))
			ft_rrb(b, "");
		else if (!ft_strcmp(s,"rrr\n"))
			ft_rrr(a, b, "");
		else
			d = 0;
		free(s);
		if (!d){
			write(2, "Error\n", 6);
			return (0);
		}
		
		s = get_next_line(0);
	}
	return 1;
}

int main(int argc, char **argv)
{
	int		i;
	int		data;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
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
		if (!check_error(a))
		{
			write(2,"Error\n", 6);
			return 0;
		}
		if (get_actions(&a, &b))
		{
			if (ft_is_sorted(a) && !b)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
		{
			return (0);
		}
	//	special_sort_5(&a);
//	check_error(&a);
	//	if (!ft_isdup(a))
		//	return (0);
	/*	if (ft_lstsize(a) == 2)
		{
			if (!ft_is_sorted(a))
				ft_sa(a);
		}
	//	else if (ft_lstsize(a) == 3)
	//		ft_sort_3(&a);
		if (ft_lstsize(a) <= 5)
			ft_sort_5(&a);
		else if (ft_lstsize(a) == 500)
			special_500(&a);
		else if (ft_lstsize(a) == 100)
			special_100(&a);*/
	/*	else
			recursive_sort(&a);
			//my_new_100(&a);*/
		

	//	printf("/////////////////////////////////////\n");
		while (a != NULL || b != NULL)
		{
			if (a != NULL)
			{
				printf("%d", a->data);
				a = a->next;
			}
			else
			{
				printf(" ");
			//	a = a->next;
			}

			if (b != NULL)
			{
				printf(" %d\n", b->data);
				b = b->next;
			}
			else
			{
				printf("\n");
			//	b = b->next;
			}
		}
		printf("_  _\n");
		printf("a  b\n");
	//	lstclear
	/*	while (b != NULL)
		{
			printf("b: %d\n", b->data);
			b = b->next;
		}*/
	}
	return (0);
}