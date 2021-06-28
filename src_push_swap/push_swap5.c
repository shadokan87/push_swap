#include "../push_swap.h"
#include <stdio.h>

int	get_loc(t_stack *stack, int to_find)
{
	int		ret;
	t_stack	*ptr;

	ret = 0;
	ptr = stack;
	while (ptr && !(ptr->elem < to_find))
	{
		ptr = ptr->n;
		ret++;
	}
	return (ret);
}

int	small_r(t_main *main, int small)
{
	int	*stack;
	int	i;
	int	count;

	count = 0;
	i = stack_len(main->stacka) - 1;
	stack = stack_to_int(main->stacka, stack_len(main->stacka));
	while (i >= 0 && !(stack[i] < small))
	{
		i--;
		count++;
	}
	free(stack);
	return (count);
}

int	small_l(t_main *main, int small)
{
	int	*stack;
	int	i;

	i = 0;
	stack = stack_to_int(main->stacka, stack_len(main->stacka));
	while (i < stack_len(main->stacka) && !(stack[i] < small))
		i++;
	free(stack);
	return (i);
}

void	move_small(t_main *main, int *stacka, int mid)
{
	if (small_l(main, stacka[mid]) < small_r(main, stacka[mid]))
	{
		while (!(main->stacka->elem < stacka[mid]))
			send_op(main, "ra");
	}
	else
	{
		while (!(main->stacka->elem < stacka[mid]))
			send_op(main, "rra");
	}	
}

int	to_b(t_main *main)
{
	int		mid;
	int		max;
	int		*stacka;

	if (stack_len(main->stacka) == 2 || !stack_len(main->stacka))
		return (case_two_a(main));
	if (is_sorted(main->stacka))
		return (0);
	stacka = stack_to_int(main->stacka, stack_len(main->stacka));
	quicksort(stacka, 0, stack_len(main->stacka) - 1);
	mid = stack_len(main->stacka) / 2;
	while (main->cutsize && mid > 10 && mid % 10 != 0)
		mid--;
	max = get_max(stacka, stacka[mid]);
	push(&main->chunks, max);
	while (max)
	{
		move_small(main, stacka, mid);
		send_op(main, "pb");
		max--;
	}
	free(stacka);
	return (to_b(main));
}
