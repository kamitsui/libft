/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:06:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/30 21:34:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_allocate_split_strings(char **result, char *p, char c)
{
	char	*start;
	size_t	count;

	count = 0;
	while (*p != '\0')
	{
		if (*p == c)
		{
			p++;
			continue ;
		}
		start = p;
		while (*p != '\0' && *p != c)
			p++;
		result[count] = ft_strndup(start, p - start);
		if (result[count] == NULL)
		{
			count--;
			while (count > 0)
				free(result[count--]);
			free(result);
			return (NULL);
		}
		count++;
	}
	return (result);
}

static size_t	ft_split_count(char *p, char c)
{
	size_t	count;

	count = 0;
	while (*p != '\0')
	{
		if (*p == c)
		{
			p++;
			continue ;
		}
		count++;
		while (*p != '\0' && *p != c)
			p++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*p;
	size_t	count;

	if (s == NULL)
		return (NULL);
	p = (char *)s;
	count = ft_split_count(p, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	result[count] = NULL;
	return (ft_allocate_split_strings(result, p, c));
}
