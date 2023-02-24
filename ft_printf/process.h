/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:20:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/24 21:53:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "ft_printf.h"

# define FLAG_HH	"hh"
# define FLAG_LL	"ll"
# define FLAG_H		"h"
# define FLAG_L		"l"
# define FLAG_ZERO	"0"
# define FLAG_HASH	"#"
# define FLAG_SPACE	" "

# define ALL_CONV	"diuoxXpcs%"

# define NB_FLAG	7
# define NB_CONV	10

# define TRUE	1
# define FALSE	0

# define HH			0x000001
# define LL			0x000002
# define H			0x000004
# define L			0x000008
# define ZERO		0x000010
# define HASH		0x000020
# define SPACE		0x000040

# define D_CONV		0x000100
# define I_CONV		0x000200
# define U_CONV		0x000400
# define O_CONV		0x000800
# define X_CONV		0x001000
# define XMAJ_CONV	0x002000
# define P_CONV		0x004000
# define C_CONV		0x008000
# define S_CONV		0x010000
# define PER_CONV	0x020000

typedef int		(*t_f_process)(char *, t_state_machine *);
int		letter(char *input, t_state_machine *machine);
int		flag(char *input, t_state_machine *machine);
int		conv(char *input, t_state_machine *machine);
int		error(char *input, t_state_machine *machine);
void	add_to_buff(char c, t_state_machine *machine);

// enum e_state
// {
// 	LETTER,
// 	FLAG,
// 	CONV,
// 	ERROR,
// 	END
// };

#endif
