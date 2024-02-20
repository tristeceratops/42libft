/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:23:30 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/20 13:54:52 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
	{
		s++;
	}
	if (*s == '\0')
		return (0);
	else
	{
		return ((char *) s);
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "Salut ici on est à 42 !";

	char c = 'z';

	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
}*/
