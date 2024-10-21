/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:57:14 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:43 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*gc_strdup(const char *s, t_alloc *mem)
{
	char	*str_cpy;
	int		size;
	int		i;

	size = ft_strlen(s);
	i = 0;
	str_cpy = gc_malloc((sizeof(char) * size + 1), mem);
	if (!str_cpy)
		return ((char *) NULL);
	while (s[i] != '\0')
	{
		str_cpy[i] = s[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
