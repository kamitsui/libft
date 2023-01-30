# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:14:33 by kamitsui          #+#    #+#              #
#    Updated: 2023/01/30 21:53:20 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
\
	   ft_isupper.c \
	   ft_islower.c \
	   ft_strncat.c \
	   ft_strnlen.c \
\
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
\
	   ft_strtol.c \
\
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
\
	   ft_strndup.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

#ifdef withbonus
#	SRCS += $SRCS_B
#	OBJS += $OBJS_B
#endif
#	(SRCSに追加する)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $@ $^

#bonus:
#	make withbonus=1
#	#makeを実行するだけ　SRCSとOBJSの中身が変わって　0だと通らない

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
