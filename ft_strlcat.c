/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:43:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/18 22:50:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strnlen(dst, dst_size);
	src_len = ft_strlen(src);
	if (dst_len >= dst_size)
		return (dst_size + src_len);
	dst += dst_len;
	i = 0;
	while (*src && i + dst_len + 1 < dst_size)
	{
		*(dst++) = *(src++);
		i++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
