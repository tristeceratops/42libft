/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:05:42 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:11 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_sep(char c, char charset)
{
	if (c == '\0')
		return (1);
	if (c == charset)
		return (1);
	return (0);
}

static void	copy_word(char *dest, char const *src, char charset)
{
	int	i;

	i = 0;
	while (check_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	free_2dtable(char **array, int curr_index)
{
	int	index;

	index = 0;
	while (index < curr_index)
	{
		free(array[index]);
		index++;
	}
	return (0);
}

static int	split_words(char **array, char const *str, char charset, t_alloc *mem)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep(str[i + j], charset) == 0)
				j++;
			array[word] = (char *)gc_malloc(sizeof(char) * (j + 1), mem);
			if (!array)
				return (free_2dtable(array, word));
			copy_word(array[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (1);
}

char	**gc_split(char const *s, char c, t_alloc *mem)
{
	char	**array;
	int		words;
	int		i;

	words = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i] != '\0')
		if (check_sep(s[i + 1], c) == 1 && check_sep(s[i], c) == 0)
			words++;
	array = (char **)gc_malloc(sizeof(char *) * (words + 1), mem);
	if (!array)
	{
		free(array);
		return (0);
	}
	array[words] = 0;
	if (!split_words(array, s, c, mem))
	{
		free(array);
		return (0);
	}
	return (array);
}
