NAME = pipex
SRCS = \
pipex_check.c \
pipex_close.c \
pipex_cmd.c \
pipex_envp.c \
pipex_exec_ch.c \
pipex_exec.c \
pipex_free.c \
pipex_get_next_line_utils.c \
pipex_get_next_line.c \
pipex_here_doc.c \
pipex_pipe.c \
pipex_utils1.c \
pipex_utils2.c \
pipex.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
