# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:14:33 by kamitsui          #+#    #+#              #
#    Updated: 2024/04/24 08:45:35 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROJECT_DIR = $(notdir $(CURDIR))
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
all: start $(NAME) end
.PHONY: all

start:
	@echo "${YELLOW}Starting build process for '${PROJECT_DIR}'...${NC}"

end:
	@echo "${YELLOW}Build process completed.${NC}"

$(NAME): $(OBJS)
	ar -r $@ $^
	@echo "${GREEN}Successfully created archive: $@${NC}"

bonus:
	make withbonus=1
.PHONY: bonus

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "${RED}Cleaning object files of '${PROJECT_DIR}'...${NC}"
	rm -f $(OBJS) $(OBJS_B)
.PHONY: clean

fclean: clean
	@echo "${RED}Removing archive file...${NC}"
	rm -f $(NAME)
	@echo "${GREEN}Archive file removed.${NC}"
.PHONY: fclean

re: fclean bonus all

# Color Definitions
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color
