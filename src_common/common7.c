/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:11:46 by motoure           #+#    #+#             */
/*   Updated: 2021/06/28 20:57:21 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*cpy_from_till(const char *s, char *str, int from, int till)
{
	int	i;

	i = 0;
	while (i < till)
	{
		str[i] = s[from];
		i++;
		from++;
	}
	str[i] = '\0';
	return (str);
}

static int	words_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_free(char **tab, int i)
{
	while (--i)
	{
		free(tab[i]);
		tab[i] = 0;
	}
	free(tab);
	tab = 0;
	return (NULL);
}

static int	*ewl(char const *s, char c)
{
	int	y;
	int	count;
	int	*ret;

	count = 0;
	y = 0;
	if (!(new_char((char **)&ret, sizeof(int) * words_count(s, c))))
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0')
			{
				s++;
				count++;
			}
			ret[y] = count;
			count = 0;
			y++;
		}
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		*words_len;
	char	**tab;
	int		y;

	if (!s || (!ewl(s, c)))
		return (0);
	words_len = ewl(s, c);
	i = 0;
	y = 0;
	if (!(new_star_char(&tab, sizeof(char *) * words_count(s, c) + 1)))
		return (0);
	while (i < words_count(s, c))
	{
		if (!(new_char(&tab[i], sizeof(char) * words_len[i] + 1)))
			return (ft_free(tab, i));
		while (s[y] == c && s[y])
			y++;
		cpy_from_till(s, tab[i], y, words_len[i]);
		while (s[y] && s[y] != c)
			y++;
		i++;
	}
	splitnorme(&tab, i, &words_len);
	return (tab);
}
