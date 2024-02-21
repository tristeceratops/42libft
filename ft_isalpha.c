/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:29:29 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 13:36:31 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	ret_value;

	ret_value = 0;
	if (c >= 65 && c <= 90)
		ret_value = 1024;
	if (c >= 97 && c <= 122)
		ret_value = 1024;
	return (ret_value);
}
