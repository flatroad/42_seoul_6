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
} t_obj;

// pipex_check_stage
void		pipex_check (int argc, char **argv, t_obj *pipex);
int			len_check (int argc, char **argv, t_obj *pipex);
int			fd_check (int argc, char **argv, t_obj *pipex);
void		envp_path(char **envp, t_obj *pipex);
void		cmd_path(t_obj *pipex, char **argv);
void		make_cmp_path1(t_obj *pipex);
void		make_cmp_path2(t_obj *pipex, char **argv);
void		make_cmp_path3(t_obj *pipex);
void		get_pipe(t_obj *pipex);
void		make_pipe1(t_obj *pipex);
void		make_pipe2(t_obj *pipex);
void		pipex_exec(t_obj *pipex);
// pipex_child
void	pipex_exec(t_obj *pipex);
void	pipex_ch1(t_obj *pipex, int i);
void	pipex_ch2(t_obj *pipex, int i);
void	pipex_ch3(t_obj *pipex, int i);
// free_check_stage
void	free_envp (t_obj *pipex);
void	free_cmd (t_obj *pipex);
void	free_cmd_all (t_obj *pipex);
void	free_pipe (t_obj *pipex, int i);
void	free_all (t_obj *pipex);
// pipex_utils1, 2
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
// get_next_line_utils
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
// get_next_line
char	*get_next_line(int fd, int buf_size);
char	*analyze(int fd, char *save_buf, int buf_size);
char	*analyze_sb(char *save_buf);
char	*out_put(char *read_buf);
char	*save_put(char *read_buf);

#endif
