#include "../push_swap.h"
#include <stdio.h>

typedef struct s_solve
{
	int left;
	int right;
	int pivot;
	int swap;
}				t_solve;

int	*get_numbers(char **argv)
{
	int i;
	int *ret;

	i = 1;
	while (argv[i])
		i++;
	if (!(ret = malloc(sizeof(int) * i)))
		return (0);
	i = 1;
	while (argv[i])
	{
		ret[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (ret);
}

void	print_stack2(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d ", stack[i]);
		i++;
	}
}

void	swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	print_loop(char *message, int n)
{
	int i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		printf("%s", message);
		i++;
	}
}

void	quicksort(int *stack, int start, int end)
{
	int pivot;
	int l_most;
	int r_most;
	
	if (!(start < end))
		return ;
	pivot = end;
	l_most = start;
	r_most = pivot;
	while (l_most < r_most)
	{
		while (stack[l_most] <= stack[pivot] && l_most <= end)
			l_most++;
		while (stack[r_most] > stack[pivot] && r_most >= start)
			r_most--;
		if (l_most < r_most)
			swap(&stack[l_most], &stack[r_most]);
	}
	swap(&stack[pivot], &stack[r_most]);
	quicksort(stack, start, r_most - 1);
	quicksort(stack, r_most + 1, end);
}

void	init_solve(t_solve *solve, int len)
{	
	solve->pivot = len - 1;
	solve->left = 0;
	solve->right = len - 2;
}

int	main(int argc, char **argv)
{
	t_main main;
	init_main(&main);
	int *stacka;
	int len;

	len = argc - 1;
	if (!check_format(&stacka, &len, argv))
		return (exit_push_swap("Error\n"));
	quicksort(stacka, 0, len - 1);
	print_stack2(stacka, len);
}
