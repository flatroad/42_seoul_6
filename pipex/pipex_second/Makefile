NAME = pipex
SRCS = \
close_file.c \
close_pipe.c \
envp_path.c \
free_all.c \
free_cmd_path.c \
free_pipe_path.c \
get_next_line_utils.c \
get_next_line.c \
get_pipe.c \
here_doc.c \
pipex_check.c \
pipex_cmd.c \
pipex_exec.c \
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

bonus :
	@make B_FLAG=1 all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
