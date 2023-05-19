NAME	=	cub3d
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
GNL_DIR		=	./get_next_line
GNL			=	$(GNL_DIR)/gnl.a
SRCS	=	
OBJS	=	${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAGS) $(GNL) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re