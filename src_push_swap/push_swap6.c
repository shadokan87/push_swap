#include "../push_swap.h"
#include <stdio.h>

int	get_max2(t_main *main, int mid)
{
	int	i;
	int	count;

	i = mid + 1;
	count = 0;
	while (i < main->chunks->elem)
	{
		i++;
		count++;
	}
	return (count);
}

int	case_one_b(t_main *main)
{
	p(&main->stackb, &main->stacka);
	move_chunk(main);
	return (1);
}

int	case_two_b(t_main *main)
{
	if (main->stackb->elem < main->stackb->n->elem)
		s(&main->stackb);
	move_chunk(main);
	return (1);
}

void	case_sorted_b(t_main *main)
{
	while (main->chunks->elem)
	{
		p(&main->stackb, &main->stacka);
		main->chunks->elem--;
	}
	move_chunk(main);
}

void	rev_count_r(t_main *main, int count_r)
{
	while (count_r)
	{
		rev_r(&main->stackb);
		count_r--;
	}
}
