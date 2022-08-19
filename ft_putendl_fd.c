/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:18:20 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:29:10 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	size;

	if (!s || fd < 0)
		return ;
	size = ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
}
