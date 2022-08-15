/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:12:11 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:29:19 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*make_str(char *str, char c, int k, char **str2)
{
	char	*tmp;
	int		i;
	int		length;

	length = k;
	i = 0;
	while (str[length] != c && str[length] != '\0')
		length++;
	tmp = (char *)malloc(sizeof(char) * (length - k + 1));
	if (!tmp)
	{
		ft_freeall(str2);
		return (0);
	}
	while (k < length && str[k] != '\0')
	{
		tmp[i] = str[k];
		i++;
		k++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int	count_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && (str[i] != c))
			i++;
	}
	return (count);
}

static char	**makestrstr(int size)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (0);
	tmp[size] = 0;
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		i;
	int		k;
	int		count;

	i = 0;
	k = 0;
	if (s == 0)
		return (NULL);
	count = count_str((char *)s, c);
	tmp = makestrstr(count);
	if (!tmp)
		return (NULL);
	while (s[i] != '\0' && k < count)
	{
		while (s[i] != '\0' && (s[i] == c))
			i++;
		if (s[i] != '\0')
			tmp[k++] = make_str((char *)s, c, i, tmp);
		if (tmp[k - 1] == 0)
			return (NULL);
		while (s[i] != '\0' && (s[i] != c))
			i++;
	}
	return (tmp);
}
