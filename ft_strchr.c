/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:08:59 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:29:23 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == c)
		return (&s1[i]);
	return (NULL);
}
