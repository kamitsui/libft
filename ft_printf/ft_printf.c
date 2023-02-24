/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:49:27 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/23 19:42:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../libft.h"
#include "ft_printf.h"

void	ft_printf(char *input, ...)
{
	t_state_machine machine;
	va_list	ap;
	int		ret;

	va_start(ap, input);
	machine.ap = ap;
	machine.state = LETTER;
	machine.len = 0;
	machine.flag = 0;
	ft_bzero((void *)&machine.buffer, (size_t)4096);
	process(input, machine);
	va_end(ap);
}
