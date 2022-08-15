/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:49:09 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:29:35 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	con;

	k = 0;
	i = ft_strlen(dst);
	con = ft_strlen(dst);
	if (dstsize >= i)
	{
		while (i + 1 < dstsize && src[k] != '\0')
		{
			dst[i] = src[k];
			i++;
			k++;
		}
		dst[i] = '\0';
		return (con + ft_strlen(src));
	}
	else
		return (dstsize + ft_strlen(src));
}
