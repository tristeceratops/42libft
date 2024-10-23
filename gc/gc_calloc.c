/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:28:56 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/23 13:59:55 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*gc_calloc(size_t nmemb, size_t size, t_alloc **mem)
{
	void	*ptr;

	if (nmemb <= 0 || size <= 0)
	{
		size = 1;
		nmemb = 1;
	}
	if (nmemb >= SIZE_MAX / size)
		return (NULL);
	ptr = gc_malloc((nmemb * size), mem);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
