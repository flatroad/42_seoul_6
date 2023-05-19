/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2023/02/02 21:41:55 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdio.h>
# include <string.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <errno.h>
# include <dirent.h>

int status;

enum	e_token_type
{
	UNKNOWN = 0,	
	OR = 1,
	AND = 2,		
	PIPE = 3,		
	CMD = 4,		
	OPTION = 5,		
	DQUOTE = 6,		
	QUOTE = 7,		
	RDIR_IN = 8,	
	RDIR_OUT = 9,	
	RDIR_APD = 10,
	HERE_DOC = 11,
	PARENS = 12,
	READ_FILE = 13,
};

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

typedef struct s_refer_env
{
	t_path_list	*path; //-> 실행경로
	t_envp_list	*envp; //-> 환경변수
}	t_refer_env;

typedef	struct s_wc_list
{
	char				*str;
	struct s_wc_list	*next;
}	t_wc_list;

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

// add option
//env
	//check_envp
char	**check_envp(char **envp);
	// free_env
t_refer_env	*free_refer_env(int flag, t_refer_env *refer_env);
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
t_refer_env	*make_refer_env(char **envp);

//execve
	// exec_error_handle.c
int	execst_error_handle(int cas);
int	mulcmd_error_handle(int cas, t_fork *fok);
int	sglcmd_error_handle(int cas, t_fork *fok);
	// execve_main.c
void	exec_st(t_prompt *exec, t_refer_env *refer_env);
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
int	exec_multi_bul(t_fork *fok, t_station *stt, int cas);
int	multi_bulitin(t_station *stt, t_fork *fok, int cas);
	// multi_cmd_exec.c
void	exec_multi_cmd(t_fork *fok, t_station *stt);
	// multi_cmd.c
int	multi_cmd(t_station *stt);
void	start_multi_cmd(t_fork *fok, t_station *stt);
void	start_multi_fork(t_fork *fok, t_station *stt, int *pip, int i);
int	check_multi_case(t_fork *fok, t_station *stt, int *pip, int i);
int	set_pipe(t_fork *fok, int *pip, int i);
	// single_bulitin_exec.c
int	single_bulitin(t_station *stt, int check);
void	single_fork(t_station *stt, char *path, char **cmd);
	// single_cmd.c
int	single_cmd(t_station *stt);
int	exec_single_cmd(t_station *stt);
int	set_dup(t_station *stt);
	// trans_fok.c
t_station	*trans_stt(t_prompt *exec_ptr, t_refer_env *refer_env);
t_station	*free_fork(t_station *stt);
t_fork	*add_fork(t_mini *mini);

t_station	*test_tran(t_refer_env *refer_env);

//bulitin
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

#endif


