#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_obj	*pipex;

	pipex = (t_obj *)malloc(sizeof(t_obj) * 1);
	pipex_check(argc, argv, pipex);	//인자값이 유효한지를 확인 
	envp_path(envp, pipex);			// 환경변수 설정.	
	cmd_path(pipex, argv);			//cmd 명령어 정리
	get_pipe(pipex);					//파이프 생성.	

	// pipex_exec(pipex);
	free_envp (pipex);
	close_file(pipex);
	free(pipex);
	pipex = 0;
	return (0);
}
