#include "../push_swap.h"

int	p(t_stack **src, t_stack **dst)
{
	t_stack	*to_free;

	if (!*src)
		return (0);
	push(dst, (*src)->elem);
	to_free = *src;
	*src = (*src)->n;
	free(to_free);
	return (1);
}

int	r(t_stack **stack)
{
	t_stack	*last;
	t_stack	*ptr;

	last = *stack;
	while (last->n)
		last = last->n;
	ptr = (*stack)->n;
	(*stack)->n = NULL;
	last->n = *stack;
	*stack = ptr;
	return (1);
}

int	rev_r(t_stack **stack)
{
	int		len;
	t_stack	*last;
	t_stack	*prevlast;

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
	return (1);
}

int	is_op(char *op)
{
	int		i;
	char	**ops;

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

int	exec_op(t_main *main)
{
	if (!is_op(main->op))
		return (0);
	return (1);
}
