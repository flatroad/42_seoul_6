NAME	=	cub3d
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
MLX		=	./libmlx.dylib
SRCS	=	maic.c \
			mini_insert.c \
			mini_obj_insert.c \
			minimap.c \
			find_minimap.c
OBJS	=	${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re