/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:23:53 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/19 16:39:46 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = dest;
	s = src;
	while (n--)
	{
		*p++ = *s++;
	}
	return (dest);
}
