# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:49:19 by choinagi          #+#    #+#              #
#    Updated: 2022/11/24 15:55:10 by sounchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-g
CFILES			=	check_content.c \
					check_file.c \
					check_map.c \
					error_handle.c \
					init_box.c \
					init_error_box.c \
					so_long.c \
					main.c \
					queue_box.c \
					check_possible.c \
					pull_visit.c

OBJS			=	$(CFILES:.c=.o)
NAME			= 	so_long

GNL_DIR		=	./get_next_line
GNL			=	$(GNL_DIR)/gnl.a
LIB_DIR		=	./libft
LIB			=	$(LIB_DIR)/libft.a


$(NAME): $(OBJS)
	@make -C $(GNL_DIR)
	@make -C $(LIB_DIR)
	$(CC) $(CFLAG) $(GNL) $(LIB) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

all: $(NAME)

clean:
	@make -C $(GNL_DIR) clean
	@make -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean:
	@make -C $(GNL_DIR) fclean
	@make -C $(LIB_DIR) fclean
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
