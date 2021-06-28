#include "../push_swap.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		y;
	char	swap;

	swap = '0';
	i = 0;
	y = ft_strlen(str) - 1;
	while (i < y)
	{
		swap = str[i];
		str[i] = str[y];
		str[y] = swap;
		i++;
		y--;
	}
	return (str);
}

int	count(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (dst == NULL)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*dup_or_negative(int *negative, int *n)
{
	if (*n == -2147483648 || *n == 0)
	{
		if (*n == 0)
			return (ft_strdup("0"));
		else
			return (ft_strdup("-2147483648"));
	}
	if (*n > 0)
		*negative = 0;
	else
		*negative = 1;
	if (*negative)
		*n = *n * -1;
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ret;
	char	*err;
	int		negative;

	i = 0;
	err = dup_or_negative(&negative, &n);
	if (err)
		return (err);
	if (!(set_ret(&ret, sizeof(char) * count(n), negative)))
		return (0);
	while (n)
	{
		ret[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	if ((negative))
	{
		ret[i] = '-';
		i++;
	}
	ret[i] = '\0';
	return (ft_strrev(ret));
}
