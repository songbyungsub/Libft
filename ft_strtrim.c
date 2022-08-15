/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:40:18 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:30:01 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	issep(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*makestr(size_t i, size_t length, char const *str)
{
	char	*tmp;
	size_t	k;

	k = 0;
	tmp = malloc(sizeof(char) * (length - i + 2));
	if (!tmp)
		return (NULL);
	while (i <= length)
	{
		tmp[k] = str[i];
		k++;
		i++;
	}
	tmp[k] = '\0';
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;
	char	*temp;

	i = 0;
	if (set == 0 || s1 == 0)
		return (NULL);
	length = ft_strlen(s1);
	if (length == 0)
	{
		temp = malloc(1);
		temp[i] = '\0';
		return (temp);
	}
	length--;
	while (issep(set, s1[i]) == 1)
		i++;
	while (issep(set, s1[length]) == 1 && length > i)
		length--;
	temp = makestr(i, length, s1);
	return (temp);
}
