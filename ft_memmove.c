/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:12:32 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:28:59 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	temp = (unsigned char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = temp[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = temp[len - 1];
			len--;
		}
	}
	return (dst);
}
