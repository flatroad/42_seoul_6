/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:59 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 05:07:13 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_object_pipex {
	int		infile_fd;
	int		outfile_fd;
	int		check_doc;
	int		cmd_start;
	int		cmd_end;
	int		cmd_count;
	char	**env_path;
	char	***cmd_path;
	int		**fd;
	pid_t	pid;
}	t_obj;

void	pipex_check(int argc, char **argv, t_obj *pipex);
int		len_check(int argc, char **argv, t_obj *pipex);
int		fd_infile(char **argv, t_obj *pipex);
int		fd_outfile(int argc, char **argv, t_obj *pipex);

int		pipex_here_doc(char *flag_str, t_obj *pipex);
int		mk_doc(char *flag_str, int start_fd, int len);
int		file_open(t_obj *pipex, int i);

void	pipex_envp(char **envp, t_obj *pipex);
void	tr_envp_path(t_obj *pipex);
void	envp_error(t_obj *pipex);

void	pipex_cmd(t_obj *pipex, char **argv);
void	mk_pipex_cmd(t_obj *pipex, char **argv);
void	pipex_cmd_error(t_obj *pipex);

void	get_pipe(t_obj *pipex);
void	mk_pipex_pipe(t_obj *pipex);
void	get_pipe_error(t_obj *pipex);

void	pipex_exec(t_obj *pipex, char **envp);
void	mk_fd_pipe(t_obj *pipex);
void	pipex_exec_error(t_obj *pipex);

void	pipex_exec_ch(t_obj *pipex, char **envp, int i);
void	tr_pipex_ch1(t_obj *pipex, char **envp, int i);
void	tr_pipex_ch2(t_obj *pipex, char **envp, int i);
int		make_dup(t_obj *pipex, int i);
void	pipex_exec_error_ch(t_obj *pipex);

void	close_file(t_obj *pipex);
void	close_pipe(t_obj *pipex, int max_i);

void	free_envp(t_obj *pipex);
void	free_cmd(t_obj *pipex);
void	free_pipe(t_obj *pipex, int max_i);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

size_t	ft_mk_size(char *s, char c);
char	**free_array(char **str_array, size_t idx);
char	**ft_mk_array(char **str_array, char *s, size_t size, char c);
void	ft_pull_array(char **str_array, char *s, size_t size, char c);
char	**ft_split(char const *s, char c);

char	*get_next_line(int fd, int buf_size);
char	*analyze(int fd, char *save_buf, int buf_size, int flag);
char	*analyze_sb(char *save_buf);
char	*out_put(char *read_buf);
char	*save_put(char *read_buf);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
