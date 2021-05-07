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

t_stack		*get_last(t_stack *stack)
{
	t_stack *last;

	last = stack;
	while (last->n)
		last = last->n;
	return (last);
}

int		get_mid(int *stacka, int *index)
{
	int i;

	i = index[0];
	while (i < (index[1] - index[0]) / 2)
		i++;
	return (i);
}

int		*stack_to_int(t_stack *stack, int len)
{
	int *new;
	int i;
	t_stack *ptr;

	i = 0;
	ptr = stack;
	if (!(new = malloc(sizeof(int) * len)))
		return (0);
	if (len == 0)
		return (0);
	while (ptr &&i < len)
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


int		is_sorted_rev(t_stack *stack)
{
	t_stack		*ptr;
	int			i;

	i = -1;
	ptr = stack;
	while (ptr)
	{
		if (i != -1 && ptr->elem > i)
			return (0);
		i = ptr->elem;
		ptr = ptr->n;
	}
	return (1);
}

int		is_sorted(t_stack *stack)
{
	t_stack		*ptr;
	int			i;

	i = -1;
	ptr = stack;
	while (ptr)
	{
		if (i != -1 && ptr->elem < i)
			return (0);
		i = ptr->elem;
		ptr = ptr->n;
	}
	return (1);
}

int		check_last(t_main *main)
{
	t_stack *ptr;

	ptr = main->stacka;
	if (stack_len(ptr) == 2 &&
	ptr->elem > ptr->n->elem)
		s(&main->stacka);
	return (0);
}
int		put_to_b(t_main *main, int *stacka)
{
	int i;
	int mid;
	int end;
	t_stack *last;
	
	i = 0;
	end = stack_len(main->stacka);
	if (end == 2)
		return (check_last(main));
	mid = stack_len(main->stacka) / 2;
	push(&main->chunks, mid);
	while (i != mid)
	{
			if (main->stacka->elem < stacka[mid])
			{
				p(&main->stacka, &main->stackb);
				i++;
			}
			else
				r(&main->stacka);
	}
	if (end == 3)
		return (check_last(main));
	return (1);
}

int		move_chunk(t_main *main)
{
	t_stack *ptr;

	ptr = main->chunks->n;
	free(main->chunks);
	main->chunks = ptr;
	return (1);
}

int		get_to_put(int *stacka, int len, int mid)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < len)
	{
		if (i > mid)
			ret++;
		i++;
	}
	return (ret);
}

int		case_one(t_main *main)
{
	p(&main->stackb, &main->stacka);
	move_chunk(main);
	return (1);
}

int		case_two(t_main *main)
{
	int i;

	i = -1;
	if (main->stackb->elem < main->stackb->n->elem)
		s(&main->stackb);
	while (++i < 2)
		p(&main->stackb, &main->stacka);
	move_chunk(main);
	return (1);
}

int		case_sorted2(t_main *main)
{
	while (main->chunks->elem)
	{
		p(&main->stackb, &main->stacka);
		main->chunks->elem--;
	}
	move_chunk(main);
	return (1);
}

int		case_sorted(t_main *main)
{
	int i;
	int y;
	t_stack *ptr;

	i = 0;
	y = -1;
	ptr = main->stackb;
	while (i < main->chunks->elem)
	{
		if (y != -1 && ptr->elem > y)
			return (0);
		y = ptr->elem;
		i++;
		ptr = ptr->n;
	}
	return (case_sorted2(main));
}

int		check_cases(t_main *main)
{
	if (main->chunks->elem == 1)
		return (case_one(main));
	else if (main->chunks->elem == 2)
		return (case_two(main));
	else if (case_sorted(main))
		return (1);
	return (0);
}

void	print_stacka(int *stacka, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("[%d]", stacka[i]);
		i++;
	}
}

int	put_to_a(t_main *main, int *stacka)
{
	int mid;
	int max;
	int count_r;

	if (check_cases(main))
		return (0);
	count_r = 0;
	mid = main->chunks->elem / 2;
	max = get_to_put(stacka, main->chunks->elem, mid);
	while (max)
	{
		if (main->stackb->elem > stacka[mid])
		{
			/*
			if (main->stackb->elem == 4)
			{
				print_stack(main->stackb);
				printf("[//%d //%d", max, stacka[mid]);
				exit (0);
			}
			*/
			p(&main->stackb, &main->stacka);
			main->chunks->elem--;
			max--;
		}
		else
		{
			r(&main->stackb);
			count_r++;
		}
	}
	if (main->chunks->elem == 0)
		move_chunk(main);
	while (stack_len(main->chunks) != 1 && count_r)
	{
		rev_r(&main->stackb);
		count_r--;
	}
	return (1);
}

int	stack_sort2(t_main *main, int *stacka)
{
	int i;

	i = 0;
	while (main->chunks)
	{
		free(stacka);
		stacka = stack_to_int(main->stackb, main->chunks->elem);
		quicksort(stacka, 0, main->chunks->elem - 1);
		put_to_a(main, stacka);
		i++;
	}
	print_stack(main->stacka);
	printf("%s", is_sorted(main->stacka) ? "OK\n" : "KO\n");
	//print_stack(main->stacka);
	return (1);	
}

int	init_stack_sort(t_main *main, int *stacka, int len)
{
	int i;

	i = len - 1;
	while (i >= 0)
	{
		push(&main->stacka, stacka[i]);
		i--;
	}
	quicksort(stacka, 0, len - 1);
	while (!is_sorted(main->stacka) && put_to_b(main, stacka))
	{
		free(stacka);
		stacka = stack_to_int(main->stacka, stack_len(main->stacka));
		quicksort(stacka, 0, stack_len(main->stacka) - 1);
	}
	return (stack_sort2(main, stacka));
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		*stacka;
	int		*index;
	int		len;

	len = argc - 1;
	if (!check_format(&stacka, &len, argv))
		return (exit_push_swap("Error\n"));
	if (!(index = malloc(sizeof(int) * 2)))
		return (0);
	main.stacka = NULL;
	main.stackb = NULL;
	init_stack_sort(&main, stacka, len);
}
