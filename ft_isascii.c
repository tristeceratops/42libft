/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:43:21 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/20 18:14:12 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	ret_value;

	ret_value = 0;
	if (c >= 0 && c <= 127)
		ret_value = 1;
	return (ret_value);
}
