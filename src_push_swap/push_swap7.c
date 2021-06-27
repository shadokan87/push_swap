#include "../push_swap.h"
#include <stdio.h>

void	to_a_part2(t_main *main, int *stacka)
{
	int	mid;
	int	count_r;
	int	max;

	count_r = 0;
	stacka = stack_to_int(main->stackb, main->chunks->elem);
	quicksort(stacka, 0, main->chunks->elem - 1);
	mid = main->chunks->elem / 2;
	max = get_max2(main, mid);
	while (max)
	{
		if (main->stackb->elem > stacka[mid])
		{
			p(&main->stackb, &main->stacka);
			max--;
			main->chunks->elem--;
		}
		else
		{
			r(&main->stackb);
			count_r++;
		}
	}
	rev_count_r(main, count_r);
}

int	to_a_case(t_main *main, int *stacka)
{
	if (main->chunks->elem == 1)
	{
		case_one_b(main);
		return (1);
	}
	else if (main->chunks->elem == 2)
	{
		case_two_b(main);
		return (1);
	}
	else if (is_sorted_rev(main->stackb, main->chunks->elem))
	{
		case_sorted_b(main);
		return (1);
	}
	return (0);
}

int	to_a(t_main *main, int *stacka)
{
	int	mid;
	int	i;
	int	max;
	int	count_r;

	i = 0;
	count_r = 0;
	if (!main->chunks)
		return (0);
	if (to_a_case(main, stacka))
		return (to_a(main, stacka));
	to_a_part2(main, stacka);
	if (!main->chunks->elem)
		move_chunk(main);
	return (to_a(main, stacka));
}

int	get_lloc(t_stack *stack, int to_find, int len)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	if (!stack)
		return (-1);
	ptr = stack;
	while (ptr && i < len && ptr->elem != to_find)
	{
		i++;
		ptr = ptr->n;
	}
	if (ptr->elem == to_find)
		return (i);
	else
		return (-1);
}

int	get_path(t_stack *stack, t_main *main, int to_find)
{
	t_stack		*ptr;
	int			ret;

	ptr = stack;
	if (ptr->n->elem == to_find)
		return (1);
	ret = get_lloc(stack, to_find, main->chunks->elem);
	if (ret == -1)
		return (-1);
	return (2);
}
