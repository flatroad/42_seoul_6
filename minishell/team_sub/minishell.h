/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2023/02/01 02:51:11 by sounchoi         ###   ########.fr       */
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

typedef struct s_redi
{
	int	infile;
	int	outfile;
	struct s_redi	*next;
}	t_redi;

typedef struct s_cmd
{
	char	*str;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_bundle
{
	t_cmd	*cmd;
	t_redi	*redi;
	pid_t	id;
	struct s_bundle *next;
} t_bundle;

typedef struct s_exec
{
	char	**cmd;
	int		infile;
	int		outfile;
	int		fd[2];
	int		check;
	int		id;
	struct s_exec	*next;
}	t_exec;

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
int	env(t_refer_env *refer_env);
// export
int	export(char **exp_str, t_refer_env *refer_env);
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
void	out_export(t_refer_env *refer_env);
//output_exp_export.c
int	output_exp(t_envp_list *exp, t_refer_env *refer_env);
int	error_check(char *str);
int	push_export(t_envp_list *exp, t_refer_env *refer_env);
int	same_check(t_envp_list *memo, t_envp_list *exp);
t_envp_list	*change_refer(t_envp_list *exp);
//unset.c
int		unset(char **str, t_refer_env *refer_env);
void	check_unset(char *str, t_refer_env *refer_env);
int		same_check_unset(char *s1, char *s2);
void	delete_str_unset(t_refer_env *refer_env, t_envp_list *memo, \
t_envp_list *before_memo);
// pwd
int	pwd(void);
// echo
int		echo(char **str);
void	group_echo(char **str);
int		check_option_echo(char *str);
void	is_op_echo(char	**str, int i);
void	not_op_echo(char **str);
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
// cd
int	cd(char *str, t_refer_env *refer_env);
int	go_to_home(t_refer_env *refer_env, char *path);
int	modify_envp(t_refer_env *refer_env, char *path, char *s);
int	change_pwd(t_envp_list *list, char *s, int i, int *count);
int	change_oldpwd(t_envp_list *list, char *s, int i, int *count);
int	change_dir(char *home, t_refer_env *refer_env);
int	error_cd(char *s);
int	stay_pwd(t_refer_env *refer_env, char *path);
int	go_to_str(t_refer_env *refer_env, char *str, char *path);

void	handle_signal(int sig);
#endif


