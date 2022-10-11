#include "pipex.h"

// 아래의 함수는 pipex의 인파일 아웃파일 등을 입력합니다.
void	pipex_check (int argc, char **argv, t_obj *pipex)
{
	if(len_check (argc, argv, pipex) == 1)  //here_doc 확인 및 cmd 갯수, 위치 확인.
	{
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	if(fd_infile (argv, pipex) == 1)
	{
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	if(fd_outfile (argc, argv, pipex) == 1)
	{
		free(pipex);
		pipex = NULL;
		exit(1);
	}
}

int	len_check (int argc, char **argv, t_obj *pipex)
{

	if (argc == 1)
	{
		write(2, "error_check1 : argc is little\n", 30);
		return (1);
	}

	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argv[1][8] == 0)
		pipex->check_doc = 1;
	else
		pipex->check_doc = 0;
	pipex->cmd_start = 2 + pipex->check_doc;    // 시작 index 값.

	if (argc - pipex->check_doc < 5)
	{
		write (2, "error_check2 : argc is little\n", 30);
		return (1);
	}
	pipex->cmd_end = argc - 2;   // 끝 index 값.
	pipex->cmd_count = pipex->cmd_end - pipex->cmd_start + 1;	//pipex의 cmd 갯수.

	return (0);
}

int fd_infile (char **argv, t_obj *pipex)
{
	int	start_fd;

	if (pipex->check_doc == 1)
		if (fd_doc(argv[2], pipex, start_fd) == 1)
			return (1);
	else
	{
		start_fd = open(argv[pipex->cmd_start - 1], O_RDONLY);
		if (start_fd == -1)
		{
			perror("error_check3 ");
			return (0);
		}
		else
			pipex->infile_fd = start_fd;
	}
	return (0);
}

int fd_outfile (int argc, char **argv, t_obj *pipex)
{
	int	end_fd;

	if (pipex->check_doc == 1)
		end_fd = open (argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);	//heredoc일 경우 추가로
	else
		end_fd = open (argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);	//아닐경우 생성으로
	if (end_fd == -1)   // 쓰기 권한이 없으면 디나인이 출력됨.
	{
		perror("error_check4 ");
		close(pipex->infile_fd);
		return (1);
	}
	else
		pipex->outfile_fd = end_fd;
	
	return (0);
}
