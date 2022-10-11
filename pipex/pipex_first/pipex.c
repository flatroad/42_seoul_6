#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_obj	*pipex;

	pipex = (t_obj *)malloc(sizeof(t_obj) * 1);
	pipex_check (argc, argv, pipex);	//main문의 인자값이 유효한지를 확인한다. ex) argc의 최소값, here_doc이 있는지. file1과 file2가 유효한지. pipex에 인자값 넣기.
	envp_path(envp, pipex);				// 환경변수 설정.	
	cmd_path(pipex, argv);				//cmd 명령어 정리
	get_pipe(pipex);					//파이프 생성.	

	pipex_exec(pipex);
	exit(0);
	
	return (0);
}
