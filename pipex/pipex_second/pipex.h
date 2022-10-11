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

// pipex_check
void	pipex_check (int argc, char **argv, t_obj *pipex);
int 	len_check (int argc, char **argv, t_obj *pipex);
int 	fd_infile (char **argv, t_obj *pipex);
int 	fd_outfile (int argc, char **argv, t_obj *pipex);
//pipex_doc_check
int	fd_doc(char *flag_str, t_obj *pipex, int start_fd);
int	mk_doc(char *flag_str, t_obj *pipex, int len);
//envp_path
void	envp_path(char **envp, t_obj *pipex);
//cmd_path
void	cmd_path(t_obj *pipex, char **argv);
void	make_cmp_path1(t_obj *pipex);
void	make_cmp_path2(t_obj *pipex, char **argv);
void	make_cmp_path3(t_obj *pipex);
//pipex_utils1
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
//pipex_utils2 (split)
static size_t	ft_mk_size(char *s, char c);
static char		**free_array(char **str_array, size_t idx);
static char		**ft_mk_array(char **str_array, char *s, size_t size, char c);
static void		ft_pull_array(char **str_array, char *s, size_t size, char c);
char			**ft_split(char const *s, char c);
//close_file
void	close_file(t_obj *pipex);
void	rm_temp(t_obj *pipex);
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
//free_path
void	free_envp (t_obj *pipex);
void	free_cmd(t_obj *pipex);
void	free_cmd_all (t_obj *pipex);

#endif
