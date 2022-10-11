NAME = pipex
SRCS = \
envp_path.c \
free_lib.c \
get_pipe.c \
pipex_check.c \
pipex_cmd.c \
pipex_exec.c \
pipex_utils1.c \
pipex_utils2.c \
pipex.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

ifdef B_FLAG
OBJS += $(OBJS_B)
endif

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

bonus :
	@make B_FLAG=1 all

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
