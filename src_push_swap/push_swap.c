#include "../push_swap.h"
#include <stdio.h>

typedef struct s_solve
{
	int left;
	int right;
	int pivot;
	int swap;
}				t_solve;

int str_diff(char *s1, char *s2)
{
	int i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i])
		return (0);
	return (1);
}

int cutsize = 20;

void	send_op(t_main *main, char *op)
{
	if (str_diff(op, "pa"))
		p(&main->stackb, &main->stacka);
	else if (str_diff(op, "pb"))
		p(&main->stacka, &main->stackb);
	else if (str_diff(op, "sa"))
		s(&main->stacka);
	else if (str_diff(op, "sb"))
		s(&main->stackb);
	else if (str_diff(op, "ra"))
		r(&main->stacka);
	else if (str_diff(op, "rb"))
		r(&main->stackb);
	else if (str_diff(op, "rra"))
		rev_r(&main->stacka);
	else if (str_diff(op, "rrb"))
		rev_r(&main->stackb);
	if (str_diff(op, "rrr"))
	{
		rev_r(&main->stackb);
		rev_r(&main->stacka);
	}
	else if (str_diff(op, "rr"))
	{
		r(&main->stackb);
		r(&main->stacka);
	}
	printf("%s\n", op);
}

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

int	 get_loc(t_stack *stack, int to_find)
{
	int ret;
	t_stack *ptr;

	ret = 0;
	ptr = stack;
	while (ptr && !(ptr->elem < to_find))
	{
		ptr = ptr->n;
		ret++;
	}
	return (ret);
}

int		small_r(t_main *main, int small)
{
	int *stack;
	int i;
	int count;
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

int		small_l(t_main *main, int small)
{
	int *stack;
	int i;

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
	int mid;
	int max;
	int loc;
	int *stacka;
	t_stack *last;

	if (stack_len(main->stacka) == 2 || !stack_len(main->stacka))
		return (case_two_a(main));
	if (is_sorted(main->stacka))
		return (0);
	stacka = stack_to_int(main->stacka, stack_len(main->stacka));
	quicksort(stacka, 0, stack_len(main->stacka) - 1);
	mid = stack_len(main->stacka) / 2;
	while (mid > 10 && mid % 10 != 0)
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
			//print_both(main);
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

int	get_lloc(t_stack *stack, int to_find, int len)
{
	int i;
	t_stack *ptr;

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
	t_stack *ptr;
	int ret;

	ptr = stack;
	if (ptr->n->elem == to_find)
		return (1);	
	ret = get_lloc(stack, to_find, main->chunks->elem);
	if (ret == -1)
		return (-1);
	return (2);
}

int	mv_elem_top(t_stack **stack, int to_find)
{
	int count_r;

	count_r = 0;
	while ((*stack)->elem != to_find)
	{
			r(stack);
			count_r++;
	}
	if (count_r)
		return (1);
	else
		return (0);
}

int	check_cases(t_main *main)
{
	if (main->chunks->elem == 1)
	{
		p(&main->stackb, &main->stacka);
		return (1);
	}
	else if (main->chunks->elem == 2)
	{
		if (main->stackb->elem < main->stackb->n->elem)
			s(&main->stackb);
		p(&main->stackb, &main->stacka);
		p(&main->stackb, &main->stacka);
		return (1);
	}
	return (0);
}

int	get_max3(t_main *main, int mid, int size)
{
	int i;
	int count;

	i = mid + 1;
	count = 0;
	while (i < size)
	{
		i++;
		count++;
	}
	return (count);
}

int		move_small2(t_main *main, int *stacka, int mid)
{
	int count_r;

	count_r = 0;
	while (!(main->stacka->elem < stacka[mid]))
	{
		send_op(main, "ra");
		count_r++;
	}
	return (count_r);
}

int	*dup_int(int *arr, int size)
{
	int *ret;
	int i;
	
	i = 0;
	if (!(ret = malloc(sizeof(size))))
		return (0);
	while (i < size)
	{
		ret[i] = arr[i];
		i++;
	}
	return (ret);
	
}

int	split_len(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	is_present2(char **curr, int to_find)
{
	int i;
	
	i = 0;
	while (curr[i])
	{
		if (ft_atoi(curr[i]) == to_find)
			return (1);
		i++;
	}
	return (0);
}

int	chunkify2(t_main *main, t_stack *tmp)
{
	int *stacka;
	int count;

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
	int *stacka;
	int count;

	t_stack *tmp;
	t_stack *tmp2;
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

int		to_a2_move_to_top(t_main *main, int to_find)
{
	int count_r;

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
	int count_r;
	int *stacka;
	int to_find;

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

int	to_a2(t_main *main)
{
	while (main->chunks->elem > cutsize)
		chunkify(main);
	while (main->chunks->elem)
		to_a2_2(main);
	move_chunk(main);
	if (main->stackb)
		return (to_a2(main));
	return (0);
}

int	init_stack_sort(t_main *main, int *stacka, int len)
{
	int i;
	int count_r;
	int to_find;
	int *orig;
	
	i = len - 1;
	while (i >= 0)
	{
		push(&main->stacka, stacka[i]);
		i--;
	}
	free(stacka);
	to_b(main);
	to_a2(main);
	//exit (0);
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

int		case_two(int *stacka, int len)
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
	t_stack *tmp;
	t_stack *tmp2;
	tmp2 = main.stacka;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->n;
		free(tmp);
	}
}
