/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:59:17 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 18:26:11 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*ret_str;
	size_t	size;

	while (start > 0 && *s != '\0')
	{
		s++;
		start--;
	}
	size = ft_strlen(s);
	if (len > size)
		len = size;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (0);
	ret_str = substring;
	while (*s != '\0' && len > 0)
	{
		*substring = *s;
		substring++;
		s++;
		len--;
	}
	*substring = '\0';
	return (ret_str);
}
