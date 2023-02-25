/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:44:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/25 16:10:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../process.h"
#include <stdio.h>// deleat this row !!!!  for debug :)

static void	letter_error(char *input, t_state_machine *machine)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < NB_FLAG)
	{
		if (i < 2)
			size = 2;
		else
			size = 1;
		i++;
	}
	while (size >= 0)
	{
		letter(input - size, machine);
		size--;
	}
}

int	error(char *input, t_state_machine *machine)
{
	printf("cur = '%c' | state = ERROR\n", *input);// for debug
	letter_error(input, machine);
	machine->state = LETTER;
	machine->flag = 0x00;
	return (1);
}
