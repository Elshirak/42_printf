/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:49:14 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/28 15:02:19 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_cnt_wd_ini_ar(char const *string_in, char symb_sep, size_t count_w)
{
	char	**array_strings;
	size_t	iter;

	iter = 0;
	while (string_in[iter] && string_in[iter] == symb_sep)
		iter++;
	while (string_in[iter])
	{
		if (string_in[iter] == symb_sep)
		{
			++count_w;
			while (string_in[iter] && string_in[iter] == symb_sep)
				++iter;
			continue ;
		}
		++iter;
	}
	if (string_in[iter - 1] != symb_sep)
		++count_w;
	array_strings = malloc((count_w + 1) * sizeof (char *));
	if (!array_strings)
		return (NULL);
	return (array_strings);
}

size_t	ft_word_end_index(const char *str, char separator, size_t itera)
{
	while (*(str + itera) && *(str + itera) != separator)
		++itera;
	return (itera);
}

void	ft_free(char **ptr_arr, size_t it)
{
	while (it--)
		free(*(ptr_arr + it));
	free(ptr_arr);
}

char	**fil_ar(char **ptr_arr, const char *string_in, char symb_sep, size_t j)
{
	size_t	itera;

	itera = 0;
	while (*(string_in + itera))
	{
		while (*(string_in + itera) && *(string_in + itera) == symb_sep)
			++itera;
		if (*(string_in + itera))
		{
			*(ptr_arr + j) = ft_substr(string_in, itera, \
				ft_word_end_index((string_in + itera), symb_sep, 0));
			if (!*(ptr_arr + j))
			{
				ft_free(ptr_arr, j);
				return (NULL);
			}
			++j;
		}
		while (*(string_in + itera) && *(string_in + itera) != symb_sep)
			++itera;
	}
	*(ptr_arr + j) = 0;
	return (ptr_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_arr;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		ptr_arr = malloc(1 * sizeof (char *));
		ptr_arr[0] = NULL;
		return (ptr_arr);
	}
	ptr_arr = ft_cnt_wd_ini_ar(s, c, 0);
	if (!ptr_arr)
		return (NULL);
	ptr_arr = fil_ar(ptr_arr, s, c, 0);
	if (!ptr_arr)
		return (NULL);
	return (ptr_arr);
}
