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

int		is_sorted_rev(t_stack *stack, int len)
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

int		move_chunk(t_main *main)
{
	t_stack *ptr;

	ptr = main->chunks->n;
	free(main->chunks);
	main->chunks = ptr;
	return (1);
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

int	get_max(int *stacka, int to_find)
{
	int ret;

	ret = 1;
	while (stacka[ret] != to_find)
		ret++;
	return (ret);
}

int	case_two_a(t_main *main)
{
	if (main->stacka->elem > main->stacka->n->elem)
		s(&main->stacka);
	return (0);
}

int	sorted_a(t_main *main, int *stacka)
{
	int i;
	t_stack *ptr;

	i = 0;
	ptr = main->stacka;
	while (i < stack_len(main->stacka))
	{
		if (stacka[i] != ptr->elem)
			return (0);
		i++;
		ptr = ptr->n;
	}
	return (1);
}

int	to_b(t_main *main, int *stacka)
{
	int mid;
	int max;
	t_stack *last;

	if (stack_len(main->stacka) == 2 || !stack_len(main->stacka))
		return (case_two_a(main));
	if (sorted_a(main, stacka))
		return (0);
	mid = stack_len(main->stacka) / 2;
	max = get_max(stacka, stacka[mid]);
	push(&main->chunks, max);
	while (max)
	{
		if (main->stacka->elem < stacka[mid])
		{
			p(&main->stacka, &main->stackb);
			max--;
		}
		else
		{
			last = get_last(main->stacka);
			if (last->elem < stacka[mid])
				rev_r(&main->stacka);
			else
				r(&main->stacka);
		}
	}
	free(stacka);
	stacka = stack_to_int(main->stacka, stack_len(main->stacka));
	quicksort(stacka, 0, stack_len(main->stacka) - 1);
	return (to_b(main, stacka));
}

int	get_max2(t_main *main, int mid)
{
	int i;
	int count;

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

void	print_both(t_main *main)
{
	printf("A: \n");
	print_stack(main->stacka);
	printf("\nB: \n");
	print_stack(main->stackb);
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

int	to_a(t_main *main, int *stacka)
{
	int mid;
	int i;
	int max;
	int count_r;

	i = 0;
	count_r = 0;
	if (!main->chunks)
		return (0);
	if (main->chunks->elem == 1)
	{
		case_one_b(main);
		return (to_a(main, stacka));
	}
	else if (main->chunks->elem == 2)
	{
		case_two_b(main);	
		return (to_a(main, stacka));
	}
	else if (is_sorted_rev(main->stackb, main->chunks->elem))
	{
		case_sorted_b(main);
		return (to_a(main, stacka));
	}
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
			print_both(main);
			r(&main->stackb);
			count_r++;
		}
	}
	while (count_r)
	{
		rev_r(&main->stackb);
		count_r--;
	}
	if (!main->chunks->elem)
		move_chunk(main);
	return (to_a(main, stacka));
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
	to_b(main, stacka);
	print_both(main);
	printf("//%d", main->chunks->n->elem);
	to_a(main, stacka);
	print_both(main);
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
