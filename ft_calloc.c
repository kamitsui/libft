/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:09:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/17 17:32:53 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct	item {
	int	val;
	char *str;
};

int	main(void)
{
	struct item	*arr;

	arr = calloc(10, sizeof(item)); // use of undeclared identifier 'item' 未宣言識別子の状態　？？わからん
//	printf("%s\n", arr);
}
