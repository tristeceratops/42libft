/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:12:52 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:31:04 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	ret_value;

	ret_value = 0;
	while ((n > 0) && (*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			ret_value = *s1 - *s2;
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return (ret_value);
}
