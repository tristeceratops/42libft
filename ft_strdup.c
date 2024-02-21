/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:57:14 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:42:50 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_cpy;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[size] != '\0')
		size++;
	str_cpy = malloc(sizeof(char *) * size + 1);
	if (!str_cpy)
		return ((char *) NULL);
	while (s[i] != '\0')
	{
		str_cpy[i] = s[i];
		i++;
	}
	str_cpy[size] = '\0';
	return (str_cpy);
}
