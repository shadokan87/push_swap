#include "../push_swap.h"

void	fill_stacka2(t_stack **stack, int **stacka, int len)
{
	int i;
	int *ptr;
	
	ptr = *stacka;
	i = len - 1;
	while (i > -1)
	{
		push(stack, ptr[i]);
		i--;
	}
}

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
	printf("s\n");
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
	printf("p\n");
	return (1);
}

int		r(t_stack **stack)
{
	t_stack *last;
	t_stack *ptr;
	
	last = *stack;
	while (last->n)
		last = last->n;
	ptr = (*stack)->n;
	(*stack)->n = NULL;
	last->n = *stack;
	*stack = ptr;
	printf("r\n");
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
	printf("rev_r\n");
}

int		rr(t_stack **a, t_stack **b)
{
	int ret;

	ret = 0;
	ret += r(a);
	ret += r(b);
	printf("rr\n");
	return (ret);
}

int		rrr(t_stack **a, t_stack**b)
{
	int ret;

	ret = 0;
	ret += rev_r(a);
	ret += rev_r(b);
	printf("rrr\n");
	return (ret);
}

int		listen_op(t_main *main)
{
	return (1);
}

int		is_op(char *op)
{
	int i;
	char **ops;

	ops = ft_split(OPS, ' ');
	i = 0;
	while (ops[i])
	{
		if (!ft_strncmp(op, ops[i], ft_strlen(ops[i])))
			return (1);
		i++;
	}
	return (0);
}

int		exec_op(t_main *main)
{
	if (!is_op(main->op))
		return (0);
}
