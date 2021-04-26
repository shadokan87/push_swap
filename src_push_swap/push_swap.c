#include "../libft/libft.h"
#include <stdio.h>

typedef struct s_solve
{
	int left;
	int right;
	int pivot;
	int swap;
}				t_solve;

int	twodlen(char **str)
{
	int i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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

void	print_stack(int *stack, int len)
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

void	quicksort(int *stack, int start, int end)
{
	int pivot;
	int l_most;
	int r_most;
	
	if (!(start < end))
		return ;
	pivot = end;
	l_most = start;
	r_most = end;
	while (l_most < r_most)
	{
		while (stack[l_most] <= stack[pivot] && l_most <= end)
			l_most++;
		while (stack[r_most] > stack[pivot] && r_most >= start)
			r_most--;
		if (l_most < r_most)
		{
			printf("[%d][%d]\n", stack[l_most], stack[r_most]);
			swap(&stack[l_most], &stack[r_most]);
		}
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

int		is_var(char **argv)
{
	int i;
	char **split;

	split = ft_split(argv[1], ' ');
	i = 0;
	while (split[i])
		i++;
	if (i == 1)
		return (0);
	return (1);
}

int		exit_push_swap(char *message)
{
	if (!message)
		printf("Error\n");
	else
		printf("%s", message);
	return (0);
}

int		number_is_valid(char *str)
{
	int i;

	if (str[0] == '-' && str[1])
		i = 1;
	else
		i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int		is_present(int *nb, int len, int to_insert)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (nb[i] == to_insert)
			return (1);
		i++;
	}
	return (0);
}

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

int		fill_stacka(int **stacka, int *nb, int len)
{
	int i;
	int *ret;

	i = 0;
	if (!(ret = malloc(sizeof(int) * len)))
		return (0);
	while (i < len)
	{
		ret[i] = nb[i];
		i++;
	}
	*stacka = ret;
	return (1);
}

int		check_nonvar_format(int **stacka, int *argc, char **argv, int mode)
{
	int i;
	int nb[*argc];
	int to_insert;

	i = mode;
	while (mode ? i <= *argc : i < *argc)
	{
		if (!number_is_valid(argv[i]))
			return (0);
		to_insert = ft_atoi(argv[i]);
		if (i > 1 && is_present(nb, i - 1, to_insert))
			return (0);
		if (!str_diff(ft_itoa(to_insert), argv[i]))
			return (0);
		nb[i - mode] = to_insert;
		i++;
	}
	return (fill_stacka(stacka, nb, *argc));
}

int		check_var_format(int **stacka, int *argc, char **argv)
{
	char **new;

	if (*argc > 2)
		return (0);
	new = ft_split(argv[1], ' ');
	*argc = twodlen(new);
	check_nonvar_format(stacka, argc, new, 0);
}

int		check_format(int **stacka, int *argc, char **argv)
{
	if (!is_var(argv))
		return (check_nonvar_format(stacka, argc, argv, 1));
	else
		return (check_var_format(stacka, argc, argv));
	return (1);
}

int	main(int argc, char **argv)
{
	int *stacka;
	int len;

	len = argc - 1;
	if (!check_format(&stacka, &len, argv))
		return (exit_push_swap("Error\n"));
	quicksort(stacka, 0, len - 1);
	print_stack(stacka, len);
}
