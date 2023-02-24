/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:43:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/24 22:03:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "../ft_printf.h"
#include "../process.h"
#include "../conversion.h"

int	conv(char *input, t_state_machine *machine)
{
	static char	*str_conv;
	int			i;

	str_conv = ALL_CONV;
	i = 0;
	while (i < NB_CONV)
	{
		if (ft_strnequ(input, str_conv + i, 1) == TRUE)
		{
			machine->flag |= (1 << i) << 8;
			conversion(machine);
			machine->flag = 0;
			machine->state = LETTER;
			return (1);
		}
		i++;
	}
	machine->state = ERROR;
	return (0);
}
