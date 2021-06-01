#include "../push_swap.h"
#include <stdio.h>

typedef struct s_solve
{
	int left;
	int right;
	int pivot;
	int swap;
}				t_solve;

static int str_diff(char *s1, char *s2)
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


void	print_stack3(t_stack *stack, int len)
{
	t_stack *ptr;
	int i;

	i = 0;
	ptr = stack;
	while (ptr && i < len)
	{
		printf("[/%d]\n", ptr->elem);
		ptr = ptr->n;
		i++;
	}
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
	return (i);
}

void	move_small(t_main *main, int *stacka, int mid)
{
	if (small_l(main, stacka[mid]) < small_r(main, stacka[mid]))
	{
	while (!(main->stacka->elem < stacka[mid]))
	{
		//if (main->stacka->n->elem < stacka[mid] && !(main->stacka->elem < stacka[mid]))
		//	send_op(main, "sa");
		//else
		send_op(main, "ra");
	}
	}
	else
	{
	while (!(main->stacka->elem < stacka[mid]))
	{
		//if (main->stacka->n->elem < stacka[mid] && !(main->stacka->elem < stacka[mid]))
		//	send_op(main, "sa");
		//else
		send_op(main, "rra");
	}
	}
	/*
	else
	{
		while (!(main->stacka->elem < stacka[mid]))
			send_op(main, "rra");
	}
	*/
}

int	to_b(t_main *main, int *stacka)
{
	int mid;
	int max;
	int loc;
	t_stack *last;

	if (stack_len(main->stacka) == 2 || !stack_len(main->stacka))
		return (case_two_a(main));
	if (is_sorted(main->stacka))
		return (0);
	mid = stack_len(main->stacka) / 2;
	max = get_max(stacka, stacka[mid]);
	//printf("max %d\n", max);
	push(&main->chunks, max);
	while (max)
	{
		move_small(main, stacka, mid);
		//send_op(main, "ra");
		send_op(main, "pb");
		max--;
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

void	print_chunk(t_main *main)
{
	t_stack *ptr;
	t_stack *ptr2;
	int i;

	ptr2 = main->stackb;
	ptr = main->chunks;
	while (ptr)
	{
		i = 0;
		while (i < ptr->elem)
		{
			printf("[%d]\n", ptr2->elem);
			i++;
			ptr2 = ptr2->n;
		}
		printf("\n\n");
		ptr = ptr->n;
	}
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

int	to_a2(t_main *main, int *stacka)
{
	return (1);
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

int	*malloc_chunk_size(int *stacka, int size)
{
	int *ret;
	int mode;
	int group_malloc_size;
	int tmp;

	mode = ((size % 20) % 10);
	if (mode)
		group_malloc_size = (size / 20) + 1;
	else
		group_malloc_size = size / 20;
	//printf("%d / %d / %d", size, size / 20, mode);
	if (!(ret = malloc(sizeof(int) * group_malloc_size)))
		return (0);
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

int	to_b2(t_main *main, int *stacka, int size)
{
	char *str;
	int i;
	int count;
	int *chunk_size;

	i = 1;
	count = 1;
	str = NULL;
	quicksort(stacka, 0, size - 1);
	chunk_size = malloc_chunk_size(stacka, size);
	str = ft_itoa(stacka[0]);
	chunk_size[0] = 20;
	while (i < size)
	{
		str = ft_strjoin(ft_strjoin(str, " "), ft_itoa(stacka[i]));
		i++;
		count++;
		if (count == 20)
		{
			str = ft_strjoin(str, "\n");
			count = 0;
		}
	}
	char **str2 = ft_split(str, '\n');
	i = 0;
	int y = 0;
	while (str2[i])
	{
		//printf("%s\n", str2[i]);
		i++;
	}
	i = 0;
	char **curr;
	int count_r;

	while (str2[i])
	{
	count_r = 0;
	curr = ft_split(str2[i], ' ');
	count = split_len(curr);
	push(&main->chunks, count);
	while (count)
	{
		while (!is_present2(curr, main->stacka->elem))
		{
			send_op(main, "ra");
			count_r++;
		}
		send_op(main, "pb");
		count--;
	}
	while (count_r)
	{
		send_op(main, "rra");
		count_r--;
	}
	i++;
	}
	//print_chunk(main);
	//exit (0);
}

int	chunkify(t_main *main)
{
	int size;
	int tmp;
	int *stacka;

	tmp = stack_len(main->stacka);
	size = main->chunks->elem;
	//printf("point: %d", main->stacka->elem);
	while (main->chunks->elem)
	{
		send_op(main, "pa");
		main->chunks->elem--;
	}
	move_chunk(main);
	stacka = stack_to_int(main->stacka, size);
	quicksort(stacka, 0, size - 1);
	return (to_b2(main, stacka, size));
}

int	to_a3(t_main *main)
{
	int count_r;
	int *stacka;
	int to_find;
	if (main->chunks->elem > 20)
	{
		return (chunkify(main));
	}
	while (main->chunks->elem)
	{
		count_r = 0;
		stacka = stack_to_int(main->stackb, main->chunks->elem);
		quicksort(stacka, 0, main->chunks->elem - 1);
		to_find = stacka[main->chunks->elem - 1];
		if (main->chunks->elem >= 2 && main->stackb->n->elem == to_find)
			send_op(main, "sb");
		while (main->stackb->elem != to_find)
		{
			send_op(main, "rb");
			count_r++;
		}
		send_op(main, "pa");
		main->chunks->elem--;
		while (count_r && stack_len(main->stackb) > 1)
		{	
			send_op(main, "rrb");
			count_r--;
		}
	}
	move_chunk(main);
	if (main->chunks)
		return (to_a3(main));
	return (0);
}

int	init_stack_sort(t_main *main, int *stacka, int len)
{
	int i;
	int count_r;
	int to_find;
	
	i = len - 1;
	while (i >= 0)
	{
		push(&main->stacka, stacka[i]);
		i--;
	}
		quicksort(stacka, 0, len - 1);
	to_b(main, stacka);
	/*
	while (main->chunks)
	{
		while (main->chunks->elem > 20)
		{
			//printf("end [%d]", main->chunks->elem);
			chunkify(main);
			//print_chunk(main);
			//exit(0);
		}
		while (main->chunks->elem)
		{
			count_r = 0;
			stacka = stack_to_int(main->stackb, main->chunks->elem);
			quicksort(stacka, 0, main->chunks->elem - 1);
			to_find = stacka[main->chunks->elem - 1];
			if (main->chunks->elem >= 2 && main->stackb->n->elem == to_find)
				send_op(main, "sb");
			while (main->stackb->elem != to_find)
			{
				send_op(main, "rb");
				count_r++;
			}
			send_op(main, "pa");
			main->chunks->elem--;
			while (count_r && stack_len(main->stackb) > 1)
			{	
				send_op(main, "rrb");
				count_r--;
			}
		}
		move_chunk(main);
	}
*/
	//print_both(main);
	to_a3(main);
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
	main.stacka = NULL;
	main.stackb = NULL;
	init_stack_sort(&main, stacka, len);
	//print_both(&main);
	//if (is_sorted(main.stacka))
	//	printf("OK\n");
}
