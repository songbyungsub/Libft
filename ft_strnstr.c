/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:10:57 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:29:53 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_same(char *str, const char *find, size_t i, size_t len)
{
	int	k;

	k = 0;
	while (find[k] != '\0')
	{
		if (find[k] != str[i] || i >= len)
			return (0);
		i++;
		k++;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ret;
	char	*hays;

	i = 0;
	hays = (char *)haystack;
	if (needle[i] == '\0')
		return (hays);
	while (i < len && haystack[i] != '\0')
	{
		if (hays[i] == needle[0])
		{
			ret = check_same(hays, needle, i, len);
			if (ret != 0)
				return (&hays[ret - ft_strlen(needle)]);
		}
		i++;
	}
	return (0);
}
