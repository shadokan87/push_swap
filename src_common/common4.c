#include "../push_swap.h"

int	twodlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	free_2dtab(char ***to_free, int ret)
{
	char	**ptr;
	int		i;

	i = -1;
	ptr = *to_free;
	if (!ptr)
		return (ret);
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	*to_free = NULL;
	return (ret);
}

int	is_var(char **argv)
{
	int		i;
	int		y;
	char	**split;

	split = ft_split(argv[1], ' ');
	i = 0;
	y = -1;
	while (split[i])
		i++;
	if (i == 1)
	{
		free_2dtab(&split, 0);
		return (0);
	}
	free_2dtab(&split, 1);
	return (1);
}

int	exit_push_swap(t_main *main, char *message)
{
	(void)main;
	if (!str_diff(message, "none"))
	{
		if (!message)
			printf("Error\n");
		else
			printf("%s", message);
	}
	return (0);
}

int	number_is_valid(char *str)
{
	int	i;

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
