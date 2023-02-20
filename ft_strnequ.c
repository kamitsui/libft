/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:51:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/20 14:11:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

int	ft_strnequ(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL)
		return (false);
	if (ft_strncmp(s1, s2, (size_t)n) == 0)
		return (true);
	else
		return (false);
}
