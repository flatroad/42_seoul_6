/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:43:48 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

typedef struct s_object_pipex {
	int		infile_fd;		//file1의 fd
	int		outfile_fd;		//file2의 fd
	int		check_doc;		//"here_doc" 확인 있으면 1, 없으면 0
	int		cmd_start;		//명령어의 시작 index
	int		cmd_end;		//마지막 명령어 index
	int		cmd_count;		//총 cmd의 갯수.
	char	**env_path;		//환경변수 저장
	char	***cmd_path;	//명령어 execve할 수 있도록 저장.
	int		**fd;			//다중 파이프라인.
	pid_t	pid;			//프로세스.
} t_obj;



// pipex_check
void	pipex_check(int argc, char **argv, t_obj *pipex);
int 	len_check (int argc, char **argv, t_obj *pipex);
int 	fd_infile (char **argv, t_obj *pipex);
int		fd_outfile (int argc, char **argv, t_obj *pipex);

//pipex_doc_check
int		pipex_here_doc(char *flag_str, t_obj *pipex);
int		mk_doc(char *flag_str, int start_fd, int len);
int 	file_open(t_obj *pipex, int i);

//pipex_envp
void	pipex_envp(char **envp, t_obj *pipex);
void	tr_envp_path(t_obj *pipex);
void	envp_error(t_obj *pipex);

//pipex_cmd
void	pipex_cmd(t_obj *pipex, char **argv);
void	mk_pipex_cmd(t_obj *pipex, char **argv);
void	pipex_cmd_error(t_obj *pipex);

//pipex_pipe
void	get_pipe(t_obj *pipex);
void	mk_pipex_pipe(t_obj *pipex);
void	get_pipe_error(t_obj *pipex);

//pipex_exec
void	pipex_exec(t_obj *pipex, char **envp);
void	mk_fd_pipe(t_obj *pipex);
void	pipex_exec_error(t_obj *pipex);
//pipex_exec_ch
void	pipex_exec_ch(t_obj *pipex, char **envp, int i);
void	tr_pipex_ch1(t_obj *pipex, char **envp, int i);
void	tr_pipex_ch2(t_obj *pipex, char **envp, int i);
int		make_dup(t_obj *pipex, int i);
void	pipex_exec_error_ch(t_obj *pipex);

//pipex_close
void	close_file(t_obj *pipex);
void	close_pipe(t_obj *pipex, int max_i);

//pipex_free
void	free_envp(t_obj *pipex);
void	free_cmd(t_obj *pipex);
void	free_pipe(t_obj *pipex, int max_i);

//pipex_utils1
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

//pipex_utils2 (split)
size_t	ft_mk_size(char *s, char c);
char	**free_array(char **str_array, size_t idx);
char	**ft_mk_array(char **str_array, char *s, size_t size, char c);
void	ft_pull_array(char **str_array, char *s, size_t size, char c);
char	**ft_split(char const *s, char c);

//get_next_line
char	*get_next_line(int fd, int buf_size);
char	*analyze(int fd, char *save_buf, int buf_size, int flag);
char	*analyze_sb(char *save_buf);
char	*out_put(char *read_buf);
char	*save_put(char *read_buf);

//get_next_line_utils
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
