# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:49:19 by choinagi          #+#    #+#              #
#    Updated: 2022/11/18 16:14:33 by sounchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
CFILES			=	a_move_cnt_utils.c error.c free_utils.c \
				ft_split.c ft_utils.c init_utils.c main_sort_utils.c \
				parsing.c prompt_r.c prompt_rr.c prompt_sp.c \
				push_swap_utils.c ft_atoll.c push_swap.c \
				prompt_pa.c prompt_pb.c main.c

OBJS			=	$(CFILES:.c=.o)
NAME			= 	push_swap

GNL_DIR		=	./get_next_line
GNL			=	$(GNL_DIR)/gnl.a

BONUS			=	a_move_cnt_utils.c error.c free_utils.c \
				ft_split.c ft_utils.c init_utils.c main_sort_utils.c \
				parsing.c prompt_r.c prompt_rr.c prompt_sp.c \
				push_swap_utils.c ft_atoll.c push_swap.c \
				prompt_pa.c prompt_pb.c \
				checker.c
					
OBJS_B			=	$(BONUS:.c=.o)
NAME_B			=	checker

ifeq ($(MAKECMDGOALS), bonus)
$(NAME_B): $(OBJS_B)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAG) $(GNL) $(OBJS_B) -o $@
else
$(NAME): $(OBJS)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAG) $(GNL) $(OBJS) -o $@
endif

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

all: $(NAME)

clean:
	@make -C $(GNL_DIR) clean
	rm -f $(OBJS)
	rm -f $(OBJS_B)

fclean:
	@make -C $(GNL_DIR) fclean
	make clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re:
	make fclean
	make all

bonus: $(NAME_B)
.PHONY: all clean fclean re bonus
