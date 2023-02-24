/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:10:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/23 19:41:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>// for: va_list

// # include "process.h"//compile error
enum e_state
{
	LETTER,
	FLAG,
	CONV,
	ERROR,
	END
};

typedef struct s_state_machine
{
	enum e_state	state;
	va_list			ap;
	char			buffer[4096];
	int				len;
	char			*out;
	int				out_size;
	int				flag;
}				t_state_machine;

void	process(char *input, t_state_machine machine);

#endif
