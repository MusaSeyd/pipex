#include "../includes/pipex.h"

void	child_process(char **argv, char **env, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein== -1)
		error_message();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], env);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT| O_TRUNC, 0777);
	if (fileout == -1)
		error_message();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_message();
		pid = fork();
		if (pid == -1)
			error_message();
		if (pid == 0)
			child_process(argv, env, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
	}
	return(0);
}