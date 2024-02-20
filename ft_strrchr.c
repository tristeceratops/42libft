/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:42:04 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/20 14:12:19 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*save;

	save = 0;
	while (*s)
	{
		if (*s == c)
			save = s;
		s++;
	}
	return ((char *)save);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s = "Salut ici on est à 42 !";
	char	c = 'z';

	printf("%s\n", strrchr(s, c));
	printf("%s\n", ft_strrchr(s, c));
}*/
