/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:31:38 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/20 18:16:24 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <unistd.h>

int			ft_atoi(const char *nptr);
void			ft_bzero(void *s, int n);
void			*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
unsigned int	ft_strlen(const char *s);
int			ft_memcmp(const void *s1, const void *s2, unsigned int n);
#endif
