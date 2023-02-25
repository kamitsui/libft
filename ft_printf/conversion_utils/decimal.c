/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:15:55 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/25 16:55:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../ft_printf.h"
#include "../process.h"

void	get_nbr(long num, t_state_machine *machine)
{
	if (num < 0)
	{
		add_to_buff('-', machine);
		if (num < -9)
			get_nbr(num / (-10), machine);
	}
	if (num > 9)
		get_nbr(num / 10, machine);
	add_to_buff((num % 10) + '0', machine);
}

void	decimal(t_state_machine *machine)
{
	get_nbr((long)va_arg(machine->ap, int), machine);
}
