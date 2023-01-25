/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2023/01/26 00:32:24 by sounchoi         ###   ########.fr       */
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

#endif
