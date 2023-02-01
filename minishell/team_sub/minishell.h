/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2023/02/01 10:51:41 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

typedef struct s_token
{
	enum e_token_type	type;
	int					hd_num;
	char				*content;
	struct s_token		*next;
}	t_token;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
	// struct s_mini *next;
}			t_mini;

// typedef struct s_prompt
// {
// 	t_list	*cmds;
// 	// t_mini	*cmds;
// 	char	**envp;
// 	pid_t	pid;
// }			t_prompt;

typedef struct s_fork
{
	char			**full_cmd;
	char			*full_path;
	int				infile;
	int				outfile;
	struct s_fork	*next;
}	t_fork;

typedef struct s_station
{
	t_fork		*fok;
	t_envp_list	*env_list;
	t_path_list	*path_list;
	pid_t		pid;
	int			check;
}	t_station;

int	global_sig;

// make_refer_env.c
t_refer_env	*make_refer_env(char **envp);
t_envp_list	*make_envp(char **envp);
t_envp_list	*add_envp_list(char *str);
t_path_list *make_path(char **envp);
char		**check_envp(char **envp);
t_path_list	*make_path_list(char **path);
t_path_list	*add_path_list(char *str);
// free
t_refer_env	*free_refer_env(int flag, t_refer_env *refer_env);
void		free_envp(int flag, t_envp_list *start);
void		free_path(int flag, t_path_list *path);
void		free_envp_path(char	**path);
// env
int	env(t_envp_list *envp);
// export
int	export(char **exp_str, t_envp_list *envp);
// free_error_Export.c
void	free_exp(t_envp_list *exp);
void	error_pr(t_envp_list *exp);
//make_exp_export_sub.c
t_envp_list	*is_pair(char *str, int	i);
t_envp_list	*is_single(char	*str);
int	make_key(char **key, char *str, int i);
int	make_value(char **value, char *str, int i);
//make_exp_export.c
t_envp_list	*make_exp(char **exp_str);
t_envp_list	*check_exp_str(char *str);
t_envp_list	*is_exp_null(void);
t_envp_list	*not_exp_null(char *str);
//out_export.c
void	out_export(t_envp_list *envp);
//output_exp_export.c
int	output_exp(t_envp_list *exp, t_envp_list *envp);
int	error_check(char *str);
int	push_export(t_envp_list *exp, t_envp_list *envp);
int	same_check(t_envp_list *memo, t_envp_list *exp);
t_envp_list	*change_refer(t_envp_list *exp);
//unset.c
int		unset(char **str, t_envp_list *envp);
void	check_unset(char *str, t_envp_list *envp);
int		same_check_unset(char *s1, char *s2);
void	delete_str_unset(t_envp_list **envp, t_envp_list *memo, \
t_envp_list *before_memo);
// pwd
int	pwd(void);
// echo
int		echo(char **str);
void	group_echo(char **str);
int		check_option_echo(char *str);
void	is_op_echo(char	**str, int i);
void	not_op_echo(char **str);
// cd
int	cd(char *str, t_envp_list *envp);
int	go_to_home(t_envp_list *envp, char *path);
int	modify_envp(t_envp_list *envp, char *path, char *s);
int	change_pwd(t_envp_list *list, char *s, int i, int *count);
int	change_oldpwd(t_envp_list *list, char *s, int i, int *count);
int	change_dir(char *str);
int	error_cd(char *s);
int	stay_pwd(t_envp_list *envp, char *path);
int	go_to_str(t_envp_list *envp, char *str, char *path);
//wildcard
t_wc_list	*wildcard(char *str, t_token *token);
t_wc_list	*make_pwd_file_list(char *path, int *check);
t_wc_list	*readdir_all(DIR *dir_ptr, int *check);
t_wc_list	*make_file_list(char *str, t_wc_list *memo, int *check);
t_wc_list	*make_token_file_list(t_token *token, t_wc_list *pwd_file_list, \
int *check, char path[]);
t_wc_list	*make_wildcard_list(t_wc_list *all_file_list, char *str, int *check);
int		check_wc_list(char *s1, char *s2);
int	star_case(char *s1, int *i, char *s2, int *j);
int	other_case(char *s1, int *i, char *s2, int *j);
t_wc_list	*add_wc_list(char *str, int *check);
t_wc_list	*free_wc_list(t_wc_list *list);
t_wc_list	*error_wl_card(char *str, int *check);
char		*error_wl_card_char(char *str, int *check);
struct dirent	*set_file(struct dirent	*file, DIR *dir_ptr);
int	check_case(char *s1, int *i, char *s2, int *j);
t_wc_list	*make_wildcard_list_sub(t_wc_list *all_file_list, char *str, \
int *check, t_wc_list	*wc_start);
t_wc_list	*append_list(t_wc_list *pwd_file_list, char *str, int *check);
t_wc_list	*append_list_sub(t_wc_list *pwd_file_list, char *str, int *check);
t_wc_list	*append_list_sub2(t_wc_list *pwd_file_list, char *str, int *check);
int	check_aski(char *s1, char *s2);
t_wc_list	*add_token_file_list(char *str, int *check);
t_wc_list	*make_token_file_list_sub(t_token *memo, t_wc_list *all_file_list, \
int *check, char path[]);
char	*check_path(char *str, char path[], int	*check);
char	*check_path_str(char path[], char *str, char *new_str, int *check);
t_wc_list	*order_list(t_wc_list *pwd_file_list);
t_wc_list	*set_fisrt(t_wc_list *list);
t_wc_list	*set_other(t_wc_list *list);
int			ft_strncmp_wildcard(const char *s1, const char *s2, size_t n);

t_station *test_tran(t_refer_env *refer_env);
void	exec_st(t_refer_env *refer_env);

int	single_cmd(t_station *stt);
int	exec_single_cmd(t_station *stt);
int	single_fork(t_station *stt, char *path, char **cmd);
int	single_bulitin(t_station *stt, int check);
int	set_dup(t_station *stt);

int	error_handle(char *str, t_station *stt);
int	error_fork(char *str, t_station *stt);

int	check_bulitin(t_fork *fok);

#endif


