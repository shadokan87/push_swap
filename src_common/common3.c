#include "../push_swap.h"

void	fill_stacka2(t_stack **stack, int **stacka, int len)
{
	int	i;
	int	*ptr;

	ptr = *stacka;
	i = len - 1;
	while (i > -1)
	{
		push(stack, ptr[i]);
		i--;
	}
}

int	push(t_stack **stack, int elem)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
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
	t_stack	*print;

	print = stack;
	while (print)
	{
		printf("%d\n", print->elem);
		print = print->n;
	}
}

int	stack_len(t_stack *stack)
{	
	int		i;
	t_stack	*count;

	i = 0;
	count = stack;
	while (count)
	{
		i++;
		count = count->n;
	}
	return (i);
}

int	s(t_stack **stack)
{
	t_stack		*tmp;
	int			i;
	int			len;

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
