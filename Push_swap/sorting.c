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