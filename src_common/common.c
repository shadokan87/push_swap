#include "../push_swap.h"

int	check_part3(char **argv, int *nb, int mode, int i)
{
	int	to_insert;

//	if (!number_is_valid(argv[i]))
//		return (0);
	to_insert = ft_atoi(argv[i]);
	if (is_present(nb, i - mode, to_insert))
		return (0);
	return (1);
}

int	check_part4(char *tmp, char **argv, int i)
{
	if (!str_diff(tmp, argv[i]))
	{
		free(tmp);
		return (0);
	}
	return (1);
}

int	check_nonvar_format(int **stacka, int *argc, char **argv, int mode)
{
	int		i;
	int		*nb;
	char	*tmp;

	tmp = NULL;
	i = mode;
	nb = new_int(*argc);
	while (mode ? i <= *argc : i < *argc)
	{
		if (tmp)
			free(tmp);
		if (!check_part3(argv, nb, mode, i))
			return (0);
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!check_part4(tmp, argv, i))
			return (0);
		nb[i - mode] = ft_atoi(argv[i]);
		i++;
	}
	if (tmp)
		free(tmp);
	return (fill_stacka(stacka, nb, *argc));
}

int	check_var_format(int **stacka, int *argc, char **argv)
{
	char	**new;

	if (*argc > 2)
		return (0);
	new = ft_split(argv[1], ' ');
	*argc = twodlen(new);
	if (!check_nonvar_format(stacka, argc, new, 0))
		return (0);
	return (1);
}

int	check_format(int **stacka, int *argc, char **argv)
{
	if (!argv[1] || str_diff(argv[1], ""))
		return (0);
	if (!is_var(argv))
		return (check_nonvar_format(stacka, argc, argv, 1));
	else
		return (check_var_format(stacka, argc, argv));
	return (1);
}
