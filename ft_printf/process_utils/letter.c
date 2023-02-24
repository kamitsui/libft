/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:53:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/23 20:02:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../process.h"// why ...........?
#include "../ft_printf.h"
#include <stdio.h> // deleate this !!!!!!!!!!  (used for debug)

// why error if written in "process.h"
void	add_to_buff(char c, t_state_machine *machine);

int		letter(char *input, t_state_machine *machine)
{
	if (*input == '%')
		machine->state = FLAG;
	else
	{
		add_to_buff(*input, machine);
		printf("cur = '%c' | state = LETTER\n", *input);
	}
	return (1);
}
