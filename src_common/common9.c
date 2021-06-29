#include "../push_swap.h"

int	set_ret(char **ret, int size, int negative)
{
	int	val;

	val = 1;
	if (negative)
		val = 2;
	if (!new_char(ret, size + val))
		return (0);
	return (1);
}

int	new_char(char **str, size_t size)
{
	*str = malloc(size);
	if (!*str)
		return (0);
	return (1);
}

int	new_star_char(char ***str, size_t size)
{
	*str = malloc(size);
	if (!*str)
		return (0);
	return (1);
}

int	free_int(int *nb, int ret)
{
	free(nb);
	return (ret);
}

void	splitnorme(char ***tab, int i, int **arr)
{
	char	**tab2;

	tab2 = *tab;
	tab2[i] = NULL;
	free(*arr);
}
