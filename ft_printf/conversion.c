/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:33:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/25 16:47:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "conversion.h"

void	conversion(t_state_machine *machine)
{
	static t_f_conversion	f_conversion[1] = {decimal};
	int						i;

	i = 0;
	while (i < NB_CONV)
	{
		if ((machine->flag & (1 << i) << 8))
			f_conversion[i](machine);
		i++;
	}
}

/*
	// NULL guard is required ??
	if (machine == NULL)
	{
		machine->state = -1;
		return ;
	}
*/
