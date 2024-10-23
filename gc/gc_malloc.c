/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:42:42 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/23 14:37:32 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	gc_free(void *adress, t_alloc **mem)
{
	t_alloc	*cpy;
	t_alloc	*prev;

	printf("gc_freen called for pointer %p\n", adress);
	if (!*mem)
		return ;
	cpy = *mem;
	prev = NULL;
	while (cpy)
	{
		if (cpy->adress == adress)
		{
			if (prev)
				prev->next = cpy->next;
			else
				*mem = cpy->next;
			free(cpy->adress);
			free(cpy);
			return ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}

void	gc_free_all(t_alloc **mem)
{
	printf("free all\n");
	while (*mem)
		gc_free((*mem)->adress, mem);
}

void	insert_alloc(void *ptr, t_alloc **mem)
{
	t_alloc	*new;

	new = malloc(sizeof(t_alloc));
	if (!new)
	{
		gc_free_all(mem);
		ft_putstr_fd("Critical : malloc failure\n", 2);
		exit(1);
	}
	new->adress = ptr;
	new->next = NULL;
	if (mem && *mem)
		new->next = *mem;
	*mem = new;
}

void	*gc_malloc(int size, t_alloc **mem)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		gc_free_all(mem);
		ft_putstr_fd("Critical : malloc failure\n", 2);
		exit(1);
	}
	insert_alloc(ptr, mem);
	return (ptr);
}
