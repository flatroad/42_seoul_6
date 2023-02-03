/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:16:38 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 22:38:25 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"

# define READ_END 0
# define WRITE_END 1

# define SUCCESS	1
# define FAIL		0
# define TRUE		1
# define FALSE		0
# define ERROR		-1

typedef	struct s_path_list
{
	char				*value;
	struct s_path_list	*next;
}	t_path_list;  //실행경로

typedef	struct s_envp_list
{
	char				*key;
	char				*value;
	struct s_envp_list	*next;
}	t_envp_list;  //환경변수

typedef struct s_ref_env
{
	t_path_list	*path; //-> 실행경로
	t_envp_list	*envp; //-> 환경변수
}	t_ref_env;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
	int		i;
}			t_prompt;

typedef struct s_fork
{
	char			**full_cmd;
	char			*full_path;
	int				check;
	int				infile;
	int				outfile;
	struct s_fork	*next;
}	t_fork;

typedef struct s_station
{
	t_fork		*fok;
	t_envp_list	*env_list;
	t_path_list	*path_list;
	int			check;
}	t_station;

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13
};

char	*mini_readline(t_prompt *prompt, char *str);

void	*mini_here_fd(int fd[2]);


void	*check_args(char *out, t_prompt *p, t_ref_env *refer_env);
char	**ft_cmdtrim(char const *s, char *set);
char	**ft_cmdsubsplit(char const *s, char *set);
char	*ft_strtrim_all(char const *s1, int squote, int dquote);
t_list	*fill_nodes(char **args, int i);

int		get_fd(int oldfd, char *path, int flags[2]);
t_mini	*get_outfile1(t_mini *node, char **args, int *i);
t_mini	*get_outfile2(t_mini *node, char **args, int *i);
t_mini	*get_infile1(t_mini *node, char **args, int *i);
t_mini	*get_infile2(t_mini *node, char **args, int *i);

void	exec_custom(char ***out, char *full, char *args, char **envp);

char	*ft_get_key_env(char *str, int i, char *key, t_prompt *prompt);
char	*expand_vars(char *str, t_ref_env *refer_env, int quotes[2], t_prompt *prompt);
char	*expand_path(char *str, int i, int quotes[2], char *var);
int		get_here_doc(char *str[2], char *aux[2]);
void	*ft_perror(int err_type, char *param, int err);
char	*ft_getenv(char	*var, t_ref_env *refer_env, int n);
char	**ft_setenv(char *var, char *value, char **envp, int n);
char	*get_prompt(t_prompt prompt);
void	free_content(void *content);
void	sigint_set_readline(int sig);
void	sig_exec(int sig);
void	handle_sigint_child(int sig);
int		ft_strchars_i(const char *s, char *set);
int		ft_strchr_i(const char *s, int c);


//asdfsdfsdfsdfsd
void	sig_heredoc_rl(int sig);

// add option
//env
	//check_envp
char	**check_envp(char **envp);
	// free_env
t_ref_env	*free_refer_env(int flag, t_ref_env *refer_env);
void	free_envp(int flag, t_envp_list *start);
void	free_path(int flag, t_path_list *path);
void	free_envp_path(char	**path);
	// make_envp
t_envp_list	*make_envp(char **envp);
t_envp_list	*add_envp_list(char *str);
	// make_path
t_path_list	*make_path(char **envp);
t_path_list	*make_path_list(char **path);
t_path_list	*add_path_list(char *str);
	// make_refer_env
t_ref_env	*make_refer_env(char **envp);

//execve
	// exec_error_handle.c
int	execst_error_handle(int cas);
int	mulcmd_error_handle(int cas, t_fork *fok);
int	sglcmd_error_handle(int cas, t_fork *fok);
	// execve_main.c
void	exec_st(t_prompt *exec, t_ref_env *refer_env);
	// execve_utils.c
int	check_bulitin(t_fork *fok);
	// find_full_path.c
int	find_path(t_fork *fork, t_station *stt);
void	conf_path(char *str, t_fork *fork, t_path_list *path);
int	first_check(char *str, t_fork *fork);
int	second_check(char *check, t_fork *fork, t_path_list *path);
	// find_path_utils.c
void	free_find_path(t_fork *fork);
char	*ft_strjoin_three(char *str_f, char *str_s, char *str_t);
	// multi_bulitin_exec.c
void	exec_multi_bul(t_fork *fok, t_station *stt, int cas);
int		multi_bulitin(t_station *stt, t_fork *fok, int cas);
	// multi_cmd_exec.c
void	exec_multi_cmd(t_fork *fok);
	// multi_cmd.c
int	multi_cmd(t_station *stt);
void	start_multi_cmd(t_fork *fok, t_station *stt);
void	start_multi_fork(t_fork *fok, t_station *stt, int *pip, int i);
int	check_multi_case(t_fork *fok, t_station *stt, int *pip, int i);
int	set_pipe(t_fork *fok, int *pip, int i);
	// single_bulitin_exec.c
