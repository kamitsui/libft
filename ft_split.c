/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:06:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/29 19:30:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// worning
#include <stdlib.h>
#include "libft.h"

static size_t	ft_split_count(char *p, char c)
{
	size_t	count;

	count = 0;
	while (*p)
	{
		if (*p == c)
		{
			p++;
			continue ;
		}
//		while (*p == c)// crush
//			p++;
		count++;
		while (*p && *p != c)
		{
			p++;
		}
	}
	return (count);
}

// not norminette (more than 25 line)
char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*p;
	char	*start;
	size_t	count;

	p = (char *)s;
	count = ft_split_count(p, c);
	if (count == 0)
		count = 1;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	result[count] = NULL;
	count = 0;
	while (*p)
	{
		if (*p == c)
		{
			p++;
			continue ;
		}
		start = p;
		while (*p && *p != c)
			p++;
		result[count] = ft_strndup(start, p - start);
		if (result[count] == NULL)
			return (NULL);
		count++;
	}
	return (result);
}
