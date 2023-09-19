# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:14:33 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/19 22:28:42 by kamitsui         ###   ########.fr        #
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
	   ft_calloc.c \
	   ft_strdup.c \
	   \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   \
	   ft_isupper.c \
	   ft_islower.c \
	   ft_strncat.c \
	   ft_strnlen.c \
	   ft_strtol.c \
	   ft_strndup.c \
	   ft_count_words.c \
	   \
	   ft_isxdigit.c \
	   ft_strjoin_free.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_itoa_binary.c \
	   \
	   ft_strtok.c \
	   \
	   ft_abs.c \
	   \
	   ft_isinteger.c \
	   ft_isint.c \
	   ft_qsort.c


SRCS_B = \
	     ft_lstnew.c \
	     ft_lstadd_front.c \
	     ft_lstsize.c \
	     ft_lstlast.c \
	     ft_lstadd_front.c \
	     ft_lstadd_back.c \
	     ft_lstdelone.c \
	     ft_lstclear.c \
	     ft_lstiter.c \
	     ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

ifdef withbonus
	OBJS += $(OBJS_B)
endif

# all: bonus $(NAME)"loop
# all: $(NAME) bonus"loop
# all: bonus=1
all: $(NAME)

$(NAME): $(OBJS)
	ar -r $@ $^

bonus:
	make withbonus=1

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean bonus all

.PHONY: all clean fclean re bonus