int	single_bulitin(t_station *stt, int check);
void	single_fork(t_station *stt, char *path, char **cmd, int pip[2]);
	// single_cmd.c
int	single_cmd(t_station *stt);
int	exec_single_cmd(t_station *stt);
int	set_dup(t_station *stt, int pip[2]);
	// trans_fok.c
t_station	*trans_stt(t_prompt *exec_ptr, t_ref_env *refer_env);
t_station	*make_fok(t_list *memo, t_station *stt);
t_station	*free_fork(t_station *stt);
t_fork	*add_fork(t_mini *mini);

t_station	*test_tran(t_ref_env *refer_env);

//bulitin
	//s_echo s_echo
	void	s_echo(char **str, int fd);
	void	s_group_echo(char **str, int fd);
	int		s_check_option_echo(char *str);
	void	s_is_op_echo(char	**str, int i, int fd);
	void	s_not_op_echo(char **str, int fd);
	//s_env s_env
	void	s_env(t_envp_list *envp, int fd);
	//s_export s_export
	void	s_export(char **exp_str, t_envp_list *envp, int fd);
	//s_export s_free_error_export.c
	void	s_free_exp(t_envp_list *exp);
	void	s_error_pr(t_envp_list *exp);
	//s_export s_make_exp_export_sub.c
	t_envp_list	*s_is_pair(char *str, int i);
	t_envp_list	*s_is_single(char	*str);
	int	s_make_key(char **key, char *str, int i);
	int	s_make_value(char **value, char *str, int i);
	//s_export s_make_exp_export.c
	t_envp_list	*s_make_exp(char **exp_str);
	t_envp_list	*s_check_exp_str(char *str);
	t_envp_list	*s_is_exp_null(void);
	t_envp_list	*s_not_exp_null(char *str);
	//s_export s_out_export.c
	void	s_out_export(t_envp_list *envp, int fd);
	//s_export s_output_exp_export.c
	int	s_output_exp(t_envp_list *exp, t_envp_list *envp);
	int	s_error_check(char *str);
	int	s_push_export(t_envp_list *exp, t_envp_list *envp);
	int	s_same_check(t_envp_list *memo, t_envp_list *exp);
	t_envp_list	*s_change_refer(t_envp_list *exp);
	//s_pwd s_pwd.c
	void	s_pwd(int fd);
	//cd	cd_utils.c
	int	modify_envp(t_envp_list *envp, char *path, char *s);
	int	change_pwd(t_envp_list *list, char *s, int i, int *count);
	int	change_oldpwd(t_envp_list *list, char *s, int i, int *count);
	int	change_dir(char *str);
	int	error_cd(char *s);
	//cd	cd.c
	void	cd(char *str, t_envp_list *envp);
	int	go_to_home(t_envp_list *envp, char *path);
	int	stay_pwd(t_envp_list *envp, char *path);
	int	go_to_str(t_envp_list *envp, char *str, char *old_path);
	//export	export.c
	void	export(char **exp_str, t_envp_list *envp);
	//export	free_error_export.c
	void	free_exp(t_envp_list *exp);
	void	error_pr(t_envp_list *exp);
	void	exec_free(t_station	*stt);
	//export	make_exp_export_sub.c
	t_envp_list	*is_pair(char *str, int i);
	t_envp_list	*is_single(char	*str);
	int	make_key(char **key, char *str, int i);
	int	make_value(char **value, char *str, int i);
	//export	make_exp_export.c
	t_envp_list	*make_exp(char **exp_str);
	t_envp_list	*check_exp_str(char *str);
	t_envp_list	*is_exp_null(void);
	t_envp_list	*not_exp_null(char *str);
	//export	out_export.c
	void	out_export(t_envp_list *envp);
	//export	output_exp_export.c
	int	output_exp(t_envp_list *exp, t_envp_list *envp);
	int	error_check(char *str);
	int	push_export(t_envp_list *exp, t_envp_list *envp);
	int	same_check(t_envp_list *memo, t_envp_list *exp);
	t_envp_list	*change_refer(t_envp_list *exp);
	// echo.c
	void	echo(char **str);
	void	group_echo(char **str);
	int	check_option_echo(char *str);
	void	is_op_echo(char	**str, int i);
	void	not_op_echo(char **str);
	// env.c
	void	env(t_envp_list *envp);
	// pwd.c
	void	pwd(void);
	// unset.c
	void	unset(char **str, t_envp_list *envp);
	void	check_unset(char *str, t_envp_list *envp);
	int		same_check_unset(char *s1, char *s2);
	void	delete_str_unset(t_envp_list **envp, t_envp_list *memo, t_envp_list *before_memo);
	// new_exit.c
	void	new_exit(char **str);
	int	all_num_check(char *str);
	void	new_exit_handle(int i, char *str);                                                                                                                                                                                                                           

#endif