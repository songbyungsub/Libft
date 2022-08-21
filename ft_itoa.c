/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byusong <byusong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:14:11 by byusong           #+#    #+#             */
/*   Updated: 2022/08/13 14:28:14 by byusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num *= (-1);
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	fillnbr(long long num, int i, char *str)
{
	if (num < 0)
		num *= (-1);
	if (num >= 10)
		fillnbr(num / 10, i - 1, str);
	str[i] = (num % 10) + '0';
	return (0);
}

char	*ft_itoa(int n)
{
	char		*tmp;
	int			size;
	int			i;
	long long	num1;

	i = 0;
	num1 = n;
	size = str_size(num1);
	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (0);
	if (num1 == 0)
	{	
		tmp[0] = '0';
		tmp[1] = '\0';
		return (tmp);
	}
	if (num1 < 0)
		tmp[0] = '-';
	tmp[size] = '\0';
	fillnbr(num1, size - 1, tmp);
	return (tmp);
}
