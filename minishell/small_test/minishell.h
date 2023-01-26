/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2023/01/27 08:09:48 by sounchoi         ###   ########.fr       */
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


typedef struct s_obj
{
	int		**fd;
	char	**cmd;
}	t_obj;

typedef struct	s_token
{
	int	type_num;
	int	value;
	int	order;
	struct s_token *next;
}	t_token;

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

#endif
