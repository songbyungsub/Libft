/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:58:47 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:29:13 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	change_num(unsigned int a, int fd)
{
	unsigned int	ar;
	unsigned int	aq;
	char			aa;

	ar = a % 10;
	aq = a / 10;
	if (aq != 0)
		change_num(aq, fd);
	aa = ar + '0';
	write(fd, &aa, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num1;

	if (n >= 0)
		change_num(n, fd);
	else
	{
		num1 = n * (-1);
		write(fd, "-", 1);
		change_num(num1, fd);
	}
}
