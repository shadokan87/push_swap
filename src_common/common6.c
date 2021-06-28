#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*casted_s1;
	unsigned char	*casted_s2;

	casted_s1 = (unsigned char *)s1;
	casted_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (casted_s1[i] == casted_s2[i] && casted_s1[i]
		&& casted_s2[i] && i < n)
	{
		if (i + 1 == n)
			return (casted_s1[i] - casted_s2[i]);
		if (casted_s1[i] != casted_s2[i] && casted_s1[i] && casted_s2[i])
			return (casted_s1[i] - casted_s2[i]);
		i++;
	}
	return (casted_s1[i] - casted_s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	return_value;
	int	i;
	int	sign;

	sign = 1;
	return_value = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_value = return_value * 10 + str[i] - '0';
		i++;
	}
	return (return_value * sign);
}
