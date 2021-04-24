#include "push_swap.h"

int		push(t_stack **stack, int elem)
{
	t_stack *new;

	if (!(new = malloc(sizeof(t_stack))))
		return (0);
	new->elem = elem;
	new->n = NULL;
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	new->n = *stack;
	*stack = new;
	return (1);
}

int		fill_stacka(t_stack **stack, int argc, char **argv)
{
	int i;

	i = argc - 1;
	while (i)
	{
		push(stack, ft_atoi(argv[i]));
		i--;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack *print;
	
	print = stack;
	while (print)
	{
		printf("%d\n", print->elem);
		print = print->n;
	}
}

int		stack_len(t_stack *stack)
{	
	int i;
	t_stack *count;

	i = 0;
	count = stack;
	while (count)
	{
		i++;
		count = count->n;
	}
	return (i);
}

int		s(t_stack **stack)
{
	t_stack *tmp;
	int i;
	int len;

	i = 0;
	len = stack_len(*stack);
	if (!(len >= 2))
		return (0);
	tmp = *stack;
	*stack = (*stack)->n;
	tmp->n = (*stack)->n;
	(*stack)->n = tmp;
	return (1);
}

int		p(t_stack **src, t_stack **dst)
{
	t_stack *to_free;

	if (!*src)
		return (0);
	push(dst, (*src)->elem);
	to_free = *src;
	*src = (*src)->n;
	free(to_free);
}

int		r(t_stack **stack)
{
	int len;
	t_stack *last;
	t_stack *prevlast;
	
	len = stack_len(*stack);
	if (!(*stack && len > 1))
		return (0);
	if (len == 2)
		return (s(stack));
	last = *stack;
	prevlast = *stack;
	while (last->n)
		last = last->n;
	while (prevlast->n->n)
		prevlast = prevlast->n;
	last->n = *stack;
	(*stack)->n = NULL;
	*stack = prevlast;
}

int		rev_r(t_stack **stack)
{
	int len;
	t_stack *last;
	t_stack *prevlast;
	
	len = stack_len(*stack);
	if (!(*stack && len > 1))
		return (0);
	if (len == 2)
		return (s(stack));
	last = *stack;
	prevlast = *stack;
	while (last->n)
		last = last->n;
	while (prevlast->n->n)
		prevlast = prevlast->n;
	prevlast->n = NULL;
	last->n = *stack;
	*stack = last;
}

int		rr(t_stack **a, t_stack **b)
{
	int ret;

	ret = 0;
	ret += r(a);
	ret += r(b);
	return (ret);
}

int		rrr(t_stack **a, t_stack**b)
{
	int ret;

	ret = 0;
	ret += rev_r(a);
	ret += rev_r(b);
	return (ret);
}

int		listen_op(t_main *main)
{
	return (1);
}

void	init_main(t_main *main)
{
	main->stack[A] = NULL;
	main->stack[B] = NULL;
}

int		main(int argc, char **argv)
{
	t_main main;
	init_main(&main);
	
	while ((get_next_line(STDIN_FILENO, &main.op)))
	{	
		printf("[%s]", main.op);
		free(main.op);
	}
}
