#include "../push_swap.h"

int	is_present(int *nb, int len, int to_insert)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (nb[i] == to_insert)
			return (1);
		i++;
	}
	return (0);
}

int	fill_stacka(int **stacka, int *nb, int len)
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc(sizeof(int) * len);
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = nb[i];
		i++;
	}
	*stacka = ret;
	free(nb);
	return (1);
}

int	*new_int(int size)
{
	int	*ret;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	return (ret);
}
