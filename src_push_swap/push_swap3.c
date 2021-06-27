#include "../push_swap.h"
#include <stdio.h>

void	print_loop(char *message, int n)
{
	int	i;

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
	int	pivot;
	int	l_most;
	int	r_most;

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

t_stack	*get_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->n)
		last = last->n;
	return (last);
}

int	*stack_to_int(t_stack *stack, int len)
{
	int		*new;
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = stack;
	new = malloc(sizeof(int) * len);
	if (!new)
		return (0);
	if (len == 0)
		return (0);
	while (ptr && i < len)
	{
		new[i] = ptr->elem;
		i++;
		ptr = ptr->n;
	}
	return (new);
}
