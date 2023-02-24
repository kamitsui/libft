/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:03:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/23 20:12:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../libft.h"

void	add_to_buff(char c, t_state_machine *machine)
{
	if (machine->len == 4096)
	{
		//ft_strjoin_free(machine->out, machine->buffer);
		ft_bzero(&machine->buffer, 4096);
		machine->len = 0;
	}
	machine->buffer[machine->len] = c;
	machine->len++;
}
