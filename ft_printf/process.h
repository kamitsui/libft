/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:20:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/24 16:49:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PROCESS_H
# define PROCESS_H

# include "ft_printf.h"


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

# define HH			0x000001
# define LL			0x000002
# define H			0x000004
# define L			0x000008
# define ZERO		0x000010
# define HASH		0x000020
# define SPACE		0x000040

typedef int		(*t_f_process)(char *, t_state_machine *);
int		letter(char *input, t_state_machine *machine);
int		flag(char *input, t_state_machine *machine);
int		conv(char *input, t_state_machine);
int		error(char *input, t_state_macine *machine);
void	add_to_buff(char c, t_state_machine *machine);

enum e_state
{
	LETTER,
	FLAG,
	CONV,
	ERROR,
	END
};

#endif
