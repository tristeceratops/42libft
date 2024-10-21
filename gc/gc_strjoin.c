/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:34:06 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:02 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*gc_strjoin(char const *s1, char const *s2, t_alloc *mem)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = gc_calloc(size, sizeof(char), mem);
	if (!str)
		return (0);
	if (ft_strlen(s1) > 0)
		ft_strlcat(str, s1, size);
	if (ft_strlen(s2) > 0)
		ft_strlcat(str, s2, size);
	return (str);
}
