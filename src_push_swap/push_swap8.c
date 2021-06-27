#include "../push_swap.h"
#include <stdio.h>

int	mv_elem_top(t_stack **stack, int to_find)
{
	int	count_r;

	count_r = 0;
	while ((*stack)->elem != to_find)
	{
		r(stack);
		count_r++;
	}
	if (count_r)
		return (1);
	else
		return (0);
}

int	check_cases(t_main *main)
{
	if (main->chunks->elem == 1)
	{
		p(&main->stackb, &main->stacka);
		return (1);
	}
	else if (main->chunks->elem == 2)
	{
		if (main->stackb->elem < main->stackb->n->elem)
			s(&main->stackb);
		p(&main->stackb, &main->stacka);
		p(&main->stackb, &main->stacka);
		return (1);
	}
	return (0);
}

int	get_max3(t_main *main, int mid, int size)
{
	int	i;
	int	count;

	i = mid + 1;
	count = 0;
	while (i < size)
	{
		i++;
		count++;
	}
	return (count);
}

int	move_small2(t_main *main, int *stacka, int mid)
{
	int	count_r;

	count_r = 0;
	while (!(main->stacka->elem < stacka[mid]))
	{
		send_op(main, "ra");
		count_r++;
	}
	return (count_r);
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
