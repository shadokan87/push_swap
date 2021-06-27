#include "../push_swap.h"
#include <stdio.h>

int	str_diff(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i])
		return (0);
	return (1);
}

void	send_op2(t_main *main, char *op)
{
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
	send_op2(main, op);
	printf("%s\n", op);
}

int	*get_numbers(char **argv)
{
	int	i;
	int	*ret;

	i = 1;
	while (argv[i])
		i++;
	ret = malloc(sizeof(int) * i);
	if (!ret)
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
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
