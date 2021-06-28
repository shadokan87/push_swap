#include "../push_swap.h"
#include <stdio.h>

int	is_sorted_rev(t_stack *stack, int len)
{
	t_stack		*ptr;
	int			i;
	int			y;

	y = 0;
	i = -1;
	ptr = stack;
	while (ptr && y < len)
	{
		if (i != -1 && ptr->elem > i)
			return (0);
		i = ptr->elem;
		ptr = ptr->n;
		y++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int		*diffa;
	int		len;
	int		i;
	t_stack	*ptr;

	i = 0;
	len = stack_len(stack);
	diffa = stack_to_int(stack, len);
	ptr = stack;
	quicksort(diffa, 0, len - 1);
	while (ptr)
	{
		if (ptr->elem != diffa[i])
		{
			free(diffa);
			return (0);
		}
		ptr = ptr->n;
		i++;
	}
	free(diffa);
	return (1);
}

int	move_chunk(t_main *main)
{
	t_stack	*ptr;

	ptr = main->chunks->n;
	free(main->chunks);
	main->chunks = ptr;
	return (1);
}

int	get_max(int *stacka, int to_find)
{
	int	ret;

	ret = 1;
	while (stacka[ret] != to_find)
		ret++;
	return (ret);
}

int	case_two_a(t_main *main)
{
	if (main->stacka->elem > main->stacka->n->elem)
		send_op(main, "sa");
	return (0);
}
