/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 02:38:06 by sounchoi         ###   ########.fr       */
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
	int		infile_fd;    //file1의 fd
	int		outfile_fd;   //file2의 fd
	int		check_doc;    //"here_doc" 확인 있으면 1, 없으면 0
	int		cmd_start;    //명령어의 시작 index
	int		cmd_end;      //마지막 명령어 index
	int		cmd_count;	  //총 cmd의 갯수.
	char	**env_path;   //환경변수 저장
	char	***cmd_path;  //명령어 execve할 수 있도록 저장.
	int		**fd;		  //다중 파이프라인.
	pid_t	pid;		  //프로세스.
	int		i;
} t_obj;

// pipex_check
void	pipex_check (int argc, char **argv, t_obj *pipex);
int 	len_check (int argc, char **argv, t_obj *pipex);
int 	fd_infile (char **argv, t_obj *pipex);
int 	fd_outfile (int argc, char **argv, t_obj *pipex);
//pipex_doc_check
int		fd_doc(char *flag_str, t_obj *pipex);
int		mk_doc(char *flag_str, int start_fd, int len);
int 	file_open(t_obj *pipex, int i);
//envp_path
void	envp_path(char **envp, t_obj *pipex);
//cmd_path
void	cmd_path(t_obj *pipex, char **argv);
void	make_cmp_path1(t_obj *pipex);
void	make_cmp_path2(t_obj *pipex, char **argv);
void	make_cmp_path3(t_obj *pipex);
//get_pipe
void	get_pipe(t_obj *pipex);
void	make_pipe1(t_obj *pipex);
void	make_pipe2(t_obj *pipex);
//pipex_exec
void	pipex_exec(t_obj *pipex, char **envp);
void	make_fd_pipe(t_obj *pipex);
void	pipex_ch1(t_obj *pipex, int i, int idx, char **envp);
void	pipex_ch2(t_obj *pipex, int i, int idx, char **envp);
//close_pipe
void	close_pipex(t_obj *pipex, int max_i);
//pipex_utils1
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
//pipex_utils2 (split)
size_t		ft_mk_size(char *s, char c);
char		**free_array(char **str_array, size_t idx);
char		**ft_mk_array(char **str_array, char *s, size_t size, char c);
void		ft_pull_array(char **str_array, char *s, size_t size, char c);
char		**ft_split(char const *s, char c);
//close_file
void	close_file(t_obj *pipex);
void	rm_temp(t_obj *pipex);
//close_pipe
void	close_pipe(t_obj *pipex, int max_i);
//get_next_line
char	*get_next_line(int fd, int buf_size);
char	*analyze(int fd, char *save_buf, int buf_size);
char	*analyze_sb(char *save_buf);
char	*out_put(char *read_buf);
char	*save_put(char *read_buf);
//get_next_line_utils
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
//free_cmd_path
void	free_envp (t_obj *pipex);
void	free_cmd(t_obj *pipex);
void	free_cmd_all (t_obj *pipex);
//free_pipe_path
void	free_pipe(t_obj *pipex, int max_i);
//free_all
void	free_all(t_obj *pipex);

#endif
