
NAME			= minishell

CC				= cc
CFLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=address
RM				= rm -rf

LIB_READ		= -l readline
LDFLAGS			= -L$(shell brew --prefix readline)/lib
CPPFLAGS		= -I$(shell brew --prefix readline)/include

LIB_DIR			= lib/
LIBFT			= libft/libft.a

MAIN			= main

BUILTIN			= echo env export pwd unset new_exit\
				cd cd_utils \
				export free_error_export make_exp_export \
				make_exp_export_sub out_export output_exp_export \
				s_echo s_env s_export s_free_error_export \
				s_make_exp_export_sub s_make_exp_export \
				s_out_export s_output_exp_export \
				s_pwd


PARSER			= fill_node	\
			    ft_cmdsubsplit	\
				ft_cmdtrim	\
			    parse_args \
				ft_strtrim_all \
				get_params \
				heredoc	\
				check_redi_here \
				stop_fill

EXEC			= exec_error_handle execve_main execve_utils find_full_path find_path_utils multi_bulitin_exec \
				multi_cmd multi_cmd_exec single_bulitin_exec single_cmd single_cmd_exec trans_fok list_tran_envp

EXPAND			= expand

ERROR			= error

SIG				= signal

ENV				= environ check_envp free_env make_envp make_path make_refer_env

UTILS			= ft_strchars_i	\
				ft_strchr_i	\
				trim_status



SRCS 			= $(addsuffix .c, $(addprefix src/, $(MAIN))) \
					$(addsuffix .c, $(addprefix src/signal/, $(SIG))) \
					$(addsuffix .c, $(addprefix src/parser/, $(PARSER))) \
					$(addsuffix .c, $(addprefix src/error/, $(ERROR))) \
					$(addsuffix .c, $(addprefix src/execve/, $(EXEC))) \
					$(addsuffix .c, $(addprefix src/expand/, $(EXPAND))) \
					$(addsuffix .c, $(addprefix src/builtin/, $(BUILTIN)))	\
					$(addsuffix .c, $(addprefix src/utils/, $(UTILS)))		\
					$(addsuffix .c, $(addprefix src/environ/, $(ENV)))


OBJS 			= $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -j -C $(LIB_DIR)/libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_DIR)/$(LIBFT) $(LIB_READ) $(LDFLAGS) $(CPPFLAGS)
	@make -j fclean -C $(LIB_DIR)/libft

%.o: %.c $(HEADERS)/$(NAME).h
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
