#include "../push_swap.h"
#include <stdio.h>

int	init_stack_sort(t_main *main, int *stacka, int len)
{
	int	i;
	int	count_r;
	int	to_find;
	int	*orig;

	i = len - 1;
	while (i >= 0)
	{
		push(&main->stacka, stacka[i]);
		i--;
	}
	free(stacka);
	to_b(main);
	to_a2(main);
	return (0);
}

void	set_cutsize(t_main *main, int len)
{
	if (len == 100)
		main->cutsize = 20;
	else if (len == 500)
		main->cutsize = 10;
	else
		main->cutsize = 0;
}

int	case_two(int *stacka, int len)
{
	if (len == 1)
	{
		free(stacka);
		return (1);
	}
	if (stacka[0] > stacka[1])
		printf("sa\n");
	free(stacka);
	return (1);
}

void	free_stack(t_main *main)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = main->stacka;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->n;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		*stacka;
	int		*index;
	int		len;

	len = argc - 1;
	if (!check_format(&stacka, &len, argv))
		return (exit_push_swap(&main, "Error\n"));
	main.stacka = NULL;
	main.stackb = NULL;
	if (len == 2 || len == 1)
		return (case_two(stacka, len));
	set_cutsize(&main, len);
	init_stack_sort(&main, stacka, len);
	if (is_sorted(main.stacka) && main.stacka && !main.stackb)
		printf("OK\n");
	free_stack(&main);
}
