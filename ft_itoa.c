/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:39:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/30 22:51:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	n_long;

	n_long = n;
	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	n_long = n * sign;
	len = 0;
	while ((n_long /= 10) > 0)
		len++;
	str = (char *)malloc(sizeof(char *) * (len + (sign < 0) + 1));
	if (str == NULL)
		return (NULL);
	if (sign < 0)
		str[0] = '-';
	str[len + (sign < 0) +1] = '\0';
	n_long = n * sign;
	while (len + 1)
	{
		str[len + (sign < 0)] = n_long % 10 + '0';
		n_long /= 10;
		len--;
	}
	return (str);
}
