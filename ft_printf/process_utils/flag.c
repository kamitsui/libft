/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:15:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/24 17:09:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "../ft_printf.h"
//#include "../process.h"// why ...............?
#include <stdlib.h>// remove this !!!  write for debug

//why error if written in "../process.h"
# define FLAG_HH	"hh"
# define FLAG_LL	"ll"
# define FLAG_H		"h"
# define FLAG_L		"l"
# define FLAG_ZERO	"0"
# define FLAG_HASH	"#"
# define FLAG_SPACE	" "

# define NB_FLAG	7

# define TRUE	1
# define FALSE	0

int	flag(char *input, t_state_machine *machine)
{
	static char *str_flag[NB_FLAG] = {FLAG_HH, FLAG_LL, FLAG_H, FLAG_L
									, FLAG_ZERO, FLAG_HASH, FLAG_SPACE};
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
		if (ft_strnequ(input, str_flag[i], size == TRUE))
		{
			machine->flag |= (1 << i);
			char *flag_bin = ft_itoa_binary(machine->flag);
			printf("cur = '%s' state = FLAG\tflag = '%d'\t%s\n", str_flag[i], machine->flag, flag_bin);
			free(flag_bin);
			return (size);
		}
	}
	machine->state = CONV;
	return (size);
}
