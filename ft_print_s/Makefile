# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sounchoi <sounchoi>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 16:13:35 by sounchoi          #+#    #+#              #
#    Updated: 2023/02/04 21:47:38 by sounchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -src
RM = rm -rf

SRCS = ./ft_printf/ft_printf.c \
./ft_printf/ft_printf_csp.c \
./ft_printf/ft_printf_dux.c
NAME = ./ft_printf/ft_printf.a
OBJS = $(SRCS:.c=.o)

SRCS_B = ./ft_printf_bonus/ft_printf_bonus.c
OBJS_B = $(BONUS:.c=.o)
NAME_B = ft_printf_bonus.a
LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a


ifeq ($(MAKECMDGOALS), bonus)
$(NAME_B): $(OBJS_B)
    @make -C $(LIB_DIR)
	$(AR) $(ARFLAGS) $(LIB) $(OBJS_B) $@ $?
else
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

all : $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	rm -f $(OBJS)
	rm -f $(OBJS_B)

fclean:
	@make -C $(LIB_DIR) fclean
	make clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re :
	make fclean
	make all

.PHONY : all clean fclean re
