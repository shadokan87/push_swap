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

void	get_index(t_stack **stack, int *stacka)
{
	t_stack *ptr;
	int i;
	
	i = 0;
	ptr = *stack;
	while (ptr)
	{
		while (stacka[i] != ptr->elem)
			i++;
		ptr->index = i;
		//printf("[%d / %d]", ptr->elem, ptr->index);
		ptr = ptr->n;
		i = 0;
	}
}

t_stack		*get_last(t_stack *stack)
{
	t_stack *last;

	last = stack;
	while (last->n)
		last = last->n;
	return (last);
}

int		is_sorted(t_stack *stack)
{
	t_stack *check;
	int		i;

	check = stack;
	i = -1;
	while (check)
	{
		if (i != -1 && check->index > i)
			return (0);
		i = check->index;
		check = check->n;
	}
	return (1);
}

void	if_not_sorted(t_stack **a, t_stack **b, int i)
{
	while ((*a)->index != i)
	{
		if ((*a)->n->index == i)
			s(a);
		else
			rev_r(a);
	}
	p(a, b);
}

int		if_sorted(t_stack **a, t_stack **b, int i)
{
	//printf("\n");
	int count;

	count = stack_len(*a);
	if (count == 2)
		return (s(a));
	while (count != 2)
	{
		r(a);
		count--;
	}
	s(a);
	//print_stack(*a);
	//exit (0);
	return (1);
}

int		get_mid(int *stacka, int *index)
{
	int i;

	i = index[0];
	while (i < (index[1] - index[0]) / 2)
		i++;
	return (i);
}

int		*stack_to_int(t_stack *stack)
{
	int *new;
	int i;
	t_stack *ptr;

	i = 0;
	ptr = stack;
	if (!(new = malloc(sizeof(int) * stack_len(stack))))
		return (0);
	while (ptr)
	{
		new[i] = ptr->elem;
		i++;
		ptr = ptr->n;
	}
	return (new);
}

int		get_mid_index(int *stacka, int len)
{
	int i;
	
	i = 0;
	while (len - i != (len / 2))
		i++;
	return (i);
}

int		put_to_b(t_stack *(*stack)[2], int *stacka)
{
	int i;
	int mid;
	t_stack *last;
	
	i = 0;
	if (stack_len((*stack)[A]) == 3)
		return (0);
	mid = stack_len((*stack)[A]) / 2;
	while (i != mid)
	{
			if ((*stack)[A]->elem < stacka[mid])
			{
				p((stack)[A], (stack[B]));
				i++;
			}
			else
			{
				//last = get_last((*stack)[A]);
				//(last->elem < stacka[mid]) ? (rev_r((stack)[A])) : r((stack)[A]);
				r((stack)[A]);
			}
	}
}

void	init_stack_sort(t_stack *(*stack)[2], int *stacka, int len)
{
	int i;

	push((stack)[A], 1);
	printf("%d", (*stack)[A]->elem);
	exit (0);
	i = -1;
	while (++i < len)
		push((stack)[A], stacka[i]);
	quicksort(stacka, 0, len - 1);
	/*
	while (put_to_b(stack, stacka))
	{
		free(stacka);
		stacka = stack_to_int((*stack)[A]);	
		quicksort(stacka, 0, stack_len((*stack)[A]));
	}
	printf("%d", stack_len((*stack)[B]));
	*/
	p((stack)[A], (stack)[B]);
	push((stack)[A], 1);
}

int	main(int argc, char **argv)
{
	t_main main;
	int *stacka;
	int *index;
	int len;

	init_main(&main);
	len = argc - 1;
	if (!check_format(&stacka, &len, argv))
		return (exit_push_swap("Error\n"));
	if (!(index = malloc(sizeof(int) * 2)))
		return (0);
	init_stack_sort(&main.stack, stacka, len);
}
