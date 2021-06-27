#include "../push_swap.h"
#include <stdio.h>

int	is_present2(char **curr, int to_find)
{
	int	i;

	i = 0;
	while (curr[i])
	{
		if (ft_atoi(curr[i]) == to_find)
			return (1);
		i++;
	}
	return (0);
}

void	chunkify2(t_main *main, t_stack *tmp)
{
	int	*stacka;
	int	count;

	count = 0;
	stacka = stack_to_int(main->stacka, stack_len(main->stacka));
	quicksort(stacka, 0, stack_len(main->stacka) - 1);
	to_b(main);
	while (main->stacka)
	{
		send_op(main, "pb");
		count++;
	}
	main->stacka = tmp;
	while (count)
	{
		send_op(main, "pa");
		count--;
	}
	free(stacka);
}

int	chunkify(t_main *main)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = NULL;
	tmp = main->stacka;
	main->stacka = tmp2;
	while (main->chunks->elem)
	{
		send_op(main, "pa");
		main->chunks->elem--;
	}
	move_chunk(main);
	chunkify2(main, tmp);
	return (1);
}

int	to_a2_move_to_top(t_main *main, int to_find)
{
	int	count_r;

	count_r = 0;
	if (main->chunks->elem >= 2 && main->stackb->n->elem == to_find)
		send_op(main, "sb");
	while (main->stackb->elem != to_find)
	{
		if (main->stackb->n->elem == to_find)
		{
			send_op(main, "sb");
			break ;
		}
		send_op(main, "rb");
		count_r++;
	}
	return (count_r);
}

void	to_a2_2(t_main *main)
{
	int	count_r;
	int	*stacka;
	int	to_find;

	count_r = 0;
	stacka = stack_to_int(main->stackb, main->chunks->elem);
	quicksort(stacka, 0, main->chunks->elem - 1);
	to_find = stacka[main->chunks->elem - 1];
	count_r = to_a2_move_to_top(main, to_find);
	send_op(main, "pa");
	to_find = stacka[main->chunks->elem - 2];
	main->chunks->elem--;
	while (count_r && stack_len(main->stackb) > 1)
	{	
		send_op(main, "rrb");
		if (main->stackb->elem == to_find)
		{
			send_op(main, "pa");
			main->chunks->elem--;
			to_find = stacka[main->chunks->elem - 1];
		}
		count_r--;
	}
	free(stacka);
}
