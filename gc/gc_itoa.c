/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:34:27 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/21 11:18:33 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	calc_lenth(int n)
{
	int		length;
	long	temp;

	length = 0;
	temp = n;
	if (n < 0)
		length++;
	while (temp != 0)
	{
		length++;
		temp /= 10;
	}
	return (length);
}

static char	*int_to_str(long n, char *str, int length)
{
	int	i;

	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[length] = '\0';
	i = length;
	while (--i >= 0)
	{
		if (str[i] != '-')
		{
			str[i] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

char	*gc_itoa(int n, t_alloc *mem)
{
	int		length;
	long	temp;
	char	*str;

	if (n == 0)
	{
		str = (char *)gc_calloc(2, sizeof(char), mem);
		str[0] = '0';
		return (str);
	}
	length = calc_lenth(n);
	str = (char *)gc_calloc((length + 1), sizeof(char), mem);
	temp = n;
	if (!str)
		return (0);
	str = int_to_str(temp, str, length);
	return (str);
}
